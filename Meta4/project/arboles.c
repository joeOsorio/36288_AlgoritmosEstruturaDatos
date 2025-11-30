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
    nodo->padre = NULL;
    nodo->izq = NULL;
    nodo->der = NULL;
    return nodo;
}

void eliminarNodo(NODO *nodo)
{
    nodo->dato = 0;
    nodo->padre = NULL;
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

void arbolVacio(ARBOL *arbol)
{
    return arbol->raiz == NULL;
}

void insertarEnArbol(int dato, ARBOL *arbol)
{
    insertar(dato, arbol->raiz);
}

void insertar(int dato, NODO *raiz)
{
    if (raiz->dato == NULL)
    {
        raiz->dato = dato;
    }
    else if (dato > raiz->dato)
    {
        if (raiz->izq == NULL)
        {
            NODO *hijoIzq = crearNodo(dato);
            raiz->izq = &hijoIzq;
            hijoIzq->padre = &raiz;
        }
        else
        {
            ins(dato, &raiz->izq);
        }
    }
    else if (raiz->dato < dato)
    {
        if (raiz->der == NULL)
        {
            NODO *hijoIzq = crearNodo(dato);
            raiz->der = &hijoIzq;
            hijoIzq->padre = &raiz;
        }
        else
        {
            ins(dato, &raiz->der);
        }
    }
}

void eliminarEnArbol(int dato, ARBOL *arbol)
{
    if (arbol->raiz == NULL)
    {
        printf("Arbol vacio, como tu corazón =( ");
    }
    else
    {
        eliminar(dato, arbol->raiz);
    }
}

void eliminar(int dato, NODO *raiz)
{
    if (raiz->dato == dato)
    {
        if (raiz->padre != NULL)
        {
            if(raiz->der == NULL & raiz == NULL){
                raiz->padre == NULL;
                eliminarNodo(raiz);
            } 
            else if (raiz->izq != NULL & raiz->der == NULL)
            {
                raiz->padre = raiz->izq;
                eliminarNodo(raiz);
            }
            else if (raiz->izq == NULL & raiz->der != NULL)
            {
                raiz->padre = raiz->der;
                eliminarNodo(raiz);
            }else
            {
                if (raiz->dato < raiz->padre->dato)
                {
                    /* code */
                }
                
            }  
        }
        else
        {
            eliminarNodo(raiz);
        }
    }
    else if (dato < raiz->dato)
    {
        if (raiz->izq == NULL)
            return 0;

        eliminar(dato, raiz->der);
    }
    else if (raiz->dato < dato)
    {
        if (raiz->der == NULL)
            return 0;
        eliminar(dato, raiz->der);
    }
}

int buscarInArbol(int dato, ARBOL *arbol)
{
    if (arbol->raiz->dato == NULL)
        return 0;
    else
    {
        return buscar(dato, arbol->raiz->dato);
    }
}

int buscar(int dato, NODO *raiz)
{
    if (raiz->dato == dato)
        return 1;
    else if (dato < raiz->dato)
    {
        if (raiz->izq == NULL)
            return 0;

        buscar(dato, raiz->der);
    }
    else if (raiz->dato < dato)
    {
        if (raiz->der == NULL)
            return 0;
        buscar(dato, raiz->der);
    }
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