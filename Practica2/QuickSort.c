/****************************************************
 * File: julian
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Oct/09/2025
 * Comments:

***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quickSort(int arr[], int n);

int main(void)
{
    int arr[7] = {12, 9, 3, 7, 14, 11, 8}, n;
    printf("Arreglo: ");
    for (n = 0; n < 7; n++)
    {
        printf("%d \t", arr[n]);
    }
    printf("\n  Quick Sort\n");
    quickSort(arr, 7);

    printf("\n");
    return 0;
}

void quickSort(int arr[], int n)
{
    int inicio[n], final[n], i, j, izq, der, aux, pivote, tope = 0;
    inicio[0] = 0;
    final[0] = n - 1;
    while (tope >= 0)
    {
        izq = inicio[tope];
        der = final[tope];
        tope--;
        if (izq < der)
        {
            pivote = arr[izq];
            i = izq;
            j = der;
            while (i < j)
            {
                while (arr[i] <= pivote && i < der)
                    i++;
                while (arr[j] > pivote)
                    j--;
                if (i < j)
                {
                    aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }
            arr[izq] = arr[j];
            arr[j] = pivote;
            tope++;
            inicio[tope] = izq;
            final[tope] = j - 1;
            tope++;
            inicio[tope] = j + 1;
            final[tope] = der;
        }
    }
    printf("Arreglo ordenado: ");
    for (n = 0; n < 7; n++)
    {
        printf("%d \t", arr[n]);
    }
}