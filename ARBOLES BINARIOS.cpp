#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


//ARBOL

struct Arbol{
  int numero;
  Arbol *der;
  Arbol *izq;
  Arbol *padre;
 };


//FUNCIONES

/*para el menu*/
void menu();
int validar_opcion(int maximo, int minimo);

/*para crear nodo en el arbol*/
Arbol *crearNodo(int, Arbol *);
void insertarNodo(Arbol *&arbol, int n, Arbol *);

/*para eliminar*/
void eliminar(Arbol *, int);
void eliminarNodo(Arbol *);
Arbol *minimo(Arbol *);
void reemplazar(Arbol *, Arbol *);
void destruirNodo(Arbol *);

/*para realizar recorrido en arboles*/
void preOrden(Arbol *);
//falta inorden y postorden
void inOrden(Arbol*)

//VARIABLES
Arbol *arbol = NULL;



using namespace std;

int main() {
  int opc, one = 1, six = 6, i, cont, num;
  
  while(1){
    system("cls");
    system("color F5");
    menu();
    opc = validar_opcion(six,one);
    switch(opc){
      
      case 1:
      system("cls");
      cout << ">>INGRESO DE NUMEROS<<";
      cout << "\n\nCantidad de numeros que va a ingresar: ";
      cin >> cont;
      for(i=0; i<cont; i++){
        cout << "\n\n\nIngrese su numero: ";
        cin >> num;
		insertarNodo(arbol, num, NULL);
      	cout << "\nNumero Insertado con exito!";
		}
        getch();
        break;
        
        
      case 2:
      system("cls");
      cout << ">>ELIMINACION DE NUMEROS<<";
      cout << "\n\n Numero que va a borrar: ";
      cin >> num;
      eliminar(arbol, num);
      cout << "\nNumero eliminado...";
      getch();
      break;
      
      
      case 3:
      system("cls");
      cout << ">>NUMEROS EN PREORDEN<<\n\n";
      preOrden(arbol);
      cout << "\n\n";
      getch();
      break;
      
      
      case 4:
      system("cls");
      cout << ">>NUMEROS EN POSTORDEN<<\n\n";
      //funcion de postorden
      getch();
      break;
      
      
      case 5:
      system("cls");
      cout << ">>NUMEROS EN INORDEN<<\n\n";
      //funcion de inorden
      inOrden(arbol);
      cout<<"\n\n";
      getch();
      break;
      
      
      case 6:
      cout << "\nBye bye...";
      getch();
      exit(0);
      break;
      
      }
   }
  return 0;
}


//FUNCION QUE MUESTRA EL MENU PRINCIPAL
void menu(){
  cout<<"--- ORDEN DE NUMEROS ---";
  cout<<"\n- 1.Ingresar numero    -";
  cout<<"\n- 2.Eliminar numero    -";
  cout<<"\n- 3.Ver en preorden    -";
  cout<<"\n- 4.Ver en postorden   -";
  cout<<"\n- 5.Ver en inorden     -";
  cout<<"\n- 6.Salir              -";
  cout<<"\n------------------------";
  cout<<"\n \n Opcion: ";
 }
 
 /*NOTA: No se fijen en esta funcion, solo es para validar que el programa no truene si se mete una letra
 		por ejemplo, pasen de largo*/
 
 //FUNCION QUE VALIDA LA ENTRADA CORRECTA A UNA OPCION DEL MENU
int validar_opcion(int maximo,int minimo){

int i,error=0,aux=0,numero=0;
char c;
char cad1[60],cad2[60];

do{

for(i=0; i < 30; i++) {
    cad1[i]=0;
    cad2[i]=0;
   }

cout << "Ingrese su opcion: ";
	fflush(stdin);
	gets(cad1);

/*el for filtra los caracteres "caracter a caracter" los que no sean digitos entre 0 y 9 pasando de la cadena 1 a la cadena 2 solo los digitos */
 for(i=0; i < 5; i++) {
    c=cad1[i];
    if(c=='0'|| c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'|| c=='8' || c=='9')
     cad2[i]=c;        }

/*valida por tipo de dato si el for dejo pasar al menos un digito menos
significa que hay un dato que no corresponde en la cadena lo cual haria invalida la cadena */
if(strlen(cad1)>strlen(cad2))
{
      error=2;}
      else{
       error=1;
       aux=atoi(cad2);}
if((aux<minimo) || (aux<=maximo) && (error==1))   /* valida por rango */
  {
      numero=aux;
      error=0;
   }
   else
     {
         if(error<2)
         printf("\n Verifique la opcion deseada: \n\n");
     }
}while(error>0);
return (numero);
}


//CREAR UN NODO EN EL ARBOL
Arbol *crearNodo(int n, Arbol *padre){
	Arbol *nuevo_nodo = new Arbol();
	
	nuevo_nodo->numero = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	return nuevo_nodo;
}


//INSERTAR DATO EN EL ARBOL
void insertarNodo(Arbol *&arbol, int n, Arbol *padre){
	if(arbol == NULL){
		Arbol *nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	}
	else{
		int Raiz = arbol->numero;
		if(n<Raiz){
			insertarNodo(arbol->izq, n, arbol);
		}else{
			insertarNodo(arbol->der, n, arbol);
		}
	}

}

//FUNCION PARA ELIMINAR
void eliminar(Arbol *arbol, int n){
	if(arbol==NULL){
		return;
	}
	else if(n < arbol->numero){
		eliminar(arbol->izq, n);
	}
	else if(n > arbol->numero){
		eliminar(arbol->der, n);
	}
	else{
		eliminarNodo(arbol);
	}
	
}


void reemplazar(Arbol *arbol, Arbol *nuevoNodo){
	if(arbol->padre){
		if(arbol->numero == arbol->padre->izq->numero){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->numero == arbol->padre->der->numero){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}


Arbol *minimo(Arbol *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return minimo(arbol->izq);
	}
	else{
		return arbol;
	}
}


void destruirNodo(Arbol *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	
	delete nodo;
}


void eliminarNodo(Arbol *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		Arbol *menor = minimo(nodoEliminar->der);
		nodoEliminar->numero = menor->numero;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar, NULL);
		destruirNodo(nodoEliminar);
	}
	
}


//FUNCION PARA PREORDEN
void preOrden(Arbol *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->numero<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//FUNCION PARA INORDEN
void inOrden(Arbol *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->numero<<" - ";
		inOrden(arbol->der);
	}
}
