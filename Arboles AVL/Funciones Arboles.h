#include <iostream>
#include "Estructuras.h"
using namespace std;


int obtenerAltura(NODO* Nodo)
{
    if (Nodo == NULL)
        return 0;
    return Nodo->;
}

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

NODO* buscarPadre(int num){
    NODO* Padre = NULL;
    NODO* Actual = Raiz;

    while(Actual != NULL){
        Padre = Actual;
        if(num < Actual->Clave){
            Actual = Actual->Izquierda;
        }else{
            Actual = Actual->Derecha;
        }
    };

    return Padre;

}

void Insetar( ){
  NODO* Nuevo = new(NODO);
  NODO* Padre;

    cout<<"Digite el dato:      ";    cin>>Nuevo->Dato;

  Nuevo->Izquierda = NULL;
  Nuevo->Derecha = NULL;
  Padre = buscarPadre(Nuevo->Dato);


  if(Raiz == NULL){
    Raiz = Nuevo;
  }else{
      if(Nuevo->Dato <= Padre->Dato){
        Padre->Izquierda = Nuevo;
      }else{
        Padre->Derecha = Nuevo;
      }
  }
  
	nodo->altura = 1+ max(obtenerAltura(nodo->hijoIzquierdo), obtenerAltura(nodo->hijoDerecho));
	
	int balance = obtenerBalance(nodo);

  
  
  
  
  
  
}
