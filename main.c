/*
=========================================
TALLER UNIDAD 5
METODOS DE ORDENAMIENTO Y BUSQUEDA BINARIA

Autor:
Mery Daniela Angulo Sinisterra
=========================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTENEDORES 30

int pesos[MAX_CONTENEDORES];
int cantidad = 0;
int ordenado = 0;

/* FUNCIONES */
void registrarPesos();
void generarAleatorios();
void mostrarContenedores();

void bubbleSort();
void selectionSort();
void insertionSort();

int busquedaBinaria(int valor);

int main()
{
    int opcion;
    int buscar;

    srand(time(NULL));

    do
    {
        printf("\n====================================\n");
        printf(" SISTEMA DE ORGANIZACION DE CONTENEDORES\n");
        printf(" MUELLE DE CARGA\n");
        printf("====================================\n");

        printf("1. Registrar peso de contenedores manualmente\n");
        printf("2. Generar pesos aleatorios\n");
        printf("3. Mostrar contenedores registrados\n");
        printf("4. Ordenar contenedores Metodo 1 (Bubble)\n");
        printf("5. Ordenar contenedores Metodo 2 (Selection)\n");
        printf("6. Ordenar contenedores Metodo 3 (Insertion)\n");
        printf("7. Buscar contenedor\n");
        printf("8. Salir\n");

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                registrarPesos();
                break;

            case 2:
                generarAleatorios();
                break;

            case 3:
                mostrarContenedores();
                break;

            case 4:
                bubbleSort();
                ordenado = 1;
                printf("\nArreglo ordenado con Bubble Sort.\n");
                break;

            case 5:
                selectionSort();
                ordenado = 1;
                printf("\nArreglo ordenado con Selection Sort.\n");
                break;

            case 6:
                insertionSort();
                ordenado = 1;
                printf("\nArreglo ordenado con Insertion Sort.\n");
                break;

            case 7:

                if(cantidad == 0)
                {
                    printf("\nNo hay datos registrados.\n");
                    break;
                }

                if(!ordenado)
                {
                    printf("\nDebe ordenar primero el arreglo.\n");
                    break;
                }

                printf("Ingrese peso a buscar: ");
                scanf("%d", &buscar);

                int posicion;
                posicion = busquedaBinaria(buscar);

                if(posicion != -1)
                {
                    printf("\nContenedor encontrado en posicion %d\n",
                           posicion + 1);
                }
                else
                {
                    printf("\nContenedor no encontrado.\n");
                }

                break;

            case 8:
                printf("\nPrograma finalizado.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 8);

    return 0;
}

/* REGISTRO MANUAL */
void registrarPesos()
{
    int i;

    printf("Cantidad de contenedores (max 30): ");
    scanf("%d", &cantidad);

    if(cantidad < 1 || cantidad > MAX_CONTENEDORES)
    {
        printf("Cantidad invalida.\n");
        cantidad = 0;
        return;
    }

    for(i = 0; i < cantidad; i++)
    {
        printf("Peso contenedor %d: ", i + 1);
        scanf("%d", &pesos[i]);
    }

    ordenado = 0;
}

/* GENERAR ALEATORIOS */
void generarAleatorios()
{
    int i;

    printf("Cantidad de contenedores (max 30): ");
    scanf("%d", &cantidad);

    if(cantidad < 1 || cantidad > MAX_CONTENEDORES)
    {
        printf("Cantidad invalida.\n");
        cantidad = 0;
        return;
    }

    for(i = 0; i < cantidad; i++)
    {
        pesos[i] = rand() % 30001;
    }

    ordenado = 0;

    printf("\nPesos generados correctamente.\n");
}

/* MOSTRAR */
void mostrarContenedores()
{
    int i;

    if(cantidad == 0)
    {
        printf("\nNo hay contenedores registrados.\n");
        return;
    }

    printf("\nLISTA DE CONTENEDORES\n");

    for(i = 0; i < cantidad; i++)
    {
        printf("[%d] %d kg\n", i + 1, pesos[i]);
    }
}

/* BUBBLE SORT */
void bubbleSort()
{
    int i, j, aux;

    for(i = 0; i < cantidad - 1; i++)
    {
        for(j = 0; j < cantidad - i - 1; j++)
        {
            if(pesos[j] > pesos[j + 1])
            {
                aux = pesos[j];
                pesos[j] = pesos[j + 1];
                pesos[j + 1] = aux;
            }
        }
    }
}

/* SELECTION SORT */
void selectionSort()
{
    int i, j, min, aux;

    for(i = 0; i < cantidad - 1; i++)
    {
        min = i;

        for(j = i + 1; j < cantidad; j++)
        {
            if(pesos[j] < pesos[min])
            {
                min = j;
            }
        }

        aux = pesos[i];
        pesos[i] = pesos[min];
        pesos[min] = aux;
    }
}

/* INSERTION SORT */
void insertionSort()
{
    int i, j, clave;

    for(i = 1; i < cantidad; i++)
    {
        clave = pesos[i];
        j = i - 1;

        while(j >= 0 && pesos[j] > clave)
        {
            pesos[j + 1] = pesos[j];
            j--;
        }

        pesos[j + 1] = clave;
    }
}

/* BUSQUEDA BINARIA */
int busquedaBinaria(int valor)
{
    int inicio = 0;
    int fin = cantidad - 1;
    int medio;

    while(inicio <= fin)
    {
        medio = (inicio + fin) / 2;

        if(pesos[medio] == valor)
        {
            return medio;
        }

        if(valor > pesos[medio])
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }

    return -1;
}