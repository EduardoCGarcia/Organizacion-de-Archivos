#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
char name[50]={"Prueba1"};



typedef struct Datos Datos;

struct Datos
{
//	char codigo[6];
	char nombre[30];
//	char PA[30];
//	char SA[30];
	char edad[2];
//	char domicilio[50];
//	int deporte;
	char estatura[3];
//	double peso;
	
};

void Pedir_Nombre(){
	cout<<"Digite el nombre del archivo de texto sin la extencion .bin: ";
	fflush(stdin);
	cin.getline(name,50);
	strcat(name,".bin");
}

void Crear_Archivo(){
	FILE *archivo;
	Pedir_Nombre();
	archivo = fopen(name,"wb");
	cout<<"\n\nEl archivo se creo con el nombre: "<<name<<endl<<endl;
	fclose(archivo);
	system("pause");
}

bool Existe(char name[]){
	FILE *archivo;
	archivo = fopen(name,"rb");
	if (archivo == NULL){
		fclose(archivo);
        return false;
    }else{
    	fclose(archivo);
        return true;
    }
}

int escribeArchivo(Datos alumnos[], int tam, const char name[]){
	
	FILE *archivo;
	archivo = fopen(name,"wb");
	if(Existe == false){
		return 0;
	}
	for(int i=0 ; i<tam ; i++){
		fwrite(&alumnos[i], sizeof(Datos), 1, archivo);
	}
		fflush(archivo);
		fclose(archivo);
		return 1;
		
}


int leeArchivo(Datos alumnos[], int tam, const char name[]){
	
	FILE *archivo;
	archivo = fopen(name,"rb");
	if(Existe == false){
		return 0;
	}
	for(int i=0 ; i<tam ; i++){
		fread(&alumnos[i], sizeof(Datos), 1, archivo);
	}
	fclose(archivo);
	return 1;
}

//Funciones que vienen en el video pero imprimen directamente de los datos generados en registro (no del archivo)
/*
void imprimePersona(Datos *datos){
	printf("Nombre: %s\n", Datos->nombre);
	printf("Edad: %d\n", Datos->edad);
	printf("Estatura: %lf\n", Datos->estatura);
}

void imprimeAlumnos(Datos alumnos[], int tam){
	for(int i=0 ; i<tam ; i++){
		imprimePersona(&alumnos[i]);
		cout<<endl;
	}
}
*/

void Leer_Archivo(){	
	FILE *archivo;
	archivo = fopen(name,"rb");
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
	
	Datos alumnos[]={{{'A','X','E','L'},{'1','3'},{'1','3','2'}},
					 {{'M','A','R','Y'},{'1','4'},{'1','4','2'}},
					 {{'J','U','A','N'},{'1','5'},{'1','5','2'}}
					 };
	const int tam = sizeof(alumnos)/sizeof(Datos);
	Datos alumnosEnt[tam];
	if(!escribeArchivo(alumnos,tam,name)){
		printf("Error de escritura\n");
		return 1;
	}
	if(!leeArchivo(alumnosEnt, tam, name)){
		printf("Error de lectura\n");
		return 2;
	}
	//imprimeAlumnos(alumnosEnt, tam);
	 printf("//////////////////////////////////\n");
	Leer_Archivo();
	
	
	return 0;
}


