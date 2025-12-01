/**
 * @file grafos.c
 * @brief Implementación de funciones para manejo de grafos
 * @author J. Osorio, Y. Prado and A. Fabara
 * @date Nov/2025
 */

#include "grafos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Crea un nuevo grafo vacío
 * @param max_vertices Número máximo de vértices
 * @param es_dirigido 1 si es dirigido, 0 si no dirigido
 * @return Puntero al grafo creado
 */
grafo *grafo_crear(int max_vertices, int es_dirigido)
{
    grafo *nuevo_grafo;
    int i;

    if (max_vertices <= 0)
    {
        fprintf(stderr, "Error: Número máximo de vértices inválido\n");
        return NULL;
    }

    nuevo_grafo = (grafo *)malloc(sizeof(grafo));
    if (nuevo_grafo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear el grafo\n");
        return NULL;
    }

    nuevo_grafo->vertices = (vertice *)malloc(max_vertices * sizeof(vertice));
    if (nuevo_grafo->vertices == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear arreglo de vértices\n");
        free(nuevo_grafo);
        return NULL;
    }

    nuevo_grafo->num_vertices = 0;
    nuevo_grafo->max_vertices = max_vertices;
    nuevo_grafo->es_dirigido = es_dirigido;

    /* Inicializar todos los vértices */
    for (i = 0; i < max_vertices; i++)
    {
        nuevo_grafo->vertices[i].id = -1;
        nuevo_grafo->vertices[i].nombre[0] = '\0';
        nuevo_grafo->vertices[i].visitado = 0;
        nuevo_grafo->vertices[i].lista_adyacencia = NULL;
    }

    return nuevo_grafo;
}

/**
 * @brief Destruye el grafo y libera toda la memoria
 * @param g Puntero al grafo
 */
void grafo_destruir(grafo *g)
{
    int i;
    nodoAdyacencia *actual, *temp;

    if (g == NULL)
    {
        return;
    }

    if (g->vertices != NULL)
    {
        for (i = 0; i < g->max_vertices; i++)
        {
            /* Liberar lista de adyacencia de cada vértice */
            actual = g->vertices[i].lista_adyacencia;
            while (actual != NULL)
            {
                temp = actual;
                actual = actual->siguiente;
                free(temp);
            }
        }
        free(g->vertices);
    }

    free(g);
}

/**
 * @brief Verifica si existe un vértice en el grafo
 * @param g Puntero al grafo
 * @param id ID del vértice a buscar
 * @return 1 si existe, 0 si no
 */
int grafo_existe_vertice(grafo *g, int id)
{
    int i;

    if (g == NULL)
    {
        return 0;
    }

    for (i = 0; i < g->max_vertices; i++)
    {
        if (g->vertices[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Encuentra un índice libre en el arreglo de vértices
 * @param g Puntero al grafo
 * @return Índice libre o -1 si no hay espacio
 */
static int encontrar_indice_libre(grafo *g)
{
    int i;

    for (i = 0; i < g->max_vertices; i++)
    {
        if (g->vertices[i].id == -1)
        {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Encuentra el índice de un vértice por ID
 * @param g Puntero al grafo
 * @param id ID del vértice
 * @return Índice del vértice o -1 si no existe
 */
static int encontrar_indice_vertice(grafo *g, int id)
{
    int i;

    for (i = 0; i < g->max_vertices; i++)
    {
        if (g->vertices[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

/**
 * @brief Inserta un nuevo vértice en el grafo
 * @param g Puntero al grafo
 * @param id ID del vértice
 * @param nombre Nombre del vértice
 * @return 1 si éxito, 0 si error
 */
int grafo_insertar_vertice(grafo *g, int id, const char *nombre)
{
    int indice_libre;

    if (g == NULL)
    {
        fprintf(stderr, "Error: Grafo no inicializado\n");
        return 0;
    }

    if (grafo_existe_vertice(g, id))
    {
        fprintf(stderr, "Error: Ya existe un vértice con ID %d\n", id);
        return 0;
    }

    if (g->num_vertices >= g->max_vertices)
    {
        fprintf(stderr, "Error: No hay espacio para más vértices\n");
        return 0;
    }

    indice_libre = encontrar_indice_libre(g);
    if (indice_libre == -1)
    {
        fprintf(stderr, "Error: No se encontró índice libre\n");
        return 0;
    }

    g->vertices[indice_libre].id = id;
    strncpy(g->vertices[indice_libre].nombre, nombre, 49);
    g->vertices[indice_libre].nombre[49] = '\0';
    g->vertices[indice_libre].visitado = 0;
    g->vertices[indice_libre].lista_adyacencia = NULL;

    g->num_vertices++;
    return 1;
}

/**
 * @brief Elimina un vértice del grafo
 * @param g Puntero al grafo
 * @param id ID del vértice a eliminar
 * @return 1 si éxito, 0 si error
 */
int grafo_eliminar_vertice(grafo *g, int id)
{
    int i, indice_eliminar;
    nodoAdyacencia *actual, *temp;

    if (g == NULL)
    {
        fprintf(stderr, "Error: Grafo no inicializado\n");
        return 0;
    }

    if (!grafo_existe_vertice(g, id))
    {
        fprintf(stderr, "Error: No existe vértice con ID %d\n", id);
        return 0;
    }

    indice_eliminar = encontrar_indice_vertice(g, id);

    /* Liberar lista de adyacencia del vértice a eliminar */
    actual = g->vertices[indice_eliminar].lista_adyacencia;
    while (actual != NULL)
    {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    /* Eliminar todas las aristas que apunten a este vértice */
    for (i = 0; i < g->max_vertices; i++)
    {
        if (g->vertices[i].id != -1)
        {
            grafo_eliminar_arista(g, g->vertices[i].id, id);
        }
    }

    /* Marcar vértice como eliminado */
    g->vertices[indice_eliminar].id = -1;
    g->vertices[indice_eliminar].nombre[0] = '\0';
    g->vertices[indice_eliminar].lista_adyacencia = NULL;

    g->num_vertices--;
    return 1;
}

/**
 * @brief Verifica si existe una arista entre dos vértices
 * @param g Puntero al grafo
 * @param origen ID del vértice origen
 * @param destino ID del vértice destino
 * @return 1 si existe, 0 si no
 */
int grafo_existe_arista(grafo *g, int origen, int destino)
{
    int indice_origen;
    nodoAdyacencia *actual;

    if (g == NULL || !grafo_existe_vertice(g, origen) || !grafo_existe_vertice(g, destino))
    {
        return 0;
    }

    indice_origen = encontrar_indice_vertice(g, origen);
    actual = g->vertices[indice_origen].lista_adyacencia;

    while (actual != NULL)
    {
        if (actual->vertice_destino == destino)
        {
            return 1;
        }
        actual = actual->siguiente;
    }

    return 0;
}

/**
 * @brief Inserta una arista entre dos vértices
 * @param g Puntero al grafo
 * @param origen ID del vértice origen
 * @param destino ID del vértice destino
 * @return 1 si éxito, 0 si error
 */
int grafo_insertar_arista(grafo *g, int origen, int destino)
{
    int indice_origen;
    nodoAdyacencia *nuevo_nodo, *actual;

    if (g == NULL)
    {
        fprintf(stderr, "Error: Grafo no inicializado\n");
        return 0;
    }

    if (!grafo_existe_vertice(g, origen) || !grafo_existe_vertice(g, destino))
    {
        fprintf(stderr, "Error: Vértice origen o destino no existe\n");
        return 0;
    }

    if (grafo_existe_arista(g, origen, destino))
    {
        fprintf(stderr, "Error: Ya existe arista entre %d y %d\n", origen, destino);
        return 0;
    }

    indice_origen = encontrar_indice_vertice(g, origen);

    /* Crear nuevo nodo de adyacencia */
    nuevo_nodo = (nodoAdyacencia *)malloc(sizeof(nodoAdyacencia));
    if (nuevo_nodo == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear nodo de adyacencia\n");
        return 0;
    }

    nuevo_nodo->vertice_destino = destino;
    nuevo_nodo->siguiente = NULL;

    /* Insertar al inicio de la lista */
    if (g->vertices[indice_origen].lista_adyacencia == NULL)
    {
        g->vertices[indice_origen].lista_adyacencia = nuevo_nodo;
    }
    else
    {
        actual = g->vertices[indice_origen].lista_adyacencia;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }

    /* Si el grafo no es dirigido, insertar arista inversa */
    if (!g->es_dirigido && origen != destino)
    {
        grafo_insertar_arista(g, destino, origen);
    }

    return 1;
}

/**
 * @brief Elimina una arista entre dos vértices
 * @param g Puntero al grafo
 * @param origen ID del vértice origen
 * @param destino ID del vértice destino
 * @return 1 si éxito, 0 si error
 */
int grafo_eliminar_arista(grafo *g, int origen, int destino)
{
    int indice_origen;
    nodoAdyacencia *actual, *anterior;

    if (g == NULL || !grafo_existe_vertice(g, origen) || !grafo_existe_vertice(g, destino))
    {
        return 0;
    }

    indice_origen = encontrar_indice_vertice(g, origen);

    /* Buscar y eliminar arista en lista de adyacencia */
    actual = g->vertices[indice_origen].lista_adyacencia;
    anterior = NULL;

    while (actual != NULL)
    {
        if (actual->vertice_destino == destino)
        {
            if (anterior == NULL)
            {
                g->vertices[indice_origen].lista_adyacencia = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);

            /* Si el grafo no es dirigido, eliminar arista inversa */
            if (!g->es_dirigido && origen != destino)
            {
                grafo_eliminar_arista(g, destino, origen);
            }

            return 1;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    return 0;
}

/**
 * @brief Muestra las listas de adyacencia del grafo
 * @param g Puntero al grafo
 */
void grafo_mostrar_listas(grafo *g)
{
    int i;
    nodoAdyacencia *actual;

    if (g == NULL)
    {
        printf("Grafo no inicializado\n");
        return;
    }

    if (g->num_vertices == 0)
    {
        printf("El grafo está vacío\n");
        return;
    }

    printf("\n=== LISTAS DE ADYACENCIA ===\n");
    for (i = 0; i < g->max_vertices; i++)
    {
        if (g->vertices[i].id != -1)
        {
            printf("Vértice %d (%s): ", g->vertices[i].id, g->vertices[i].nombre);
            actual = g->vertices[i].lista_adyacencia;

            if (actual == NULL)
            {
                printf("Sin conexiones");
            }
            else
            {
                while (actual != NULL)
                {
                    printf("%d", actual->vertice_destino);
                    if (actual->siguiente != NULL)
                    {
                        printf(" -> ");
                    }
                    actual = actual->siguiente;
                }
            }
            printf("\n");
        }
    }
}

/**
 * @brief Muestra información sobre los vértices del grafo
 * @param g Puntero al grafo
 */
void grafo_mostrar_vertices(grafo *g)
{
    int i, count;

    if (g == NULL)
    {
        printf("Grafo no inicializado\n");
        return;
    }

    printf("\n=== VÉRTICES DEL GRAFO ===\n");
    printf("Total de vértices: %d\n", g->num_vertices);
    printf("Máximo de vértices: %d\n", g->max_vertices);
    printf("Tipo: %s\n", g->es_dirigido ? "Dirigido" : "No dirigido");

    count = 0;
    for (i = 0; i < g->max_vertices; i++)
    {
        if (g->vertices[i].id != -1)
        {
            printf("  %d. ID: %d, Nombre: %s\n",
                   ++count, g->vertices[i].id, g->vertices[i].nombre);
        }
    }
}

/**
 * @brief Muestra información completa del grafo
 * @param g Puntero al grafo
 */
void grafo_mostrar(grafo *g)
{
    grafo_mostrar_vertices(g);
    grafo_mostrar_listas(g);
}

/**
 * @brief Retorna el número de vértices en el grafo
 * @param g Puntero al grafo
 * @return Número de vértices
 */
int grafo_num_vertices(grafo *g)
{
    if (g == NULL)
    {
        return 0;
    }
    return g->num_vertices;
}

/**
 * @brief Reinicia el estado de visitado de todos los vértices
 * @param g Puntero al grafo
 */
static void grafo_reset_visitados(grafo *g)
{
    int i;

    if (g == NULL)
    {
        return;
    }

    for (i = 0; i < g->max_vertices; i++)
    {
        if (g->vertices[i].id != -1)
        {
            g->vertices[i].visitado = 0;
        }
    }
}

/**
 * @brief Realiza búsqueda en anchura (BFS) desde un vértice
 * @param g Puntero al grafo
 * @param vertice_inicio ID del vértice de inicio
 */
void grafo_bfs(grafo *g, int vertice_inicio)
{
    cola *q;
    int indice_actual, indice_vecino;
    nodoAdyacencia *actual;

    if (g == NULL || !grafo_existe_vertice(g, vertice_inicio))
    {
        printf("Error: Grafo no inicializado o vértice no existe\n");
        return;
    }

    grafo_reset_visitados(g);
    q = cola_crear();
    if (q == NULL)
    {
        fprintf(stderr, "Error: No se pudo crear cola para BFS\n");
        return;
    }

    indice_actual = encontrar_indice_vertice(g, vertice_inicio);
    g->vertices[indice_actual].visitado = 1;
    cola_insertar(q, vertice_inicio);

    printf("\n=== RECORRIDO BFS (Anchura) desde vértice %d ===\n", vertice_inicio);
    printf("Orden de visita: ");

    while (!cola_vacia(q))
    {
        int vertice_actual = cola_remover(q);
        printf("%d ", vertice_actual);

        indice_actual = encontrar_indice_vertice(g, vertice_actual);
        actual = g->vertices[indice_actual].lista_adyacencia;

        while (actual != NULL)
        {
            indice_vecino = encontrar_indice_vertice(g, actual->vertice_destino);
            if (indice_vecino != -1 && !g->vertices[indice_vecino].visitado)
            {
                g->vertices[indice_vecino].visitado = 1;
                cola_insertar(q, actual->vertice_destino);
            }
            actual = actual->siguiente;
        }
    }
    printf("\n");

    cola_destruir(q);
}

/**
 * @brief Realiza BFS y retorna distancias desde el vértice inicial
 * @param g Puntero al grafo
 * @param vertice_inicio ID del vértice de inicio
 * @return Arreglo con distancias o NULL si error
 */
int *grafo_bfs_distancias(grafo *g, int vertice_inicio)
{
    cola *q;
    int *distancias;
    int indice_actual, indice_vecino;
    nodoAdyacencia *actual;
    int i;

    if (g == NULL || !grafo_existe_vertice(g, vertice_inicio))
    {
        return NULL;
    }

    distancias = (int *)malloc(g->max_vertices * sizeof(int));
    if (distancias == NULL)
    {
        return NULL;
    }

    /* Inicializar distancias */
    for (i = 0; i < g->max_vertices; i++)
    {
        distancias[i] = -1; /* -1 significa no alcanzable */
    }

    grafo_reset_visitados(g);
    q = cola_crear();
    if (q == NULL)
    {
        free(distancias);
        return NULL;
    }

    indice_actual = encontrar_indice_vertice(g, vertice_inicio);
    g->vertices[indice_actual].visitado = 1;
    distancias[indice_actual] = 0;
    cola_insertar(q, vertice_inicio);

    while (!cola_vacia(q))
    {
        int vertice_actual = cola_remover(q);
        indice_actual = encontrar_indice_vertice(g, vertice_actual);
        actual = g->vertices[indice_actual].lista_adyacencia;

        while (actual != NULL)
        {
            indice_vecino = encontrar_indice_vertice(g, actual->vertice_destino);
            if (indice_vecino != -1 && !g->vertices[indice_vecino].visitado)
            {
                g->vertices[indice_vecino].visitado = 1;
                distancias[indice_vecino] = distancias[indice_actual] + 1;
                cola_insertar(q, actual->vertice_destino);
            }
            actual = actual->siguiente;
        }
    }

    cola_destruir(q);
    return distancias;
}