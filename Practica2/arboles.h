#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

typedef struct NODO
{
    int numero;
    struct NODO *izquierda;
    struct NODO *derecha;
} NODO;


NODO *crearNodo(CANCION *c);

COLA *crearCola(void);
void vaciar(COLA *cola);

void push(COLA *cola, CANCION c);
void pop(COLA *cola);

CANCION *top(COLA *cola);
CANCION *frond(COLA *cola);

int llena(COLA *cola);
int vacia(COLA *cola);
int size(COLA *cola);

#endif /* COLAS_H_INCLUDED */
