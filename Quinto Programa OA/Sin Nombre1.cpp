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
	int DIR_FIS;
};


typedef struct {
	int Clave;
	char NombreDep[15];
	char Categoria[20];
	char Rango[10];
}Deporte;

typedef struct Index{
	int DIR_FIS;
	char ID[6];

};

long int dir_fisica;

void GOTOXY(int x, int y){ //Ancho=80  ,  Alto=25

        HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon,dwPos);
}

int MENU_PRINCIPAL(){
	system("cls");
	int opc;
    GOTOXY(25,1);cout << "_______________________________________________________" << endl;
    GOTOXY(25,2);cout << "|          A R C H I V O S    A L U M N O S           | " << endl;
    GOTOXY(25,3);cout << "|_____________________________________________________| " << endl;
    GOTOXY(25,4);cout << "|                 [1] Insertar alumno                 | " << endl;
    GOTOXY(25,5);cout << "|                 [2] Mostrar Lista                   | " << endl;
    GOTOXY(25,6);cout << "|                 [3] Consulta alumno                 | " << endl;
    GOTOXY(25,7);cout << "|                 [4] Baja Logica                     | " << endl;
    GOTOXY(25,8);cout << "|                 [5] Modificar alumno                | " << endl;
    GOTOXY(25,9);cout << "|                 [6] Tabla                           | " << endl;
    GOTOXY(25,10);cout << "|                 [7] Insertar alumno                 | " << endl;
    GOTOXY(25,11);cout << "|_____________________________________________________|" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

void Crear_Archivo_Alumnos(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.DIR","wb");
	Alumno Cargar;
	int DIR_FIS = 0;
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Alumno),1,Archivo);
	for(int i=0;i<120;i++){
		DIR_FIS = i;
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		strcpy(Cargar.Nombre,"-------");
		strcpy(Cargar.AP,"-------");
		strcpy(Cargar.AM,"-------");
		strcpy(Cargar.Domicilio,"-------");
		strcpy(Cargar.ID,"-------");
		Cargar.Deporte = 0;
		Cargar.Edad = 0;
		Cargar.Estatura = 0;
		Cargar.Peso = 0;
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Alumno),1,Archivo);	
	}
	cout << "_______________________________________________________" << endl;
    cout << "|            A R C H I V O  A L U M N O S             | " << endl;
    cout << "|                     C R E A D O                     | " << endl;
    cout << "|_____________________________________________________|" << endl;
	fclose(Archivo);
}

void Crear_Archivo_Deportes(){
	FILE *Archivo;
	Archivo = fopen("Deportes.DIR","wb");
	
	cout << "_______________________________________________________" << endl;
    cout << "|           A R C H I V O  D E P O R T E S            | " << endl;
    cout << "|                    C R E A D O                      | " << endl;
    cout << "|_____________________________________________________|" << endl;
	fclose(Archivo);
}

void Crear_Lista_Index(){
	FILE *Archivo;
	Archivo = fopen("Index.DIR","wb");
	fclose(Archivo);
}

int Menu_Crear_Archivos(){
	system("cls");
	int opc;
	GOTOXY(40,1);cout << "--------------------------------" << endl;
    GOTOXY(40,2);cout << "|           Archivos           | " << endl;
	GOTOXY(40,3);cout << "|    1.-  Alumnos              | " << endl;
    GOTOXY(40,4);cout << "|    2.-  Deportes             | " << endl;
    GOTOXY(40,5);cout << "|    3.-  Cargar documento     | " << endl;
    GOTOXY(40,6);cout << "|    4.-  Index                | " << endl;
    GOTOXY(40,7);cout <<"--------------------------------" << endl;
    cout<<"Selecione el archivo que desea crear: ";	cin>>opc;
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
    GOTOXY(40,6);cout << "|    4.-  Lista   Ordenado     | " << endl;
    GOTOXY(40,7);cout << "|    5.-  Salir                | " << endl;
    GOTOXY(40,8);cout <<"--------------------------------" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

int Obtener_dir_fisica(char F[]){
	int DIR_FIS, aux=0;
	int DIR_FIS2;
	DIR_FIS = atoi(F);
	DIR_FIS = DIR_FIS%101;
	return DIR_FIS;
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

void Cargar_Index(char ID[],int DIR_FIS);

void Ordenar_Lista();

bool collision_detect(char ID[],char F[]){
	if(F[0] == ID[2] && F[1] == ID[3] && F[2] == ID[4]){
		return true;
	}else{
		return false;
	}
}

void Addposition();	

int inicializar(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb");	
	char ID[30];
	Alumno Consulta;

	int DIR_FIS = 0;
	int DIR_FIS1 = 100;
	
	//DIR_FIS1 = Obtener_dir_fisica(F);
	DIR_FIS = DIR_FIS1;
	DIR_FIS = DIR_FIS*sizeof(Consulta);

	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Consulta,sizeof(Alumno),1,Archivo);
	
	while(!feof(Archivo)){
		if(strcmp(Consulta.ID,"-------") == 0){	
			fclose(Archivo);
			return DIR_FIS1;
		}else{
			DIR_FIS1++;
			fread(&Consulta,sizeof(Alumno),1,Archivo);
		}
	}
	

	

}

void Addposition(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.DIR","ab");
	Alumno Cargar;
	fread(&Cargar,sizeof(Alumno),1,Archivo);
	
	strcpy(Cargar.Nombre,"-------");
	strcpy(Cargar.AP,"-------");
	strcpy(Cargar.AM,"-------");
	strcpy(Cargar.Domicilio,"-------");
	strcpy(Cargar.ID,"-------");
	Cargar.Deporte = 0;
	Cargar.Edad = 0;
	Cargar.Estatura = 0;
	Cargar.Peso = 0;
			
	fwrite(&Cargar,sizeof(Alumno),1,Archivo);
	fclose(Archivo);
}

void handle_collision(char Nombres[],char Prim_Apellido[],char Seg_Apellido[],int Edad,float Estatura,float Peso,char Dom[],int Clave_Deporte,char ID[],int DIR_FIS){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb+");	
	Alumno Cargar;
	int DIRVAL = DIR_FIS;
	DIR_FIS = DIR_FIS*sizeof(Cargar);
	
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Alumno),1,Archivo);

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
	
	Cargar.DIR_FIS = DIRVAL;
	
	for(int i=0; i<49; i++){ //Domicilio
		Cargar.Domicilio[i]=toupper(Dom[i]);		
	}
	
	Cargar.Deporte = Clave_Deporte; //Clave del deporte 

	for(int i=0;i<=6;i++){ //ID
		Cargar.ID[i]= ID[i];
	}
	
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
			
	fwrite(&Cargar,sizeof(Alumno),1,Archivo);
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;


	fclose(Archivo);
	
}

void Cargar_Index(char ID[],int DIR_FIS);
/*
void Ordenar_Lista_colision(char ID[],int DIR_FIS){
	FILE *Archivo;
	Crear_Lista_Index();
	Archivo = fopen("Alumnos.DIR","rb");
	Alumno Consulta;
	

	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				if(strcmp(Consulta.ID,"-------")!=0){		
					Cargar_Index(ID,DIR_FIS);
				}
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
*/
void Cargar_Alumno(char Nombres[],char Prim_Apellido[],char Seg_Apellido[],int Edad,float Estatura,float Peso,char Dom[],int Clave_Deporte,char ID[],int DIR_FIS){
	FILE *Archivo;
	Archivo = fopen("Alumnos.DIR","rb+");	
	int op;
	int DIR_FIS2;
	char F[3];
	int DIRVAL = 0;
	Alumno Cargar;
	
	DIRVAL = DIR_FIS;
	
	if(Archivo != NULL){
		
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		
		fread(&Cargar,sizeof(Alumno),1,Archivo);
		
		F[0] = Cargar.ID[2];
		F[1] = Cargar.ID[3];
		F[2] = Cargar.ID[4];

		if(collision_detect(ID,F)==true){
			DIRVAL = inicializar();
			handle_collision(Nombres,Prim_Apellido,Seg_Apellido,Edad,Estatura,Peso,Dom,Clave_Deporte,ID,DIRVAL);
			return ;
		}else{
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
			
			Cargar.DIR_FIS = DIRVAL;
			
			for(int i=0; i<49; i++){ //Domicilio
				Cargar.Domicilio[i]=toupper(Dom[i]);		
			}
			
			Cargar.Deporte = Clave_Deporte; //Clave del deporte 
		
			for(int i=0;i<=6;i++){ //ID
				Cargar.ID[i]= ID[i];
			}
		}
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Alumno),1,Archivo);
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
	
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
	int DIR_FIS;
	char F[3];

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
	cout<<"\n\tClave del deporte: 	";	cin>> Clave_Deporte;
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
	
	F[0] = ID[2];
	F[1] = ID[3];
	F[2] = ID[4];
	DIR_FIS = Obtener_dir_fisica(F);
	
	Cargar_Alumno(Nombres,Prim_Apellido,Seg_Apellido,Edad,Estatura,Peso,Dom,Clave_Deporte,ID,DIR_FIS);

}

void Pintar(int a){
	int i=1;
	switch(a){
		case 1:
			printf("\n%c", 204);
		break;
		case 0:
			printf("%c", 201);
		break;
		default:
			printf("%c", 200);
		break;	
	}
	while(i<150){
		if(i%15==0){
			if(a == 1){
				printf("%c", 206);
			}else if(a==0){
				printf("%c", 203);
			}else{
				printf("%c", 202);
			}
		}else{
			printf("%c", 205);
		}
		i++;
	}
	if(a == 1){
		printf("%c\n", 185);
	}else if(a==0){
		printf("%c\n", 187);
	}else{
		printf("%c\n", 188);
	}
}

void PintarCampos(){
	Pintar(0);
	printf("%c    DIRECCION %c     ID       %c     NOMBRE   %cP. APPELLIDO  %cS. APELLIDO   %cEDAD\t  %cESTATURA\t %cPESO\t        %cDOMICILIO     %cDEPORTE       %c", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186,186);
	Pintar(1);
	fflush(stdin);
}

void escribirRegistros(Alumno Consulta, int r,int i){
	fflush(stdin);
	GOTOXY(0, r);
    printf("%c", 186);
	GOTOXY(1, r);
    printf("%i", i);
	
    GOTOXY(15, r);
    printf("%c", 186);

    GOTOXY(16, r);
    printf("%s", Consulta.ID);
	

    GOTOXY(30,r);
    printf("%c", 186);

    GOTOXY(31, r);
    printf("%s", Consulta.Nombre);
	

    GOTOXY(45, r);
    printf("%c", 186);
    GOTOXY(46, r);
    printf("%s", Consulta.AP);
	
    GOTOXY(60, r);
    printf("%c", 186);
    GOTOXY(61, r);
    printf("%s", Consulta.AM);

    GOTOXY(75, r);
    printf("%c", 186);
    GOTOXY(76, r);
   	printf("%i",Consulta.Edad);
	
    GOTOXY(90, r);
    printf("%c", 186);
    GOTOXY(91, r);
    printf("%.2f", Consulta.Estatura);
	
    GOTOXY(105, r);
    printf("%c", 186);
    GOTOXY(106, r);
    printf("%0.2f", Consulta.Peso);
	
    GOTOXY(120, r);
    printf("%c", 186);
    printf("%s", Consulta.Domicilio);
	
    GOTOXY(135, r);
    printf("%c", 186);
    printf("%i",Consulta.Deporte);
    
    GOTOXY(150, r);
    printf("%c", 186);
    Pintar(1);
}

void Consultar_Archivo_Alumnos(){
	system("cls");
	FILE *Archivo;
	Archivo = fopen("Alumnos.DIR","rb");
	Alumno Consulta;
	int i=0;
	int r=3;
	PintarCampos();
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				escribirRegistros(Consulta, r,i);
				r+=2;
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

void Cargar_Index(char ID[],int DIR_FIS);

int Buscar_Index(){
	FILE* Archivo;
	Archivo = fopen("Index.DIR","rb");
	char ID[10];
	Index Consulta;
	
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    return 1000;
	}
	fflush(stdin);
	cout<<"Digite el ID: ";	cin.getline(ID,10);
	for(int i=0; i<10; i++){	
		ID[i]=toupper(ID[i]); 			
	}
	fread(&Consulta,sizeof(Index),1,Archivo);
	while(!feof(Archivo)){
		if(strcmp(Consulta.ID,ID) == 0){
			return Consulta.DIR_FIS;
		}
		fread(&Consulta,sizeof(Index),1,Archivo);	
	}
	
	return 1000;
			
}

void Cargar_Archio_Binario(){
	FILE *Archivo2;	
	Archivo2 = fopen("Archivo_Ordenado.dat","rb+");	
	int DIR_FIS;
	char F[3];
	Alumno Consulta;
	if(Archivo2 != NULL){
		if(ftell(Archivo2) == 0){
			fread(&Consulta,sizeof(Alumno),1,Archivo2);
			while(!feof(Archivo2)){
				F[0] = Consulta.ID[2];
				F[1] = Consulta.ID[3];
				F[2] = Consulta.ID[4];
				DIR_FIS = Obtener_dir_fisica(F);
				
				Cargar_Alumno(Consulta.Nombre,Consulta.AP,Consulta.AM,
								Consulta.Edad,Consulta.Estatura,Consulta.Peso,
								Consulta.Domicilio,Consulta.Deporte,Consulta.ID,DIR_FIS);
				
				fread(&Consulta,sizeof(Alumno),1,Archivo2);
				
				
			}
		}else{
			cout<<"Archivo vacio"<<endl;
		}
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo2);
		
}




void Baja_Logica(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb+");	
	
  	int DIR_FIS;
  	Alumno Cargar;
  	
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	
	DIR_FIS = Buscar_Index();
	
	if(DIR_FIS != 1000){
		DIR_FIS = DIR_FIS*sizeof(Cargar);
	
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Cargar,sizeof(Alumno),1,Archivo);
		
		strcpy(Cargar.Nombre,"-------");
		strcpy(Cargar.AP,"-------");
		strcpy(Cargar.AM,"-------");
		strcpy(Cargar.Domicilio,"-------");
		strcpy(Cargar.ID,"-------");
		Cargar.Deporte = 0;
		Cargar.Edad = 0;
		Cargar.Estatura = 0;
		Cargar.Peso = 0;
		Cargar.DIR_FIS = 0;
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fwrite(&Cargar,sizeof(Alumno),1,Archivo);
		
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;

		
	}else{
		cout<<"\nRegistro no encontrado"<<endl;
	}

	fflush(Archivo);
	fclose(Archivo);
}

void Consultar_Alumno(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb+");	
	
  	int DIR_FIS;
  	Alumno Consulta;
  	
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	
	DIR_FIS = Buscar_Index();
	
	if(DIR_FIS != 1000){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
	
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Alumno),1,Archivo);
		
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"Nombre:"<<Consulta.Nombre<<" "<<Consulta.AP<<" "<<Consulta.AM<<endl;
		cout<<"Edad: "<<Consulta.Edad<<endl;
		cout<<"Estatura: "<<Consulta.Estatura<<endl;
		cout<<"Peso: "<<Consulta.Peso<<endl;
		cout<<"Domicilio: "<<Consulta.Domicilio<<endl;
		cout<<"Clave del deporte: "<<Consulta.Deporte<<endl;
		cout<<"ID: "<<Consulta.ID<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		
	}else{
		cout<<"\nRegistro no encontrado"<<endl;
	}

	fclose(Archivo);
}

void Modificar(){
	FILE *Archivo;	
	Archivo = fopen("Alumnos.DIR","rb+");	
	
  	int DIR_FIS;
  	Alumno Consulta;
  	
	if(Archivo == NULL){
	    cout << "\n\n\n\rNo existe el archivo !!!";
	    cout << "\n\r<<< Oprima cualquier tecla para continuar >>>";
	    getch();
	    return;
	}
	
	DIR_FIS = Buscar_Index();
	
	if(DIR_FIS != 1000){
		DIR_FIS = DIR_FIS*sizeof(Consulta);
	
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		fread(&Consulta,sizeof(Alumno),1,Archivo);
		
		cout<<"Ingrese los datos"<<endl;
		fflush(stdin);
		cout<<"\n\tNombres: 			";	cin.getline(Consulta.Nombre,30);
		fflush(stdin);
		cout<<"\n\tPrimer Apellido: 	";	cin.getline(Consulta.AP,15);
		fflush(stdin);
		cout<<"\n\tSegundo Apellido: 	";	cin.getline(Consulta.AM,15);
		cout<<"\n\tEdad:				";	cin>>Consulta.Edad;
		cout<<"\n\tEstatura: 			";	cin>>Consulta.Estatura;
		cout<<"\n\tPeso: 				";	cin>> Consulta.Peso;
		fflush(stdin);
		cout<<"\n\tDomicilio: 			";	cin.getline(Consulta.Domicilio,50);
		cout<<"\n\tClave del deporte: 	";	cin>> Consulta.Deporte;
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo		
		fwrite(&Consulta,sizeof(Alumno),1,Archivo);
		
	}else{
		cout<<"\nRegistro no encontrado"<<endl;
	}
		
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;


	fflush(Archivo);
	fclose(Archivo);
}

void Pintar2(int a){
	int i=1;
	switch(a){
		case 1:
			printf("\n%c", 204);
		break;
		case 0:
			printf("%c", 201);
		break;
		default:
			printf("%c", 200);
		break;	
	}
	while(i<30){
		if(i%15==0){
			if(a == 1){
				printf("%c", 206);
			}else if(a==0){
				printf("%c", 203);
			}else{
				printf("%c", 202);
			}
		}else{
			printf("%c", 205);
		}
		i++;
	}
	if(a == 1){
		printf("%c\n", 185);
	}else if(a==0){
		printf("%c\n", 187);
	}else{
		printf("%c\n", 188);
	}
}

void PintarCampos2(){
	Pintar2(0);
	printf("%c    DIRECCION %c     ID       %c    ",186, 186,186);
	Pintar2(1);
	fflush(stdin);
}

void escribirRegistros2(Index Consulta, int r,int i){


	fflush(stdin);
	GOTOXY(0, r);
    printf("%c", 186);
	GOTOXY(1, r);
    printf("%i", Consulta.DIR_FIS);
	
    GOTOXY(15, r);
    printf("%c", 186);

    GOTOXY(16, r);
    printf("%s", Consulta.ID);
	
	GOTOXY(30, r);
    printf("%c", 186);
    Pintar2(1);
}

void Ordenar_Lista(){
	FILE *Archivo;
	Crear_Lista_Index();
	Archivo = fopen("Alumnos.DIR","rb");
	Alumno Consulta;

	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Alumno),1,Archivo);
			while(!feof(Archivo)){
				if(strcmp(Consulta.ID,"-------")!=0){
						
					Cargar_Index(Consulta.ID,Consulta.DIR_FIS);
					
				}
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

void Cargar_Index(char ID[],int DIR_FIS){
	FILE *Archivo;
	Archivo = fopen("Index.DIR","ab");	
	
	Index CargarIndex;
	
	if(Archivo != NULL){
		fread(&CargarIndex,sizeof(Index),1,Archivo);
		for(int i=0;i<=6;i++){ //ID
			CargarIndex.ID[i]= ID[i];
		}

		CargarIndex.DIR_FIS = DIR_FIS;

		fwrite(&CargarIndex,sizeof(Index),1,Archivo);
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
}

void Crear_Listado(){
	system("cls");
	FILE *Archivo;
	Archivo = fopen("Index.DIR","rb");
	Index Consulta;
	int i=0;
	int r=3;
	PintarCampos2();
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Index),1,Archivo);
			while(!feof(Archivo)){
				escribirRegistros2(Consulta, r,i);
				r+=2;
				i++;
				cout<<endl;
				
				fread(&Consulta,sizeof(Index),1,Archivo);
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
		Ordenar_Lista();
		op = Menu_Archivos();
		switch(op){
			case 1:
				//Alumnos
				do{
					Ordenar_Lista();
					op = MENU_PRINCIPAL();
					switch(op){
						case 1:
							Pedir_Los_Datos_del_Alumno();

							system("pause");
							break;
						case 2:
							Consultar_Archivo_Alumnos();
							system("pause");
							cout<<endl;
							break;
						case 3:
							Consultar_Alumno();
							system("pause");
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
							Crear_Listado();
							cout<<endl;
							system("pause");
							break;
							
					}
				}while(op != 7);
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
						case 3: Cargar_Archio_Binario();
							system("pause");
								break;
						case 4: Crear_Lista_Index(); 
							system("pause");
							break;
							
					}
				}while(op != 5);
				break;
				
			case 4:
				Ordenar_Lista();
				system("pause");
				break;
		}
	}while(op != 6);
	return 0;
}


