/*Listas doblemente enlazadas
Cada nodo contiene dos apuntadores

gcc Arboles.c -o Arboles.exe*/

#include <stdio.h>
#include <stdlib.h>

//La estructura para los demas nodos
struct Nodo {
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
	struct Nodo *dad;
};

void imprimir_arbol(struct Nodo* nodo, int nivel)
{
    int i;
    if (nodo != NULL)
        {
        printf(" ");
		printf("%d",nodo->dato);
        if(nodo->der)
        {
            printf("\n");
            for (i = 0; i < nivel+1; i++)
            {
                if(i==nivel)
                    printf(" |____R ");
                else
                    printf(" |      ");
            }
            imprimir_arbol(nodo->der, nivel + 1);
        }
        if(nodo->izq)
        {
            printf("\n");
            for (i = 0; i < nivel+1; i++)
            {
                printf(" |      ");
                //printf(" |      ");
            }
            printf("\n");
            for (i = 0; i < nivel+1; i++)
            {
                if(i==nivel)
                    printf(" |____L ");
                else
                    printf(" |      ");
            }
            imprimir_arbol(nodo->izq, nivel + 1);
        }
    }
}

void imprimirArbol(struct Nodo* principal)
{
	imprimir_arbol(principal,0);
}

//Función para saber si la lista esta vacia
int vacia(struct Nodo *principal) {
	return (principal == NULL);
}

//Funcion para crear nodos
struct Nodo *crearNodo(int n) {
	//Paso 1: Creamos el nuevo nodo
	struct Nodo *nuevo_nodo;
	nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	
	//Paso 2: Asignar el dato al nuevo nodo
	nuevo_nodo->dato = n;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;
	nuevo_nodo->dad = NULL;
	return(nuevo_nodo);
}

struct Nodo* Insertar(struct Nodo *principal, int n) {
	//Si es mayor es ponerlo hacia la derecha , si no es a la izquierda 
	struct Nodo* nuevo = crearNodo(n);
	struct Nodo* temp = principal;
	//int bandera = 1;
	
	if(principal == NULL) {
		return nuevo;
		//printf("\nEntre 2");
	}
	else {
		//Revisamos si el dato es mayor o menor a nuestro nodo padre
		do { 
			//struct Nodo *aux = NULL; 
			if(nuevo->dato > temp->dato) {
				if(temp->der != NULL) {
					temp = temp->der;
				}
				else {
					break;
				}
				
				if(nuevo->dato == temp->dato) {
					printf("\nEste dato ya se encuentra");
					return principal;
				}
				//printf("\nEntre Derecha");
			}
			else if(nuevo->dato < temp->dato) {
				if(temp->izq != NULL) {
					temp = temp->izq;
				}
				else {
					break;
				}
				
				if(nuevo->dato == temp->dato) {
					printf("\nEste dato ya se encuentra");
					return principal;
				}
				//printf("\nEntre Izquierda");
			}
			else {
				printf("\nEste dato ya se encuentra");
				return principal;
			}
		}while((temp->izq != NULL) || (temp->der != NULL));	
		
		if (nuevo->dato < temp->dato) {
			temp->izq = nuevo;
		} 
		else {
			temp->der = nuevo;
		}
		nuevo->dad = temp;
	}
	
	return principal;
}

struct Nodo* Eliminar(struct Nodo *principal, int n) {
	/*CASOS DE ELIMINAR
	CASO A) Cuando no se encuentra en el arbol
	CASO B) Cuando es una hoja
	CASO C) Cuando no es una hoja*/
	
}

int main(void) {
	int op, n;
	struct Nodo* principal = NULL;
	
	do {
		printf("\n\n--------- MENU PRINCIPAL ---------");
		printf("\nInsertar  [1]");
		printf("\nEliminar [2]");
		printf("\nMostrar [3]");
		printf("\nSalir [4]");
		printf("\nIngrese Opcion: ");
		scanf("%d", &op);
		
		switch(op) {
			case 1: 
				//INSERTAR 
				printf("\nIngrese el dato: ");
				scanf("%d", &n);
				
				principal = Insertar(principal, n);
				break;
			case 2: 
				//ELIMINAR
				if(principal != NULL) {
					printf("\nIngrese el dato: ");
					scanf("%d", &n);
					//principal = Eliminar(principal, n);
				}
				else {
					printf("\nEsta vacia");
				}
				break;
			case 3: 
				//MOSTRAR ARBOL
				imprimirArbol(principal);
				break;
		}

	}while(op != 4);
	
	return 0;
}

