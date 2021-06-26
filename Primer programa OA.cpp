#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <ctime>
#include <string.h>

using namespace std;

int Menu(){
	int x;
	cout<<"Escuela Deportiva"<<endl<<endl;
	cout<<"Bienvenidos"<<endl<<endl;
	cout<<"1.Insertar Alumno"<<endl<<endl;
	cout<<"2.Salir"<<endl;
	cout<<endl<<"Opcion"<<endl;
	cin>>x;
	return x;
}

void insertar(ofstream &es){
	string Nombre;
	string Estatura;
	string Peso;
	string Edad;
	string Domicilio;
	string Deporte;
	es.open("Alumnos.txt");
	cout<<"Nombre del alumno:"<<endl<<endl;
	cin>>Nombre;
	cout<<endl<<"Estatura:"<<endl<<endl;
	cin>>Estatura;
	cout<<endl<<"Peso:"<<endl<<endl;
	cin>>Peso;
	cout<<endl<<"Edad:"<<endl<<endl;
	cin>>Edad;
	cout<<endl<<"Domicilio:"<<endl<<endl;
	cin>>Domicilio;
	cout<<endl<<"Deporte:"<<endl<<endl;
	cin>>Deporte; 
	es<<Nombre<<"   "<<Estatura<<"   "<<Peso<<"   "<<Edad<<"   "<<Domicilio<<"   "<<Deporte<<"\n";
	es.close();
}

int main(){
	ofstream Esc;
	int opc;
	do{
		opc=Menu();
		switch (opc){
			case 1:
				insertar(Esc);
			break;
		}
		
	}while(opc != 3);
		



}
