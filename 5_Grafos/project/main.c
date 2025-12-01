/**
 * @file main.c
 * @brief Programa principal para prueba de grafos con BFS
 * @author J. Osorio, Y. Prado and A. Fabara
 * @date Nov/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

int main(void)
{
    grafo *g = NULL;
    int opcion, id, origen, destino, max_vertices, es_dirigido;
    int *distancias;
    int i;
    char nombre[50];

    printf("Práctica de Grafos - Búsqueda en Anchura (BFS -> Breadth First Search)\n");

    printf("Implementación con listas de adyacencia\n");

    do
    {
        printf("\n=== SISTEMA DE GRAFOS CON BFS ===\n");
        printf("1. Crear grafo\n");
        printf("2. Insertar vértice\n");
        printf("3. Eliminar vértice\n");
        printf("4. Insertar arista\n");
        printf("5. Eliminar arista\n");
        printf("6. Mostrar grafo\n");
        printf("7. Recorrido BFS\n");
        printf("8. BFS con distancias\n");
        printf("9. Mostrar vértices\n");
        printf("10. Mostrar listas de adyacencia\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1: /* Crear grafo */
            if (g != NULL)
            {
                grafo_destruir(g);
                g = NULL;
            }

            printf("Número máximo de vértices: ");
            if (scanf("%d", &max_vertices) != 1 || max_vertices <= 0)
            {
                printf("Error: Número inválido\n");
                break;
            }

            printf("¿Grafo dirigido? (1=Sí, 0=No): ");
            if (scanf("%d", &es_dirigido) != 1)
            {
                printf("Error: Entrada inválida\n");
                break;
            }

            g = grafo_crear(max_vertices, es_dirigido);
            if (g != NULL)
            {
                printf("Grafo creado exitosamente\n");
            }
            break;

        case 2: /* Insertar vértice */
            if (g == NULL)
            {
                printf("Error: Primero debe crear un grafo\n");
                break;
            }

            printf("ID del vértice: ");
            if (scanf("%d", &id) != 1)
            {
                printf("Error: ID inválido\n");
                break;
            }

            printf("Nombre del vértice: ");
            if (scanf("%49s", nombre) != 1)
            {
                printf("Error: Nombre inválido\n");
                break;
            }

            if (grafo_insertar_vertice(g, id, nombre))
            {
                printf("Vértice insertado exitosamente\n");
            }
            break;

        case 3: /* Eliminar vértice */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }

            printf("ID del vértice a eliminar: ");
            if (scanf("%d", &id) != 1)
            {
                printf("Error: ID inválido\n");
                break;
            }

            if (grafo_eliminar_vertice(g, id))
            {
                printf("Vértice eliminado exitosamente\n");
            }
            break;

        case 4: /* Insertar arista */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }

            printf("Vértice origen: ");
            if (scanf("%d", &origen) != 1)
            {
                printf("Error: Origen inválido\n");
                break;
            }

            printf("Vértice destino: ");
            if (scanf("%d", &destino) != 1)
            {
                printf("Error: Destino inválido\n");
                break;
            }

            if (grafo_insertar_arista(g, origen, destino))
            {
                printf("Arista insertada exitosamente\n");
            }
            break;

        case 5: /* Eliminar arista */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }

            printf("Vértice origen: ");
            if (scanf("%d", &origen) != 1)
            {
                printf("Error: Origen inválido\n");
                break;
            }

            printf("Vértice destino: ");
            if (scanf("%d", &destino) != 1)
            {
                printf("Error: Destino inválido\n");
                break;
            }

            if (grafo_eliminar_arista(g, origen, destino))
            {
                printf("Arista eliminada exitosamente\n");
            }
            else
            {
                printf("Error: No se pudo eliminar la arista\n");
            }
            break;

        case 6: /* Mostrar grafo completo */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }
            grafo_mostrar(g);
            break;

        case 7: /* Recorrido BFS */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }

            printf("Vértice de inicio para BFS: ");
            if (scanf("%d", &id) != 1)
            {
                printf("Error: Vértice inválido\n");
                break;
            }

            grafo_bfs(g, id);
            break;

        case 8: /* BFS con distancias */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }

            printf("Vértice de inicio para BFS con distancias: ");
            if (scanf("%d", &id) != 1)
            {
                printf("Error: Vértice inválido\n");
                break;
            }

            distancias = grafo_bfs_distancias(g, id);
            if (distancias != NULL)
            {
                printf("\n=== DISTANCIAS DESDE VÉRTICE %d ===\n", id);
                for (i = 0; i < g->max_vertices; i++)
                {
                    if (g->vertices[i].id != -1)
                    {
                        printf("Vértice %d: ", g->vertices[i].id);
                        if (distancias[i] == -1)
                        {
                            printf("No alcanzable\n");
                        }
                        else
                        {
                            printf("%d aristas\n", distancias[i]);
                        }
                    }
                }
                free(distancias);
            }
            else
            {
                printf("Error: No se pudieron calcular las distancias\n");
            }
            break;

        case 9: /* Mostrar vértices */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }
            grafo_mostrar_vertices(g);
            break;

        case 10: /* Mostrar listas de adyacencia */
            if (g == NULL)
            {
                printf("Error: No hay grafo creado\n");
                break;
            }
            grafo_mostrar_listas(g);
            break;

        case 0: /* Salir */
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Error: Opción inválida\n");
            break;
        }

    } while (opcion != 0);

    if (g != NULL)
    {
        grafo_destruir(g);
    }

    return 0;
}