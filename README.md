# README - Resolución de Trabajo Práctico en C

Este repositorio contiene la resolución de un trabajo práctico desarrollado en lenguaje C. El objetivo del trabajo práctico es aplicar los conceptos aprendidos en la asignatura y demostrar habilidades de programación en C.

## Estructura del repositorio

La estructura del repositorio es la siguiente:

```
├── src/
│   ├── principal.c
│   ├── recorrerArchivo.c
│   └── GeneracionArchivo.c
└── README.md
```

- `src/`: Directorio que contiene los archivos fuente del proyecto.
  - `main.c`: Archivo principal del programa, contiene la función `main()` y la lógica principal del trabajo práctico.
  - `recorrerArchivo.c`: Archivo que contiene las implementaciones de las funciones auxiliares utilizadas en el programa.
  - `GeneracionArchivo.c`: Archivo que contiene la generación del archivo como dato de entrada, debe ser el primero en compilar y ejecutarse. 
- `README.md`: Este archivo que estás leyendo ahora, proporciona información sobre el proyecto y cómo utilizarlo.

## Compilación y ejecución del proyecto

Sigue los siguientes pasos para compilar y ejecutar el proyecto:

1. Asegúrate de tener un compilador de C instalado en tu sistema.

2. Clona el repositorio en tu entorno local:

   ```bash
   git clone https://github.com/tu-usuario/trabajo-practico-c.git
   ```

3. Navega al directorio `src/`:

   ```bash
   cd trabajo-practico-c/src
   ```

4. Compila el proyecto utilizando el archivo `Makefile`:

   ```bash
   make
   ```

5. Ejecuta el programa compilado:

   ```bash
   ./main
   ```

6. Sigue las instrucciones en la interfaz de línea de comandos para interactuar con el programa y verificar su funcionamiento.

## Pruebas

El repositorio también incluye archivos de prueba adicionales en el directorio `tests/`. Puedes utilizar estos archivos para probar diferentes escenarios y verificar la robustez del programa.

Para compilar y ejecutar un archivo de prueba específico, sigue los siguientes pasos:


## Contribuciones

Si deseas contribuir al proyecto, sigue estos pasos:

1. Haz un fork de este repositorio.

2. Crea una nueva rama para realizar tus modificaciones:

   ```bash
   git checkout -b tu-rama
   ```

3. Realiza las modificaciones y mejoras en el código.

4. Commitea tus cambios:

   ```bash
   git commit -m "Descripción de tus cambios"
   ```
