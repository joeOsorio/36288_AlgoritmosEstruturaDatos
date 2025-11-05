#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

typedef struct NODO
{
    int *dato;
    struct NODO *anterior;
    struct NODO *siguiente;
} NODO;

typedef struct COLA
{
    NODO *inicio;
    NODO *fin;
    int longitud;
} COLA;

NODO *crearNodo(int *dato);
void eliminarNodo(NODO *nodo);

COLA *crearCola(void);
void vaciar(COLA *cola);

void push(COLA *cola, int dato);
void pop(COLA *cola);

int *top(COLA *cola);
int *frond(COLA *cola);

int llena(COLA *cola);
int size(COLA *cola);

#endif /* COLAS_H_INCLUDED */
