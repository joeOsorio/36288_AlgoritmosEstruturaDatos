/****************************************************
    * File: main
    * Author: Joshua Osorio
    * Materia: Algoritmos y Estructura de Datos (551)
    * Date: Sep/17/2025
    * Comments:
    * Métodos de ordenamiento avanzados
        - Shell Sort
        - Quick Sort
        - Radix Sort
    * Compilación:  gcc main.c -o main.exe -fdiagnostics-color=always -g -std=c99 -Wall -Wextra -Werror -Wpedantic
***************************************************/

#include <stdio.h>
#include <stdlib.h>


/* Métosdes de ordenamiento */
void shellSort(int arr[], int tamArr);
void quickSort(int arr[], int n);
void radixSort(int arr[], int n);

/* funciones de arreglos */
void imprimirArrInt(int *arr, int n);
void llenarArrInt(int *arr, int n);
void liberarArrInt(int **arr);
void CrearArrInt(int **arr, int n);

/* Pruebas */
int main2(void);

int main(void)
{
    int *arr = NULL, n;

    /* Shell sort */
    printf("\n  Heap Sort");
    printf("\n   Ingresa el tamaño del arrego:");
    scanf("%d", &n);
    CrearArrInt(&arr, n);
    printf("\n   Llena el arreglo: \n");
    llenarArrInt(arr, n);
    printf("\n   Arreglo original: \n");
    imprimirArrInt(arr, n);
    shellSort(arr, n);
    printf("\n   Arreglo ordenado: \n");
    imprimirArrInt(arr, n);
    scanf("%d", &n);
    liberarArrInt(&arr);
    return 0;
}

int main2(void)
{
    int opcion, *arr = NULL, n;
    printf("Practica 1: Métodos de ordenamiento y búsqueda\n");
    do
    {
        printf("\n   1. Shell sort");
        printf("\n   2. Quick sort");
        printf("\n   3. Radix sort");
        printf("\n   4. Salir.");

        /* Filtramos la opción elegida por el usuario sólo puede ser 1 al 4*/
        do
        {
            printf("\n   Introduzca opci%cn (1-4): ", 162);
            scanf("%d", &opcion);

        } while (opcion < 1 || opcion > 5);

        switch (opcion)
        {
        case 1: /* Shell sort */
            printf("\n  Shell Sort");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            printf("\n   Arreglo original: \n");
            imprimirArrInt(arr, n);
            shellSort(arr, n);
            printf("\n   Arreglo ordenado: \n");
            imprimirArrInt(arr, n);
            liberarArrInt(&arr);
            break;
        case 2:
            printf("\n  Quick Sort");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            printf("\n   Arreglo original: \n");
            imprimirArrInt(arr, n);
            /* ordInsercion(arr, n); */ /* cambiar por el adecuado */
            printf("\n   Arreglo ordenado: \n");
            imprimirArrInt(arr, n);
            liberarArrInt(&arr);
            break;
        case 3:
            printf("\n  Radix Sort");
            printf("\n   Ingresa el tamaño del arrego:");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            printf("\n   Arreglo original: \n");
            imprimirArrInt(arr, n);
            /* ordBurbuja(arr, n); */ /* Cabiar por el correcto*/
            printf("\n   Arreglo ordenado: \n");
            imprimirArrInt(arr, n);
            liberarArrInt(&arr);
            break;
        case 4:
            printf("\n  Saliendo...\n");
            break;
        }

    } while (opcion != 4);

    return 0;
}

/* metodos de ordenamiento avanzados */

void shellSort(int arr[], int tamArr)
{
    int salto, cambios, i, temp;
    for (salto = tamArr / 2; salto != 0; salto /= 2)
    {
        do
        {
            cambios = 0;
            for (i = salto; i < tamArr; i++)
            {
                if (arr[i - salto] > arr[i])
                {
                    temp = arr[i];
                    arr[i] = arr[i - salto];
                    arr[i - salto] = temp;
                    cambios = 1;
                }
            }
        } while (cambios != 0);
    }
}

void mergeSort(int arr[], int n)
{
    int i, j, k, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void quickSort(int arr[], int n)
{
    int pivot, L[n * 2], R[n * 2], i, j, k, idx, aux, r;

    idx = 0;      // Contador de segmentos totales agregados a la lista
    i = 0;        // Indica el segmento de la lista que s esta revisando
    L[i] = 0;     // Indice izquierdo de mi segmento i
    R[i] = n - 1; // Indice derecho de mi segmento i

    do
    {
        pivot = vect[R[i]];
        j = L[i];
        r = R[i];
        do
        {
            if (vect[j] > pivot)
            {
                aux = vect[j];
                for (k = j; k < R[i]; k++)
                {
                    vect[k] = vect[k + 1];
                }
                vect[k] = aux;
                R[i] = k - 1; // Actualizar posicion del pivote
            }
            else
            {
                j++;
            }
        } while (j <= R[i]);

        // Agregar segmento izquierdo
        if (((R[i] - 1) - L[i]) > 0)
        { // Si hay mas de un elemento
            idx++;
            L[idx] = L[i];
            R[idx] = R[i] - 1;
        }

        // Agregar segmento derecho
        if (r - (R[i] + 1) > 0)
        { // Si hay mas de un elemento
            idx++;
            L[idx] = R[i] + 1;
            R[idx] = r;
        }
        i++;
    } while (i <= idx);
}

void heapSort(int arr[], int n)
{
    /* Heapsort implementation can be added here */
}

void radixSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* funciones de arreglos */

void CrearArrInt(int **arr, int n)
{
    *arr = (int *)malloc(n * sizeof(int));
}

void liberarArrInt(int **arr)
{
    free(*arr);
    *arr = NULL;
}

void llenarArrInt(int *arr, int n)
{
    int i, m;
    printf("Ingrese los %d numeros enteros del arreglo\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &m);
        arr[i] = m;
    }
}

void imprimirArrInt(int *arr, int n)
{
    int i;
    printf("\nArreglo de numeros enteros: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

