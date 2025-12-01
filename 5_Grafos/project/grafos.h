/**
 * @file grafos.h
 * @brief Librería para implementación de grafos con listas de adyacencia
 * @author J. Osorio, Y. Prado y A. Fabara
 * @date Nov/2025
 */

#ifndef GRAFOS_H
#define GRAFOS_H

#include "ColasProject/colas.h"

/* Estructura para nodos de la lista de adyacencia */
typedef struct nodoAdyacencia
{
    int vertice_destino;
    struct nodoAdyacencia *siguiente;
} nodoAdyacencia;

/* Estructura para vértices del grafo */
typedef struct vertice
{
    int id;
    char nombre[50];
    int visitado;
    nodoAdyacencia *lista_adyacencia;
} vertice;

/* Estructura principal del grafo */
typedef struct grafo
{
    int num_vertices;
    int max_vertices;
    vertice *vertices;
    int es_dirigido;
} grafo;

/* Operaciones básicas del grafo */
grafo *grafo_crear(int max_vertices, int es_dirigido);
void grafo_destruir(grafo *g);

int grafo_insertar_vertice(grafo *g, int id, const char *nombre);
int grafo_eliminar_vertice(grafo *g, int id);
int grafo_insertar_arista(grafo *g, int origen, int destino);
int grafo_eliminar_arista(grafo *g, int origen, int destino);

/* Operaciones complementarias */
void grafo_mostrar_listas(grafo *g);
void grafo_mostrar_vertices(grafo *g);
void grafo_mostrar(grafo *g);
int grafo_num_vertices(grafo *g);

/* Búsqueda en anchura (BFS) */
void grafo_bfs(grafo *g, int vertice_inicio);
int *grafo_bfs_distancias(grafo *g, int vertice_inicio);

/* Utilidades */
int grafo_existe_vertice(grafo *g, int id);
int grafo_existe_arista(grafo *g, int origen, int destino);

#endif