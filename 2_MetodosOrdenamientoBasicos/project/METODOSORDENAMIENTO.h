#ifndef METODOSORDENAMIENTO_H
#define METODOSORDENAMIENTO_H

#include <stdio.h>
#include <stdlib.h>

/* Ordenamientos avanzados*/
void shellSort(int arr[], int tamArr);
void quickSort(int arr[], int n);
void radixSort(int arr[], int n);
void heapSort(int arr[], int n);
void mergeSort(int arr[], int n);

/* Metodos para manejar arreglos */
void imprimirArrInt(int *arr, int n);
void llenarArrInt(int *arr, int n);
void liberarArrInt(int **arr);
void CrearArrInt(int **arr, int n);

#endif