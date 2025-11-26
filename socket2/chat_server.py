# chat_server_files.py
import socket
import threading
import json
import struct

HOST = "0.0.0.0"
PORT = 65436

lock = threading.Lock()
usuarios = {}  # username -> socket
grupos = {}


# ==== Utilidades de framing ====

CHUNK = 65536

def send_frame(sock: socket.socket, header: dict, payload: bytes = b""):
    header_bytes = json.dumps(header).encode("utf-8")
    header_len = len(header_bytes)
    sock.sendall(struct.pack("!I", header_len))  # 4 bytes longitud header
    sock.sendall(header_bytes)
    if payload:
        sock.sendall(payload)


def recv_exact(sock: socket.socket, n: int) -> bytes:
    data = b""
    while len(data) < n:
        chunk = sock.recv(n - len(data))
        if not chunk:
            raise ConnectionError("Socket cerrado mientras se recibían datos")
        data += chunk
    return data


def recv_frame(sock: socket.socket):
    # Leer primero 4 bytes de longitud
    raw_len = sock.recv(4)
    if not raw_len:
        raise ConnectionError("Socket cerrado al leer longitud de encabezado")
    (header_len,) = struct.unpack("!I", raw_len)
    header_bytes = recv_exact(sock, header_len)
    header = json.loads(header_bytes.decode("utf-8"))

    # NO leer el payload aquí - lo haremos después si es necesario
    return header, None


# ==== Lógica del servidor ====

def broadcast_userlist():
    with lock:
        user_list = list(usuarios.keys())
        for user, sock in usuarios.items():
            header = {
                "type": "userlist",
                "from": "SERVER",
                "to": user,
                "users": user_list,
            }
            try:
                send_frame(sock, header)
            except OSError:
                pass

def broadcast_grouplist():
    with lock:
        for username, sock in usuarios.items():
            # Obtener grupos donde está este usuario
            mis_grupos = [
                nombre_grupo 
                for nombre_grupo, miembros in grupos.items()
                if username in miembros
            ]
            
            # Enviar frame con sus grupos
            header = {
                "type": "grouplist",
                "from": "SERVER",
                "to": username,
                "groups": mis_grupos,
            }
            try:
                send_frame(sock, header)
            except OSError:
                pass


def manejar_cliente(sock: socket.socket, addr):
    username = None
    try:
        # Esperar frame de login
        header, _ = recv_frame(sock)
        if header.get("type") != "login":
            raise ValueError("Primer mensaje no es login")

        username = header.get("from")
        if not username:
            raise ValueError("Login sin nombre de usuario")

        with lock:
            if username in usuarios:
                # Nombre en uso
                error_header = {
                    "type": "system",
                    "from": "SERVER",
                    "to": username,
                    "message": "Nombre de usuario ya está en uso.",
                }
                send_frame(sock, error_header)
                raise ValueError("Username duplicado")
            usuarios[username] = sock

        print(f"[+] {username} conectado desde {addr}")
        # Avisar userlist nueva
        broadcast_userlist()
        broadcast_grouplist()

        # Bucle principal de recepción
        while True:
            header, payload = recv_frame(sock)
            mtype = header.get("type")

            if mtype == "text":
                destino = header.get("to")
                mensaje = header.get("message", "")
                print(f"[MSG] {username} -> {destino}: {mensaje}")

                with lock:
                    dest_sock = usuarios.get(destino)
                if dest_sock:
                    send_frame(dest_sock, header)  # reenviamos tal cual
                else:
                    # Enviar error al remitente
                    err = {
                        "type": "system",
                        "from": "SERVER",
                        "to": username,
                        "message": f"Usuario '{destino}' no existe o no está conectado.",
                    }
                    send_frame(sock, err)

            elif mtype == "file":
                destino = header.get("to")
                filename = header.get("filename", "archivo")
                filesize = header.get("filesize", 0)
                print(f"[FILE] {username} -> {destino}: {filename} ({filesize} bytes)")

                # Recibir el archivo completo del cliente
                file_data = b""
                if filesize > 0:
                    file_data = recv_exact(sock, filesize)

                with lock:
                    dest_sock = usuarios.get(destino)
                if dest_sock:
                    # Reenviar mismo header y datos al destinatario
                    send_frame(dest_sock, header, file_data)
                else:
                    err = {
                        "type": "system",
                        "from": "SERVER",
                        "to": username,
                        "message": f"No se pudo entregar el archivo, usuario '{destino}' no está conectado.",
                    }
                    send_frame(sock, err)

            elif mtype == "create_group":
                nombre_grupo = header.get("group_name", "").strip()
                miembros = header.get("members", [])
                
                # Validar nombre de grupo
                if not nombre_grupo:
                    err = {
                        "type": "system",
                        "from": "SERVER",
                        "to": username,
                        "message": "El nombre del grupo no puede estar vacío."
                    }
                    send_frame(sock, err)
                    continue
                
                # Validar que no exista el grupo
                with lock:
                    if nombre_grupo in grupos:
                        err = {
                            "type": "system",
                            "from": "SERVER",
                            "to": username,
                            "message": f"El grupo '{nombre_grupo}' ya existe."
                        }
                        send_frame(sock, err)
                        continue
                    
                    # Validar que todos los miembros existan
                    miembros_validos = [m for m in miembros if m in usuarios]
                    
                    if not miembros_validos:
                        err = {
                            "type": "system",
                            "from": "SERVER",
                            "to": username,
                            "message": "Debes seleccionar al menos un miembro."
                        }
                        send_frame(sock, err)
                        continue
                    
                    # Asegurar que el creador esté en el grupo
                    if username not in miembros_validos:
                        miembros_validos.append(username)
                    
                    # Crear el grupo
                    grupos[nombre_grupo] = miembros_validos
                
                print(f"[+] Grupo '{nombre_grupo}' creado por {username} con miembros: {miembros_validos}")
                
                # Notificar éxito al creador
                exito = {
                    "type": "system",
                    "from": "SERVER",
                    "to": username,
                    "message": f"Grupo '{nombre_grupo}' creado exitosamente."
                }
                send_frame(sock, exito)
                
                # Actualizar lista de grupos para todos los miembros
                broadcast_grouplist()

            elif mtype == "group_text":
                nombre_grupo = header.get("to")
                mensaje = header.get("message", "")
                
                print(f"[GROUP MSG] {username} -> {nombre_grupo}: {mensaje}")
                
                with lock:
                    miembros = grupos.get(nombre_grupo, [])
                
                if not miembros:
                    err = {
                        "type": "system",
                        "from": "SERVER",
                        "to": username,
                        "message": f"El grupo '{nombre_grupo}' no existe."
                    }
                    send_frame(sock, err)
                    continue
                
                # Verificar que el usuario está en el grupo
                if username not in miembros:
                    err = {
                        "type": "system",
                        "from": "SERVER",
                        "to": username,
                        "message": f"No eres miembro del grupo '{nombre_grupo}'."
                    }
                    send_frame(sock, err)
                    continue
                
                # Enviar mensaje a todos los miembros del grupo
                enviados = 0
                with lock:
                    for miembro in miembros:
                        if miembro in usuarios:
                            dest_sock = usuarios[miembro]
                            nuevo_header = {
                                "type": "group_message",
                                "from": username,
                                "group": nombre_grupo,
                                "message": mensaje
                            }
                            try:
                                send_frame(dest_sock, nuevo_header)
                                enviados += 1
                            except OSError:
                                pass
                
                print(f"[GROUP MSG] Enviado a {enviados}/{len(miembros)} miembros")

            elif mtype == "group_file":
                nombre_grupo = header.get("to")
                filename = header.get("filename", "archivo")
                
                print(f"[GROUP FILE] {username} -> {nombre_grupo}: {filename}")
                
                with lock:
                    miembros = grupos.get(nombre_grupo, [])
                
                if not miembros:
                    err = {
                        "type": "system",
                        "from": "SERVER",
                        "to": username,
                        "message": f"El grupo '{nombre_grupo}' no existe."
                    }
                    send_frame(sock, err)
                    continue
                
                if username not in miembros:
                    err = {
                        "type": "system",
                        "from": "SERVER",
                        "to": username,
                        "message": f"No eres miembro del grupo '{nombre_grupo}'."
                    }
                    send_frame(sock, err)
                    continue
                # Primero: recibir el payload (datos del archivo) del cliente original
                filesize = header.get("filesize", 0)
                file_data = b""
                if filesize > 0:
                    try:
                        file_data = recv_exact(sock, filesize)
                    except ConnectionError:
                        err = {
                            "type": "system",
                            "from": "SERVER",
                            "to": username,
                            "message": "Conexión perdida mientras se recibía el archivo del remitente."
                        }
                        send_frame(sock, err)
                        continue

                # Enviar archivo a todos los miembros del grupo
                with lock:
                    for miembro in miembros:
                        if miembro in usuarios and miembro != username:  # No enviar a sí mismo
                            dest_sock = usuarios[miembro]
                            nuevo_header = header.copy()
                            nuevo_header["type"] = "file"  # Cambiar a file normal para receptores
                            nuevo_header["from"] = f"{username} [{nombre_grupo}]"  # Indicar que es de grupo
                            try:
                                send_frame(dest_sock, nuevo_header, file_data)
                            except OSError:
                                pass

            else:
                # Mensaje no soportado
                print(f"[WARN] Tipo no soportado: {mtype} de {username}")

    except (ConnectionError, OSError):
        print(f"[!] Conexión perdida con {addr} ({username})")
    except Exception as e:
        print(f"[ERR] Error con {addr} ({username}): {e}")
    finally:
        if username:
            with lock:
                if usuarios.get(username) is sock:
                    del usuarios[username]
            print(f"[-] {username} desconectado")
            broadcast_userlist()
        try:
            sock.close()
        except OSError:
            pass


def main():
    servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    servidor.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    servidor.bind((HOST, PORT))
    servidor.listen()
    print(f"[SERVIDOR] Escuchando en {HOST}:{PORT} ...")

    try:
        while True:
            conn, addr = servidor.accept()
            hilo = threading.Thread(target=manejar_cliente, args=(conn, addr), daemon=True)
            hilo.start()
    except KeyboardInterrupt:
        print("\n[SERVIDOR] Cerrando por CTRL+C...")
    finally:
        servidor.close()


if __name__ == "__main__":
    main()
