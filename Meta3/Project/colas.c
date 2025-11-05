/****************************************************
 * File: colas
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Nov/05/2024
 * Comments:
 ***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "colas.h"

NODO *crearNodo(int *dato)
{
    NODO *nodo = (NODO *)malloc(sizeof(NODO));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    nodo->anterior = NULL;
    return nodo;
}

void eliminarNodo(NODO *nodo)
{
    nodo->dato = NULL;
    nodo->anterior = NULL;
    nodo->siguiente = NULL;
    free(nodo);
}

COLA *crearCola(void)
{
    COLA *cola = (COLA *)malloc(sizeof(cola)); /*  realloc ? */
    cola->inicio = cola->fin = NULL;
    cola->longitud = 0;
    return cola;
}

void vaciar(COLA *cola)
{
    while (cola->fin)
    {
        pop(cola);
    }
    free(cola);
}

void push(COLA *cola, int dato)
{
    NODO *nodo = crearNodo(&dato);
    if (!cola->inicio)
    {
        cola->inicio = nodo;
        cola->fin = nodo;
    }
    else
    {
        cola->fin->siguiente = nodo;
        cola->fin = nodo;
    }
}

void pop(COLA *cola)
{
    if (cola->inicio)
    {
        NODO *eliminar = cola->inicio;
        cola->inicio = cola->inicio->siguiente;
        eliminarNodo(eliminar);
        if (!cola->inicio)
        {
            cola->fin = NULL;
        }
        cola->longitud--;
    }
}

int *top(COLA *cola)
{
    if (cola->fin)
    {
        return cola->fin->dato;
    }
    else
    {
        return NULL;
    }
}

int *frond(COLA *cola)
{
    if (cola->inicio)
    {
        return cola->inicio->dato;
    }
    else
    {
        return NULL;
    }
}

int llena(COLA *cola)
{
    return cola->longitud != 0;
}

int size(COLA *cola)
{
    return cola->longitud;
}