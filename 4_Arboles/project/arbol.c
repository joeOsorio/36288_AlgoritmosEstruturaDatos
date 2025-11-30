/**
 * @file arbol.c
 * @brief Implementacion de funciones para manejo de arboles binarios
 * @author J. Osorio, Y. Prado and A. Fabara
 * @date Nov/2025
 */

#include "arbol.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Crea un nuevo nodo para el arbol
 * @param Dato a almacenar en el nodo
 * @return Puntero al nuevo nodo creado
 */

nodoArbol *arbol_crear_nodo(int dato)
{
    nodoArbol *nuevo_nodo;

    nuevo_nodo = (nodoArbol *)malloc(sizeof(nodoArbol));
    if (nuevo_nodo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear nodo del arbol\n");
        return NULL;
    }

    nuevo_nodo->dato = dato;
    nuevo_nodo->izquierdo = NULL;
    nuevo_nodo->derecho = NULL;

    return nuevo_nodo;
}

/**
 * @brief Verifica si el arbol esta vacio
 * @param raiz Raiz del arbol
 * @return 1 si esta vacio, 0 si no
 */
int arbol_vacio(nodoArbol *raiz)
{
    return (raiz == NULL);
}

/**
 * @brief Verifica si hay memoria disponible para nuevos nodos
 * @return 1 si no hay memoria, 0 si hay memoria disponible
 */
int arbol_lleno(void)
{
    nodoArbol *test;

    test = (nodoArbol *)malloc(sizeof(nodoArbol));
    if (test == NULL)
    {
        return 1;
    }
    free(test);
    return 0;
}

/**
 * @brief Inserta un nuevo dato en el arbol binario
 * @param raiz Raiz del arbol
 * @param dato dato a insertar
 * @return Nueva raiz del arbol
 */
nodoArbol *arbol_insertar(nodoArbol *raiz, int dato)
{
    if (arbol_lleno())
    {
        fprintf(stderr, "Error: No hay memoria disponible\n");
        return raiz;
    }

    if (raiz == NULL)
    {
        return arbol_crear_nodo(dato);
    }

    if (dato < raiz->dato)
    {
        raiz->izquierdo = arbol_insertar(raiz->izquierdo, dato);
    }
    else if (dato > raiz->dato)
    {
        raiz->derecho = arbol_insertar(raiz->derecho, dato);
    }
    /* Si el dato es igual, no se inserta (evita duplicados) */

    return raiz;
}

/**
 * @brief Encuentra el nodo con dato minimo en el arbol
 * @param raiz Raiz del arbol
 * @return Nodo con dato minimo
 */
nodoArbol *arbol_encontrar_minimo(nodoArbol *raiz)
{
    nodoArbol *actual;

    if (raiz == NULL)
    {
        return NULL;
    }

    actual = raiz;
    while (actual->izquierdo != NULL)
    {
        actual = actual->izquierdo;
    }

    return actual;
}

/**
 * @brief Encuentra el nodo con dato maximo en el arbol
 * @param raiz Raiz del arbol
 * @return Nodo con dato maximo
 */
nodoArbol *arbol_encontrar_maximo(nodoArbol *raiz)
{
    nodoArbol *actual;

    if (raiz == NULL)
    {
        return NULL;
    }

    actual = raiz;
    while (actual->derecho != NULL)
    {
        actual = actual->derecho;
    }

    return actual;
}

/**
 * @brief Elimina un dato del arbol binario
 * @param raiz Raiz del arbol
 * @param dato dato a eliminar
 * @return Nueva raiz del arbol
 */
nodoArbol *arbol_eliminar(nodoArbol *raiz, int dato)
{
    nodoArbol *temp;
    nodoArbol *sucesor;

    if (raiz == NULL)
    {
        fprintf(stderr, "Error: dato %d no encontrado en el arbol\n", dato);
        return NULL;
    }

    if (dato < raiz->dato)
    {
        raiz->izquierdo = arbol_eliminar(raiz->izquierdo, dato);
    }
    else if (dato > raiz->dato)
    {
        raiz->derecho = arbol_eliminar(raiz->derecho, dato);
    }
    else
    {
        /* Caso 1: Nodo hoja o con un solo hijo */
        if (raiz->izquierdo == NULL)
        {
            temp = raiz->derecho;
            free(raiz);
            return temp;
        }
        else if (raiz->derecho == NULL)
        {
            temp = raiz->izquierdo;
            free(raiz);
            return temp;
        }

        /* Caso 2: Nodo con dos hijos - usar sucesor (minimo del subarbol derecho) */
        sucesor = arbol_encontrar_minimo(raiz->derecho);
        raiz->dato = sucesor->dato;
        raiz->derecho = arbol_eliminar(raiz->derecho, sucesor->dato);
    }

    return raiz;
}

/**
 * @brief Recorrido preorden: Raiz - Izquierdo - Derecho
 * @param raiz Raiz del arbol
 */
void arbol_recorrer_preorden(nodoArbol *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->dato);
        arbol_recorrer_preorden(raiz->izquierdo);
        arbol_recorrer_preorden(raiz->derecho);
    }
}

/**
 * @brief Recorrido inorden: Izquierdo - Raiz - Derecho
 * @param raiz Raiz del arbol
 */
void arbol_recorrer_inorden(nodoArbol *raiz)
{
    if (raiz != NULL)
    {
        arbol_recorrer_inorden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        arbol_recorrer_inorden(raiz->derecho);
    }
}

/**
 * @brief Recorrido postorden: Izquierdo - Derecho - Raiz
 * @param raiz Raiz del arbol
 */
void arbol_recorrer_postorden(nodoArbol *raiz)
{
    if (raiz != NULL)
    {
        arbol_recorrer_postorden(raiz->izquierdo);
        arbol_recorrer_postorden(raiz->derecho);
        printf("%d ", raiz->dato);
    }
}

/**
 * @brief Calcula el numero de nodos en el arbol
 * @param raiz Raiz del arbol
 * @return Cantidad de nodos
 */
int arbol_tamano(nodoArbol *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return 1 + arbol_tamano(raiz->izquierdo) + arbol_tamano(raiz->derecho);
}

/**
 * @brief Muestra el arbol de forma jerarquica (simplificada)
 * @param raiz Raiz del arbol
 */
void arbol_mostrar(nodoArbol *raiz)
{
    if (arbol_vacio(raiz))
    {
        printf("El arbol esta vacio\n");
        return;
    }

    printf("Recorrido inorden del arbol: ");
    arbol_recorrer_inorden(raiz);
    printf("\n");
}

/**
 * @brief Elimina todos los nodos del arbol
 * @param raiz Raiz del arbol
 * @return NULL (arbol vacio)
 */
nodoArbol *arbol_vaciar(nodoArbol *raiz)
{
    if (raiz != NULL)
    {
        arbol_vaciar(raiz->izquierdo);
        arbol_vaciar(raiz->derecho);
        free(raiz);
    }
    return NULL;
}