#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <windows.h>


using namespace std;

typedef struct {
	char Nombre[30];
	char AP[15];
	char AM[15];
	int Edad;
	float Estatura;
	float Peso;
	char Domicilio[50];
	int Deporte;
	//char ID;
}Alumno;



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
    GOTOXY(40,2);cout << "|    1.-  Crear Archivo                | " << endl;
    GOTOXY(40,3);cout << "|    2.-  Agregar Alumnos              | " << endl;
    GOTOXY(40,4);cout << "|    3.-  Ver archivo                  | " << endl;
    GOTOXY(40,5);cout << "|    4.-  Consultar                    | " << endl;
    GOTOXY(40,6);cout << "|    5.-  Modificar un archivo         | " << endl;
    GOTOXY(40,7);cout << "|    6.-  Eliminar un registro         | " << endl;
    GOTOXY(40,8);cout << "----------------------------------------" << endl;
}

int MENU_MODIFICAR(){
int opc;
	system("cls");
    GOTOXY(40,1);cout << "--------------------------------" << endl;
    GOTOXY(40,2);cout << "|           Modificar          | " << endl;
	GOTOXY(40,3);cout << "|    1.-  Nombre               | " << endl;
    GOTOXY(40,4);cout << "|    2.-  Primer Apellido      | " << endl;
    GOTOXY(40,5);cout << "|    3.-  Segundo Apellido     | " << endl;
    GOTOXY(40,6);cout << "|    4.-  Edad                 | " << endl;
    GOTOXY(40,7);cout << "|    5.-  Estatura             | " << endl;
    GOTOXY(40,8);cout << "|    6.-  Peso                 | " << endl;
    GOTOXY(40,9);cout << "|    7.-  Domicilio            | " << endl;
    GOTOXY(40,10);cout <<"|    8.-  Deporte              | " << endl;
    GOTOXY(40,11);cout <<"--------------------------------" << endl;
    cout<<"Selecione una opcion"<<endl;	cin>>opc;
    return opc;

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

void Crear_archivo(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.dat","wb");
	fclose(Archivo);
}

void Cargar(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.dat","ab");
	Alumno Ingresar;
	if(Existe("Alumnos.dat") == true){
		fflush(stdin);
		cout<<"Digite el nombre del alumno: ";	cin.getline(Ingresar.Nombre,30);
		fflush(stdin);
		cout<<"Digite el primer apellido: ";	cin.getline(Ingresar.AP,15);
		fflush(stdin);
		cout<<"Digite el segundo apellido: ";	cin.getline(Ingresar.AM,15);
		cout<<"Digite la edad: ";	cin>>Ingresar.Edad;
		cout<<"Digite la estatura: ";	cin>>Ingresar.Estatura;
		cout<<"Digite la peso: ";	cin>>Ingresar.Peso;
		fflush(stdin);
		cout<<"Digite el domicilio ";	cin.getline(Ingresar.Domicilio,50);
		
		fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	
	fclose(Archivo);
}

void Mostrar(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.dat","rb");
	Alumno Ingresar;
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Ingresar,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				cout<<"Nombre: "<<Ingresar.Nombre<<" "<<Ingresar.AP<<" "<<Ingresar.AM<<endl;
				cout<<"Edad: "<<Ingresar.Edad<<endl;
				cout<<"Estatura: "<<Ingresar.Estatura<<endl;
				cout<<"Peso: "<<Ingresar.Peso<<endl;
				cout<<"Domicilio: "<<Ingresar.Domicilio<<endl;
				fread(&Ingresar,sizeof(Alumno),1,Archivo);
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}

void Consulta(){
	FILE *Archivo;
	int existe=0; 
	Archivo = fopen("Alumnos.dat","rb");
	Alumno Ingresar;
	char Nom[30];
	fflush(stdin);
	if(ftell(Archivo) == 0){
	cout<<"Digite el nombre del alumno: ";	cin.getline(Nom,30);
	fread(&Ingresar,sizeof(Alumno),1,Archivo);
	while(!feof(Archivo)){

		if(strcmp(Nom,Ingresar.Nombre)==0){
			//strcmp(Nom,Ingresar.Nombre)==0 Son iguales 
			cout<<"Nombre: "<<Ingresar.Nombre<<" "<<Ingresar.AP<<" "<<Ingresar.AM<<endl;
			cout<<"Edad: "<<Ingresar.Edad<<endl;
			cout<<"Estatura: "<<Ingresar.Estatura<<endl;
			cout<<"Peso: "<<Ingresar.Peso<<endl;
			cout<<"Domicilio: "<<Ingresar.Domicilio<<endl;
			existe=1;
		}
		fread(&Ingresar,sizeof(Alumno),1,Archivo);
		

	}
	if(existe==0){
		cout<<"El achivo no se encontro"<<endl;
	}
	}else{
			cout<<"Archivo vacio"<<endl;
	}
	
	fclose(Archivo);
}

void Modificar(){
	FILE *Archivo;
	int existe=0;
	int opc;
	int pos; 
	Archivo = fopen("Alumnos.dat","r+b");
	Alumno Ingresar;
	char Nom[30];
	fflush(stdin);
	if(ftell(Archivo) == 0){
	cout<<"Digite el nombre del alumno: ";	cin.getline(Nom,30);
	fread(&Ingresar,sizeof(Alumno),1,Archivo);
	while(!feof(Archivo)){

		if(strcmp(Nom,Ingresar.Nombre)==0){
			//strcmp(Nom,Ingresar.Nombre)==0 Son iguales 
			
			
			opc=MENU_MODIFICAR();
			
			switch(opc){
				case 1:
					
					cout<<"Modificar nombre"<<endl;
					cout<<"Digite el nombre del alumno: ";
					fflush(stdin);
					cin.getline(Ingresar.Nombre,30);
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nuevo nombre" << endl;
					cout<<"Nombre: "<<Ingresar.Nombre<<" "<<Ingresar.AP<<" "<<Ingresar.AM<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
				
					break;
				case 2:
					
					cout<<"Modificar Primer Apellido"<<endl;
					cout<<"Digite el Primer Apellido del alumno: ";
					fflush(stdin);
					cin.getline(Ingresar.AP,15);
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nuevo nombre" << endl;
					cout<<"Nombre: "<<Ingresar.Nombre<<" "<<Ingresar.AP<<" "<<Ingresar.AM<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
					
					break;
				case 3:
					
					cout<<"Modificar Segundo Apellido"<<endl;
					cout<<"Digite el Segundo Apellido del alumno: ";
					fflush(stdin);
					cin.getline(Ingresar.AM,15);
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nuevo nombre" << endl;
					cout<<"Nombre: "<<Ingresar.Nombre<<" "<<Ingresar.AP<<" "<<Ingresar.AM<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
					
					break;
				case 4:
					
					cout<<"Modificar Edad"<<endl;
					cout<<"Digite la edad del alumno: ";
					fflush(stdin);
					cin >> Ingresar.Edad;
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nueva Edad" << endl;
					cout<<"Edad: "<<Ingresar.Edad<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
					break;
				case 5:
					
					cout<<"Modificar Estatura"<<endl;
					cout<<"Digite la estatura del alumno: ";
					fflush(stdin);
					cin >> Ingresar.Estatura;
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nueva Estatura" << endl;
					cout<<"Estatura: "<<Ingresar.Estatura<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
					break;
				case 6:
					
					cout<<"Modificar Peso"<<endl;
					cout<<"Digite el peso del alumno: ";
					fflush(stdin);
					cin >> Ingresar.Peso;
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nuevo Peso" << endl;
					cout<<"Peso: "<<Ingresar.Peso<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
					break;
				case 7:
					
						cout<<"Modificar domicilio"<<endl;
					cout<<"Digite el domicilio del alumno: ";
					fflush(stdin);
					cin.getline(Ingresar.Domicilio,50);
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nuevo domicilio" << endl;
					cout<<"Domicilio: "<<Ingresar.Domicilio<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
					break;
				case 8:
					
					cout<<"Modificar Deporte"<<endl;
					cout<<"Digite el codigo del Deporte: ";
					fflush(stdin);
					cin >> Ingresar.Deporte;
			
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
			
			
					cout << "Nuevo Deporte" << endl;
					cout<<"Deporte: "<<Ingresar.Deporte<<endl;
			
			
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					break;
					break;
					default: cout << "Error" << endl;
				}
				
			existe=1;
			break;
		}
		fread(&Ingresar,sizeof(Alumno),1,Archivo);
		

	}
	if(existe==0){
		cout<<"El achivo no se encontro"<<endl;
	}
}else{
		cout<<"Archivo vacio"<<endl;
}
	
	fclose(Archivo);
}


void Eliminar(){
	FILE *Archivo;
	FILE *Temporal;
	int r, existe=0;
	char Nom[30];
	Alumno Ingresar;
	Archivo = fopen("Alumnos.dat","r+b");
	Temporal = fopen("Temporal.dat","w+b"); //Se crea archivo auxiliar
	fflush(stdin);

	if(Archivo != NULL){
		if(ftell(Archivo) == 0){ 
		cout<<"Digite el nombre del alumno: ";	cin.getline(Nom,30);
		fflush(stdin);
		cout<<"Esta seguro que desea eliminar el registro del alumno?"<<endl;
		cout<<"1)Si\n2)No"<<endl;
		cin>>r;
			if(r==1){
			fread(&Ingresar,sizeof(Alumno),1,Archivo);
				while(!feof(Archivo)){
					if(strcmp(Nom,Ingresar.Nombre)!=0){
				
						fwrite(&Ingresar,sizeof(Alumno),1,Temporal);
						cout<<"El registro del alumno se borro exitosamente"<<endl;
			}
			
						fread(&Ingresar,sizeof(Alumno),1,Archivo);
		}
		
		}else{
						cout<<"El registro del alumno no se ha encontrado"<<endl;
			}
	}else{
						cout<<"Error\nArchivo vacio"<<endl;
	}
	     
}else{
	cout<<"Error\n El archivo no fue creado"<<endl;
}


	
	fclose(Archivo);
	fclose(Temporal);
	remove("Alumnos.dat");
	rename("Temporal.dat","Alumnos.dat");
	
}


int main(){
	int op;
	do{
	system("cls");
		MENU_PRINCIPAL();
		cout<<"Selecione una opcion"<<endl;	cin>>op;
		switch(op){
			case 1:
				Crear_archivo();
				system("pause");
				break;
			case 2:
				Cargar();
				system("pause");
				break;
			case 3:
				Mostrar();
				system("pause");
				break;
			case 4: 
				Consulta();
				system("pause");
				break;
			case 5:
				Modificar();
				system("pause");
				break;
			case 6:
				Eliminar();
				system("pause");
				break;
		}
	}while(op!=7);

	
	
	
	getch();
	return 0;
}
