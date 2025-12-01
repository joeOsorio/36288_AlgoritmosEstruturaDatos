/**
 * @file colas.c
 * @brief Implementación de funciones para manejo de colas
 * @author J. Osorio, Y. Prado y A. Fabara
 * @date Nov/2025
 */

#include "colas.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 * COLA NORMAL O SIMPLE
 ******************************************************************************/

/**
 * @brief Crea una nueva cola vacía
 * @return Puntero a la cola creada
 */

cola *cola_crear(void)
{
    cola *nueva_cola;

    nueva_cola = (cola *)malloc(sizeof(cola));
    if (nueva_cola == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la cola\n");
        return NULL;
    }
    nueva_cola->frente = NULL;
    nueva_cola->final = NULL;
    return nueva_cola;
}

/**
 * @brief Verifica si la cola está vacía
 * @param c Puntero a la cola
 * @return 1 si está vacía, 0 si no
 */
int cola_vacia(cola *c)
{
    return (c == NULL || c->frente == NULL);
}

/**
 * @brief Verifica si la cola está llena (solo por memoria)
 * @return 1 si no hay memoria, 0 si hay memoria disponible
 */
int cola_llena(void)
{
    nodoCola *test;

    test = (nodoCola *)malloc(sizeof(nodoCola));
    if (test == NULL)
    {
        return 1;
    }
    free(test);
    return 0;
}

/**
 * @brief Inserta un elemento al final de la cola
 * @param c Puntero a la cola
 * @param n Valor a insertar
 */

void cola_insertar(cola *c, int n)
{
    nodoCola *nuevo_nodo;

    if (c == NULL)
    {
        fprintf(stderr, "Error: Cola no inicializada\n");
        return;
    }

    if (cola_llena())
    {
        fprintf(stderr, "Error: No hay memoria disponible\n");
        return;
    }

    nuevo_nodo = (nodoCola *)malloc(sizeof(nodoCola));
    if (nuevo_nodo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear nodo\n");
        return;
    }

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if (cola_vacia(c))
    {
        c->frente = nuevo_nodo;
        c->final = nuevo_nodo;
    }
    else
    {
        c->final->siguiente = nuevo_nodo;
        c->final = nuevo_nodo;
    }
}

/**
 * @brief Remueve el primer elemento de la cola
 * @param c Puntero a la cola
 * @return Valor removido, o -1 si hay error
 */
int cola_remover(cola *c)
{
    nodoCola *aux;
    int valor;

    if (cola_vacia(c))
    {
        fprintf(stderr, "Error: No se puede remover de cola vacia\n");
        return -1;
    }

    aux = c->frente;
    valor = aux->dato;

    c->frente = c->frente->siguiente;

    /* Si la cola queda vacía, actualizar final también */
    if (c->frente == NULL)
    {
        c->final = NULL;
    }

    free(aux);
    return valor;
}

/**
 * @brief Muestra todos los elementos de la cola
 * @param c Puntero a la cola
 */
void cola_mostrar(cola *c)
{
    nodoCola *actual;

    if (cola_vacia(c))
    {
        printf("La cola esta vacia\n");
        return;
    }

    actual = c->frente;
    printf("Elementos de la cola (frente -> final): ");
    while (actual != NULL)
    {
        printf("%d", actual->dato);
        if (actual->siguiente != NULL)
        {
            printf(" -> ");
        }
        actual = actual->siguiente;
    }
    printf("\n");
}

/**
 * @brief Calcula el número de elementos en la cola
 * @param c Puntero a la cola
 * @return Cantidad de elementos
 */
int cola_size(cola *c)
{
    nodoCola *actual;
    int contador;

    if (cola_vacia(c))
    {
        return 0;
    }

    contador = 0;
    actual = c->frente;
    while (actual != NULL)
    {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

/**
 * @brief Vacía todos los elementos de la cola
 * @param c Puntero a la cola
 */
void cola_vaciar(cola *c)
{
    if (c == NULL)
        return;

    while (!cola_vacia(c))
    {
        cola_remover(c);
    }
}

/**
 * @brief Destruye la cola y libera toda la memoria
 * @param c Puntero a la cola
 */
void cola_destruir(cola *c)
{
    if (c == NULL)
        return;

    cola_vaciar(c);
    free(c);
}

/*******************************************************************************
 * COLA DOBLEMENTE ENLAZADA
 ******************************************************************************/

/**
 * @brief Crea una nueva cola doble vacía
 * @return Puntero a la cola doble creada
 */
cola_doble *cola_doble_crear(void)
{
    cola_doble *nueva_cola;

    nueva_cola = (cola_doble *)malloc(sizeof(cola_doble));
    if (nueva_cola == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear la cola doble\n");
        return NULL;
    }
    nueva_cola->frente = NULL;
    nueva_cola->final = NULL;
    return nueva_cola;
}

/**
 * @brief Verifica si la cola doble está vacía
 * @param cd Puntero a la cola doble
 * @return 1 si está vacía, 0 si no
 */
int cola_doble_vacia(cola_doble *cd)
{
    return (cd == NULL || cd->frente == NULL);
}

/**
 * @brief Inserta un elemento al final de la cola doble
 * @param cd Puntero a la cola doble
 * @param n Valor a insertar
 */
void cola_doble_insertar(cola_doble *cd, int n)
{
    nodoColaDoble *nuevo_nodo;

    if (cd == NULL)
    {
        fprintf(stderr, "Error: Cola doble no inicializada\n");
        return;
    }

    nuevo_nodo = (nodoColaDoble *)malloc(sizeof(nodoColaDoble));
    if (nuevo_nodo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear nodo doble\n");
        return;
    }

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = cd->final;

    if (cola_doble_vacia(cd))
    {
        cd->frente = nuevo_nodo;
        cd->final = nuevo_nodo;
    }
    else
    {
        cd->final->siguiente = nuevo_nodo;
        cd->final = nuevo_nodo;
    }
}

/**
 * @brief Remueve el primer elemento de la cola doble
 * @param cd Puntero a la cola doble
 * @return Valor removido, o -1 si hay error
 */
int cola_doble_remover(cola_doble *cd)
{
    nodoColaDoble *aux;
    int valor;

    if (cola_doble_vacia(cd))
    {
        fprintf(stderr, "Error: No se puede remover de cola doble vacia\n");
        return -1;
    }

    aux = cd->frente;
    valor = aux->dato;

    cd->frente = cd->frente->siguiente;

    if (cd->frente != NULL)
    {
        cd->frente->anterior = NULL;
    }
    else
    {
        cd->final = NULL; /* Cola queda vacía */
    }

    free(aux);
    return valor;
}

/**
 * @brief Muestra todos los elementos de la cola doble
 * @param cd Puntero a la cola doble
 */
void cola_doble_mostrar(cola_doble *cd)
{
    nodoColaDoble *actual;

    if (cola_doble_vacia(cd))
    {
        printf("La cola doble esta vacia\n");
        return;
    }

    actual = cd->frente;
    printf("Elementos de la cola doble (frente -> final): ");
    while (actual != NULL)
    {
        printf("%d", actual->dato);
        if (actual->siguiente != NULL)
        {
            printf(" <-> ");
        }
        actual = actual->siguiente;
    }
    printf("\n");
}

/**
 * @brief Vacía todos los elementos de la cola doble
 * @param cd Puntero a la cola doble
 */
void cola_doble_vaciar(cola_doble *cd)
{
    if (cd == NULL)
        return;

    while (!cola_doble_vacia(cd))
    {
        cola_doble_remover(cd);
    }
}

/**
 * @brief Destruye la cola doble y libera toda la memoria
 * @param cd Puntero a la cola doble
 */
void cola_doble_destruir(cola_doble *cd)
{
    if (cd == NULL)
        return;

    cola_doble_vaciar(cd);
    free(cd);
}