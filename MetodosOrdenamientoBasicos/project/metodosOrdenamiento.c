/****************************************************
 * File: metodosOrdenamiento
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Sep/17/2025
 * Comments:

 ***************************************************/
/* *******************SHELL SORT******************* */
#include "METODOSORDENAMIENTO.h"

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
/* ******************* QUICK SORT ******************* */

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
}

/* ******************* Radix Sort ******************* */
int obtenerMaximo(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void contarSort(int arr[], int n, int exp)
{
    int salida[n];
    int i, contador[10] = {0};

    for (i = 0; i < n; i++)
        contador[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        contador[i] += contador[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        salida[contador[(arr[i] / exp) % 10] - 1] = arr[i];
        contador[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = salida[i];
}

void radixSort(int arr[], int n)
{
    int max = obtenerMaximo(arr, n);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
        contarSort(arr, n, exp);
}

/* ******************* Heap Sort ******************* */

void heapify(int arr[], int n, int i)
{
    int mayor = i;
    int izquierdo = 2 * i + 1;
    int derecho = 2 * i + 2;
    int temp;

    if (izquierdo < n && arr[izquierdo] > arr[mayor])
        mayor = izquierdo;

    if (derecho < n && arr[derecho] > arr[mayor])
        mayor = derecho;

    if (mayor != i)
    {
        temp = arr[i];
        arr[i] = arr[mayor];
        arr[mayor] = temp;
        heapify(arr, n, mayor);
    }
}

/* ******************* Merge Sort ******************* */
void heapSort(int arr[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void merge(int arr[], int izquierdo, int medio, int derecho)
{
    int i, j, k;
    int n1 = medio - izquierdo + 1;
    int n2 = derecho - medio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[izquierdo + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[medio + 1 + j];

    i = 0;
    j = 0;
    k = izquierdo;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n)
{
    int tamActual;
    int inicioIzquierdo;

    for (tamActual = 1; tamActual <= n - 1; tamActual = 2 * tamActual)
    {
        for (inicioIzquierdo = 0; inicioIzquierdo < n - 1; inicioIzquierdo += 2 * tamActual)
        {
            int medio = inicioIzquierdo + tamActual - 1;
            if (medio >= n - 1)
                medio = n - 1;

            int finDerecho = inicioIzquierdo + 2 * tamActual - 1;
            if (finDerecho >= n)
                finDerecho = n - 1;

            merge(arr, inicioIzquierdo, medio, finDerecho);
        }
    }
}