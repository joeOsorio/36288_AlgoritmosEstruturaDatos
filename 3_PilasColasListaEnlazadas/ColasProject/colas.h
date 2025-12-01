/**
 * @file colas.h
 * @brief Librería para implementación de colas con listas enlazadas
 * @author J. Osorio, Y. Prado y A. Fabara
 * @date Nov/2025
 */

#ifndef COLAS_H
#define COLAS_H

/* Cola normal */
typedef struct nodoCola
{
    int dato;
    struct nodoCola *siguiente;
} nodoCola;

/* Estructura para cola normal */
typedef struct cola
{
    nodoCola *frente;
    nodoCola *final;
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
void cola_destruir(cola *c);

/* Cola doblemente enlazada */
typedef struct nodoColaDoble
{
    int dato;
    struct nodoColaDoble *siguiente;
    struct nodoColaDoble *anterior;
} nodoColaDoble;

typedef struct cola_doble
{
    nodoColaDoble *frente;
    nodoColaDoble *final;
} cola_doble;

/* Operaciones para Cola Doble */
cola_doble *cola_doble_crear(void);
void cola_doble_insertar(cola_doble *cd, int n);
int cola_doble_remover(cola_doble *cd);
int cola_doble_vacia(cola_doble *cd);
void cola_doble_mostrar(cola_doble *cd);
void cola_doble_vaciar(cola_doble *cd);
void cola_doble_destruir(cola_doble *cd);

#endif