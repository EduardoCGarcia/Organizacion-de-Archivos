#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <windows.h>
#include <cctype> // libreria necesaria
#include <time.h>
using namespace std;

typedef struct Alumno{
	char Nombre[30];
	char AP[15];
	char AM[15];
	int Edad;
	float Estatura;
	float Peso;
	char Domicilio[50];
	int Deporte;
	char ID[6];

};
typedef struct Alumno ALUMNOS;

typedef struct {
	int Clave;
	char NombreDep[15];
	char Categoria[20];
	char Rango[10];
}Deporte;


int contarRegistros(FILE *archivo){
	int i=0;
	archivo = fopen("Alumnos.dat", "rb");
	Alumno Consulta;
	if(archivo == NULL){
		cout<<"Error al abrir el archivo...";
	}else{
		while(!feof(archivo)){
				fread(&Consulta,sizeof(Alumno),1,archivo);
			i++;
		}
	}
	fclose(archivo);
	return (i-1);
}
void cambiar(Alumno *alumno, int i, int j);
//burbuja
void bubbleSort(Alumno *vectorAlumno, int tamanio, int z){

	for(int i=0; i<tamanio; i++){
		for(int j=0; j<tamanio-1; j++){
			if(z==0){
				if(strcmp(vectorAlumno[j].ID, vectorAlumno[j+1].ID)>0){
					cambiar(vectorAlumno, i, j);
				}
			}else{
				if((strcmp(vectorAlumno[j].ID, vectorAlumno[j+1].ID)>0)&&(vectorAlumno[j].ID==vectorAlumno[j+1].ID)){
					cambiar(vectorAlumno, i, j);
				}
			}	
		}
	}
}

//swap de todos los elementos del registro
void cambiar(Alumno *alumno, int i, int j){
	Alumno auxiliar;
	strcpy(auxiliar.ID, alumno[j].ID);
	strcpy(auxiliar.Nombre, alumno[j].Nombre);
	strcpy(auxiliar.AP, alumno[j].AP);
	strcpy(auxiliar.AM, alumno[j].AM);
	auxiliar.Edad = alumno[j].Edad;
	auxiliar.Estatura = alumno[j].Estatura;
	auxiliar.Peso = alumno[j].Peso;
	strcpy(auxiliar.Domicilio,alumno[j].Domicilio);
	auxiliar.Deporte = alumno[j].Deporte;
	
	strcpy(alumno[j].ID, alumno[j+1].ID);
	strcpy(alumno[j].Nombre, alumno[j+1].Nombre);
	strcpy(alumno[j].AP, alumno[j+1].AP);
	strcpy(alumno[j].AM, alumno[j+1].AM);
	alumno[j].Edad = alumno[j+1].Edad;
	alumno[j].Estatura = alumno[j+1].Estatura;
	alumno[j].Peso = alumno[j+1].Peso;
	strcpy(alumno[j].Domicilio, alumno[j+1].Domicilio);
	alumno[j].Deporte = alumno[j+1].Deporte;
	
	strcpy(alumno[j+1].ID, auxiliar.ID);
	strcpy(alumno[j+1].Nombre, auxiliar.Nombre);
	strcpy(alumno[j+1].AP, auxiliar.AP);
	strcpy(alumno[j+1].AM, auxiliar.AM);
	alumno[j+1].Edad = auxiliar.Edad;
	alumno[j+1].Estatura = auxiliar.Estatura;
	alumno[j+1].Peso = auxiliar.Peso;
	strcpy(alumno[j+1].Domicilio, auxiliar.Domicilio);
	alumno[j+1].Deporte = auxiliar.Deporte;

}

//preparando vector de registros
void ordenarRegistros(FILE *archivo, int n){
	Alumno vector[n];
	Alumno Consulta;
	archivo = fopen("Alumnos.dat", "rb");
	if(archivo == NULL){
		perror("ERROR");
	}else{
		int i=0;
		fread(&Consulta,sizeof(Alumno),1,archivo);
		while(!feof(archivo)){
			//colocando los registros en el vector de objetos
			strcpy(vector[i].ID, Consulta.ID);
			strcpy(vector[i].Nombre, Consulta.Nombre);
			strcpy(vector[i].AP, Consulta.AP);
			strcpy(vector[i].AM, Consulta.AM);
			vector[i].Edad = Consulta.Edad;
			vector[i].Estatura = Consulta.Estatura;
			vector[i].Peso = Consulta.Peso;
			strcpy(vector[i].Domicilio, Consulta.Domicilio);
			vector[i].Deporte = Consulta.Deporte;
			fread(&Consulta, sizeof(Alumno), 1, archivo);
			i++;
		}
	}
	fclose(archivo);
	bubbleSort(vector, n, 0);
	bubbleSort(vector, n, 1);
	FILE *archivo2 =fopen("Archivo_Ordenado.dat", "wb");
	if(archivo2==NULL){
		cout<<"ERROR AL CREAR EL ARCHIVO...";
	}else{
		for(int i=0; i<n; i++){
			//con este simple condicional se eliminan los espacios vacíos físicamente al no escribirlos en el nuevo archivo
			if(strlen(vector[i].ID)>1){
				fwrite(&vector[i], sizeof(vector[i]), 1, archivo2);	
			}
		}
	}
	fclose(archivo2);
}

//preparar todo para ordenar
void ordenarArchivo(){
	FILE *archivo;
	int size = contarRegistros(archivo);
	ordenarRegistros(archivo,size);
}

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

int MENU_PRINCIPAL(){
	system("cls");
	int opc;
    GOTOXY(25,1);cout << "_______________________________________________________" << endl;
    GOTOXY(25,2);cout << "|         A R C H I V O S    D I R E C T O S          | " << endl;
    GOTOXY(25,3);cout << "|_____________________________________________________| " << endl;
    GOTOXY(25,4);cout << "|                 [1] Insertar alumno                 | " << endl;
    GOTOXY(25,5);cout << "|                 [2] Consultar Alumnos               | " << endl;
    GOTOXY(25,6);cout << "|                 [3] Consultar Alumno                | " << endl;
    GOTOXY(25,7);cout << "|                 [4] Baja Logica                     | " << endl;
    GOTOXY(25,8);cout << "|                 [5] Modificar                       | " << endl;
    GOTOXY(25,9);cout << "|                 [6] Ordenar                         | " << endl;
    GOTOXY(25,10);cout << "|                 [7] Insertar alumno                 | " << endl;
    GOTOXY(25,11);cout << "|_____________________________________________________|" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

int MENU_DEPORTES(){
	system("cls");
	int opc;
    GOTOXY(40,1);cout << "----------------------------------------" << endl;
    GOTOXY(40,2);cout << "|    1.-  Agregar Deporte              | " << endl;
    GOTOXY(40,3);cout << "|    2.-  Ver catalogo                 | " << endl;
    GOTOXY(40,4);cout << "|    3.-                               | " << endl;
    GOTOXY(40,5);cout << "|    4.-                               | " << endl;
    GOTOXY(40,6);cout << "|    5.-                               | " << endl;
    GOTOXY(40,7);cout << "|    6.- Salir                         | " << endl;
    GOTOXY(40,8);cout << "----------------------------------------" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

int MENU_MODIFICAR(){
	system("cls");
	int opc;
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
    cout<<"Selecione una opcion: "<<endl;	cin>>opc;
    return opc;
}

int Menu_Archivos(){
	system("cls");
	int opc;
	GOTOXY(40,1);cout << "--------------------------------" << endl;
    GOTOXY(40,2);cout << "|           Archivos           | " << endl;
	GOTOXY(40,3);cout << "|    1.-  Alumnos              | " << endl;
    GOTOXY(40,4);cout << "|    2.-  Deportes             | " << endl;
    GOTOXY(40,5);cout << "|    3.-  Crear Archivos       | " << endl;
    GOTOXY(40,6);cout << "|    4.-  Archivo Ordenado     | " << endl;
    GOTOXY(40,7);cout << "|    5.-  Salir                | " << endl;
    GOTOXY(40,8);cout <<"--------------------------------" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

int Menu_Crear_Archivos(){
	system("cls");
	int opc;
	GOTOXY(40,1);cout << "--------------------------------" << endl;
    GOTOXY(40,2);cout << "|           Archivos           | " << endl;
	GOTOXY(40,3);cout << "|    1.-  Alumnos              | " << endl;
    GOTOXY(40,4);cout << "|    2.-  Deportes             | " << endl;
    GOTOXY(40,5);cout << "|    3.-  Salir                | " << endl;
    GOTOXY(40,6);cout <<"--------------------------------" << endl;
    cout<<"Selecione el archivo que desea crear: ";	cin>>opc;
    return opc;
}

void Crear_Archivo_Alumnos(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.dat","wb");
	cout<<"\n\t--------Archivo Creado con exito-------"<<endl;
	fclose(Archivo);
}

void Crear_Archivo_Deportes(){
	FILE *Archivo;
	Archivo = fopen("Deportes.dat","wb");
	cout<<"\n\t--------Archivo Creado con exito-------"<<endl;
	fclose(Archivo);
}
	
bool validar_numeros(char cadena[]){
    int i,punto=0,carac, signo=0;
    if(strlen(cadena) != 6){
    	printf("\n\tLA CADENA NO ES VALIDA\n");
        system("pause");
		return false;
	}
    if(cadena[0]==0){
        printf("\n\tLA CADENA NO ES VALIDA\n");
        system("pause");
        return false;
    }
    if(cadena[0]<65 || cadena[0]>90 ){
        printf("\n\tEL PRIMER CARACTER DEBE SER UNA LETRA\n \n");
        system("pause");
        return false;
    }
    if(cadena[1]<65 || cadena[1]>90 ){
        printf("\n\tEL SEGUNDO CARACTER DEBE SER UNA LETRA\n \n");
        system("pause");
        return false;
    }
    if(cadena[2]<48 || cadena[2]>57 ){
        printf("\n\tEL TERCER CARACTER DEBE SER UN NUMERO ENTERO\n \n");
        system("pause");
        return false;
    }
    if(cadena[3]<48 || cadena[3]>57 ){
        printf("\n\tEL CUARTO CARACTER DEBE SER UN NUMERO ENTERO\n \n");
        system("pause");
        return false;
    }
    if(cadena[4]<48 || cadena[4]>57 ){
        printf("\n\tEL QUINTO CARACTER DEBE SER UN NUMERO ENTERO\n \n");
        system("pause");
        return false;
    }
    if(cadena[5]<65 || cadena[5]>90 ){
        printf("\n\tEL SEXTO CARACTER DEBE SER UNA LETRA\n \n");
        system("pause");
        return false;
    }
    return true;
}

int Consultar_Deporte(){
	FILE *Archivo2;
	Archivo2 = fopen("Deportes.dat","rb");
	Deporte Consulta;
	int encontrado = 0;
	int Clave_Deporte = 0;
	
	fread(&Consulta,sizeof(Deporte),1,Archivo2);
	do{
		cout<<"\n\tClave del Deporte: ";	cin>>Clave_Deporte;	
		while(!feof(Archivo2)){
				if(Clave_Deporte == Consulta.Clave){
					encontrado = 1;
					break;
				}
			fread(&Consulta,sizeof(Deporte),1,Archivo2);
		}
		Archivo2 = fopen("Deportes.dat","rb");
		fread(&Consulta,sizeof(Deporte),1,Archivo2);
	}while(encontrado != 1);
	return Clave_Deporte;
}

void Cargar_Alumno(char Nombres[],char Prim_Apellido[],char Seg_Apellido[],int Edad,float Estatura,float Peso,char Dom[],int Clave_Deporte,char ID[]){
	FILE *Archivo;
	Archivo = fopen("Alumnos.dat","rb");	
	int op;
	
	Alumno Cargar;

	if(Archivo != NULL){
		Archivo = fopen("Alumnos.dat","ab");
		
		for(int i=0; i<29; i++){ // Nombres
			Cargar.Nombre[i]=toupper(Nombres[i]); 			
		}

		for(int i=0; i<14; i++){ // Primer Apellido			
			Cargar.AP[i]=toupper(Prim_Apellido[i]);
		}

		for(int i=0; i<14; i++){ //Segundo Apellido
			Cargar.AM[i]=toupper(Seg_Apellido[i]);		
		}
		
		Cargar.Edad = Edad; //Edad
		
		Cargar.Estatura = Estatura; //Estatura
		
		Cargar.Peso = Peso; //Peso
		
		for(int i=0; i<49; i++){ //Domicilio
			Cargar.Domicilio[i]=toupper(Dom[i]);		
		}
		
		Cargar.Deporte = Clave_Deporte; //Clave del deporte 
	
		for(int i=0;i<=6;i++){ //ID
			Cargar.ID[i]= ID[i];
		}
				
		fwrite(&Cargar,sizeof(Alumno),1,Archivo);
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fclose(Archivo);
	ordenarArchivo();
}

void Pedir_Los_Datos_del_Alumno(){
	system("cls");
	char Nombres[30];
	char Prim_Apellido[15];
	char Seg_Apellido[15];
	int Edad;
	float Estatura;
	float Peso;
	char Dom[50];
	int Clave_Deporte;
	char ID[7];
	char clave2[50];
	
	cout<<"Ingrese los datos"<<endl;
	fflush(stdin);
	cout<<"\n\tNombres: 			";	cin.getline(Nombres,30);
	fflush(stdin);
	cout<<"\n\tPrimer Apellido: 	";	cin.getline(Prim_Apellido,15);
	fflush(stdin);
	cout<<"\n\tSegundo Apellido: 	";	cin.getline(Seg_Apellido,15);
	cout<<"\n\tEdad:				";	cin>>Edad;
	cout<<"\n\tEstatura: 			";	cin>>Estatura;
	cout<<"\n\tPeso: 				";	cin>> Peso;
	fflush(stdin);
	cout<<"\n\tDomicilio: 			";	cin.getline(Dom,50);
	Clave_Deporte = Consultar_Deporte();
	do{
		system("cls");
		cout<<"El ID debe ser de la siguiente manera"<<endl;
		cout<<"\nPA = Primer apellido"<<endl;
		cout<<"\nSA = Segundo apellido"<<endl;
		cout<<"\nNC = Numero de 3 digitos cualesquiera"<<endl;
		cout<<"\nG  = Sexo: Hombre(H) Mujer(M)"<<endl;
		cout<<"\nClave: (PA)(SA)(NC)(G) **Sin espacios**"<<endl;
		fflush(stdin);
		cout<<"\n\tID: ";	cin.getline(clave2,20);
		for(int i=0; i<7; i++){			
			ID[i]=toupper(clave2[i]);
		}

	}while(validar_numeros(ID) == false);
	
	Cargar_Alumno(Nombres,Prim_Apellido,Seg_Apellido,Edad,Estatura,Peso,Dom,Clave_Deporte,ID);

}

int Num_Aleatorio(){
	int dato;
	srand(time(NULL));
	dato = 1 + rand() % (1000);
	return dato;
}

void Ingresar_Deporte(){
	FILE *Archivo;
	Archivo = fopen("Deportes.dat","rb");
	char NombresDep[30];
	char PRINCIPIANTE[] = "PRINCIPIANTE";
	char INTERMEDIO[] = "INTERMEDIO";
	char AVANZADO[] = "AVANZADO";
	char ADOLESCENTE[] = "ADOLESCENTE";
	char JUVENIL[] = "JUVENIL";
	char ADULTO[] = "ADULTO";
	char Rango[20];
	char Categoria[20];
	int rango;
	int CPA = 0;
	int CPJ = 0;
	int CPAD = 0;
	
	int CIA = 0;
	int CIJ = 0;
	int CIAD = 0;
	
	int CAA = 0;
	int CAJ = 0;
	int CAAD = 0;


	Deporte Ingresar;
	if(Archivo != NULL){
		Archivo = fopen("Deportes.dat","ab");
		system("cls");
		fflush(stdin);
		cout<<"Digite el nombre del deporte: ";	cin.getline(NombresDep,30);
		for(int i=0; i<29; i++){	
			Ingresar.NombreDep[i]=toupper(NombresDep[i]); 			
		}
		system("cls");
		cout<<"\t1.- Principiente"<<endl;
		cout<<"\t2.- Intermedio"<<endl;
		cout<<"\t3.- Avanzado"<<endl;
		cout<<"\n\tDigite el rango: ";	cin>>rango;
		switch(rango){
			case 1: //Principiantes
				system("cls");
				for(int i = 0 ; i < 13 ; i++){
					Ingresar.Rango[i] = PRINCIPIANTE[i];
				}
				cout<<"\t1.- 10-15"<<endl;
				cout<<"\t2.- 16-22"<<endl;
				cout<<"\t3.- 22-30"<<endl;
				cout<<"\n\tDigite la categora: ";	cin>>rango;
				switch(rango){
					case 1:
						system("cls");
						Ingresar.Clave = 1000 + CPA;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = ADOLESCENTE[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CPA++;
						break;
					case 2:
						system("cls");
						Ingresar.Clave = 2000 + CPJ;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = JUVENIL[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CPJ++;
						break;
					case 3:
						system("cls");
						Ingresar.Clave = 3000 + CPAD;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = ADULTO[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CPAD++;
						break;
				}
				break;
			case 2: // Intermedio
				system("cls");
				for(int i=0;i<11;i++){
					Ingresar.Rango[i] = INTERMEDIO[i];
				}
				cout<<"1.- 10-15"<<endl;
				cout<<"2.- 16-22"<<endl;
				cout<<"3.- 22-30"<<endl;
				cout<<"Digite la categora: ";	cin>>rango;
				switch(rango){
					case 1:
						system("cls");
						Ingresar.Clave = 10000 + CIA;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = ADOLESCENTE[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CIA++;
						break;
					case 2:
						system("cls");
						Ingresar.Clave = 20000 + CIJ;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = JUVENIL[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CIJ++;
						break;
					case 3:
						system("cls");
						Ingresar.Clave = 30000 + CIAD;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = ADULTO[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CIAD++;
						break;
				}
				break;
				
			case 3:
				system("cls");
				for(int i=0;i<9;i++){
					Ingresar.Rango[i] = AVANZADO[i];
				}
				cout<<"1.- 10-15"<<endl;
				cout<<"2.- 16-22"<<endl;
				cout<<"3.- 22-30"<<endl;
				cout<<"Digite la categora: ";	cin>>rango;
				switch(rango){
					case 1:
						system("cls");
						Ingresar.Clave = 100000 + CAA;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = ADOLESCENTE[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CAA++;
						break;
					case 2:
						system("cls");
						Ingresar.Clave = 200000 + CAJ;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = JUVENIL[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CAJ++;
						break;
					case 3:
						system("cls");
						Ingresar.Clave = 300000 + CAAD;
						for(int i = 0 ; i < 13 ; i++){
							Ingresar.Categoria[i] = ADULTO[i];
						}
						cout<<"El rango es: "<<Ingresar.Rango<<endl;
						cout<<"La categoria es: "<<Ingresar.Categoria <<endl;
						cout<<"La clave es: "<<Ingresar.Clave<<endl;
						CAAD++;
						break;
				}
				break;
		}
	}
	fwrite(&Ingresar,sizeof(Deporte),1,Archivo);
	fclose(Archivo);
}

void Consultar_Archivo_Alumnos(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.dat","rb");
	char op[2];
	int i=1;
	Alumno Consulta;
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Alumno),1,Archivo);
			
			while(!feof(Archivo)){
				cout<<"-----------------------------------------------------"<<endl;
				cout<<"Registro "<<i<<endl;
				cout<<"-----------------------------------------------------"<<endl;
				cout<<"Nombre:"<<Consulta.Nombre<<" "<<Consulta.AP<<" "<<Consulta.AM<<endl;
				cout<<"Edad: "<<Consulta.Edad<<endl;
				cout<<"Estatura: "<<Consulta.Estatura<<endl;
				cout<<"Peso: "<<Consulta.Peso<<endl;
				cout<<"Domicilio: "<<Consulta.Domicilio<<endl;
				cout<<"Clave del deporte: "<<Consulta.Deporte<<endl;
				cout<<"ID: "<<Consulta.ID<<endl;
				cout<<"-----------------------------------------------------"<<endl;
				i++;
				cout<<endl;
				
				fread(&Consulta,sizeof(Alumno),1,Archivo);
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}

void Consultar_Archivo_Deportes(){
	FILE *Archivo;
	Archivo = fopen("Deportes.dat","rb");
	Deporte Consulta;
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Deporte),1,Archivo);
			
			while(!feof(Archivo)){
				cout<<"-----------------------------------------------------"<<endl;
				cout<<"Nombre: "<<Consulta.NombreDep<<endl;
				cout<<"Categoria: "<<Consulta.Categoria<<endl;
				cout<<"Rango: "<<Consulta.Rango<<endl;
				cout<<"Clave: "<<Consulta.Clave<<endl;
				cout<<"-----------------------------------------------------"<<endl;
				
				cout<<endl;
				
				fread(&Consulta,sizeof(Deporte),1,Archivo);
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}

void Consultar_Alumno(){	
	FILE *Archivo;
	int existe=0; 

	Archivo = fopen("Alumnos.dat","rb");
	Alumno Ingresar;
	
	char ID[30];
	fflush(stdin);
	
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			cout<<"Digite el ID: ";	cin.getline(ID,30);
			for(int i=0; i<29; i++){	
				ID[i]=toupper(ID[i]); 			
			}
			fread(&Ingresar,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				cout<<"-----------------------------------------------------"<<endl;
				if(strcmp(ID,Ingresar.ID)==0){
					//strcmp(Nom,Ingresar.Nombre)==0 Son iguales 
					cout<<"======== A L U M N O    E N C O N T R A D O =========="<<endl;
					cout<<"Nombre: "<<Ingresar.Nombre<<" "<<Ingresar.AP<<" "<<Ingresar.AM<<endl;
					cout<<"Edad: "<<Ingresar.Edad<<endl;
					cout<<"Estatura: "<<Ingresar.Estatura<<endl;
					cout<<"Peso: "<<Ingresar.Peso<<endl;
					cout<<"Domicilio: "<<Ingresar.Domicilio<<endl;
					cout<<"Clave del deporte: "<<Ingresar.Deporte<<endl;
					cout<<"ID: "<<Ingresar.ID<<endl;
					cout<<"-----------------------------------------------------"<<endl;
					system("pause");
					break;
				}else{
					cout<<"Nombre: "<<Ingresar.Nombre<<" "<<Ingresar.AP<<" "<<Ingresar.AM<<endl;
					cout<<"Edad: "<<Ingresar.Edad<<endl;
					cout<<"Estatura: "<<Ingresar.Estatura<<endl;
					cout<<"Peso: "<<Ingresar.Peso<<endl;
					cout<<"Domicilio: "<<Ingresar.Domicilio<<endl;
					cout<<"Clave del deporte: "<<Ingresar.Deporte<<endl;
					cout<<"ID: "<<Ingresar.ID<<endl;
					cout<<"-----------------------------------------------------"<<endl;
					system("pause");
				}
			fread(&Ingresar,sizeof(Alumno),1,Archivo);
			}
			if(existe==0){
				cout<<"El alumno no se encontro"<<endl;
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}

void Baja_Logica(){
	FILE *Archivo;
	int pos; 
	//FILE *Temporal;
	char ID[6];
	char Vacia[]="                         ";
	Archivo = fopen("Alumnos.dat","r+b");
	//Temporal = fopen("Temporal.dat","w+b");
	Alumno Ingresar;
	bool encontrado = true;

	if(Archivo != NULL){
		if(ftell(Archivo) == 0){ 
			fflush(stdin);
			cout<<"Digite ID: ";	cin.getline(ID,30);
			for(int i=0; i<29; i++){	
				ID[i]=toupper(ID[i]); 			
			}
			fread(&Ingresar,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				if(strcmp(ID,Ingresar.ID)==0){
				//strcmp(Nom,Ingresar.Nombre)==0 Son iguales 
					strcpy(Ingresar.Nombre,Vacia);
					strcpy(Ingresar.AP,Vacia);
					strcpy(Ingresar.AM,Vacia);
					strcpy(Ingresar.Domicilio,Vacia);
					strcpy(Ingresar.ID,Vacia);
					Ingresar.Deporte = 0;
					Ingresar.Edad = 0;
					Ingresar.Estatura = 0;
					Ingresar.Peso = 0;
					pos = ftell(Archivo) - sizeof(Alumno); // Recoge la posicion actual del indicador en el archivo
					fseek(Archivo, pos, SEEK_SET);
					fwrite(&Ingresar,sizeof(Alumno),1,Archivo);
					cout<<"El registro del alumno se borro exitosamente"<<endl;
					break;
					break;
				}else{
					encontrado = false;
				}
				fread(&Ingresar,sizeof(Alumno),1,Archivo);
			}
			if(encontrado == false){
				cout<<"No se encontro el alumno"<<endl;
			}
			
		}else{
			cout<<" El archivo no fue creado"<<endl;
		}
	}else{
		cout<<"Error\n El archivo no fue creado"<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
	ordenarArchivo();

}

void Modificar(){
	FILE *Archivo;
	int existe=0;
	int opc;
	int pos; 
	Archivo = fopen("Alumnos.dat","r+b");
	Alumno Ingresar;
	
	char ID[30];
	fflush(stdin);
	
	if(ftell(Archivo) == 0){
		cout<<"Digite el ID: ";	cin.getline(ID,30);
		for(int i=0; i<29; i++){	
			ID[i]=toupper(ID[i]); 			
		}
		fread(&Ingresar,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				if(strcmp(ID,Ingresar.ID)==0){
					//strcmp(Nom,Ingresar.Nombre)==0 Son iguales 
					opc=MENU_MODIFICAR();
			
					switch(opc){
						case 1:
							
							cout<<"Modificar nombre"<<endl;
							cout<<"Digite el nuevo nombre del alumno: ";
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
							
							/*cout<<"Modificar Deporte"<<endl;
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
							default: cout << "Error" << endl;*/
							break;
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
	ordenarArchivo();
}

void Consultar_Archivo_Ordenado(){
	FILE *Archivo;
	Archivo = fopen("Archivo_Ordenado.dat","rb");
	char op[2];
	Alumno Consulta;
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Alumno),1,Archivo);
			
			while(!feof(Archivo)){
				cout<<"-----------------------------------------------------"<<endl;
				cout<<"Nombre:"<<Consulta.Nombre<<" "<<Consulta.AP<<" "<<Consulta.AM<<endl;
				cout<<"Edad: "<<Consulta.Edad<<endl;
				cout<<"Estatura: "<<Consulta.Estatura<<endl;
				cout<<"Peso: "<<Consulta.Peso<<endl;
				cout<<"Domicilio: "<<Consulta.Domicilio<<endl;
				cout<<"Clave del deporte: "<<Consulta.Deporte<<endl;
				cout<<"ID: "<<Consulta.ID<<endl;
				cout<<"-----------------------------------------------------"<<endl;
				
				cout<<endl;
				
				fread(&Consulta,sizeof(Alumno),1,Archivo);
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}




int main(){
	int op;
	do{
		op = Menu_Archivos();
		switch(op){
			case 1:
				//Alumnos
				do{
					op = MENU_PRINCIPAL();
					switch(op){
						case 1:
							Pedir_Los_Datos_del_Alumno();
							cout<<endl;
							cout<<"--------------------------------------------------------------------------------------------------"<<endl;
							cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
							cout<<"--------------------------------------------------------------------------------------------------"<<endl;
							system("pause");
							break;
						case 2:
							Consultar_Archivo_Alumnos();
							system("pause");
							cout<<endl;
							break;
						case 3:
							Consultar_Alumno();
							cout<<endl;
							break;
						case 4:
							Baja_Logica();
							cout<<endl;
							system("pause");
							break;
						case 5:
							Modificar();
							system("pause");
							break;
						case 6:
							ordenarArchivo();
							cout<<"--------------------------------------------------------------------------------------------------"<<endl;
							cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
							cout<<"--------------------------------------------------------------------------------------------------"<<endl;
							system("pause");
							break;
						
							
					}
				}while(op != 7);
				break;
			case 2:
				//Deportes
				do{
					op = MENU_DEPORTES();
					switch(op){
						case 1:
							Ingresar_Deporte();
							cout<<endl;
							cout<<"--------------------------------------------------------------------------------------------------"<<endl;
							cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
							cout<<"--------------------------------------------------------------------------------------------------"<<endl;
							system("pause");
							break;
						case 2:
							Consultar_Archivo_Deportes();
							system("pause");
							cout<<endl;
							break;
						case 3:
							
							cout<<endl;
							break;
						case 4:
							
							cout<<endl;
							system("pause");
							break;
						case 5:
							
							system("pause");
							break;
						
					}
				}while(op != 6);
				break;
			case 3:
				do{
					op = Menu_Crear_Archivos();
					switch(op){
						case 1:
							Crear_Archivo_Alumnos();
							system("pause");
							break;
						case 2:
							Crear_Archivo_Deportes();
							system("pause");
							break;
					}
				}while(op != 3);
				break;
			case 4:
				Consultar_Archivo_Ordenado();
				system("pause");
				break;
			case 5:
				cout<<"\n\t Fue un placer atenderlo "<<endl;
				system("pause");
				break;
				
		}
		
	}while(op != 5);
	return 0;
}















