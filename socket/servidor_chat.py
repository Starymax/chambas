import socket
import os

# configuracion
HOST = '0.0.0.0'
PORT = 5001
BUFFER = 4096

# crear carpeta para recibir archivos
os.makedirs("archivos_recibidos", exist_ok=True)

# crear servidor
servidor = socket.socket()
servidor.bind((HOST, PORT))
servidor.listen(5)

print(f"servidor activo en puerto {PORT}")
print("esperando archivos...\n")

while True:
    # aceptar conexion
    cliente, direccion = servidor.accept()
    print(f"cliente conectado: {direccion[0]}")
    
    # recibir nombre y tamaño del archivo
    info = cliente.recv(BUFFER).decode().split("|")
    nombre = info[0]
    tamaño = int(info[1])
    print(f"recibiendo: {nombre} ({tamaño} bytes)")
    
    # Recibir y guardar archivo
    ruta = f"archivos_recibidos/{nombre}"
    with open(ruta, "wb") as archivo:
        recibido = 0
        while recibido < tamaño:
            datos = cliente.recv(BUFFER)
            archivo.write(datos)
            recibido += len(datos)
            progreso = (recibido / tamaño) * 100
            print(f"\r {progreso:.0f}%", end="")
    
    print(f"\nguardado en: {ruta}\n")
    cliente.close()