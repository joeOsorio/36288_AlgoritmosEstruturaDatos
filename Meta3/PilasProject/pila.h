
/**
 * @file pila.h
 * @brief Librería para implementación de pilas con listas enlazadas
 * @author J. Osorio, Y. Prado and A. Fabara
 * @date 2025
 */

#ifndef PILA_H
#define PILA_H

typedef struct nodo
{
    int dato;
    struct nodo *ant;
} nodo;

nodo *pila_crear_nodo(int n);

/* Operaciones básicas */
nodo *pila_push(nodo *tope, int n);
nodo *pila_pop(nodo *tope);

/* Operaciones complementarias */
int pila_vacia(nodo *tope);
nodo *pila_vaciar(nodo *tope);
int pila_size(nodo *tope);
void pila_mostrar(nodo *tope);
#endif