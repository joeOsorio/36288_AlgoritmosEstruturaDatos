/****************************************************
 * File: apuntador2
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Oct/16/2025
 * Comments:

 ***************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo *ant;
} nodo;

int vacia(nodo *tope)
{
    return (!tope) ? 1 : 0;
}

nodo *crearNodo(int n)
{
    nodo *nuevoNodo;
    nuevoNodo = (nodo *)malloc(sizeof(nodo));
    nuevoNodo->dato = n;
    nuevoNodo->ant = NULL;
    return (nuevoNodo);
}

nodo *push(nodo *tope, int n)
{
    nodo *aux;
    aux = crearNodo(n);
    aux->ant = tope;
    tope = aux;
    return (tope);
}

void mostrar(nodo *tope)
{
    nodo *aux;
    if (!tope)
    {
        printf("La pila es vacia");
    }
    else
    {
        aux = tope;
        do
        {
            printf("%d ", aux->dato);
            aux = aux->ant;
        } while (aux != NULL);
    }
    getchar();
}

nodo *pop(nodo *tope)
{
    nodo *aux;
    aux = tope;
    tope = tope->ant;
    free(aux);
    return (tope);
}

int main(void)
{
    nodo *tope = NULL;
    int dato, op;
    do
    {
        printf("Programa que implemtenta pilas con listas enlazadas\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("4. Salir\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Introduce un numero:\t");
            scanf("%d", &dato);
            if (tope == NULL)
                tope = crearNodo(dato);
            else
                tope = push(tope, dato);
            break;
        case 2:
            if (!vacia(tope))
            {
                printf("El dato eliminado es: %d\n", tope->dato);
                tope = pop(tope);
            }
            else
                printf("Pila vacia\n");
            getchar();
            break;
        case 3:
            if (!vacia(tope))
                mostrar(tope);
            else
                printf("Pila vacia\n");
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Error intente de nuevo");
            break;
        }
    } while (0 < op && op < 4);

    return 0;
}
