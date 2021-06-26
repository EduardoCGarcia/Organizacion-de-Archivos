#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
using namespace std;

char Nombre[50];

void GOTOXY(int x, int y){ //Ancho=80  ,  Alto=25
        HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon,dwPos);
}

void INICIO_DE_PROGRAMA(){
    GOTOXY(10,1);cout <<"*****************************************************************************************************" << endl;
    GOTOXY(10,2);cout <<"*                              ---------------------------------------                              *" << endl;
    GOTOXY(10,3);cout <<"*                              ----------B I E N V E N I D O----------                              *" << endl;
    GOTOXY(10,4);cout <<"*                              ---------------------------------------                              *" << endl;
    GOTOXY(10,5);cout <<"*****************************************************************************************************" << endl;
}

void MENU_PRINCIPAL(){
    GOTOXY(40,1);cout << "----------------------------------------" << endl;
    GOTOXY(40,2);cout << "|    1.-  Abrir un archivo             | " << endl;
    GOTOXY(40,3);cout << "|    2.-  Crear un archivo             | " << endl;
    GOTOXY(40,4);cout << "|    3.-  Copiar un archivo            | " << endl;
    GOTOXY(40,5);cout << "|    4.-  Modificar un archivo         | " << endl;
    GOTOXY(40,6);cout << "----------------------------------------" << endl;
}

void MENU_Archivo_encontrado(){
    GOTOXY(40,0);cout << "El archivo no se ha encontrado..." << endl;
    GOTOXY(40,1);cout << "----------------------------------------" << endl;
    GOTOXY(40,2);cout << "|    1.-  Intentar de nuevo            | " << endl;
    GOTOXY(40,3);cout << "|    2.-  Crear un archivo             | " << endl;
    GOTOXY(40,4);cout << "|    3.-  Salir                        | " << endl;
    GOTOXY(40,5);cout << "----------------------------------------" << endl;
}



void Pedir_Nombre(){
	cout<<"Digite el nombre del archivo de texto sin la extencion .txt: ";
	fflush(stdin);
	cin.getline(Nombre,50);
	strcat(Nombre,".txt");
}

void Crear_Archivo(){
	FILE *archivo;
	Pedir_Nombre();
	archivo = fopen(Nombre,"w");
	cout<<"\n\nEl archivo se creo con el nombre: "<<Nombre<<endl<<endl;
	fclose(archivo);
	system("pause");
}


bool Existe(char Nombre[]){
	FILE *archivo;
	archivo = fopen(Nombre,"r");
	if (archivo == NULL){
		fclose(archivo);
        return false;
    }else{
    	fclose(archivo);
        return true;
    }
}

bool Lleno(){
	FILE *archivo;
	archivo = fopen(Nombre,"r");
	fseek(archivo,0,SEEK_END);
	if (ftell(archivo) != 0){
		//Archivo tiene contenido
		fclose(archivo);
		return true;
	}else{
		//Archivo vacio
		fclose(archivo);
		return false;
	}
}

void Leer_Archivo(){	
	FILE *archivo;
	archivo = fopen(Nombre,"r");
	char caracter;
	printf("\nEl contenido del archivo es: \n\n");
    while((caracter = fgetc(archivo)) != EOF){
		printf("%c",caracter);
   	}
    fclose(archivo);
    cout<<endl<<endl;
}

void escribir(){
	char caracter;
	FILE *archivo;
	archivo = fopen (Nombre,"a");
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
/*
void crear_datosout(void){
	FILE *ptrdatos,*ptrdatos2;
	char caracter,caracter2;
	cout<<"Nombre del archivo origen"<<endl;
	Pedir_Nombre();
	ptrdatos=fopen(Nombre,"rt");
	cout<<"Nombre del archivo destino"<<endl;
	Pedir_Nombre();
	ptrdatos2=fopen(Nombre,"wt");
	while (caracter!=EOF) {
		if (caracter>=92 && caracter<=122){
			caracter=fgetc(ptrdatos);
			caracter2=caracter;
			fputc(caracter2,ptrdatos2);
		}
			fclose(ptrdatos);
			fclose(ptrdatos2);
	}
}
*/

void Copiar_Arhivo(){
	FILE *file1 , *file2;
    int data1 =0;
    cout<<"Nombre del archivo origen"<<endl;
	Pedir_Nombre();
    file1 = fopen ( Nombre, "r" );
    cout<<"Nombre del archivo destino"<<endl;
	Pedir_Nombre();
    file2 = fopen ( Nombre , "w" );
    
    while ( (data1 = fgetc ( file1 )) != EOF ) {
        fputc ( data1, file2 );
    }
    
    fclose ( file1 );
    fclose ( file2 );
}

void Archivo_Encontrado(){
	system("cls");
	int op=0;
	do{
		system("cls");
		Pedir_Nombre();	
		system("cls");
		if (Existe(Nombre) != true){
	    	MENU_Archivo_encontrado();
	    	cout<<"Que desea hacer : "; cin>>op;
   		}else{
   			if(Lleno()==true){
   				int op;
   				do{
   					system("cls");
   					cout<<"|-----------------------|"<<endl;
					cout<<"| 1. Solo abrir archivo |"<<endl;
					cout<<"| 2. Editar el archivo  |"<<endl;
					cout<<"| 3. Salir              |"<<endl;
					cout<<"|-----------------------|"<<endl;
					cout<<"Que desea hacer : "; cin>>op;
					switch(op){
						case 1:
							Leer_Archivo();
							system("pause");
							break;
						case 2:
							escribir();
							break;
						case 3:
							cout<<"Fue un placer atenderle"<<endl;
							break;
					}
				}while(op!=3);
			
			}else{
				cout<<"El archivo esta vacio"<<endl;
				cout<<"Desea agregar contenido (si=1 no=0)";	cin>>op;
				if(op==1){
					escribir();
					system("pause");
				}
			}
   			
		}
	}while(Existe(Nombre) != true && op==1);
	if(op==2){
		Crear_Archivo();
	}
}








int main(){
	int op;
	INICIO_DE_PROGRAMA();
	system("pause");
	do{
		system("cls");
		MENU_PRINCIPAL();
		cout<<"Seleccione una opcion: ";	cin>>op;
		system("cls");
		switch(op){
			case 1:
				Archivo_Encontrado();	
				break;
			case 2:
				Crear_Archivo();
				
				break;
			case 3:
				Copiar_Arhivo();
				break;
			case 4:
				Pedir_Nombre();
				escribir();
				break;
		}
		
		
	}while(op!=5);
	
	
	
	
	
	

	
	system("pause");
	return 0;
}
