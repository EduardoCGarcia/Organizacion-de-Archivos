#include <iostream>
#include "ARBOLESMENUS.h"
#include "RECORRIDOARBOLES.h"
#include "OPERACIONESBASICASARBOLES.h"
using namespace std;




int main(){
	int op;
	int array[] = {89,23,12,45,76,65,19,27,81,47};
	
    do{
       Mostar_Menu();
       cout<<"Digite una opcion: ";     cin>>op;
       switch(op){
       case 1:
			system("cls");
			for (int i=0; i<10; i++){
				Insetar(array[i]);
			}
			break;

       case 2:
            /*if (Raiz!=NULL){
                cout<<"Digite la clave:      ";    cin>>clave;
                NodoEncontrado=Buscar(clave);
                if(NodoEncontrado!=NULL){
                    Eliminar(NodoEncontrado);
                    cout<<"Dato eliminado con exito"<<endl;
                }else{
                    cout<<"Dato no encontrado"<<endl;
                }

           }else{
            cout<<"\n\nNo hay Productos"<<endl;
           }
           break;*/

       case 3:
           /*if (Raiz!=NULL){
                cout<<"Digite la clave:      ";    cin>>clave;
                NodoEncontrado=Buscar(clave);
                if(NodoEncontrado!=NULL){
                    Mostar_Nodo_Buscado(NodoEncontrado);
                }else{
                    cout<<"Dato no encontrado"<<endl;
                }
           }else{
            cout<<"\n\nNo hay Productos"<<endl;
           }
                break;*/

       case 4:
		system("cls");
 		if (Raiz!=NULL){
 		   PreOrden(Raiz);
 		}else{
 		cout<<"\n\nNo hay Productos"<<endl;
 		}
 		break;


       default:cout<<"Dato no valido"<<endl;
       }


    }while(op!=5);
	
	system("pause");
	return 0;
}
