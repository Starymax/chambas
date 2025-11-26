# chat_client_gui_files.py
import socket
import threading
import queue
import json
import struct
import os
import tkinter as tk
from tkinter import scrolledtext, messagebox, filedialog, ttk

HOST_DEFECTO = "127.0.0.1"
PORT_DEFECTO = 65436
CHUNK = 65536

CARPETA_DESCARGAS = "descargas_chat"
os.makedirs(CARPETA_DESCARGAS, exist_ok=True)


# ==== Utilidades de framing ====

def send_frame(sock: socket.socket, header: dict):
    header_bytes = json.dumps(header).encode("utf-8")
    header_len = len(header_bytes)
    sock.sendall(struct.pack("!I", header_len))
    sock.sendall(header_bytes)

def send_chunks(sock: socket.socket, filepath: str, filesize: int, callback = None):
    enviado = 0
    with open(filepath, "rb") as f:
        while enviado < filesize:
            chunk = f.read(CHUNK)
            if not chunk:
                break
            sock.sendall(chunk)
            enviado += len(chunk)
            if callback:
                progreso = (enviado/filesize) * 100
                callback(progreso)
    return enviado

def recv_exact(sock: socket.socket, n: int) -> bytes:
    data = b""
    while len(data) < n:
        chunk = sock.recv(n - len(data))
        if not chunk:
            raise ConnectionError("Socket cerrado mientras se recibían datos")
        data += chunk
    return data


def recv_frame(sock: socket.socket):
    raw_len = sock.recv(4)
    if not raw_len:
        raise ConnectionError("Socket cerrado al leer longitud header")
    (header_len,) = struct.unpack("!I", raw_len)
    header_bytes = recv_exact(sock, header_len)
    header = json.loads(header_bytes.decode("utf-8"))

    # NO leer el payload aquí - lo haremos después si es necesario
    return header, None


class ChatClientGUI:
    def __init__(self, master):
        self.master = master
        self.master.title("Chat multiusuario con archivos")

        # Estado de red
        self.sock = None
        self.conectado = False
        self.username = None

        # Cola para mensajes entrantes (texto que se mostrará)
        self.cola_mensajes = queue.Queue()
        # Cola para updates de userlist (lista de strings)
        self.cola_userlist = queue.Queue()
        # cola para updates de grouplist
        self.cola_grouplist = queue.Queue()

        # ---- UI conexión ----
        frame_conn = tk.Frame(master)
        frame_conn.pack(padx=10, pady=5, fill="x")

        tk.Label(frame_conn, text="Servidor:").grid(row=0, column=0, sticky="e")
        self.entry_host = tk.Entry(frame_conn, width=15)
        self.entry_host.insert(0, HOST_DEFECTO)
        self.entry_host.grid(row=0, column=1, padx=3)

        tk.Label(frame_conn, text="Puerto:").grid(row=0, column=2, sticky="e")
        self.entry_port = tk.Entry(frame_conn, width=6)
        self.entry_port.insert(0, str(PORT_DEFECTO))
        self.entry_port.grid(row=0, column=3, padx=3)

        tk.Label(frame_conn, text="Usuario:").grid(row=0, column=4, sticky="e")
        self.entry_user = tk.Entry(frame_conn, width=12)
        self.entry_user.grid(row=0, column=5, padx=3)

        self.btn_conectar = tk.Button(frame_conn, text="Conectar", command=self.conectar)
        self.btn_conectar.grid(row=0, column=6, padx=5)

        # ---- UI principal: lista usuarios + chat ----
        frame_main = tk.Frame(master)
        frame_main.pack(padx=10, pady=5, fill="both", expand=True)

        # Lista de usuarios conectados
        frame_users = tk.Frame(frame_main)
        frame_users.pack(side="left", fill="y")

        tk.Label(frame_users, text="Usuarios conectados").pack()
        self.listbox_users = tk.Listbox(frame_users, height=20, width=20)
        self.listbox_users.pack(fill="y", expand=False)

        # Lista de grupos
        tk.Label(frame_users, text="Grupos").pack(pady=(10, 0))
        self.listbox_grupos = tk.Listbox(frame_users, height=10, width=20)
        self.listbox_grupos.pack(fill="y", expand=False)
        
        # Botón crear grupo
        self.btn_crear_grupo = tk.Button(
            frame_users, 
            text="Crear Grupo", 
            command=self.crear_grupo)
        self.btn_crear_grupo.pack(pady=5)

        # Área de chat
        frame_chat = tk.Frame(frame_main)
        frame_chat.pack(side="left", fill="both", expand=True, padx=(10, 0))

        self.text_chat = scrolledtext.ScrolledText(frame_chat, state="disabled", width=60, height=20)
        self.text_chat.pack(fill="both", expand=True)

        # Campo mensaje + botones
        frame_bottom = tk.Frame(master)
        frame_bottom.pack(padx=10, pady=5, fill="x")

        self.frame_progreso = tk.Frame(master)

        self.label_progreso = tk.Label(self.frame_progreso, text = "")
        self.label_progreso.pack(side = "left", padx = 5)

        self.barraprogreso = ttk.Progressbar(
            self.frame_progreso,
            length=300,
            mode = 'determinate',
            maximum = 100
        )

        self.barraprogreso.pack(side="left", padx=5)

        self.entry_msg = tk.Entry(frame_bottom)
        self.entry_msg.pack(side="left", fill="x", expand=True)
        self.entry_msg.bind("<Return>", self.enviar_texto_evento)

        self.btn_enviar = tk.Button(frame_bottom, text="Enviar mensaje", command=self.enviar_texto)
        self.btn_enviar.pack(side="left", padx=5)

        self.btn_archivo = tk.Button(frame_bottom, text="Enviar archivo", command=self.enviar_archivo)
        self.btn_archivo.pack(side="left", padx=5)

        # Timer para procesar colas
        self.master.after(100, self.procesar_colas)

        # Cierre ordenado
        self.master.protocol("WM_DELETE_WINDOW", self.cerrar)

    # ========= Lógica de red =========

    def conectar(self):
        if self.conectado:
            messagebox.showinfo("Chat", "Ya estás conectado.")
            return

        host = self.entry_host.get().strip()
        port = int(self.entry_port.get().strip())
        username = self.entry_user.get().strip()

        if not username:
            messagebox.showwarning("Chat", "Debes escribir un nombre de usuario.")
            return

        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.connect((host, port))
        except OSError as e:
            messagebox.showerror("Error", f"No se pudo conectar: {e}")
            return

        self.sock = sock
        self.conectado = True
        self.username = username

        # Enviar frame de login
        header = {
            "type": "login",
            "from": self.username,
            "to": "SERVER",
        }
        send_frame(self.sock, header)

        self.btn_conectar.config(state="disabled")
        self._log_local(f"[CLIENTE] Conectado a {host}:{port} como {username}\n")

        # Lanzar hilo de recepción
        hilo = threading.Thread(target=self.hilo_receptor, daemon=True)
        hilo.start()

    def hilo_receptor(self):
        try:
            while self.conectado and self.sock:
                header, payload = recv_frame(self.sock)
                mtype = header.get("type")

                if mtype == "userlist":
                    users = header.get("users", [])
                    self.cola_userlist.put(users)

                elif mtype == "text":
                    remitente = header.get("from")
                    destino = header.get("to")
                    msg = header.get("message", "")
                    self.cola_mensajes.put(f"{remitente} -> {destino}: {msg}\n")
                
                elif mtype == "group_message":
                    remitente = header.get("from")
                    grupo = header.get("group")
                    msg = header.get("message", "")
                    self.cola_mensajes.put(f"[{grupo}] {remitente}: {msg}\n")
                
                elif mtype == "grouplist":
                    grupos = header.get("groups", [])
                    self.cola_grouplist.put(grupos)

                elif mtype == "file":
                    remitente = header.get("from")
                    destino = header.get("to")
                    filename = header.get("filename", "archivo")
                    filesize = header.get("filesize", 0)
                    
                    # Mostrar barra
                    self.master.after(0, lambda: self._mostrarprogreso(f"Recibiendo {filename}..."))
                    
                    ruta = os.path.join(CARPETA_DESCARGAS, filename)

                    # Evitar sobrescribir
                    base, ext = os.path.splitext(ruta)
                    i = 1
                    while os.path.exists(ruta):
                        ruta = f"{base}_{i}{ext}"
                        i += 1

                    # Recibir en fragmentos
                    try:
                        with open(ruta, "wb") as f:
                            recibido = 0
                            while recibido < filesize:
                                # Calcular cuánto leer
                                bytes_faltantes = filesize - recibido
                                chunk_size = min(CHUNK, bytes_faltantes)
                                
                                # Recibir chunk
                                chunk = recv_exact(self.sock, chunk_size)
                                f.write(chunk)
                                recibido += len(chunk)
                                
                                # Actualizar progreso
                                porcentaje = (recibido / filesize) * 100
                                texto = f"Recibiendo {filename}: {porcentaje:.1f}%"
                                self.master.after(0, lambda p=porcentaje, t=texto: 
                                                self._actualizar_progreso(p, t))
                        
                        # Ocultar barra
                        self.master.after(0, self._ocultar_progreso)
                        
                        self.cola_mensajes.put(
                            f"[ARCHIVO] {remitente} te envió '{filename}'. Guardado en: {ruta}\n"
                        )
                        
                    except Exception as e:
                        self.master.after(0, self._ocultar_progreso)
                        self.cola_mensajes.put(f"[ERROR] No se pudo recibir archivo: {e}\n")

                elif mtype == "system":
                    msg = header.get("message", "")
                    self.cola_mensajes.put(f"[SERVIDOR] {msg}\n")

                else:
                    self.cola_mensajes.put(f"[WARN] Mensaje desconocido: {header}\n")

        except (ConnectionError, OSError):
            self.cola_mensajes.put("[CLIENTE] Conexión con el servidor perdida.\n")
        finally:
            self.conectado = False
            self.sock = None

    # ========= Envío de datos =========

    def _obtener_destinatario(self):
        """Obtiene el destinatario (usuario o grupo)"""
        sel_user = self.listbox_users.curselection()
        sel_grupo = self.listbox_grupos.curselection()
        
        # Verificar que solo uno esté seleccionado
        if sel_user and sel_grupo:
            messagebox.showwarning("Chat", "Selecciona SOLO un usuario O un grupo, no ambos.")
            return None
        
        if sel_user:
            usuario = self.listbox_users.get(sel_user[0])
            if usuario == self.username:
                if not messagebox.askyesno("Chat", "Seleccionaste tu propio usuario. ¿Quieres continuar?"):
                    return None
            return ("user", usuario)
        
        if sel_grupo:
            grupo = self.listbox_grupos.get(sel_grupo[0])
            return ("group", grupo)
        
        messagebox.showwarning("Chat", "Selecciona un usuario o grupo en la lista.")
        return None

    def enviar_texto_evento(self, event):
        self.enviar_texto()

    def enviar_texto(self):
        if not self.conectado or not self.sock:
            messagebox.showwarning("Chat", "No estás conectado.")
            return

        resultado = self._obtener_destinatario()
        if not resultado:
            return
        
        tipo, destino = resultado

        texto = self.entry_msg.get().strip()
        if not texto:
            return

        if tipo == "user":
            header = {
                "type": "text",
                "from": self.username,
                "to": destino,
                "message": texto,
            }
        elif tipo == "group":
            header = {
                "type": "group_text",
                "from": self.username,
                "to": destino,
                "message": texto,
            }
        try:
            send_frame(self.sock, header)
            # Mostrar en chat local
            if tipo == "user":
                self._log_local(f"Yo -> {destino}: {texto}\n")
            elif tipo == "group":
                self._log_local(f"Yo -> [{destino}]: {texto}\n")
        except OSError as e:
            messagebox.showerror("Error", f"No se pudo enviar el mensaje: {e}")
            self.conectado = False
            self.sock = None

        self.entry_msg.delete(0, tk.END)

    def enviar_archivo(self):
        if not self.conectado or not self.sock:
            messagebox.showwarning("Chat", "No estás conectado.")
            return

        resultado = self._obtener_destinatario()  # ← CAMBIAR NOMBRE
        if not resultado:
            return
        
        tipo, destino = resultado  # ← DESEMPAQUETAR AQUÍ

        ruta = filedialog.askopenfilename(title="Selecciona un archivo para enviar")
        if not ruta:
            return

        try:
            tam = os.path.getsize(ruta)
            filename = os.path.basename(ruta)
        except OSError as e:
            messagebox.showerror("Error", f"No se pudo leer el archivo: {e}")
            return

        if tam == 0:
            if not messagebox.askyesno("Archivo vacío", "El archivo mide 0 bytes. ¿Deseas enviarlo de todos modos?"):
                return
        
        self._mostrarprogreso(f"Preparando envío de {filename}...")

        hilo = threading.Thread(
            target=self._enviarthread,
            args=(ruta, tipo, destino, filename, tam),  # ← AGREGAR 'tipo'
            daemon=True
        )
        hilo.start()

    def _enviarthread(self, ruta, tipo, destino, filename, tam):  # ← AGREGAR 'tipo'
        try:
            # Preparar header según tipo
            if tipo == "user":
                header = {
                    "type": "file",
                    "from": self.username,
                    "to": destino,
                    "filename": filename,
                    "filesize": tam,
                }
            elif tipo == "group":
                header = {
                    "type": "group_file",  # ← Diferente para grupos
                    "from": self.username,
                    "to": destino,
                    "filename": filename,
                    "filesize": tam,
                }

            send_frame(self.sock, header)
            
            # Callback para actualizar progreso
            def actualizar(porcentaje):
                texto = f"Enviando {filename}: {porcentaje:.1f}%"
                self.master.after(0, lambda: self._actualizar_progreso(porcentaje, texto))
            
            # Enviar archivo en chunks
            enviado = send_chunks(self.sock, ruta, tam, callback=actualizar)
            
            # Ocultar barra y mostrar éxito
            self.master.after(0, self._ocultar_progreso)
            self._log_local(f"[ARCHIVO] Yo -> {destino}: '{filename}' ({tam} bytes) ✓\n")

        except OSError as e:
            self.master.after(0, self._ocultar_progreso)
            mensaje = f"Error al enviar archivo: {e}"
            self.master.after(0, lambda: messagebox.showerror("Error", mensaje))

    # ========= GUI helpers =========

    def _log_local(self, texto: str):
        self.text_chat.config(state="normal")
        self.text_chat.insert(tk.END, texto)
        self.text_chat.see(tk.END)
        self.text_chat.config(state="disabled")

    def _mostrarprogreso(self, texto):
        self.label_progreso.config(text=texto)
        self.barraprogreso['value'] = 0
        self.frame_progreso.pack(padx=10, pady=5, fill="x")

    def _actualizar_progreso(self, porcentaje, texto=None):
        self.barraprogreso['value'] = porcentaje
        if texto:
            self.label_progreso.config(text=texto)

    def _ocultar_progreso(self):
        self.frame_progreso.pack_forget()

    def procesar_colas(self):
        # Mensajes de chat
        try:
            while True:
                msg = self.cola_mensajes.get_nowait()
                self._log_local(msg)
        except queue.Empty:
            pass

        # Actualizar lista de usuarios
        try:
            while True:
                users = self.cola_userlist.get_nowait()
                self.listbox_users.delete(0, tk.END)
                for u in users:
                    self.listbox_users.insert(tk.END, u)
        except queue.Empty:
            pass

        try:
            while True:
                grupos = self.cola_grouplist.get_nowait()
                self.listbox_grupos.delete(0, tk.END)
                for g in grupos:
                    self.listbox_grupos.insert(tk.END, g)
        except queue.Empty:
            pass

        self.master.after(100, self.procesar_colas)

    def cerrar(self):
        self.conectado = False
        if self.sock:
            try:
                self.sock.shutdown(socket.SHUT_RDWR)
            except OSError:
                pass
            self.sock.close()
        self.master.destroy()

    def crear_grupo(self):
        """Abre ventana para crear un grupo"""
        if not self.conectado:
            messagebox.showwarning("Chat", "Debes estar conectado para crear un grupo.")
            return
        
        ventana = tk.Toplevel(self.master)
        ventana.title("Crear Grupo")
        ventana.geometry("300x400")
        
        # Nombre del grupo
        tk.Label(ventana, text="Nombre del grupo:").pack(pady=5)
        entry_nombre = tk.Entry(ventana, width=30)
        entry_nombre.pack(pady=5)
        
        # Lista de usuarios con checkboxes
        tk.Label(ventana, text="Selecciona miembros:").pack(pady=5)
        
        frame_checks = tk.Frame(ventana)
        frame_checks.pack(fill="both", expand=True, padx=10, pady=5)
        
        # Crear scrollbar
        scrollbar = tk.Scrollbar(frame_checks)
        scrollbar.pack(side="right", fill="y")
        
        canvas = tk.Canvas(frame_checks, yscrollcommand=scrollbar.set)
        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.config(command=canvas.yview)
        
        frame_interior = tk.Frame(canvas)
        canvas.create_window((0, 0), window=frame_interior, anchor="nw")
        
        # Variables para checkboxes
        check_vars = {}
        
        # Obtener usuarios conectados de la listbox
        usuarios_disponibles = []
        for i in range(self.listbox_users.size()):
            user = self.listbox_users.get(i)
            if user != self.username:  # No incluir a sí mismo
                usuarios_disponibles.append(user)
        
        # Crear checkbox por cada usuario
        for user in usuarios_disponibles:
            var = tk.BooleanVar()
            check_vars[user] = var
            cb = tk.Checkbutton(frame_interior, text=user, variable=var)
            cb.pack(anchor="w", padx=5, pady=2)
        
        frame_interior.update_idletasks()
        canvas.config(scrollregion=canvas.bbox("all"))
        
        # Botón crear
        def crear():
            nombre_grupo = entry_nombre.get().strip()
            
            if not nombre_grupo:
                messagebox.showwarning("Crear Grupo", "Debes escribir un nombre para el grupo.")
                return
            
            # Obtener usuarios seleccionados
            miembros = [user for user, var in check_vars.items() if var.get()]
            
            if not miembros:
                messagebox.showwarning("Crear Grupo", "Debes seleccionar al menos un miembro.")
                return
            
            # Enviar solicitud al servidor
            header = {
                "type": "create_group",
                "from": self.username,
                "to": "SERVER",
                "group_name": nombre_grupo,
                "members": miembros
            }
            
            try:
                send_frame(self.sock, header)
                ventana.destroy()
                self._log_local(f"[SISTEMA] Solicitud de crear grupo '{nombre_grupo}' enviada\n")
            except OSError as e:
                messagebox.showerror("Error", f"No se pudo enviar la solicitud: {e}")
        
        tk.Button(ventana, text="Crear Grupo", command=crear).pack(pady=10)

def main():
    root = tk.Tk()
    app = ChatClientGUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()