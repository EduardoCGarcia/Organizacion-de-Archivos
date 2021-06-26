#include <stdio.h>
#include <conio.h>

void Crear_Lista_Index(){
	FILE *Archivo;
	Archivo = fopen("Index.DIR","wb");
	fclose(Archivo);
}

void Cargar_Index(char ID[],int DIR_FIS, int DEP){
	FILE *Archivo;
	Archivo = fopen("Index.DIR","ab");	
	
	Index CargarIndex;
	
	if(Archivo != NULL){
		fread(&CargarIndex,sizeof(Index),1,Archivo);
		for(int i=0;i<=6;i++){ //ID
			CargarIndex.ID[i]= ID[i];
		}

		CargarIndex.DIR_FIS = DIR_FIS;
		CargarIndex.Clave_Dep = DEP;
		
		fwrite(&CargarIndex,sizeof(Index),1,Archivo);
	}else{
		cout<<"El archivo no se ha encontrado..."<<endl;
	}
	fflush(Archivo);
	fclose(Archivo);
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
						
					Cargar_Index(Consulta.ID,Consulta.DIR_FIS,Consulta.Deporte);
					
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



