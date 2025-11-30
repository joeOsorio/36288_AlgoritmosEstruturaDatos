/****************************************************
 * File: pila
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Nov/23/2025
 * Comments:

 ***************************************************/

/**
 * @file pila.c
 * @brief Implementación de funciones para manejo de pilas
 */

#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

int pila_vacia(nodo_pila *tope)
{
    return (tope == NULL);
}

nodo_pila *pila_crear_nodo(int n)
{
    nodo_pila *nuevo_nodo = (nodo_pila *)malloc(sizeof(nodo_pila));
    if (nuevo_nodo == NULL)
    {
        fprintf(stderr, "Error: No se pudo asignar memoria para nuevo nodo\n");
        return NULL;
    }
    nuevo_nodo->dato = n;
    nuevo_nodo->ant = NULL;
    return nuevo_nodo;
}

nodo_pila *pila_push(nodo_pila *tope, int n)
{
    nodo_pila *nuevo_nodo = pila_crear_nodo(n);
    if (nuevo_nodo == NULL)
    {
        return tope; /* Retorna la pila original si falla la creación */
    }

    nuevo_nodo->ant = tope;
    return nuevo_nodo;
}

nodo_pila *pila_pop(nodo_pila *tope)
{
    nodo_pila *aux;

    if (pila_vacia(tope))
    {
        fprintf(stderr, "Error: No se puede hacer pop de pila vacia\n");
        return NULL;
    }

    aux = tope;
    tope = tope->ant;

    free(aux);
    return tope;
}

void pila_mostrar(nodo_pila *tope)
{
    nodo_pila *actual = tope;
    if (pila_vacia(tope))
    {
        printf("La pila esta vacia\n");
        return;
    }

    printf("Elementos de la pila (tope -> base): ");
    while (actual != NULL)
    {
        printf("%d", actual->dato);
        if (actual->ant != NULL)
        {
            printf(" -> ");
        }
        actual = actual->ant;
    }
    printf("\n");
}

/**
 * @brief Elimina todos los elementos de la pila
 * @param tope Puntero al tope de la pila
 * @return NULL siempre, ya que la pila queda vacía
 */
nodo_pila *pila_vaciar(nodo_pila *tope)
{
    while (!pila_vacia(tope))
    {
        tope = pila_pop(tope);
    }
    return NULL;
}

/**
 * @brief Calcula el número de elementos en la pila
 * @param tope Puntero al tope de la pila
 * @return Cantidad de elementos en la pila
 */
int pila_size(nodo_pila *tope)
{
    int contador = 0;
    nodo_pila *actual = tope;

    while (actual != NULL)
    {
        contador++;
        actual = actual->ant;
    }
    return contador;
}