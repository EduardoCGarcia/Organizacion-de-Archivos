//Librerias de c y c++
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h> //Para manejo de cadenas de caracteres
#include "pintar.h"


/*
=============================================================================================
								C R U D     D E    A L U M N O S
=============================================================================================
*/

bool comprobarCurso(int clave, int Edad, char Sexo[]){
	FILE *archivoDep;	 
	archivoDep = fopen("Cursos.DIR","rb");
	if(archivoDep == NULL){
		cout << "_______________________________________________________" << endl;
		cout << "|       EL ARCHIVO INSTRUCTORES NO SE ENCONTRO        | " << endl;
		cout << "|_____________________________________________________|" << endl;
		return false;
	}
	Curso Buscado;
	fread(&Buscado,sizeof(Curso),1,archivoDep);
	while(!feof(archivoDep)){
		if( (Buscado.claveCurso == clave) && (Buscado.max>=Edad) && (Buscado.min<=Edad) && (strcmp(Buscado.sexo,Sexo)==0) ){
			return true;
		}
		fread(&Buscado,sizeof(Curso),1,archivoDep);	
	}
	return false;
}

/* comprobarInstructor: Busca en el archivo de Instructores la clave del deporte para asegurarnos
					 de que el curso es impartido por un instructor */
bool comprobarInstructor(int clave_Curso){
	FILE *Archivo;
	Archivo = fopen("Instructores.DIR","rb");
	Instructor Bclave;

								
	if(Archivo == NULL){
		cout << "_______________________________________________________" << endl;
		cout << "|       EL ARCHIVO INSTRUCTORES NO SE ENCONTRO        | " << endl;
		cout << "|_____________________________________________________|" << endl;
		return false;
	}		
	
	fread(&Bclave,sizeof(Instructor),1,Archivo);
	while(!feof(Archivo)){
		if(Bclave.claveCurso == clave_Curso){
			strcpy(arrayIdBusquedas,Bclave.id);
			fclose(Archivo);
			return true;
		}
		fread(&Bclave,sizeof(Instructor),1,Archivo);
	}
	return false;
	fclose(Archivo);
}

/* bajaIndex: Realiza la baja de manera fisica en el archivo index ya que si no se quedairia guardado un alumno
				que ya no existe en la escuela */
void bajaIndex(char ID[]){
	
	FILE *Archivo;
	FILE *Temporal;
	Index Eliminar;
	Archivo = fopen("Index.DIR","rb");
	Temporal = fopen("Temporal.DIR","wb"); //Se crea archivo auxiliar
			fread(&Eliminar,sizeof(Index),1,Archivo);								
			while(!feof(Archivo)){															
				if(strcmp(ID,Eliminar.claveAlumno) != 0){						
				fwrite(&Eliminar,sizeof(Index),1,Temporal);
				}
				fread(&Eliminar,sizeof(Index),1,Archivo);			
			}
	_fcloseall();	
	remove("Index.DIR");
	rename("Temporal.DIR","Index.DIR");	
}

/*Buscar_Index: busca la posision fisica dentro del archvio de un alumno*/
int Buscar_Index(char ID[]){
	FILE *Archivo;
	Archivo = fopen("Index.DIR","rb");
	Index Consulta;
	
	for(int i=0; i<10; i++){	
		ID[i]=toupper(ID[i]); 			
	}
	
	fread(&Consulta,sizeof(Index),1,Archivo);
	while(!feof(Archivo)){
		if(strcmp(Consulta.claveAlumno,ID) == 0){
			return Consulta.dirFis;
		}
		fread(&Consulta,sizeof(Index),1,Archivo);	
	}
	
	return 1000;
	fflush(Archivo);
	fclose(Archivo);
			
}


void eliminarAlumno(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb+");	
	
  	int DIR_FIS;
  	char ID[6];
  	Alumno Consulta;
  	
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	fflush(stdin);
	GOTOXY(10,13);cout<<"Digite el ID del alumno: ";	cin.getline(ID,10);
	DIR_FIS = Buscar_Index(ID);
	
	if(DIR_FIS != 1000){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
	
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Alumno),1,Archivo);
		
		strcpy(Consulta.nombre,"-------");
		strcpy(Consulta.primAp,"-------");
		strcpy(Consulta.secAp,"-------");
		strcpy(Consulta.domicilio,"-------");
		strcpy(Consulta.id,"-------");
		strcpy(Consulta.sexo,"-------");
		Consulta.claveCurso = 0;
		Consulta.edad = 0;
		Consulta.estatura = 0;
		Consulta.peso = 0;
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fwrite(&Consulta,sizeof(Alumno),1,Archivo);
		
		bajaIndex(ID);
		GOTOXY(10,15);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		GOTOXY(10,16);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
		GOTOXY(10,17);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		
	}else{
		cout<<"\nRegistro no encontrado"<<endl;
	}

	fflush(Archivo);
	fclose(Archivo);
}

void consultarAlumno(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb+");	
	char ID[10];
  	int DIR_FIS;
  	Alumno Consulta;
  	
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	fflush(stdin);
	GOTOXY(10,13);cout<<"Digite el ID del alumno: ";	cin.getline(ID,10);
	DIR_FIS = Buscar_Index(ID);
	
	if(DIR_FIS != 1000){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
	
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Alumno),1,Archivo);
		
		GOTOXY(10,15);cout<<"Nombre del Alumno: "<<Consulta.nombre<<" "<<Consulta.primAp<<" "<<Consulta.secAp<<endl;
		GOTOXY(10,17);cout<<"Domicilio: "<<Consulta.domicilio<<endl;
		GOTOXY(10,19);cout<<"Edad: "<<Consulta.edad<<endl;
		GOTOXY(10,21);cout<<"Estatura: "<<Consulta.estatura<<endl;
		GOTOXY(10,23);cout<<"Peso: "<<Consulta.peso<<endl;
		GOTOXY(10,25);cout<<"Sexo: "<<Consulta.sexo<<endl;
		GOTOXY(10,27);cout<<"Clave del curso: "<<Consulta.claveCurso<<endl;
		GOTOXY(10,29);cout<<"Clave del Alumno: "<<Consulta.id<<endl;
		cout<<endl<<endl;
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fwrite(&Consulta,sizeof(Alumno),1,Archivo);
	
		
	}else{
		cout<<"\nRegistro no encontrado"<<endl;
	}

	fflush(Archivo);
	fclose(Archivo);
}

void modificarAlumno(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb+");	
	int edad,curso;
	char ID[10];
	char Sexo[8];
	
  	int DIR_FIS;
  	Alumno Consulta;
  	
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	fflush(stdin);
	GOTOXY(10,13);cout<<"Digite el ID del alumno: ";	cin.getline(ID,10);
	DIR_FIS = Buscar_Index(ID);
	
	if(DIR_FIS != 1000){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
			system("cls");
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Alumno),1,Archivo);
		
			GOTOXY(10,1);cout<<"Ingrese los datos"<<endl;
			fflush(stdin);
			GOTOXY(10,3);cout<<"\n\t\tNombres: ";	cin.getline(Consulta.nombre,30);
			fflush(stdin);
			GOTOXY(10,5);cout<<"\n\t\tPrimer Apellido: ";	cin.getline(Consulta.primAp,15);
			fflush(stdin);
			GOTOXY(10,7);cout<<"\n\t\tSegundo Apellido: ";	cin.getline(Consulta.secAp,15);
			fflush(stdin);
			GOTOXY(10,9);cout<<"\n\t\tDomicilio: ";	cin.getline(Consulta.domicilio,50);
			GOTOXY(10,11);cout<<"\n\t\tEstatura: ";	cin>>Consulta.estatura;
			GOTOXY(10,13);cout<<"\n\t\tPeso: ";	cin>> Consulta.peso;
			do{
				system("cls");
				cout<<"Ingrese los siguientes datos a manera de que conisidan con el catalogo (la edad y el sexo deben coinsidir con el curso)"<<endl;
				if(menu_sexo() == 1){
					strcpy(Consulta.sexo,arraySexoM);
				}else{
					strcpy(Consulta.sexo,arraySexoH);
				}
				
				GOTOXY(10,9);cout<<"\n\t\tEdad: ";	cin>> Consulta.edad;
				GOTOXY(10,11);cout<<"\n\t\tClave del deporte: ";	cin>> Consulta.claveCurso;
			}while(comprobarCurso(Consulta.claveCurso,Consulta.edad,Consulta.sexo) == false || comprobarInstructor(Consulta.claveCurso) == false);	
			
		
		
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo		
		fwrite(&Consulta,sizeof(Alumno),1,Archivo);
		
	}else{
		cout<<"\nRegistro no encontrado"<<endl;
	}
		
		GOTOXY(10,13);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		GOTOXY(10,14);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
		GOTOXY(10,15);cout<<"--------------------------------------------------------------------------------------------------"<<endl;


	fflush(Archivo);
	fclose(Archivo);
}


/*
solounaclaveAlumno: que cada alumno tenga una clave unica
*/
bool solounaclaveAlumno(char clave[]){
	FILE* Archivo = fopen("Index.DIR","rb+");	
  	Index Consulta;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return false;
	}
	fread(&Consulta,sizeof(Index),1,Archivo);
	while(!feof(Archivo)){
		if(strcmp(Consulta.claveAlumno,clave) == 0){// son iguales
			return false;
		}
		fread(&Consulta,sizeof(Index),1,Archivo);	
	}
	return true;
	fflush(Archivo);
	fclose(Archivo);
}


/*
inicializar: permite recorrer el archivo de los alumnos desde el ?rea de desborde para retornar el valor
			 siguiente en el que se encuentra el ?ltimo dato de este modo los datos en colisi?n mantienen un orden incluso si se eliminan.
*/
int inicializarAlumno(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb");	
	char ID[30];
	Alumno Consulta;

	int DIR_FIS = 0;      //Una de las direcciones es 0
	int DIR_FIS1 = 100;		// Desde la zona de desborde 
	
	DIR_FIS = DIR_FIS1;
	DIR_FIS = DIR_FIS*sizeof(Consulta); //La posici?n real de acuerdo al tama?o del struct

	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Consulta,sizeof(Alumno),1,Archivo); //Comenzamos a leer el archivo
		
	while(!feof(Archivo)){
		if(strcmp(Consulta.id,"-------") == 0){	
			fclose(Archivo);
			return DIR_FIS1;
		}else{
			DIR_FIS1++; //Incrementa los valores de las posiciones para retornar la direcci?n f?sica en el ?rea de
						// desborde que no est? ocupada 
			fread(&Consulta,sizeof(Alumno),1,Archivo); //Brinca a la siguiente posici?n del archivo
		}
	}
}

/*
collision_detect: detecta cuando hay una colisi?n 
*/
bool collision_detect(char ID[],char F[]){
	if(F[0] == ID[2] && F[1] == ID[3] && F[2] == ID[4]){
		return true;
	}else{
		return false;
	}
}

/*
comprobarCurso: busca el curso que nos da el alumno para comprobar que existe. Busca dentro del
				archivo de Cursos para comprobar si existe el curso
				0:No existe el archivo
				1:
*/
/*
cargarIndex: Se cargan los 4 datos en el archivo index
*/
void cargarIndex(int dirFis, char claveAlumno[],char claveInstructor[], int claveCurso){
	FILE *archivoIndex;	
	archivoIndex = fopen("Index.DIR","ab");	
	Index Cargar;
	strcpy(Cargar.claveAlumno,claveAlumno);
	strcpy(Cargar.claveInstructor,claveInstructor);
	Cargar.dirFis = dirFis;
	Cargar.claveCurso = claveCurso;
	fwrite(&Cargar,sizeof(Index),1,archivoIndex);
	fflush(archivoIndex);
	fclose(archivoIndex);
}

/*
handleCollisionAlumno: hace el manejo de la colisi?n (llenado de los datos en caso de que haya colisi?n)
					   Escribiremos en 2 archivos,  
*/
void handleCollisionAlumno(char Nombres[],char Prim_Apellido[],char Seg_Apellido[],int Edad,float Estatura,float Peso,char Dom[],int Clave_Deporte,char ID[],int DIR_FIS,char Sexo[]){
	FILE *archivoAlumnos;	
	archivoAlumnos = fopen("Alumnos.DIR","rb+");	
	Alumno Cargar;
	
	char idInstructor[6];
	int DIRVAL = DIR_FIS;
	DIR_FIS = DIR_FIS*sizeof(Cargar);
	
	fseek(archivoAlumnos,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Alumno),1,archivoAlumnos);

	for(int i=0;i<=6;i++){ //ID
		Cargar.id[i]= ID[i];
	}
	for(int i=0; i<29; i++){ // Nombres
		Cargar.nombre[i]=toupper(Nombres[i]); 			
	}

	for(int i=0; i<14; i++){ // Primer Apellido			
		Cargar.primAp[i]=toupper(Prim_Apellido[i]);
	}

	for(int i=0; i<14; i++){ //Segundo Apellido
		Cargar.secAp[i]=toupper(Seg_Apellido[i]);		
	}
	
	for(int i=0; i<49; i++){ //Domicilio
		Cargar.domicilio[i]=toupper(Dom[i]);		
	}
	
	Cargar.edad = Edad; //Edad
	Cargar.estatura = Estatura; //Estatura
	Cargar.peso = Peso; //Peso
	for(int i=0; i<9; i++){ //Sexo
		Cargar.sexo[i]=toupper(Sexo[i]);		
	}
	Cargar.claveCurso = Clave_Deporte; //Clave del deporte 
	
	fseek(archivoAlumnos,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo Alumnos

	fwrite(&Cargar,sizeof(Alumno),1,archivoAlumnos); //Escribimos en el archivo Alumnos
	
/*
Con lo anterior podemos cargar ?nicamente los datos del alumno mas no se ha cargado al archivo ?ndex
Para cargar al archivo ?ndex es necesario obtener la clave del profesor que da el curso al que se quiere 
inscribir el alumno por lo tanto hacemos esa consulta con la funci?n buscarInstructor(claveCurso)
para esto enviamos la clave del curso que el instructor da
*/
	strcpy(idInstructor,arrayIdBusquedas); //Aqui copiamos el contendo de busqueda, que es el id del instructor
	cargarIndex(DIRVAL,ID,idInstructor,Clave_Deporte);	//mandamos los datos necesarios para cargar el index
	
	
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;

	fclose(archivoAlumnos);
}

/*
validar_numeros: Valida que la clave dada por el usuario este construida de la manera correcta  
*/
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

/*
Obtener_dir_fisica: obtiene la direccion fisica usando truncamiento y aritmetica modular con 101
*/
int Obtener_dir_fisica(char F[]){
	int DIR_FIS, aux=0;
	int DIR_FIS2;
	DIR_FIS = atoi(F);
	DIR_FIS = DIR_FIS%101;
	return DIR_FIS;
}

/*
Cargar_Alumno: carga los datos en el archivo de alumnos. En caso de haber una colision se pasa a handleCollisionAlumno
*/
void Cargar_Alumno(char Nombres[],char Prim_Apellido[],char Seg_Apellido[],int Edad,float Estatura,float Peso,char Dom[],int Clave_Deporte,char ID[],int DIR_FIS,char Sexo[]){
	FILE *Archivo;
	Archivo = fopen("Alumnos.DIR","rb+");	
	int op;
	int DIR_FIS2;
	char F[3];
	char idInstructor[6];
	int DIRVAL = DIR_FIS;
	Alumno Cargar;
	
	
	if(Archivo != NULL){
		
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		
		fread(&Cargar,sizeof(Alumno),1,Archivo);
		
		F[0] = Cargar.id[2];
		F[1] = Cargar.id[3];
		F[2] = Cargar.id[4];

		if(collision_detect(ID,F) == true){//Preguntamos si hay colision
			DIRVAL = inicializarAlumno(); // inicializamos DIRVAL(la nueva direccion)
			handleCollisionAlumno(Nombres,Prim_Apellido,Seg_Apellido,Edad,Estatura,Peso,Dom,Clave_Deporte,ID,DIRVAL,Sexo);
			return ;
		}else{
			for(int i=0;i<=6;i++){ //ID
				Cargar.id[i]= ID[i];
			}
			for(int i=0; i<29; i++){ // Nombres
				Cargar.nombre[i]=toupper(Nombres[i]); 			
			}
		
			for(int i=0; i<14; i++){ // Primer Apellido			
				Cargar.primAp[i]=toupper(Prim_Apellido[i]);
			}
		
			for(int i=0; i<14; i++){ //Segundo Apellido
				Cargar.secAp[i]=toupper(Seg_Apellido[i]);		
			}
			
			for(int i=0; i<49; i++){ //Domicilio
				Cargar.domicilio[i]=toupper(Dom[i]);		
			}
			
			Cargar.edad = Edad; //Edad
			Cargar.estatura = Estatura; //Estatura
			Cargar.peso = Peso; //Peso
			for(int i=0; i<9; i++){ //Sexo
				Cargar.sexo[i]=toupper(Sexo[i]);		
			}
			Cargar.claveCurso = Clave_Deporte; //Clave del deporte 
			
		}
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Alumno),1,Archivo);
		
/*
Con lo anterior podemos cargar ?nicamente los datos del alumno mas no se ha cargado al archivo ?ndex
Para cargar al archivo ?ndex es necesario obtener la clave del profesor que da el curso al que se quiere 
inscribir el alumno por lo tanto hacemos esa consulta con la funci?n buscarInstructor(claveCurso)
para esto enviamos la clave del curso que el instructor da
*/
	strcpy(idInstructor,arrayIdBusquedas); //Aqui copiamos el contendo de busqueda, que es el id del instructor
	cargarIndex(DIRVAL,ID,idInstructor,Clave_Deporte);	//mandamos los datos necesarios para cargar el index
	
		
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		cout<<"                           O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                    "<<endl;
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
	
}

/*
pedirDatosAlumno: pide los datos a los alumnos y valida que los datos sean correctos
*/
void pedirDatosAlumno(){

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
	int DIR_FIS;
	char F[3];
	char Sexo[8];

	GOTOXY(10,1);cout<<"Ingrese los datos"<<endl;
	fflush(stdin);
	GOTOXY(10,3);cout<<"\n\t\tNombres: ";	cin.getline(Nombres,30);
	fflush(stdin);
	GOTOXY(10,5);cout<<"\n\t\tPrimer Apellido: ";	cin.getline(Prim_Apellido,15);
	fflush(stdin);
	GOTOXY(10,7);cout<<"\n\t\tSegundo Apellido: ";	cin.getline(Seg_Apellido,15);
	fflush(stdin);
	GOTOXY(10,9);cout<<"\n\t\tDomicilio: ";	cin.getline(Dom,50);
	GOTOXY(10,11);cout<<"\n\t\tEstatura: ";	cin>>Estatura;
	GOTOXY(10,13);cout<<"\n\t\tPeso: ";	cin>> Peso;
	do{
		system("cls");
		cout<<"Ingrese los siguientes datos a manera de que conisidan con el catalogo (la edad y el sexo deben coinsidir con el curso)"<<endl;
		if(menu_sexo() == 1){
			strcpy(Sexo,arraySexoM);
		}else{
			strcpy(Sexo,arraySexoH);
		}
		
		GOTOXY(10,9);cout<<"\n\t\tEdad: ";	cin>> Edad;
		GOTOXY(10,11);cout<<"\n\t\tClave del deporte: ";	cin>> Clave_Deporte;
	}while(comprobarCurso(Clave_Deporte,Edad,Sexo) == false || comprobarInstructor(Clave_Deporte) == false);	
	
	//comprobarInstructor llena el arrayIdBusquedas el cual lo necesitaremos para cargar el index
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

	}while(validar_numeros(ID) == false  || solounaclaveAlumno(ID) == false );
	
	F[0] = ID[2];
	F[1] = ID[3];
	F[2] = ID[4];
	DIR_FIS = Obtener_dir_fisica(F);
	
	Cargar_Alumno(Nombres,Prim_Apellido,Seg_Apellido,Edad,Estatura,Peso,Dom,Clave_Deporte,ID,DIR_FIS,Sexo);

}




/*
=============================================================================================
						  C R U D     D E    I N S T R U C T O R E S
=============================================================================================
*/
void consultarArchivoAlumnos(){
	system("cls");
	FILE *Archivo;
	int r=3;
	Archivo = fopen("Alumnos.DIR","rb");
	Alumno Consulta;
	PintarCamposAlumnos();
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				escribirRegistrosAlumnos(Consulta,r);
				r+=2;
				cout<<endl<<endl;
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

void consultarArchivoInstructores(){
	system("cls");
	FILE *Archivo;
	Archivo = fopen("Instructores.DIR","rb");
	Instructor Consulta;
	int r=3;
	PintarCamposInstructores();
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Instructor),1,Archivo);
			while(!feof(Archivo)){
				escribirRegistrosInstructores(Consulta,r);
				r+=2;
				cout<<endl<<endl;
				fread(&Consulta,sizeof(Instructor),1,Archivo);
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}

/*
comprobarSoloCurso: Comprueba que el curso exista
*/
bool comprobarSoloCurso(int clave){
	FILE *archivoDep;	
	archivoDep = fopen("Cursos.DIR","rb");
	if(archivoDep == NULL){
		cout << "_______________________________________________________" << endl;
		cout << "|       EL ARCHIVO INSTRUCTORES NO SE ENCONTRO        | " << endl;
		cout << "|_____________________________________________________|" << endl;
		return false;
	}
	Curso Buscado;
	fread(&Buscado,sizeof(Curso),1,archivoDep);
	while(!feof(archivoDep)){
		if( Buscado.claveCurso == clave ){
			return true;
		}
		fread(&Buscado,sizeof(Curso),1,archivoDep);	
	}
	return false;
}

/*solounInstructorCurso: valida que un curso solo tenga un instructor*/
bool solounInstructorCurso(int claveCurso){
	FILE *archivoDep;
	archivoDep = fopen("Instructores.DIR","rb");
	Instructor Buscado;
	fread(&Buscado,sizeof(Instructor),1,archivoDep);
	while(!feof(archivoDep)){
		if( Buscado.claveCurso == claveCurso ){
			return true;
		}
		fread(&Buscado,sizeof(Instructor),1,archivoDep);	
	}
	return false;
}

/*solounaclaveInstructor: valida que no se repitan las claves de los instructores */
bool solounaclaveInstructor(char clave[]){
	FILE* Archivo = fopen("Instructores.DIR","rb+");	
  	Instructor Consulta;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return false;
	}
	fread(&Consulta,sizeof(Instructor),1,Archivo);
	while(!feof(Archivo)){
		if(strcmp(Consulta.id,clave) == 0){// son iguales
			return false;
		}
		fread(&Consulta,sizeof(Instructor),1,Archivo);	
	}
	return true;
	fflush(Archivo);
	fclose(Archivo);
}

/*bucarenInstructor: retorna la direccion fisica del instructor que el usuario este buscando
					 para eliminarlo o acutalizarlo*/
int bucarenInstructor(){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb+");	
	char claveInstructor[10];
  	Instructor Consulta;
  	int encontrado=0;

	fflush(stdin);
	GOTOXY(10,13);cout<<"Digite la clave del Instructor: "; cin.getline(claveInstructor,10);
	for(int i=0;i<=6;i++){ //ID
		claveInstructor[i]= toupper(claveInstructor[i]);
	}
	fread(&Consulta,sizeof(Instructor),1,Archivo);
	while(!feof(Archivo)){
		if(strcmp(Consulta.id,claveInstructor) == 0){// son iguales
			return encontrado;
		}
		encontrado++;
		fread(&Consulta,sizeof(Instructor),1,Archivo);	
	}
	return -1;
	fflush(Archivo);
	fclose(Archivo);
}

void eliminarInstructor(){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb+");	
	char claveInstructor[10];
  	int DIR_FIS;
  	Instructor Cargar;
  	int encontrado=0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	DIR_FIS = bucarenInstructor();
	if(DIR_FIS != -1){
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Cargar,sizeof(Instructor),1,Archivo);
		strcpy(Cargar.nombre,"-------");
		strcpy(Cargar.primAp,"-------");
		strcpy(Cargar.secAp,"-------");
		strcpy(Cargar.domicilio,"-------");
		strcpy(Cargar.id,"-------");
		strcpy(Cargar.correo,"-------");
		strcpy(Cargar.curp,"-------");
		strcpy(Cargar.rfc,"-------");
		strcpy(Cargar.telefono,"-------");
		Cargar.claveCurso = 0;
		Cargar.codigoPostal = 0;
		cout<<endl<<endl;
		fseek(Archivo,DIR_FIS,SEEK_SET);
		fwrite(&Cargar,sizeof(Instructor),1,Archivo);
		GOTOXY(10,15);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
			GOTOXY(10,16);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
			GOTOXY(10,17);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"No se encontro al Instructor"<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);

}

void consultarInstructor(){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb+");	
	char claveInstructor[10];
  	int DIR_FIS;
  	Instructor Consulta;
  	int encontrado=0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	DIR_FIS = bucarenInstructor();
	if(DIR_FIS != -1){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Instructor),1,Archivo);
		GOTOXY(10,15);cout<<"Nombre del instructor: "<<Consulta.nombre<<" "<<Consulta.primAp<<" "<<Consulta.secAp<<endl;
		GOTOXY(10,16);cout<<"Clave del Instructor: "<<Consulta.id<<endl;
		GOTOXY(10,17);cout<<"Domicilio: "<<Consulta.domicilio<<endl;
		GOTOXY(10,18);cout<<"RFC: "<<Consulta.rfc<<endl;
		GOTOXY(10,19);cout<<"CURP: "<<Consulta.curp<<endl;
		GOTOXY(10,20);cout<<"Correo: "<<Consulta.correo<<endl;
		GOTOXY(10,21);cout<<"Telefono: "<<Consulta.telefono<<endl;
		GOTOXY(10,22);cout<<"Codigo postal: "<<Consulta.codigoPostal<<endl;
		GOTOXY(10,23);cout<<"Clave del curso: "<<Consulta.claveCurso<<endl;
		cout<<endl<<endl;
	}else{
		cout<<"No se encontro al Instructor"<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
}

void modificarInstructor(){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb+");	
	char claveInstructor[10];
  	int DIR_FIS;
  	Instructor Consulta;
  	int encontrado=0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	DIR_FIS = bucarenInstructor();
	if(DIR_FIS != -1){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Instructor),1,Archivo);
		GOTOXY(10,15);cout<<"Ingrese los datos"<<endl;
		fflush(stdin);
		GOTOXY(10,16);cout<<"\n\t\tNombres: ";	cin.getline(Consulta.nombre,30);
		fflush(stdin);
		GOTOXY(10,17);cout<<"\n\t\tPrimer Apellido: ";	cin.getline(Consulta.primAp,15);
		fflush(stdin);
		GOTOXY(10,18);cout<<"\n\t\tSegundo Apellido: ";	cin.getline(Consulta.secAp,15);
		fflush(stdin);
		GOTOXY(10,19);	cout<<"\n\t\tDomicilio: ";	cin.getline(Consulta.domicilio,50);
		fflush(stdin);
		GOTOXY(10,20);cout<<"\n\t\tRFC: ";	cin.getline(Consulta.rfc,13);
		fflush(stdin);
		GOTOXY(10,21);cout<<"\n\t\tCurp: ";	cin.getline(Consulta.curp,50);
		fflush(stdin);
		GOTOXY(10,22);cout<<"\n\t\tCorreo: ";	cin.getline(Consulta.correo,50);
		fflush(stdin);
		GOTOXY(10,23);cout<<"\n\t\tTelefono: ";	cin.getline(Consulta.telefono,12);
		GOTOXY(10,24);cout<<"\n\t\tCodigo Postal: ";	cin>> Consulta.codigoPostal;
	
		system("cls");

		do{
			system("cls");
			cout<<"Asegurese de que el curso exista"<<endl;
			cout<<"\n\tClave del deporte: 	";	cin>> Consulta.claveCurso;
		}while(comprobarSoloCurso(Consulta.claveCurso) == false);		
		cout<<endl<<endl;

		fseek(Archivo,DIR_FIS,SEEK_SET);
		fwrite(&Consulta,sizeof(Instructor),1,Archivo);
		GOTOXY(10,9);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		GOTOXY(10,10);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
		GOTOXY(10,11);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"No se encontro al Instructor"<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);


}

/*bucarenInstructor: retorna la direccion fisica del instructor que el usuario este buscando
					 para eliminarlo o acutalizarlo*/
int bucarenInstructorCurso(int claveCurso){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb+");	
	char claveInstructor[10];
  	Instructor Consulta;
  	int encontrado=0;

	fread(&Consulta,sizeof(Instructor),1,Archivo);
	while(!feof(Archivo)){
		if(Consulta.claveCurso == claveCurso){// son iguales
			return encontrado;
		}
		encontrado++;
		fread(&Consulta,sizeof(Instructor),1,Archivo);	
	}
	return -1;
	fflush(Archivo);
	fclose(Archivo);
}

int inicializarInstructor(){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb");	
	char ID[30];
	Instructor Consulta;

	int DIR_FIS = 0;      //Una de las direcciones es 0
	int DIR_FIS1 = 100;		// Desde la zona de desborde 
	
	DIR_FIS = DIR_FIS1;
	DIR_FIS = DIR_FIS*sizeof(Consulta); //La posici?n real de acuerdo al tama?o del struct

	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Consulta,sizeof(Instructor),1,Archivo); //Comenzamos a leer el archivo
		
	while(!feof(Archivo)){
		if(strcmp(Consulta.id,"-------") == 0){	
			fclose(Archivo);
			return DIR_FIS1;
		}else{
			DIR_FIS1++; //Incrementa los valores de las posiciones para retornar la direcci?n f?sica en el ?rea de
						// desborde que no est? ocupada 
			fread(&Consulta,sizeof(Instructor),1,Archivo); //Brinca a la siguiente posici?n del archivo
		}
	}
}

void handleCollisionInstructor(char Nombres[],char Prim_Apellido[],char Seg_Apellido[], char dom[], char rfc[], char curp[], char correo[], char telef[], int CP, int claveC, int DIR_FIS,char ID[]){ //Agregue faltantes de instructor y quite ID 
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb+");	
	Instructor Cargar;
	
	char idInstructor[6];
	int DIRVAL = DIR_FIS;
	DIR_FIS = DIR_FIS*sizeof(Cargar);
	
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Instructor),1,Archivo);
	for(int i=0;i<=6;i++){ //ID
		Cargar.id[i]= ID[i];
	}
	
	for(int i=0; i<29; i++){ // Nombres
		Cargar.nombre[i]=toupper(Nombres[i]); 			
	}

	for(int i=0; i<19; i++){ // Primer Apellido			
		Cargar.primAp[i]=toupper(Prim_Apellido[i]);
	}

	for(int i=0; i<19; i++){ //Segundo Apellido
		Cargar.secAp[i]=toupper(Seg_Apellido[i]);		
	}
	for(int i=0; i<49; i++){ //Domicilio
		Cargar.domicilio[i]=toupper(dom[i]);		
	}
	
	for(int i=0; i<12; i++){ //rfc
		Cargar.rfc[i]=toupper(rfc[i]);		
	}
	
	for(int i=0; i<49; i++){ //curp
		Cargar.curp[i]=toupper(curp[i]);		
	}
	
	for(int i=0; i<49; i++){ //correo
		Cargar.correo[i]=toupper(correo[i]);		
	}
	
	for(int i=0; i<11; i++){ //correo
		Cargar.telefono[i]=toupper(telef[i]);		
	}
	
	
	Cargar.codigoPostal = CP; //codigo postal

	Cargar.claveCurso = claveC; //Clave del deporte 
	
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo Alumnos

	fwrite(&Cargar,sizeof(Instructor),1,Archivo); //Escribimos en el archivo Alumnos
	

	GOTOXY(10,14);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	GOTOXY(10,15);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
	GOTOXY(10,16);cout<<"--------------------------------------------------------------------------------------------------"<<endl;

	fclose(Archivo);
}

/*
repiteInstructor: si regresa un true significa que la clave del deporte ya ha sido asignada a otro instructor
					por lo tanto no se puede usar
*/
bool repiteInstructor(int claveVer){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb");
	if(Archivo == NULL){
		cout << "_______________________________________________________" << endl;
		cout << "|       EL ARCHIVO INSTRUCTORES NO SE ENCONTRO        | " << endl;
		cout << "|_____________________________________________________|" << endl;
		return false;
	}
	Instructor Buscado;
	fread(&Buscado,sizeof(Instructor),1,Archivo);
	while(!feof(Archivo)){
		if(Buscado.claveCurso == claveVer){
			fclose(Archivo);
			return true;
		}
		fread(&Buscado,sizeof(Instructor),1,Archivo);	
	}
	fclose(Archivo);
	return false;
}

void Cargar_Instructor(char Nombres[],char Prim_Apellido[],char Seg_Apellido[], char dom[], char rfc[], char curp[], char correo[], char telef[], int CP, int claveC,int DIR_FIS, char ID[]){  //Agregue los campos faltantes de instructor y le quite ID 
	FILE *Archivo;
	Archivo = fopen("Instructores.DIR","rb+");	
	int op;
	int DIR_FIS2;
	char F[3];
	char idInstructor[6];
	int DIRVAL = DIR_FIS;
	Instructor Cargar;
	
	if(Archivo != NULL){
		
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		
		fread(&Cargar,sizeof(Instructor),1,Archivo);
		
		F[0] = Cargar.id[2];
		F[1] = Cargar.id[3];
		F[2] = Cargar.id[4];

		if(collision_detect(ID,F) == true){//Preguntamos si hay colision
			DIRVAL = inicializarInstructor(); // inicializamos DIRVAL(la nueva direccion)
			handleCollisionInstructor(Nombres,Prim_Apellido,Seg_Apellido,dom,rfc,curp,correo,telef,CP,claveC,DIRVAL,ID);
			return ;
		}else{
			for(int i=0; i<29; i++){ // Nombres
				Cargar.id[i]=toupper(ID[i]); 			
			}
			
			for(int i=0; i<29; i++){ // Nombres
				Cargar.nombre[i]=toupper(Nombres[i]); 			
			}
		
			for(int i=0; i<19; i++){ // Primer Apellido			
				Cargar.primAp[i]=toupper(Prim_Apellido[i]);
			}
		
			for(int i=0; i<19; i++){ //Segundo Apellido
				Cargar.secAp[i]=toupper(Seg_Apellido[i]);		
			}
			
			for(int i=0; i<49; i++){ //Domicilio
				Cargar.domicilio[i]=toupper(dom[i]);		
			}
			
			for(int i=0; i<12; i++){ //rfc agregado 
				Cargar.rfc[i]=toupper(rfc[i]);		
			}
	
			for(int i=0; i<50; i++){ //curp agregado 
				Cargar.curp[i]=toupper(curp[i]);		
			}
	
			for(int i=0; i<49; i++){ //correo agregado 
				Cargar.correo[i]=toupper(correo[i]);		
			}
	
			for(int i=0; i<11; i++){ //telefono  agregado 
				Cargar.telefono[i]=toupper(telef[i]);		
			}
	
	
			Cargar.codigoPostal = CP; //codigo postal agregado 

			Cargar.claveCurso = claveC; //Clave del deporte  agregado 
		}
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Instructor),1,Archivo);
		

		GOTOXY(10,14);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		GOTOXY(10,15);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
		GOTOXY(10,16);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
}

void pedirInstructor(){
	system("cls");
	char Nombres[30];
	char Prim_Apellido[15];
	char Seg_Apellido[15];
	char dom[50];
	char rfc[13];
	char curp[50];
	char correo[50];
	char telef[12];
	int CP;
	//int claveC
	int Clave_Deporte;
	char ID[7];
	int DIR_FIS;
	char F[3];

	GOTOXY(10,2);cout<<"Ingrese los datos"<<endl;
	fflush(stdin);
	cout<<"\n\t\tNombres: ";	cin.getline(Nombres,30);
	fflush(stdin);
	cout<<"\n\t\tPrimer Apellido: ";	cin.getline(Prim_Apellido,15);
	fflush(stdin);
	cout<<"\n\t\tSegundo Apellido: ";	cin.getline(Seg_Apellido,15);
	fflush(stdin);
	cout<<"\n\t\tDomicilio: ";	cin.getline(dom,50);
	fflush(stdin);
	cout<<"\n\t\tRFC: ";	cin.getline(rfc,13);
	fflush(stdin);
	cout<<"\n\t\tCurp: ";	cin.getline(curp,50);
	fflush(stdin);
	cout<<"\n\t\tCorreo: ";	cin.getline(correo,50);
	fflush(stdin);
	cout<<"\n\t\tTelefono: ";	cin.getline(telef,12);
	
	cout<<"\n\t\tCodigo Postal: ";	cin>> CP;


	do{
		system("cls");
		cout<<"Asegurese de que el curso exista"<<endl;
		cout<<"\n\tClave del deporte: ";	cin>> Clave_Deporte;
	}while(comprobarSoloCurso(Clave_Deporte) == false || solounInstructorCurso(Clave_Deporte));	
	
	do{
		system("cls");
		cout<<"El ID debe ser de la siguiente manera"<<endl;
		cout<<"\nPA = Primer apellido"<<endl;
		cout<<"\nSA = Segundo apellido"<<endl;
		cout<<"\nNC = Numero de 3 digitos cualesquiera"<<endl;
		cout<<"\nG  = Sexo: Hombre(H) Mujer(M)"<<endl;
		cout<<"\nClave: (PA)(SA)(NC)(G) Sin espacios"<<endl;
		fflush(stdin);
		cout<<"\n\tID: ";	cin.getline(ID,20);
		for(int i=0; i<7; i++){			
			ID[i]=toupper(ID[i]);
		}

	}while(validar_numeros(ID) == false || solounaclaveInstructor(ID) == false);
	
	F[0] = ID[2];
	F[1] = ID[3];
	F[2] = ID[4];
	DIR_FIS = Obtener_dir_fisica(F);
	
			Cargar_Instructor(Nombres,Prim_Apellido,Seg_Apellido,dom,rfc,curp,correo,telef,CP,Clave_Deporte,DIR_FIS,ID);

}


/*
=============================================================================================
								C R U D     D E    C U R S O S 
=============================================================================================
*/


int quitarCursoInstructor(int claveCurso){
	FILE *Archivo;	
	Archivo = fopen("Instructores.DIR","rb+");	
	char claveInstructor[10];
  	int DIR_FIS;
  	Instructor Cargar;

	DIR_FIS = bucarenInstructorCurso(claveCurso);
	if(DIR_FIS != -1){
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Cargar,sizeof(Instructor),1,Archivo);
		
		Cargar.claveCurso = 0;

		cout<<endl<<endl;
		fseek(Archivo,DIR_FIS,SEEK_SET);
		fwrite(&Cargar,sizeof(Instructor),1,Archivo);
	}
	fflush(Archivo);
	fclose(Archivo);

}

int bucarenCurso(int claveCurso){
	FILE *Archivo;	
	Archivo = fopen("Cursos.DIR","rb+");	
  	Curso Consulta;
  	int encontrado=0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return -1;
	}
	fread(&Consulta,sizeof(Curso),1,Archivo);
	while(!feof(Archivo)){
		if(Consulta.claveCurso == claveCurso){// son iguales
			return encontrado;
		}
		encontrado++;
		fread(&Consulta,sizeof(Curso),1,Archivo);	
	}
	return -1;
	fflush(Archivo);
	fclose(Archivo);
}

void consultarArchivoCursos(){
	system("cls");
	FILE *Archivo;
	Archivo = fopen("Cursos.DIR","rb");
	Curso Consulta;
	int r=3;
  	PintarCamposCurso();
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Curso),1,Archivo);
			while(!feof(Archivo)){
				escribirRegistrosCurso(Consulta,r);
				r+=2;
				cout<<endl<<endl;
				fread(&Consulta,sizeof(Curso),1,Archivo);
				
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}

int Obtener_dir_fisica_Dep(int Clave_Deporte){
	
	int DIR_FIS;
	DIR_FIS = Clave_Deporte%31;
	return DIR_FIS;

}

void Cargar_Deporte(char Nombre[],char Categoria[],char Rango[],int Max,int Min,char Horario[], char Sexo[],int Clave_Deporte, int DIR_FIS){
	FILE *Archivo;
	Archivo = fopen("Cursos.DIR","rb+");	
	Curso Cargar;
	if(Archivo != NULL){
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Cargar,sizeof(Curso),1,Archivo);
		
			for(int i=0; i<29; i++){ 
				Cargar.nombreCurso[i]=toupper(Nombre[i]); 			
			}

			for(int i=0; i<19; i++){ 		
				Cargar.categoria[i]=toupper(Categoria[i]);
			}

			for(int i=0; i<14; i++){ 
				Cargar.rango[i]=toupper(Rango[i]);		
			}
			
			for(int i=0; i<7; i++){ 
				Cargar.sexo[i]=toupper(Sexo[i]);		
			}
			
			for(int i=0; i<49; i++){ 
				Cargar.horario[i]=toupper(Horario[i]);		
			}
			
			Cargar.max = Max; 
			Cargar.min = Min;
			Cargar.claveCurso = Clave_Deporte; 
			
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fwrite(&Cargar,sizeof(Curso),1,Archivo);
		
		GOTOXY(10,7);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		GOTOXY(10,8);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
		GOTOXY(10,9);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fclose(Archivo);
}

void pedirDatosCurso(){
	system("cls");
	char Nombre[30];
	char Categoria[15];
	char Rango[15];
	char Sexo[10];
	char Horario[50];
	int guardado=0;
	int Clave_Deporte;
	int Max;
	int Min;
	int DIR_FIS;
	
	int op;
	GOTOXY(10,2);cout<<"Ingrese los datos"<<endl;
	fflush(stdin);
	cout<<"\n\tNombre del deporte: ";	cin.getline(Nombre ,30);
	fflush(stdin);
	op = menu_categ();
	
	if (op == 1){
		strcpy(Categoria,arrayCatA);
		cout<<Categoria<<endl;
		Min = 13;
		Max = 17;
		
	}else if(op == 2){
		strcpy(Categoria,arrayCatJ);
		cout<<Categoria<<endl;
		Min = 18;
		Max = 35;
		
	}else{ 
		strcpy(Categoria,arrayCatVet);
		cout<<Categoria<<endl;
		Min = 36;
		Max = 50;
		
	}
	do{
	int op = categHorario();
	switch(op){
		case 1:
			strcpy(Horario, arrayHorario1);
			guardado = 1;
		break;
		
		case 2:
			strcpy(Horario, arrayHorario2);
			guardado = 1;
		break;
		
		case 3:
			strcpy(Horario, arrayHorario3);
			guardado = 1;
		break;
		
		case 4:
			strcpy(Horario, arrayHorario4);
			guardado = 1;
		break;
		
		default:
			cout<<"\n\tElige una opcion correcta";
		break;
	}
	}while(guardado==0);
	
	system("cls");
	
	if(menu_sexo() == 1){
		strcpy(Sexo,arraySexoM);
	}else{
		strcpy(Sexo,arraySexoH);
	}

	if(menu_rango() == 1){
		strcpy(Rango,arrayRangP);
	}else{
		strcpy(Rango,arrayRangA);
	}
	
	do{
		system("cls");
		GOTOXY(10,2);cout<<"Digite la clave de un curso existente"<<endl;
		cout<<"\n\tClave (4 digitos): ";	cin>>Clave_Deporte;
	}while(Clave_Deporte < 999 || Clave_Deporte > 10000);
	
	
	DIR_FIS = Obtener_dir_fisica_Dep(Clave_Deporte);
	
	Cargar_Deporte(Nombre,Categoria,Rango,Max,Min,Horario, Sexo,Clave_Deporte,DIR_FIS);

}


/* contarBajaCurso:Cuenta el numero de alumnos en un curso, para sabes si se puede dar 
de baja el curso, el numero que retorna debe ser cero */
int contarBajaCurso(int claveCurso){
	FILE *Archivo;	
	Archivo = fopen("Index.DIR","rb+");	
  	Index Consulta;
  	int encontrado=0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return -1;
	}
	fread(&Consulta,sizeof(Index),1,Archivo);
	while(!feof(Archivo)){
		if(Consulta.claveCurso == claveCurso){// son iguales
			encontrado++;
		}
		fread(&Consulta,sizeof(Index),1,Archivo);	
	}
	return encontrado;
	fflush(Archivo);
	fclose(Archivo);
}

void eliminarCurso(){
	FILE *Archivo;	
	Archivo = fopen("Cursos.DIR","rb+");	
  	Curso Cargar;
  	int DIR_FIS;
  	int claveCurso;
  	int numdeAlu;
  	int encontrado=0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	GOTOXY(10,13);cout<<"Digite la clave del curso: "; cin>>claveCurso;
	numdeAlu = contarBajaCurso(claveCurso);
	
	if(numdeAlu == 0){//Significa que que no tiene alumnos por o tanto si se puede eliminar
		DIR_FIS = bucarenCurso(claveCurso);
		if(DIR_FIS != -1){
			DIR_FIS = DIR_FIS*sizeof(Cargar);
			fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
			fread(&Cargar,sizeof(Curso),1,Archivo);
			strcpy(Cargar.nombreCurso,"-------");
			strcpy(Cargar.categoria,"-------");
			strcpy(Cargar.sexo,"-------");
			strcpy(Cargar.rango,"-------");
			strcpy(Cargar.horario,"-------");
			Cargar.claveCurso = 0;
			Cargar.max = 0;
			Cargar.min = 0;
			cout<<endl<<endl;
			cout<<endl<<endl;
			fseek(Archivo,DIR_FIS,SEEK_SET);
			fwrite(&Cargar,sizeof(Curso),1,Archivo);
			quitarCursoInstructor(claveCurso);
			GOTOXY(10,15);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
			GOTOXY(10,16);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
			GOTOXY(10,17);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		}else{
			cout<<"No se encontro al Curso"<<endl;
		}
	}else{
		cout<<"No se puede eliminar el curso puesto que cuenta con ["<< numdeAlu <<"] alumnos ingresados"<<endl;
		cout<<"Debe eliminarlos primero"<<endl;
	}
	
	fflush(Archivo);
	fclose(Archivo);
	

}

void consultarCurso(){
	FILE *Archivo;	
	Archivo = fopen("Cursos.DIR","rb+");	
  	Curso Consulta;
  	int claveCurso;
  	int DIR_FIS = 0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	GOTOXY(10,13);cout<<"Digite la clave del curso: "; cin>>claveCurso;
	DIR_FIS = bucarenCurso(claveCurso);
	if(DIR_FIS != -1){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Curso),1,Archivo);
		GOTOXY(10,15);cout<<"Nombre del curso: "<<Consulta.nombreCurso<<endl;
		GOTOXY(10,16);cout<<"Categoria del curso: "<<Consulta.categoria<<endl;
		GOTOXY(10,17);cout<<"Rago del curso: "<<Consulta.rango<<endl;
		GOTOXY(10,18);cout<<"Horario del curso: "<<Consulta.horario<<endl;
		GOTOXY(10,19);cout<<"Sexo para el curso: "<<Consulta.sexo<<endl;
		GOTOXY(10,20);cout<<"Edad maxima: "<<Consulta.max<<endl;
		GOTOXY(10,21);cout<<"Edad minima: "<<Consulta.min<<endl;
		GOTOXY(10,22);cout<<"Clave del curso: "<<Consulta.claveCurso<<endl;
		cout<<endl<<endl;
	}else{
		cout<<"No se encontro al Curso"<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
	

}

void modificarCurso(){
	FILE *Archivo;	
	Archivo = fopen("Cursos.DIR","rb+");	
  	Curso Consulta;
  	int claveCurso;
  	int guardado = 0;
  	int DIR_FIS = 0;
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	GOTOXY(10,13);cout<<"Digite la clave del curso: "; cin>>claveCurso;
	DIR_FIS = bucarenCurso(claveCurso);
	if(DIR_FIS != -1){
		system("cls");
		DIR_FIS = DIR_FIS*sizeof(Consulta);
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Curso),1,Archivo);
		GOTOXY(10,2);cout<<"Ingrese los datos"<<endl;
		fflush(stdin);
		GOTOXY(10,4);cout<<"\n\tNombre del Curso: ";	cin.getline(Consulta.nombreCurso ,30);
		fflush(stdin);
		int op = menu_categ();
		
		if (op == 1){
			strcpy(Consulta.categoria,arrayCatA);
			Consulta.min = 13;
			Consulta.max = 17;
			
		}else if(op == 2){
			strcpy(Consulta.categoria,arrayCatJ);
			Consulta.min = 18;
			Consulta.max = 35;
			
		}else{ 
			strcpy(Consulta.categoria,arrayCatVet);
			Consulta.min = 36;
			Consulta.max = 50;
			
		}
		do{
		int op = categHorario();
		switch(op){
			case 1:
				strcpy(Consulta.horario, arrayHorario1);
				guardado = 1;
			break;
			
			case 2:
				strcpy(Consulta.horario, arrayHorario2);
				guardado = 1;
			break;
			
			case 3:
				strcpy(Consulta.horario, arrayHorario3);
				guardado = 1;
			break;
			
			case 4:
				strcpy(Consulta.horario, arrayHorario4);
				guardado = 1;
			break;
			
			default:
				cout<<"\n\tElige una opcion correcta";
			break;
		}
		}while(guardado==0);
		
		system("cls");
		
		if(menu_sexo() == 1){
			strcpy(Consulta.sexo,arraySexoM);
		}else{
			strcpy(Consulta.sexo,arraySexoH);
		}
	
		if(menu_rango() == 1){
			strcpy(Consulta.rango,arrayRangP);
		}else{
			strcpy(Consulta.rango,arrayRangA);
		}
		fseek(Archivo,DIR_FIS,SEEK_SET);
		fwrite(&Consulta,sizeof(Curso),1,Archivo);
		GOTOXY(10,9);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		GOTOXY(10,10);cout<<"                          O  P  E  R  A  C  I  O  N       E  X  I  T  O  S  A                     "<<endl;
		GOTOXY(10,11);cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"No se encontro al Curso"<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
	
	
}


