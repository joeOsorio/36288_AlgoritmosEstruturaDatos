/****************************************************
 * File: main2
 * Author: Joe O2 *
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Oct/15/2025
 * Comments:

 ***************************************************/

#include <stdio.h>

typedef struct pila
{
    int tope;
    int dato[5];
} pila;

int main(void)
{
    pila numeros = {0};
    int num = 0;
    printf("Que dato desea ingresar? ");
    scanf("%d", &num);
    if (numeros.tope < 5) {
        numeros.dato[numeros.tope++] = num;
        printf("El dato introducido es %d \n", numeros.dato[numeros.tope - 1]);
    } else {
        printf("Error: La pila esta llena.\n");
    }
    printf("Sacar un dato de la pila\n");
    if (numeros.tope > 0) {
        printf("El dato que se saca es %d \n", numeros.dato[--numeros.tope]);
    } else {
        printf("Error: La pila esta vacia.\n");
    }
    return 0;
}
