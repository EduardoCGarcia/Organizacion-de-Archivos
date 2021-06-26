//=====================================================
//						Alumnos
//=====================================================

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

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

bool collision_detect(char ID[],char F[]){
	if(F[0] == ID[2] && F[1] == ID[3] && F[2] == ID[4]){
		return true;
	}else{
		return false;
	}
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
		for(int i=0; i<29; i++){ // Nombres
			Consulta.Nombre[i]=toupper(Consulta.Nombre[i]); 			
		}
		fflush(stdin);
		cout<<"\n\tPrimer Apellido: 	";	cin.getline(Consulta.AP,15);
		for(int i=0; i<14; i++){ // Nombres
			Consulta.AP[i]=toupper(Consulta.AP[i]); 			
		}
		fflush(stdin);
		cout<<"\n\tSegundo Apellido: 	";	cin.getline(Consulta.AM,15);
		for(int i=0; i<14; i++){ // Nombres
			Consulta.AM[i]=toupper(Consulta.AM[i]); 			
		}
		cout<<"\n\tEdad:				";	cin>>Consulta.Edad;
		cout<<"\n\tEstatura: 			";	cin>>Consulta.Estatura;
		cout<<"\n\tPeso: 				";	cin>> Consulta.Peso;
		fflush(stdin);
		cout<<"\n\tDomicilio: 			";	cin.getline(Consulta.Domicilio,50);
		for(int i=0; i<14; i++){ // Nombres
			Consulta.Domicilio[i]=toupper(Consulta.Domicilio[i]); 			
		}
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



//=====================================================
//						Deportes
//=====================================================

int Obtener_dir_fisica_Dep(int Clave_Deporte){
	
	int DIR_FIS;
	DIR_FIS = Clave_Deporte%31;
	return DIR_FIS;

}

void Cargar_Deporte(char Nombre[],char Categoria[],char Rango[],float Max,float Min,char Sexo[],int Clave_Deporte, int DIR_FIS){
	FILE *Archivo;
	Archivo = fopen("Deportes.DIR","rb+");	
	
	Deporte Cargar;
	
	if(Archivo != NULL){
		
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
		
		fread(&Cargar,sizeof(Deporte),1,Archivo);
		

			for(int i=0; i<29; i++){ 
				Cargar.NombreDep[i]=toupper(Nombre[i]); 			
			}
	
			for(int i=0; i<14; i++){ 		
				Cargar.Categoria[i]=toupper(Categoria[i]);
			}
	
			for(int i=0; i<14; i++){ 
				Cargar.Rango[i]=toupper(Rango[i]);		
			}
			
			Cargar.Clave = Clave_Deporte; 
			
			Cargar.DIR_FIS = DIR_FIS; 
			
			Cargar.Max = Max; 
			
			Cargar.Min = Min;
			
			for(int i=0; i<10; i++){ //Domicilio
				Cargar.Sexo[i]=toupper(Sexo[i]);		
			}
			

		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Deporte),1,Archivo);
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		cout<<"---------------------------------------------OPERACION EXITOSA------------------------------------"<<endl;
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
	
}

void Pedir_Datos_del_deporte(){
	system("cls");
	char Nombre[30];
	char Categoria[15];
	char Rango[15];
	char Sexo[10];
	
	int Clave_Deporte;
	int Max;
	int Min;
	int DIR_FIS;
	char A[]="ADOLESCENTE";
	char J[]="JUVENIL";
	char V[]="VETERANO";
	char M[]="MUJER";
	char H[]="HOMBRE";
	char P[]="PRINCIPIANTE";
	char AV[]="AVANZADO";
	/*
	A -> 13 - 17
	J -> 18 - 35
	V -> 36 - 50
	*/	

	cout<<"Ingrese los datos"<<endl;
	fflush(stdin);
	cout<<"\n\tNombre del deporte: 			";	cin.getline(Nombre,30);
	fflush(stdin);
	if (menu_categ() == 1){
		strcpy(Categoria,A);
		Max = 17;
		Min = 13;
	}else if(menu_categ() == 2){
		strcpy(Categoria,J);
		Max = 35;
		Min = 18;
	}else{
		strcpy(Categoria,V);
		Max = 36;
		Min = 50;
	}

	if(menu_sexo() == 1){
		strcpy(Sexo,M);
	}else{
		strcpy(Sexo,H);
	}

	if(menu_rango() == 1){
		strcpy(Rango,P);
	}else{
		strcpy(Rango,AV);
	}
	
	do{
		cout<<"\n\tClave (4 digitos):				";	cin>>Clave_Deporte;
	}while(Clave_Deporte < 999 || Clave_Deporte > 10000);
	
	
	DIR_FIS = Obtener_dir_fisica_Dep(Clave_Deporte);
	
	Cargar_Deporte(Nombre,Categoria,Rango,Max,Min,Sexo,Clave_Deporte,DIR_FIS);

}

void Consultar_Archivo_Deportes(){
	system("cls");
	FILE *Archivo;
	Archivo = fopen("Deportes.DIR","rb");
	Deporte Consulta;
	int i=0;
	int r=3;
	PintarCamposD();
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Deporte),1,Archivo);
			while(!feof(Archivo)){
				escribirRegistrosD(Consulta, r,i);
				r+=2;
				i++;
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


