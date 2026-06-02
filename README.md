//enlace a github:https://github.com/eskheleitor/practica4-so/edit/main/README.md
# Práctica 4 - Procesamiento e Interpolación de Imagenes 

# Descripción

Esta practica consiste en el desarrollo de un sistema distribuido utilizando C++   y Python para el procesamiento de información tactil procedente de un sensor robotico.

El sistema es capaz de leer capturas almacenadas en formato JSON,  validar las matrices recibidas, aplicar interpolación bilineal para aumentar su resolución y generar imágenes que representan la distribución de presión detectada.

# Estructura del proyecto

``` text
practica4-so
│
|-- main.cpp
|-- json_reader.h
|-- json_reader.cpp
|-- matrix_validator.h
|-- matrix_validator.cpp
|-- interpolation.h
|-- interpolation.cpp
|-- http_client.h
|-- http_client.cpp
|-- tactile_captures_50.json
|--INFORME_PRACTICA_4_.pdf
│
|-- python_server
│   ├--server.py
│   └--requirements.txt
│
└-- imagenes_generadas
```

# Funcionamiento

El sistema sigue una arquitectura cliente-servidor.

# Cliente C++

* Lee las capturas almacenadas en un archivo JSON.
* Valida que las matrices tengan dimensiones 16x16.
* Aplica interpolación bilineal para obtener matrices de 128x128.
* Envía los datos al servidor mediante peticiones HTTP POST.

# Servidor Python

* Recibe las matrices interpoladas.
* Reconstruye la información recibida.
* Genera mapas de calor utilizando Matplotlib.
* Guarda automáticamente las imágenes generadas en formato PNG.

# Librerías utilizadas

# C++

* nlohmann/json
* libcurl

# Python

* Flask
* NumPy
* Matplotlib

# Compilación

```bash
g++ *.cpp -lcurl -o practica4
```

# Ejecución

# Iniciar servidor Python

```bash
python3 python_server/server.py
```

### Ejecutar cliente C++

```bash
./practica4
```

# Resultados

Tras la ejecución del programa se generan automáticamente imágenes PNG que representan la distribución de presión de cada captura táctil procesada.

Las imágenes se almacenan en la carpeta:

```text
imagenes_generadas/
```

# Autores

* Lucia Castellanos Paz
* Ander Zuazquita Pastor

Asignatura: Sistemas Operativos
Curso: 2025-2026
