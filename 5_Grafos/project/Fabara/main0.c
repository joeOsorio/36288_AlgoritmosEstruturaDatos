/****************************************************
 * @file main.c
 * @brief Programa principal para prueba de grafos con BFS
 * @author J. Osorio, Y. Prado y A. Fabara
 * @date Nov/2025
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int destino;
    struct Nodo *sig;
} Nodo;

typedef struct Grafo
{
    int numVertices;
    Nodo *listasAdy[9]; /* Array de punteros  */
    char nombres[9];    /* Para guardar 'r', 's', 't' */
    int visitado[9];    /* Para la busqueda en anchura */
} Grafo;

typedef struct Cola
{
    int items[9];
    int frente;
    int final;
} Cola;

Nodo *crearNodo(int destino);

Grafo *crearGrafo(void);
void agregarArista(Grafo *grafo, int origen, int destino);
void realizarConexiones(Grafo *grafo);
void imprimirGrafo(Grafo *grafo);
void BFS(Grafo *grafo, int nodoInicio);
void calcularDistancia(Grafo *grafo, int inicio, int destino);

/* Prototipos para implementar colas */

Cola *crearCola(void);
int esVacia(Cola *q);
void encolar(Cola *q, int valor);
int desencolar(Cola *q);

int main(void)
{
    Grafo *grafo = crearGrafo();

    realizarConexiones(grafo);

    imprimirGrafo(grafo);

    /* Prueba 1: De 's' (1) a 'z' (8) */
    calcularDistancia(grafo, 1, 8);

    /*  Prueba 2: De 's' (1) a 'w' (5) */
    /*  Camino visual: s -> v -> w (2 saltos) o s -> r -> w (2 saltos) */
    calcularDistancia(grafo, 1, 5);

    /* Prueba 3: De 's' (1) a 's' (1) */
    calcularDistancia(grafo, 1, 1);
    BFS(grafo, 1);
    getchar();

    return 0;
}
void realizarConexiones(Grafo *grafo)
{
    /*
         Mapeo de índices:
         r=0, s=1, t=2, u=3, v=4, w=5, x=6, y=7, z=8

         Se realizan las conexiones de la presentación.
     */

    /* W (5) conecta con R, V, X, Z */
    agregarArista(grafo, 5, 0); /* w-r */
    agregarArista(grafo, 5, 4); /* w-v */
    agregarArista(grafo, 5, 6); /* w-x */
    agregarArista(grafo, 5, 8); /* w-z */

    /* R (0) conecta con S, T (y W ya está arriba) */
    agregarArista(grafo, 0, 1); /* r-s */
    agregarArista(grafo, 0, 2); /* r-t */

    /* S (1) conecta con V, U (y R ya está) */
    agregarArista(grafo, 1, 4); /*  s-v */
    agregarArista(grafo, 1, 3); /*  s-u */

    /* T (2) conecta con U (y R ya está) */
    agregarArista(grafo, 2, 3); /* t-u */

    /* U (3) conecta con Y (y S, T ya están) */
    agregarArista(grafo, 3, 7); /* u-y */

    /* V (4) conecta con Y (y W, S ya están) */
    agregarArista(grafo, 4, 7); /* v-y */

    /* X (6) conecta con Y, Z (y W ya está) */
    agregarArista(grafo, 6, 7); /*  x-y */
    agregarArista(grafo, 6, 8); /*  x-z */
}

Nodo *crearNodo(int destino)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->destino = destino;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

Grafo *crearGrafo(void)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    char letras[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int i;
    grafo->numVertices = 9;

    /* Inicializar listas en NULL y nombres */

    for (i = 0; i < 9; i++)
    {
        grafo->listasAdy[i] = NULL;
        grafo->nombres[i] = letras[i]; /* Asignamos r=0, s=1. */
        grafo->visitado[i] = 0;
    }
    return grafo;
}

/* Manejamos grafo no dirigido, se realizan conexiones en ambos sentidos */
void agregarArista(Grafo *grafo, int origen, int destino)
{
    /* Agregar arista de origen -> destino */
    Nodo *nuevoNodo = crearNodo(destino);
    nuevoNodo->sig = grafo->listasAdy[origen];
    grafo->listasAdy[origen] = nuevoNodo;

    /* Agregar arista de destino -> origen */
    nuevoNodo = crearNodo(origen);
    nuevoNodo->sig = grafo->listasAdy[destino];
    grafo->listasAdy[destino] = nuevoNodo;
}

void imprimirGrafo(Grafo *grafo)
{
    int i;
    printf("\n--- ESTRUCTURA DE ADYACENCIA DEL GRAFO ---\n");
    for (i = 0; i < grafo->numVertices; i++)
    {
        Nodo *temp = grafo->listasAdy[i];
        printf("\n Nodo %c conecta con: ", grafo->nombres[i]);
        while (temp)
        {
            printf("%c", grafo->nombres[temp->destino]);
            if (temp->sig != NULL)
            {
                printf(" -> ");
            }
            temp = temp->sig;
        }
    }
    printf("\n");
}

Cola *crearCola(void)
{
    Cola *q = (Cola *)malloc(sizeof(Cola));
    q->frente = -1;
    q->final = -1;
    return q;
}
int esVacia(Cola *q)
{
    return q->final == -1;
}
void encolar(Cola *q, int valor)
{
    if (q->final == 9 - 1)
    {
        return;
    }
    if (q->frente == -1)
    {
        q->frente = 0;
    }
    q->final++;
    q->items[q->final] = valor;
}
int desencolar(Cola *q)
{
    int item;
    if (esVacia(q))
    {
        return -1;
    }
    item = q->items[q->frente];
    q->frente++;
    if (q->frente > q->final)
    {
        q->frente = q->final = -1;
    }
    return item;
}

void BFS(Grafo *grafo, int nodoInicio)
{
    Cola *q = crearCola();
    Nodo *temp;
    grafo->visitado[nodoInicio] = 1;
    encolar(q, nodoInicio);

    printf("\n--- RECORRIDO BFS (Iniciando en %c) ---\n", grafo->nombres[nodoInicio]);

    while (!esVacia(q))
    {
        /* Sacar nodo actual */
        int nodoActualIndex = desencolar(q);
        printf("%c ", grafo->nombres[nodoActualIndex]);

        /* Buscar vecinos */
        temp = grafo->listasAdy[nodoActualIndex];
        while (temp)
        {
            int vecinoIndex = temp->destino;

            /* Si no ha sido visitado, lo marcamos y encolamos */
            if (grafo->visitado[vecinoIndex] == 0)
            {
                grafo->visitado[vecinoIndex] = 1;
                encolar(q, vecinoIndex);
            }
            temp = temp->sig;
        }
    }
    printf("\n");
}
void calcularDistancia(Grafo *grafo, int inicio, int destino)
{
    Cola *q = crearCola();
    Nodo *temp;
    int distancias[9], i, actual;

    /* 2. Inicializar distancias en -1 (sirve como "no visitado") */
    for (i = 0; i < 9; i++)
    {
        distancias[i] = -1;
    }

    /* 3. Configuración inicial */
    distancias[inicio] = 0; /* La distancia a sí mismo es 0 */
    encolar(q, inicio);

    /* Bandera para saber si llegamos */

    while (!esVacia(q))
    {

        actual = desencolar(q);

        /* Si encontramos el destino, podemos detenernos (opcional) */
        if (actual == destino)
        {
            break;
        }

        temp = grafo->listasAdy[actual];
        while (temp)
        {
            int vecino = temp->destino;

            /* Si distancia es -1, significa que no ha sido visitado */
            if (distancias[vecino] == -1)
            {
                /* La distancia del vecino es la del actual + 1 */
                distancias[vecino] = distancias[actual] + 1;
                encolar(q, vecino);
            }
            temp = temp->sig;
        }
    }
    printf("\n--- CALCULO DE DISTANCIA ---");
    if (distancias[destino] != -1)
    {
        printf("\nPara ir de '%c' a '%c' necesitas: %d aristas (saltos).\n",
               grafo->nombres[inicio],
               grafo->nombres[destino],
               distancias[destino]);
    }
    else
    {
        printf("\nNo hay camino entre '%c' y '%c'.\n",
               grafo->nombres[inicio],
               grafo->nombres[destino]);
    }

    /* Liberamos la memoria */
    free(q);
}
