#ifndef ARBOLES_H
#define ARBOLES_H

#include <stdio.h>  /* funciones de entrada/salida `printf` y `scanf`.*/
#include <stdlib.h> /* funciones como `system` y `exit` */
#include <conio.h>  /* funciones como `_getch` no estandar */

/* otras */
#include <windows.h> /* funciones específicas de Windows como `SetConsoleOutputCP` y `COORD` */

typedef struct NODO
{
    int dato;
    struct NODO *padre;
    struct NODO *izq;
    struct NODO *der;

} NODO;

typedef struct ARBOL
{
    NODO *raiz;
    int tamano;
} ARBOL;

NODO *crearNodo(int dato);
void eliminarNodo(NODO *nodo);

ARBOL *crearArbol(void);

void arbolVacio(ARBOL *arbol);

void insertarEnArbol(int dato, ARBOL *arbol);
void insertar(int dato, NODO *raiz);
int buscarInArbol(int dato, ARBOL *arbol);
int buscar(int dato, NODO *raiz);
void eliminarEnArbol(int dato, ARBOL *arbol);
void recorrerPreOrden(void);
void recorrerIntOrden(void);
void recorrerPosOrden(void);

#endif