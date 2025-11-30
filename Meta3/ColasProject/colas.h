/**
 * @file colas.h
 * @brief Librería para implementación de colas con listas enlazadas
 * @author J. Osorio, Y. Prado and A. Fabara
 * @date Nov/2025
 */

#ifndef COLAS_H
#define COLAS_H

typedef struct nodo_cola
{
    int dato;
    struct nodo_cola *siguiente;
} nodo_cola;

typedef struct cola
{
    nodo_cola *frente;
    nodo_cola *final;
} cola;

/* Operaciones básicas - Cola Normal */
cola *cola_crear(void);
void cola_insertar(cola *c, int n);
int cola_remover(cola *c);

/* Operaciones complementarias */
int cola_vacia(cola *c);
int cola_llena(void);
void cola_mostrar(cola *c);
int cola_size(cola *c);
void cola_vaciar(cola *c);

/* Cola Doblemente Enlazada */
typedef struct nodo_doble
{
    int dato;
    struct nodo_doble *siguiente;
    struct nodo_doble *anterior;
} nodo_doble;

typedef struct cola_doble
{
    nodo_doble *frente;
    nodo_doble *final;
} cola_doble;

/* Operaciones para Cola Doble */
cola_doble *cola_doble_crear(void);
void cola_doble_insertar(cola_doble *cd, int n);
int cola_doble_remover(cola_doble *cd);
int cola_doble_vacia(cola_doble *cd);
void cola_doble_mostrar(cola_doble *cd);

#endif