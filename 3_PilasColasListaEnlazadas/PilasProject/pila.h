
/**
 * @file pila.h
 * @brief Librería para implementación de pilas con listas enlazadas
 * @author J. Osorio, Y. Prado and A. Fabara
 * @date 2025
 */

#ifndef PILA_H
#define PILA_H

typedef struct nodo_pila
{
    int dato;
    struct nodo_pila *ant;
} nodo_pila;

nodo_pila *pila_crear_nodo(int n);

/* Operaciones básicas */
nodo_pila *pila_push(nodo_pila *tope, int n);
nodo_pila *pila_pop(nodo_pila *tope);

/* Operaciones complementarias */
int pila_vacia(nodo_pila *tope);
nodo_pila *pila_vaciar(nodo_pila *tope);
int pila_size(nodo_pila *tope);
void pila_mostrar(nodo_pila *tope);
#endif