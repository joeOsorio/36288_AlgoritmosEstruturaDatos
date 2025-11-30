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
        - Heap Sort
        - Merge Sort
    * Compilación:  gcc main.c -o main.exe -fdiagnostics-color=always -g -std=c99 -Wall -Wextra -Werror -Wpedantic
***************************************************/
#include "METODOSORDENAMIENTO.h"

int main(void)
{
    int opcion, *arr = NULL, n;

    printf("Practica: Métodos de ordenamiento avanzados\n");

    do
    {
        printf("\n   1. Shell sort");
        printf("\n   2. Quick sort");
        printf("\n   3. Radix sort");
        printf("\n   4. Heap sort");
        printf("\n   5. Merge sort");
        printf("\n   6. Salir");

        do
        {
            printf("\n   Introduzca opcion (1-6): ");
            scanf("%d", &opcion);
        } while (opcion < 1 || opcion > 6);

        if (opcion != 6)
        {
            printf("\n   Ingresa el tamaño del arreglo: ");
            scanf("%d", &n);
            CrearArrInt(&arr, n);
            printf("\n   Llena el arreglo: \n");
            llenarArrInt(arr, n);
            printf("\n   Arreglo original: \n");
            imprimirArrInt(arr, n);
        }

        switch (opcion)
        {
        case 1:
            shellSort(arr, n);
            break;
        case 2:
            quickSort(arr, n);
            break;
        case 3:
            radixSort(arr, n);
            break;
        case 4:
            heapSort(arr, n);
            break;
        case 5:
            mergeSort(arr, n);
            break;
        case 6:
            printf("\n  Saliendo...\n");
            break;
        }

        if (opcion != 6)
        {
            printf("\n   Arreglo ordenado: \n");
            imprimirArrInt(arr, n);
            liberarArrInt(&arr);
        }

    } while (opcion != 6);

    return 0;
}
