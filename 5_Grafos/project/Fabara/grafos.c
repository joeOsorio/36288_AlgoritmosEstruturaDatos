#define MAX_NODOS 9 // Según tu imagen hay 9 nodos (r, s, t, u, v, w, x, y, z)


// Crear un nuevo nodo vecino
Nodo* crearNodo(int destino) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->destino = destino;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

// Inicializar el grafo
Grafo* crearGrafo() {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = MAX_NODOS;

    // Inicializar listas en NULL y nombres
    char letras[] = {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < MAX_NODOS; i++) {
        grafo->listasAdy[i] = NULL;
        grafo->nombres[i] = letras[i]; // Asignamos r=0, s=1, etc.
        grafo->visitado[i] = false;
    }
    return grafo;
}

// Agregar Arista (Conexión)
// Como es NO dirigido, conectamos A->B y B->A
void agregarArista(Grafo* grafo, int origen, int destino) {
    // 1. Agregar arista de origen -> destino
    Nodo* nuevoNodo = crearNodo(destino);
    nuevoNodo->sig = grafo->listasAdy[origen];
    grafo->listasAdy[origen] = nuevoNodo;

    // 2. Agregar arista de destino -> origen (porque es no dirigido)
    nuevoNodo = crearNodo(origen);
    nuevoNodo->sig = grafo->listasAdy[destino];
    grafo->listasAdy[destino] = nuevoNodo;
}

// Imprimir el grafo (Lista de adyacencia)
void imprimirGrafo(Grafo* grafo) {
    printf("\n--- ESTRUCTURA DE ADYACENCIA DEL GRAFO ---\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        Nodo* temp = grafo->listasAdy[i];
        printf("\n Nodo %c conecta con: ", grafo->nombres[i]);
        while (temp) {
            printf("%c -> ", grafo->nombres[temp->destino]);
            temp = temp->sig;
        }
        printf("NULL");
    }
    printf("\n");
}

// --- FUNCIONES DE COLA (Para BFS) ---
Cola* crearCola() {
    Cola* q = (Cola*)malloc(sizeof(Cola));
    q->frente = -1;
    q->final = -1;
    return q;
}
int esVacia(Cola* q) {
    return q->final == -1;
}
void encolar(Cola* q, int valor) {
    if (q->final == MAX_NODOS - 1) return;
    if (q->frente == -1) q->frente = 0;
    q->final++;
    q->items[q->final] = valor;
}
int desencolar(Cola* q) {
    int item;
    if (esVacia(q)) return -1;
    item = q->items[q->frente];
    q->frente++;
    if (q->frente > q->final) {
        q->frente = q->final = -1; // Resetear cola
    }
    return item;
}

// --- RECORRIDO BFS (Anchura) ---
void BFS(Grafo* grafo, int nodoInicio) {
    Cola* q = crearCola();
    
    // 1. Configuración inicial
    grafo->visitado[nodoInicio] = true;
    encolar(q, nodoInicio);
    
    printf("\n--- RECORRIDO BFS (Iniciando en %c) ---\n", grafo->nombres[nodoInicio]);

    while (!esVacia(q)) {
        // 2. Sacar nodo actual
        int nodoActualIndex = desencolar(q);
        printf("%c ", grafo->nombres[nodoActualIndex]); // Imprimimos la letra

        // 3. Buscar vecinos
        Nodo* temp = grafo->listasAdy[nodoActualIndex];
        while (temp) {
            int vecinoIndex = temp->destino;

            // Si no ha sido visitado, lo marcamos y encolamos
            if (grafo->visitado[vecinoIndex] == false) {
                grafo->visitado[vecinoIndex] = true;
                encolar(q, vecinoIndex);
            }
            temp = temp->sig;
        }
    }
    printf("\n");
}
void calcularDistancia(Grafo* grafo, int inicio, int destino) {
    // 1. Crear Cola y arreglo de distancias
    Cola* q = crearCola();
    int distancias[MAX_NODOS];

    // 2. Inicializar distancias en -1 (sirve como "no visitado")
    for (int i = 0; i < MAX_NODOS; i++) {
        distancias[i] = -1; 
    }

    // 3. Configuración inicial
    distancias[inicio] = 0; // La distancia a sí mismo es 0
    encolar(q, inicio);
    
    // Bandera para saber si llegamos
    bool encontrado = false;

    // 4. Bucle BFS
    while (!esVacia(q)) {
        int actual = desencolar(q);

        // Si encontramos el destino, podemos detenernos (opcional)
        if (actual == destino) {
            encontrado = true;
            break; 
        }

        Nodo* temp = grafo->listasAdy[actual];
        while (temp) {
            int vecino = temp->destino;

            // Si distancia es -1, significa que no ha sido visitado
            if (distancias[vecino] == -1) {
                // LA MAGIA: La distancia del vecino es la del actual + 1
                distancias[vecino] = distancias[actual] + 1;
                encolar(q, vecino);
            }
            temp = temp->sig;
        }
    }

    // 5. Mostrar resultado
    printf("\n--- CALCULO DE DISTANCIA ---");
    if (distancias[destino] != -1) {
        printf("\nPara ir de '%c' a '%c' necesitas: %d aristas (saltos).\n", 
               grafo->nombres[inicio], 
               grafo->nombres[destino], 
               distancias[destino]);
    } else {
        printf("\nNo hay camino entre '%c' y '%c'.\n", 
               grafo->nombres[inicio], 
               grafo->nombres[destino]);
    }
    
    // Limpieza (opcional pero recomendada)
    free(q);
}
