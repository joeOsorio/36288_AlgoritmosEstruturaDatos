/****************************************************
 * File: main
 * Author: Joshua Osorio
 * Materia: Algoritmos y Estructura de Datos (551)
 * Date: Nov/12/2025
 * Comments: Test para funciones de árboles
 ***************************************************/

#include "ARBOLES.c"

void test1(void);
void testCreacion(void);
void testInsercion(void);

int main(void)
{
    SetConsoleOutputCP(CP_UTF8); /* Cambiar a UTF-8 */
    printf("=== INICIANDO PRUEBAS DE ARBOLES ===\n\n");

    testCreacion();
    testInsercion();
    test1();

    printf("\n=== PRUEBAS COMPLETADAS ===\n");
    return 0;
}

void testCreacion(void)
{
    ARBOL *arbol;
    NODO *nodo;
    printf("--- Prueba de Creación ---\n");

    /* Test crear árbol */
    arbol = crearArbol();
    printf("Árbol creado: %p\n", (void *)arbol);
    printf("Raíz del árbol: %p\n", (void *)arbol->raiz);
    printf("Tamaño del árbol: %d\n", arbol->tamano);

    /* Test crear nodo */
    nodo = crearNodo(100);
    printf("Nodo creado con dato: %d\n", nodo->dato);
    printf("Hijo izquierdo: %p\n", (void *)nodo->izq);
    printf("Hijo derecho: %p\n", (void *)nodo->der);

    /* Test eliminar nodo */
    eliminarNodo(nodo);
    printf("Nodo eliminado correctamente\n");

    free(arbol);
    printf("Árbol liberado\n\n");
}

void testInsercion(void)
{
    ARBOL *arbol = crearArbol();
    printf("--- Prueba de Inserción ---\n");

    /* Crear raíz manualmente ya que insertar no modifica la raíz del árbol */
    arbol->raiz = crearNodo(50);
    arbol->tamano = 1;
    printf("Raíz creada con dato: %d\n", arbol->raiz->dato);

    /* Insertar elementos menores */
    printf("Insertando 30...\n");
    insertar(30, arbol->raiz);
    if (arbol->raiz->izq != NULL)
    {
        printf("Nodo izquierdo creado: %d\n", arbol->raiz->izq->dato);
    }

    printf("Insertando 20...\n");
    insertar(20, arbol->raiz);

    /* Insertar elementos mayores */
    printf("Insertando 70...\n");
    insertar(70, arbol->raiz);
    if (arbol->raiz->der != NULL)
    {
        printf("Nodo derecho creado: %d\n", arbol->raiz->der->dato);
    }

    printf("Insertando 90...\n");
    insertar(90, arbol->raiz);

    /* Probar funciones en proceso */
    printf("\nProbando funciones en desarrollo:\n");
    eliminar();
    printf("\n");
    buscar();
    printf("\n");
    recorrerPreOrden();
    printf("\n");
    recorrerIntOrden();
    printf("\n");
    recorrerPosOrden();
    printf("\n");

    /* Liberar memoria (de manera básica) */
    if (arbol->raiz != NULL)
    {
        if (arbol->raiz->izq != NULL)
            eliminarNodo(arbol->raiz->izq);
        if (arbol->raiz->der != NULL)
            eliminarNodo(arbol->raiz->der);
        eliminarNodo(arbol->raiz);
    }
    free(arbol);
    printf("Memoria liberada\n\n");
}

void test1(void)
{
    int dato;
    ARBOL *arbolito;
    printf("--- Prueba Interactiva ---\n");

    arbolito = crearArbol();
    printf("Árbol creado exitosamente\n");

    do
    {
        printf("\nIngresa un numero:\t");
        scanf("%d", &dato);

        /* Para la primera inserción necesitamos crear la raíz manualmente */
        if (arbolito->raiz == NULL)
        {
            arbolito->raiz = crearNodo(dato);
            arbolito->tamano = 1;
            printf("Raíz establecida: %d\n", dato);
        }
        else
        {
            insertar(dato, arbolito->raiz);
            printf("Número %d insertado\n", dato);
        }

        printf("\nSeguir?  si:1 || No:0\t");
        scanf("%d", &dato);
    } while (dato == 1);

    printf("Prueba interactiva completada\n");

    /* Limpiar memoria */
    if (arbolito->raiz != NULL)
    {
        /* Nota: Esta es una limpieza básica, no recursiva */
        /* Para un árbol completo necesitarías una función recursiva de limpieza */
        eliminarNodo(arbolito->raiz);
    }
    free(arbolito);
}