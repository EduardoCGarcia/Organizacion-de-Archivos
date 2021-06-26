//Melyza Alejandra Rodriguez Contreras
//201314821
//Laboratorio de EDD Sección B
//Tarea No. 4

#include<stdio.h>
#include<stdlib.h>

struct Nodo
{
    int id;
    struct Nodo *hijoIzquierdo;
    struct Nodo *hijoDerecho;
    int altura;
};

struct ArbolAVL{
    struct Nodo *raiz;
};

//ya
int obtenerAltura(struct Nodo *nodo)
{
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}
//ya
int max(int a, int b)
{
    if(a > b){
        return a;
    }else if(a < b){
        return b;
    }else{
        return a;
    }
}
//ya
struct ArbolAVL* newArbolALV(){
    struct ArbolAVL* arbolAVL = (struct ArbolAVL*) malloc(sizeof(struct ArbolAVL));
    arbolAVL->raiz = 0;
    return(arbolAVL);
}
//ya
struct Nodo* newNodo(int i)
{
    struct Nodo* nodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nodo->id   = carnet;
    nodo->hijoIzquierdo  = NULL;
    nodo->hijoDerecho = NULL;
    nodo->altura = 1;
    return(nodo);
}
//ya
struct Nodo *rotacionDerecha(struct Nodo *nodo)
{
    struct Nodo *n = nodo;
    struct Nodo *n1 = nodo->hijoIzquierdo;

    n->hijoIzquierdo = n1->hijoDerecho;
    n1->hijoDerecho = n;
    n = n1;
    n->altura = max(obtenerAltura(n->hijoIzquierdo), obtenerAltura(n->hijoDerecho))+1;
    n1->altura = max(obtenerAltura(n1->hijoIzquierdo), obtenerAltura(n1->hijoDerecho))+1;

    return n1;
}
//ya
struct Nodo *rotacionIzquierda(struct Nodo *nodoA)
{
    struct Nodo *n = nodoA;
    struct Nodo *n1 = nodoA->hijoDerecho;

    n->hijoDerecho = n1->hijoIzquierdo;
    n1->hijoIzquierdo = n;
    n = n1;

    n->altura = max(obtenerAltura(n->hijoIzquierdo), obtenerAltura(n->hijoDerecho))+1;
    n1->altura = max(obtenerAltura(n1->hijoIzquierdo), obtenerAltura(n1->hijoDerecho))+1;

    return n;

}
//ya
int obtenerBalance(struct Nodo *nodo)
{
    if (nodo == NULL){
        return 0;
    }
    return obtenerAltura(nodo->hijoIzquierdo) - obtenerAltura(nodo->hijoDerecho);
}
//ya
int buscar(struct Nodo *raiz, int valor){

    if(raiz == 0){
        return 0;
    }else{
        if(raiz->id == valor){
            return 1;
        }else{
            if(valor > raiz->id && raiz->hijoDerecho != 0){
                return  buscar(raiz->hijoDerecho, valor);
            }else if(valor < raiz->id && raiz->hijoIzquierdo != 0){
                return buscar(raiz->hijoIzquierdo, valor);
            }
        }
    }
    return 0;
}
//ya
struct Nodo* insertar(struct Nodo* nodo, int id)
{

    if (nodo == NULL){
        return(newNodo(id));
    }else{
        if(buscar(nodo, id) == 0){
            //***************************************************************************************************
            if (id < nodo->id){
                nodo->hijoIzquierdo  = insertar(nodo->hijoIzquierdo, id);
            }else if (id > nodo->id){
                nodo->hijoDerecho = insertar(nodo->hijoDerecho, id);
            }
            else{
                printf("Nodo duplicado\n");
                return nodo;
            }

            nodo->altura = 1+ max(obtenerAltura(nodo->hijoIzquierdo), obtenerAltura(nodo->hijoDerecho));

            int balance = obtenerBalance(nodo);

            // Izquierda Simple
            if (balance > 1 && id < nodo->hijoIzquierdo->id){
                return rotacionDerecha(nodo);
            }

            // Derecha Simple
            if (balance < -1 && id > nodo->hijoDerecho->id){
                return rotacionIzquierda(nodo);
            }

            // Izquierda Derecha Doble
            if (balance > 1 && id > nodo->hijoIzquierdo->id){
                nodo->hijoIzquierdo =  rotacionIzquierda(nodo->hijoIzquierdo);
                return rotacionDerecha(nodo);
            }

            // Derecha Izquierda Doble
            if (balance < -1 && id < nodo->hijoDerecho->id){
                nodo->hijoDerecho = rotacionDerecha(nodo->hijoDerecho);
                return rotacionIzquierda(nodo);
            }
        }else{
            printf("Nodo duplicado\n");
            printf("\nPresione enter para continuar...\n");
            getchar();
            getchar();
        }
            //***************************************************************************************************
    }
    return nodo;
}
//ya
void preOrden(struct Nodo *raiz)
{
    if(raiz != NULL)
    {
        printf("Dato: %d -> ", raiz->id);
        preOrden(raiz->hijoIzquierdo);
        preOrden(raiz->hijoDerecho);
    }
}
//ya
void graficarArbol(struct Nodo *raiz){
    system("clear");
    FILE* fichero;
    fichero = fopen("arbol.dot", "wt");
    fputs("digraph Arbol{\n", fichero);
    if(raiz!= 0){
        graf(raiz, fichero);
    }else{
        fputs("Vacio", fichero);
    }
    fputs("}", fichero);
    fclose(fichero);
    system("dot -Tpng arbol.dot -o arbol.png");
    return;
}
//ya
void graf(struct Nodo *raiz, FILE* fichero){
    if(raiz != 0){
        if(raiz->hijoIzquierdo != 0){
            graficarArbolS(raiz, raiz->hijoIzquierdo, fichero);
            graf(raiz->hijoIzquierdo, fichero);
        }
        if(raiz->hijoDerecho  != 0){
            graficarArbolS(raiz, raiz->hijoDerecho, fichero);
            graf(raiz->hijoDerecho, fichero);
        }

        if(raiz->hijoIzquierdo == 0 && raiz->hijoDerecho == 0){
            int n = raiz->id;
            char * cad = malloc(12 * sizeof(char));
            sprintf(cad, "%i", n);
            fputs(cad, fichero);
            fputs("\n", fichero);
        }
    }
}
//ya
void graficarArbolS(struct Nodo *raiz, struct Nodo *hijo, FILE* fichero){
    int n = raiz->id;
    int n2 = hijo->id;
    char * cad = malloc(12 * sizeof(char));
    char * cad2 = malloc(12 * sizeof(char));
    sprintf(cad, "%i", n);
    sprintf(cad2, "%i", n2);
    fputs(cad, fichero);
    fputs("->", fichero);
    fputs(cad2, fichero);
    fputs("\n", fichero);
}
//ya
struct Nodo * minValueNode(struct Nodo* node)
{
    struct Nodo* current = node;
    while (current->hijoIzquierdo != 0){
        current = current->hijoIzquierdo;
    }
    return current;
}
//ya
struct Nodo* eliminar(struct Nodo* raiz, int valor){
    if(raiz == 0){
        return raiz;
    }else{
        if ( valor < raiz->id ){
            raiz->hijoIzquierdo = eliminar(raiz->hijoIzquierdo, valor);
        }else if( valor > raiz->id ){
            raiz->hijoDerecho = eliminar(raiz->hijoDerecho, valor);
        }else{
            if(raiz->hijoDerecho == 0 || raiz->hijoIzquierdo == 0){
                struct Nodo *temp = raiz->hijoIzquierdo ? raiz->hijoIzquierdo :
                                                 raiz->hijoDerecho;
                if (temp == 0){
                    temp = raiz;
                    raiz = 0;
                }else{
                    *raiz = *temp;
                }
                //free(temp);
            }else{
                struct Nodo* temp = minValueNode(raiz->hijoDerecho);
                raiz->id = temp->id;
                raiz->hijoDerecho = eliminar(raiz->hijoDerecho, temp->id);
            }
            if(raiz == 0){
                printf("raiz nula");
            }else if(raiz->hijoDerecho != 0 && raiz->hijoIzquierdo != 0){
                raiz->altura = 1 + max(obtenerAltura(raiz->hijoIzquierdo), obtenerAltura(raiz->hijoDerecho));

            }else if(raiz->hijoDerecho == 0 && raiz->hijoIzquierdo != 0){
                printf("Entra a izquierdo\n");
                raiz->altura = 1 + raiz->hijoIzquierdo->altura;
            }else if(raiz->hijoDerecho != 0 && raiz->hijoIzquierdo == 0){
                printf("Entra a derecho\n");
                raiz->altura = 1 + raiz->hijoDerecho->altura;
            }else if(raiz->hijoDerecho == 0 && raiz->hijoIzquierdo == 0){
                printf("El nodo no posee ningún hijo\n");
            }
            int balance = obtenerBalance(raiz);
            if (balance > 1 && obtenerBalance(raiz->hijoIzquierdo) >= 0){
                return rotacionDerecha(raiz);
            }

            if (balance > 1 && obtenerBalance(raiz->hijoIzquierdo) < 0){
                raiz->hijoIzquierdo =  rotacionIzquierda(raiz->hijoIzquierdo);
                return rotacionDerecha(raiz);
            }

            if (balance < -1 && obtenerBalance(raiz->hijoDerecho) <= 0){
                return rotacionIzquierda(raiz);
            }

            if (balance < -1 && obtenerBalance(raiz->hijoDerecho) > 0){
                raiz->hijoDerecho = rotacionDerecha(raiz->hijoDerecho);
                return rotacionIzquierda(raiz);
            }
        }
    }
    return raiz;
}

void pantallaInsertar(struct Nodo *raiz){
    system("clear");
    int x = 0;
    int ingre = 0;
    printf("Melyza Alejandra Rodriguez Contreras\n");
    printf("201314821\n");
    printf("***AVL***\nSeleccione una opcion:\n1- Insertar\n2- Eliminar\n3- Buscar\n4- Salir\nOpcion: ");
    scanf("%d", &x);
    switch(x){
    case 1:
        system("clear");
        printf("Ingrese un valor: ");
        scanf("%d", &ingre);
        raiz = insertar(raiz, ingre);
        graficarArbol(raiz);
        system("shotwell arbol.png");
        printf("\nPresione enter para continuar...\n");
        getchar();
        getchar();
        pantallaInsertar(raiz);
        break;
    case 2:
        system("clear");
        printf("Ingrese un valor para eliminar: ");
        scanf("%d", &ingre);
        raiz = eliminar(raiz, ingre);
        graficarArbol(raiz);
        system("shotwell arbol.png");
        printf("\nPresione enter para continuar...\n");
        getchar();
        getchar();
        pantallaInsertar(raiz);
        break;
    case 4:
        system("clear");
        printf("Salir\n");
        system("exit");
        break;
    case 3:
        system("clear");
        printf("Ingrese un valor para buscar: ");
        scanf("%d", &ingre);
        int a = buscar(raiz, ingre);
        if(a == 0){
            printf("El valor %d no se encuentra en el arbol\n", ingre);
        }else{
            printf("El valor %d si se encuentra en el arbol\n", ingre);
        }
        printf("\nPresione enter para continuar...\n");
        getchar();
        getchar();
        pantallaInsertar(raiz);
        break;
    default:
        printf("\nIngrese una opcion correcta\n");
        getchar();
        getchar();
        pantallaInsertar(raiz);
    }
}

int main()
{
  struct ArbolAVL *arbol = newArbolALV();
  pantallaInsertar(arbol->raiz);
  return 0;
}



