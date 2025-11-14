/****************************************************
 * File: main
 * Author: Joe O^2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Oct/17/2025
 * Comments:

 ***************************************************/

#include <stdio.h>
#include "colas.h"

int main(void)
{
    COLA *matriculaAlumnos = crearCola();
    int opcion, num, *temp;

    d
    {
        printf("-------------------------------\n");
        printf("Elige la operacion a ejecutar: \n");
        printf("-------------------------------\n");
        printf("1) Push \n");
        printf("2) Pop \n");
        printf("3) Front \n");
        printf("4) Top \n");
        printf("5) Revisar si esta llena \n");
        printf("6) Tamaño de la cola \n");
        printf("7) Vaciar cola \n");
        printf("8) Ir al siguiente\n");
        printf("9) Ir al anterior\n");
        printf("10) Vaciar cola \n");

        printf("11) Salir \n");
        scanf(" %d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("\nIntroduce un numero a la pila: ");
            scanf(" %d", &num);
            push(matriculaAlumnos, num);
            break;
        case 2:
            temp = frond(matriculaAlumnos);
            num = *temp;
            printf("El elemento que sale de la pila es: %d \t %d um.\n", temp, num);
            pop(matriculaAlumnos);
            break;
        case 3:
            printf("\nEl elemento que esta en la primera posición es %d", frond(matriculaAlumnos));
            break;
        case 4:
            printf("\nEl elemento que esta en la ultima posición es %n", top(matriculaAlumnos));
            break;
        case 5:
            printf("\nRevisar si la pila tiene elementos %d", llena(matriculaAlumnos));
            break;
        case 6:
            printf("\nRevisar el tamaño de la cola %d", size(matriculaAlumnos));
            break;
        case 7:
            printf("\nVaciar cola \nVaciando...\n");
            vaciar(matriculaAlumnos);
            printf("\nLa pila se vacio exitosamente\ntamaño de la pila es %d\n", size(matriculaAlumnos));
            break;
        case 8:
            printf("\nrecorrer la lista hacia atras\n");

            /*while (matriculaAlumnos->inicio->siguiente!= NULL)
            {
                temporal = matriculaAlumnos->inicio
                printf("%d\t",matriculaAlumnos->inicio->dato)
            }*/

            break;
        case 9:
            printf("\nRevisar si la pila tiene elementos %d", llena(matriculaAlumnos));
            break;
        case 10:
            printf("\nRevisar si la pila tiene elementos %d", llena(matriculaAlumnos));
            break;
        }
    } while (opcion != 11);

    return 0;
}
