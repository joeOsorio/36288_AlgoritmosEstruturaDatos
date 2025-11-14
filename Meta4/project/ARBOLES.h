#ifndef ARBOLES_H
#define ARBOLES_H

#include <stdio.h>  /* funciones de entrada/salida `printf` y `scanf`.*/
#include <stdlib.h> /* funciones como `system` y `exit` */
#include <conio.h>  /* funciones como `_getch()` no estandar */

/* otras */
#include <windows.h> /* funciones específicas de Windows como `SetConsoleOutputCP` y `COORD` */

typedef struct NODO
{
    int dato;
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

void insertar(int dato, NODO *raiz);
void eliminar(void);
void buscar(void);
void recorrerPreOrden(void);
void recorrerIntOrden(void);
void recorrerPosOrden(void);

#endif /* ARBOLES_H_INCLUDED */