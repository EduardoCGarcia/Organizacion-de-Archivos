#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

using namespace std;


struct Nodo {
	char Nombre[3]={'H','O','L','A'};
	char PA[30];	//Primer apellido 
	char SA[30];	//Segundo apellido
	float Estatura;
	float Peso;
	int Edad;
	char Domicilio[50];
	int Deporte;
	char Clave[6];
};
Nodo *primero=NULL;

void GOTOXY(int x, int y){ //Ancho=80  ,  Alto=25
        HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon,dwPos);
}

void MENU_PRINCIPAL(){

    GOTOXY(40,1);cout << "----------------------------------------" << endl;
    GOTOXY(40,2);cout << "|    1.-  Ingresar nuevo integrante    | " << endl;
    GOTOXY(40,3);cout << "|    2.-  Eliminar a un integrante     | " << endl;
    GOTOXY(40,4);cout << "|    3.-  Consultar                    | " << endl;
    GOTOXY(40,5);cout << "|    4.-  Modificar                    | " << endl;
    GOTOXY(40,6);cout << "|    5.-  Salir                        | " << endl;
    GOTOXY(40,7);cout << "----------------------------------------" << endl;

}

void Insertar(){
    Nodo* nuevo=new Nodo;
    FILE *archivo;
    archivo = fopen("Alumnos.bin","wb");
    fflush(stdin);
    cout<<"\n Primer Apellido:   ";  						//cin.getline(nuevo->PA,30);
    fputs (primero->PA, archivo);
	fputs ("\n" ,archivo);  	
    fflush(stdin);
    cout<<"\n Segundo Apellido:   "; 	 					cin.getline(nuevo->SA,30);
    fputs (primero->SA, archivo);
	fputs ("\n" ,archivo);  	
    fflush(stdin);
    cout<<"\n Nombre:   ";  								cin.getline(nuevo->Nombre,30);
    fputs (primero->Nombre, archivo);
	fputs ("\n" ,archivo);
    cout<<"\n Estatura (m):   ";  							cin>>nuevo->Estatura;
    //fputc (primero->Estatura, archivo);
	fputs ("\n" ,archivo);
    cout<<"\n Peso (kg):   ";  								cin>>nuevo->Peso;
    //fputs (primero->Peso, archivo);
	fputs ("\n" ,archivo);
    cout<<"\n Edad:   ";  									cin>>nuevo->Edad;
    //fputs (primero->Edad, archivo);
	fputs ("\n" ,archivo);
    fflush(stdin);
    cout<<"\n Domicilio:   ";  								cin.getline(nuevo->Domicilio,30);
    fputs (primero->Domicilio, archivo);
	fputs ("\n" ,archivo);
    cout<<"\n Deporte:   ";  								cin>>nuevo->Deporte;
    //fputs (primero->Deporte, archivo);
	fputs ("\n" ,archivo);
    
    fflush(archivo);
    fclose(archivo);
}


void Crear_Archivo(){
	FILE *archivo;
	archivo = fopen("Alumnos.bin","wb");
	fclose(archivo);
	system("pause");
}

/*void escribir(){
	
	FILE *archivo;
	archivo = fopen ("Alumnos.bin","a");
	fflush(stdin);
	
	//Gomez Nuñez
	

		fputc (primero->Nombre, archivo);
		fputc ("\n" archivo);  	
	
	fputs (" ", archivo);
	//fputc ('\n', archivo); 
	fflush(archivo);
	fclose(archivo);					
}
*/

void Leer_Archivo(){	
	FILE *archivo;
	archivo = fopen("Alumnos.bin","rb");
	char caracter;
	printf("\nEl contenido del archivo es: \n\n");
    while((caracter = fgetc(archivo)) != EOF){
		printf("%c",caracter);
   	}
    fclose(archivo);
    cout<<endl<<endl;
}


int main(int argc, char** argv) {
	Crear_Archivo();
	FILE *archivo;
	archivo = fopen("Alumnos.bin","wb");
	Leer_Archivo();
	
	//Insertar();
	//Leer_Archivo();
	
	return 0;
}
