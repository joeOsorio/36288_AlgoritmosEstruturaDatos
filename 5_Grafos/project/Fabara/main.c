/****************************************************
 * @file: main
 * @author: J. Osorio, 
 * Materia: Algoritmos y Estructura de Datos (551) 
 * Date: Nov/30/2025
 * Comments: 
 
 ***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafos.h"

int main()
{
    Grafo *grafo = crearGrafo();

    // Mapeo de índices para no perdernos:
    // r=0, s=1, t=2, u=3, v=4, w=5, x=6, y=7, z=8

    // Conexiones de la imagen:
    // W (5) conecta con R, V, X, Z
    agregarArista(grafo, 5, 0); // w-r
    agregarArista(grafo, 5, 4); // w-v
    agregarArista(grafo, 5, 6); // w-x
    agregarArista(grafo, 5, 8); // w-z

    // R (0) conecta con S, T (y W ya está arriba)
    agregarArista(grafo, 0, 1); // r-s
    agregarArista(grafo, 0, 2); // r-t

    // S (1) conecta con V, U (y R ya está)
    agregarArista(grafo, 1, 4); // s-v
    agregarArista(grafo, 1, 3); // s-u

    // T (2) conecta con U (y R ya está)
    agregarArista(grafo, 2, 3); // t-u

    // U (3) conecta con Y (y S, T ya están)
    agregarArista(grafo, 3, 7); // u-y

    // V (4) conecta con Y (y W, S ya están)
    agregarArista(grafo, 4, 7); // v-y

    // X (6) conecta con Y, Z (y W ya está)
    agregarArista(grafo, 6, 7); // x-y
    agregarArista(grafo, 6, 8); // x-z

    // Y y Z ya tienen sus conexiones completas con las líneas anteriores

    imprimirGrafo(grafo);

    // ... después de imprimir el grafo ...

    // Prueba 1: De 's' (1) a 'z' (8)
    calcularDistancia(grafo, 1, 8);

    // Prueba 2: De 's' (1) a 'w' (5)
    // Camino visual: s -> v -> w (2 saltos) o s -> r -> w (2 saltos)
    calcularDistancia(grafo, 1, 5);

    // Prueba 3: De 's' (1) a 's' (1)
    calcularDistancia(grafo, 1, 1);

    // En la imagen, 's' tiene un 0, lo que sugiere que es el nodo inicial
    // El índice de 's' es 1.
    BFS(grafo, 1);

    return 0;
}