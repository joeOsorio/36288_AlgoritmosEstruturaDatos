/**
 * @file main.c
 * @brief Programa de prueba para libreria de arboles binarios
 * @author J. Osorio.
 * @date Nov/2025
 */

#include <stdio.h>
#include "arbol.h"


int main(void)
{
    int opcion, dato;
    nodoArbol *raiz = NULL;

    printf("\n--- ARBOL BINARIO ---\n");
    do
    {
        printf("\nOperaciones del Arbol:\n");
        printf("1. Insertar\n");
        printf("2. Eliminar\n");
        printf("3. Recorrer Pre-Orden\n");
        printf("4. Recorrer In-Orden\n");
        printf("5. Recorrer Post-Orden\n");
        printf("6. Mostrar Arbol\n");
        printf("7. Tamano del Arbol\n");
        printf("8. Verificar si esta vacio\n");
        printf("9. Verificar si esta lleno\n");
        printf("10. Vaciar Arbol\n");
        printf("11. Regresar al menu principal\n");
        printf("Opcion: ");

        if (scanf("%d", &opcion) != 1)
        {
            fprintf(stderr, "Error: Entrada invalida\n");
            while (getchar() != '\n')
                ; /* Limpiar buffer */
            continue;
        }

        switch (opcion)
        {
        case 1:
            printf("Dato a insertar: ");
            if (scanf("%d", &dato) != 1)
            {
                fprintf(stderr, "Error: Dato invalido\n");
                break;
            }
            raiz = arbol_insertar(raiz, dato);
            printf("Dato %d insertado\n", dato);
            break;

        case 2:
            printf("Dato a eliminar: ");
            if (scanf("%d", &dato) != 1)
            {
                fprintf(stderr, "Error: Dato invalido\n");
                break;
            }
            raiz = arbol_eliminar(raiz, dato);
            break;

        case 3:
            printf("Recorrido Pre-Orden: ");
            arbol_recorrer_preorden(raiz);
            printf("\n");
            break;

        case 4:
            printf("Recorrido In-Orden: ");
            arbol_recorrer_inorden(raiz);
            printf("\n");
            break;

        case 5:
            printf("Recorrido Post-Orden: ");
            arbol_recorrer_postorden(raiz);
            printf("\n");
            break;

        case 6:
            arbol_mostrar(raiz);
            break;

        case 7:
            printf("Tamano del arbol: %d nodos\n", arbol_tamano(raiz));
            break;

        case 8:
            printf("Arbol vacio: %s\n", arbol_vacio(raiz) ? "SI" : "NO");
            break;

        case 9:
            printf("Memoria llena: %s\n", arbol_lleno() ? "SI" : "NO");
            break;

        case 10:
            raiz = arbol_vaciar(raiz);
            printf("Arbol vaciado completamente\n");
            break;

        case 11:
            printf("Regresando...\n");
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 11);

    /* Liberar memoria antes de salir */
    raiz = arbol_vaciar(raiz);
    return 0;
}
