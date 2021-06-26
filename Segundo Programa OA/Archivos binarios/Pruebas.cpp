#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

char Nombre[50];

void Pedir_Nombre();
void Crear_Archivo();
void escribir();







int main(){
	
	escribir();
	
	system("pause");
	return 0;
}

void Pedir_Nombre(){
	cout<<"Digite el nombre del archivo de texto sin la extencion .txt: ";
	fflush(stdin);
	cin.getline(Nombre,50);
	strcat(Nombre,".docx");
}

void Crear_Archivo(){
	FILE *archivo;
	Pedir_Nombre();
	archivo = fopen("prueba3.docx","a+");
	cout<<"\n\nEl archivo se creo con el nombre: "<<Nombre<<endl<<endl;
	fclose(archivo);
	system("pause");
}

void escribir(){
	char caracter;
	FILE *archivo;
	archivo = fopen ("Prueba.docx","a+");
	fflush(stdin);
	printf("\n Introduce el texto:\n");
	
	while((caracter=getchar())!='.'){
		fputc (caracter, archivo); 
	}	
	fputs (" ", archivo);
	//fputc ('\n', archivo); 
	fflush(archivo);
	fclose(archivo);					
}
