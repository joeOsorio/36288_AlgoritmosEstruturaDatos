/****************************************************
 * File: Arboles
 * Author: Joshua Osorio
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Nov/12/2025
 * Comments:
 ***************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ARBOLES.h"

NODO *crearNodo(int dato)
{
    NODO *nodo = (NODO *)malloc(sizeof(NODO));
    nodo->dato = dato;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

void eliminarNodo(NODO *nodo)
{
    nodo->dato = 0;
    nodo->izq = NULL;
    nodo->der = NULL;
    free(nodo);
}

ARBOL *crearArbol(void)
{
    ARBOL *arbol = (ARBOL *)malloc(sizeof(ARBOL));
    arbol->raiz = NULL;
    arbol->tamano = 0;
    return arbol;
}

void insertar(int dato, NODO *raiz)
{
    if (raiz == NULL)
    {
        raiz = crearNodo(dato);
    }
    else if (dato < raiz->dato)
    {
        if (raiz->izq == NULL)
            raiz->izq = crearNodo(dato);
        else
            insertar(dato, raiz->izq);
    }
    else
    {
        if (raiz->der == NULL)
            raiz->der = crearNodo(dato);
        else
            insertar(dato, raiz->der);
    }
}

void eliminar(void)
{
    printf("in porsess");
}
void buscar(void)
{
    printf("in porsess");
}
void recorrerPreOrden(void)
{
    printf("in porsess");
}
void recorrerIntOrden(void)
{
    printf("in porsess");
}
void recorrerPosOrden(void)
{
    printf("in porsess");
}