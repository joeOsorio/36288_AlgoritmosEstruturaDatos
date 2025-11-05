/****************************************************
 * File: Funiones para la creacion y manejo de arboles
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Nov/05/2025
 * Comments:

 ***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arboles.h"

NODO *crearNodo(int numero)
{
    NODO *nodo = (NODO *)malloc(sizeof(NODO));
    nodo->numero = numero;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar(NODO **raiz, int numero)
{
    if (*raiz == NULL)
    {
        *raiz = crearNodo(numero);
    }
    else if (numero < (*raiz)->numero)
    {
        insertar(&(*raiz)->izquierda, numero);
    }
    else
    {
        insertar(&(*raiz)->derecha, numero);
    }
}

void eliminarNodo(NODO *nodo)
{
    nodo->c = NULL;
    nodo->siguiente = NULL;
    free(nodo);
}