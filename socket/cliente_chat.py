import socket
import os

SERVIDOR = "192.168.11.172"
PORT = 5001
BUFFER = 4096

# archivo a enviar
archivo_path = input("archivo a enviar: ")
if not os.path.exists(archivo_path):
    print("archivo no existe")
    exit()

# conectar al servidor
cliente = socket.socket()
print("conectando...")
cliente.connect((SERVIDOR, PORT))
print("conectado\n")

# obtener info del archivo
nombre = os.path.basename(archivo_path)
tamaño = os.path.getsize(archivo_path)
cliente.send(f"{nombre}|{tamaño}".encode())

# enviar archivo
print(f"enviando {nombre}...")
with open(archivo_path, "rb") as archivo:
    enviado = 0
    while True:
        datos = archivo.read(BUFFER)
        if not datos:
            break
        cliente.sendall(datos)
        enviado += len(datos)
        progreso = (enviado / tamaño) * 100
        print(f"\r {progreso:.0f}%", end="")

print("\narchivo enviado")
cliente.close()