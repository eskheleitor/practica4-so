from flask import Flask, request, jsonify

import numpy as np
import matplotlib.pyplot as plt
import os

# Cear servidor
app = Flask(__name__)

# Crear carpeta para guardar imagenes
if not os.path.exists("imagenes_generadas"):
    os.makedirs("imagenes_generadas")


# Ruta que recibira las matrices desde C++
@app.route("/upload", methods=["POST"])
def recibirMatriz():

    # Obtener datos enviados
    datos = request.json

    # Leer informacion recibida
    idCaptura = datos["capture_id"]

    ancho = datos["width"]

    alto = datos["height"]

    matriz = np.array(datos["data"])

    print("Captura recibida:", idCaptura)
    print("Dimensiones:", ancho, "x", alto)

    # Crear figura
    plt.figure(figsize=(6, 6))

    # Mostrar matriz como mapa de calor
    plt.imshow(matriz, cmap="inferno")

    # Barra lateral de colores
    plt.colorbar(label="Presion")

    # Titulo de la imagen
    plt.title(f"Mapa tactil {idCaptura}")

    # Nombre del archivo
    nombreImagen = (
        f"imagenes_generadas/capture_{idCaptura}.png"
    )

    # Guardar imagen
    plt.savefig(nombreImagen)

    # Cerrar figura para liberar memoria
    plt.close()

    print("Imagen guardada:", nombreImagen)

    # Respuesta al cliente
    return jsonify({
        "mensaje": "Imagen generada correctamente"
    })


# Iniciar servidor
if __name__ == "__main__":

    print("Servidor iniciado")

    app.run(
        host="0.0.0.0",
        port=5000,
        debug=True
    )
