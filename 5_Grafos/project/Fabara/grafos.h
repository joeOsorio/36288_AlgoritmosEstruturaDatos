#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED

typedef struct Nodo
{
    int destino;      // Índice del nodo vecino (0, 1, 2...)
    struct Nodo *sig; // Puntero al siguiente vecino
} Nodo;

// Estructura del Grafo
typedef struct Grafo
{
    int numVertices;
    Nodo *listasAdy[MAX_NODOS]; // Array de punteros (cabeceras de listas)
    char nombres[MAX_NODOS];    // Para guardar 'r', 's', 't', etc.
    bool visitado[MAX_NODOS];   // Para el BFS
} Grafo;

// --- ESTRUCTURAS PARA COLA (Necesaria para BFS) ---
typedef struct Cola
{
    int items[MAX_NODOS];
    int frente;
    int final;
} Cola;

Nodo* crearNodo(int destino);

#endif /* GRAFOS_H_INCLUDED */