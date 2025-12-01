/**
 * @file main.c
 * @brief Programa de prueba para librería de colas
 * @author J. Osorio, Y. Prado y A. Fabara
 * @date 2025
 */

#include <stdio.h>
#include "colas.h"

void probar_cola_normal(void);
void probar_cola_doble(void);

int main(void)
{
    int opcion;

    printf("=== PRUEBA DE LIBRERIA DE COLAS ===\n");

    do
    {
        printf("\n=== SISTEMA DE COLAS ===\n");
        printf("1. Probar Cola Normal\n");
        printf("2. Probar Cola Doblemente Enlazada\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            probar_cola_normal();
            break;

        case 2:
            probar_cola_doble();
            break;

        case 3:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 3);
    return 0;
}

void probar_cola_normal(void)
{
    cola *c = cola_crear();
    int opcion, valor;
    if (c == NULL)
        return;

    printf("\n--- COLA NORMAL ---\n");
    do
    {
        printf("\nOperaciones Cola Normal:\n");
        printf("1. Insertar\n");
        printf("2. Remover\n");
        printf("3. Mostrar\n");
        printf("4. Tamaño\n");
        printf("5. ¿Está vacía?\n");
        printf("6. ¿Está llena?\n");
        printf("7. Vaciar\n");
        printf("8. Regresar al menu principal\n");
        printf("Opcion: ");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            cola_insertar(c, valor);
            break;

        case 2:
            valor = cola_remover(c);
            if (valor != -1)
            {
                printf("Valor removido: %d\n", valor);
            }
            break;

        case 3:
            cola_mostrar(c);
            break;

        case 4:
            printf("Elementos en cola: %d\n", cola_size(c));
            break;

        case 5:
            printf("Cola vacia: %s\n", cola_vacia(c) ? "SI" : "NO");
            break;

        case 6:
            printf("Cola llena: %s\n", cola_llena() ? "SI" : "NO");
            break;

        case 7:
            cola_vaciar(c);
            printf("Cola vaciada\n");
            break;

        case 8:
            printf("Regresando...\n");
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 8);

    cola_vaciar(c);
    free(c);
}

void probar_cola_doble(void)
{
    cola_doble *cd = cola_doble_crear();
    int opcion, valor;
    if (cd == NULL)
        return;

    printf("\n--- COLA DOBLEMENTE ENLAZADA ---\n");
    do
    {
        printf("\nOperaciones Cola Doble:\n");
        printf("1. Insertar\n");
        printf("2. Remover\n");
        printf("3. Mostrar\n");
        printf("4. ¿Está vacía?\n");
        printf("5. Regresar al menu principal\n");
        printf("Opcion: ");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Valor a insertar: ");
            scanf("%d", &valor);
            cola_doble_insertar(cd, valor);
            break;

        case 2:
            valor = cola_doble_remover(cd);
            if (valor != -1)
            {
                printf("Valor removido: %d\n", valor);
            }
            break;

        case 3:
            cola_doble_mostrar(cd);
            break;

        case 4:
            printf("Cola doble vacia: %s\n", cola_doble_vacia(cd) ? "SI" : "NO");
            break;

        case 5:
            printf("Regresando...\n");
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    } while (opcion != 5);

    /* Liberar memoria de la cola doble (implementar cola_doble_vaciar si es necesario) */
    cola_doble_vacia(cd);
    free(cd);
}