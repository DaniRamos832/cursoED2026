Taller Métodos de Organización Eficientes y Búsqueda Binaria
Unidad 5 - Estructura de Datos
Integrantes:

Loren Dayana Quintero Ramos
Mery Daniela Angulo Sinisterra
Karol Nicol Díaz Silva
Descripción
Este proyecto consiste en el desarrollo de un programa en lenguaje C para la gestión de contenedores en un patio de carga portuario.

El sistema permite registrar, organizar y buscar pesos de contenedores mediante el uso de arreglos, funciones, métodos de ordenamiento eficientes y búsqueda binaria, aplicando los conceptos estudiados en la Unidad 5.

Funcionalidades
Registro manual de pesos de contenedores.
Generación aleatoria de pesos utilizando rand()y srand(time(NULL)).
Visualización de los contenedores registrados.
Ordenamiento de contenedores mediante:
Ordenación rápida
Ordenar por fusión
Ordenación por montículo
Búsqueda binaria de contenedores.
Control del estado del arreglo mediante una bandera de ordenamiento.
Requisitos
Lenguaje C
GCC
Código de Visual Studio
Compilación
gcc main.c -o main

Ejecución
.\main.exe

Estructura del Proyecto
unidad5/ └── tallerMetodosEficientes/ ├── main.c ├── README.md └── evidencias/

Métodos de Ordenamiento Implementados
Ordenación rápida
Método de ordenamiento eficiente basado en la estrategia de dividir y conquistar mediante el uso de un pivote.

Ordenar por fusión
Método de ordenamiento eficiente que divide el arreglo en subarreglos más pequeños para posteriormente fusionarlos de forma ordenada.

Ordenación por montículo
Método de ordenamiento basado en una estructura de datos tipo Heap (montículo) que permite organizar los elementos de forma eficiente.

Método de Búsqueda
Búsqueda Binaria
Permite localizar un peso específico dentro del arreglo ordenado reduciendo progresivamente el espacio de búsqueda.

Observaciones
El programa utiliza una llamada de bandera variable ordenadopara controlar si el arreglo se encuentra organizado antes de permitir la ejecución de la búsqueda binaria.

Asignatura
Estructura de Datos

Unidad
Unidad 5: Métodos de Organización Eficientes y Búsqueda Binaria.