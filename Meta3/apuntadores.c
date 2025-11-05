#include <stdio.h>
#include <conio.h>

void fun(void)
{

    int *direccion;
    int edad = 0;
    printf("Cuando anios tienes");
    scanf("%d", &edad);
    direccion = &edad;
    printf("\nTu edad esta guarda en la posicion %p", direccion);
    printf("\nTu edad es %d:\t", edad);
    printf("\nTu apuntador a tu edad esta en la posicion de memoria %p\t", &direccion);
    getch();
}

void imprimir(int *v)
{
    int i = 0;
    do
    {
        printf("%d\t \n", *(v + i));
        i++;
    } while (i < 5);
}

int main(void)
{
    int vector[5] = {3, 0, 2, 2, 4};
    imprimir(vector);
    getch();
    return 0;
}