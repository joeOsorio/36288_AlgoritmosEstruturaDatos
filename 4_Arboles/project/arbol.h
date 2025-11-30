/**
 * @file arbol.h
 * @brief Libreria para implementacion de arboles binarios
 * @author J. Osorio.
 * @date Nov/2025
 */

#ifndef ARBOL_H
#define ARBOL_H

/* Estructura para nodo de arbol binario */
typedef struct nodoArbol
{
    int dato;
    struct nodoArbol *izquierdo;
    struct nodoArbol *derecho;
} nodoArbol;

/* Operaciones basicas */
nodoArbol *arbol_insertar(nodoArbol *raiz, int valor);
nodoArbol *arbol_eliminar(nodoArbol *raiz, int valor);

/* Operaciones complementarias */
int arbol_vacio(nodoArbol *raiz);
int arbol_lleno(void);
void arbol_recorrer_preorden(nodoArbol *raiz);
void arbol_recorrer_inorden(nodoArbol *raiz);
void arbol_recorrer_postorden(nodoArbol *raiz);
int arbol_tamano(nodoArbol *raiz);
nodoArbol *arbol_vaciar(nodoArbol *raiz);
void arbol_mostrar(nodoArbol *raiz);

/* Funciones auxiliares */
nodoArbol *arbol_crear_nodo(int valor);
nodoArbol *arbol_encontrar_minimo(nodoArbol *raiz);
nodoArbol *arbol_encontrar_maximo(nodoArbol *raiz);

#endif /* ARBOL_H */