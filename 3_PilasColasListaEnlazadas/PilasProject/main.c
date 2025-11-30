/****************************************************
 * File: main
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Nov/23/2025
 * Comments:
 * Programa, en donde se prueban las funciones principales y caracteristicas de las pilas.

 ***************************************************/
/**
 * @file main.c
 * @brief Programa de prueba para la librería de pilas
 */

#include <stdio.h>
#include "pila.h"

void mostrar_estado_pila(nodo_pila *tope)
{
    printf("=== ESTADO ACTUAL DE LA PILA ===\n");
    pila_mostrar(tope);
    printf("Elementos en pila: %d\n", pila_size(tope));
    printf("Pila vacia: %s\n", pila_vacia(tope) ? "SI" : "NO");
    printf("Pila llena: %s\n", !pila_vacia(tope) ? "SI" : "NO");
    printf("================================\n\n");
}

int main(void)
{
    nodo_pila *tope = NULL;
    int opcion, valor;

    printf("=== PRUEBA DE LIBRERIA PILA ===\n");

    do
    {
        printf("\nMenu de operaciones:\n");
        printf("1. Push (insertar)\n");
        printf("2. Pop (eliminar)\n");
        printf("3. Mostrar pila\n");
        printf("4. Cantidad de elementos\n");
        printf("5. Verificar si esta vacia\n");
        printf("6. Verificar si esta llena\n");
        printf("7. Vaciar pila\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");

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
            printf("Ingrese el valor a insertar: ");
            if (scanf("%d", &valor) != 1)
            {
                fprintf(stderr, "Error: Valor invalido\n");
                break;
            }
            tope = pila_push(tope, valor);
            printf("Valor %d insertado en la pila\n", valor);
            break;

        case 2:
            if (!pila_vacia(tope))
            {
                printf("Valor eliminado: %d\n", tope->dato);
                tope = pila_pop(tope);
            }
            else
            {
                printf("La pila esta vacia, no se puede hacer pop\n");
            }
            break;

        case 3:
            mostrar_estado_pila(tope);
            break;

        case 4:
            printf("La pila contiene %d elementos\n", pila_size(tope));
            break;

        case 5:
            printf("La pila %s esta vacia\n",
                   pila_vacia(tope) ? "SI" : "NO");
            break;

        case 6:
            printf("La pila %s esta llena\n",
                   !pila_vacia(tope) ? "SI" : "NO");
            break;

        case 7:
            tope = pila_vaciar(tope);
            printf("Pila vaciada completamente\n");
            break;

        case 8:
            printf("Saliendo del programa...\n");
            break;

        default:
            fprintf(stderr, "Error: Opcion invalida\n");
            break;
        }

    } while (opcion != 8);

    /* Limpieza final de memoria.*/
    tope = pila_vaciar(tope);

    return 0;
}