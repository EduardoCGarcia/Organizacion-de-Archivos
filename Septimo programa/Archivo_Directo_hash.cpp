#include <iostream>

#include <windows.h>
#include <cctype> // libreria necesaria
#include <time.h>	

#include "FuncPintar.h"
#include "CRUD_Archivos.h"
#include "Index.h"

using namespace std;


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
	Deporte Cargar;
	int DIR_FIS = 0;
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Deporte),1,Archivo);
	for(int i=0;i<30;i++){
		DIR_FIS = i;
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		strcpy(Cargar.NombreDep,"-------");
		strcpy(Cargar.Categoria,"-------");
		strcpy(Cargar.Sexo,"-------");
		strcpy(Cargar.Rango,"-------");
		Cargar.Clave = 0;
		Cargar.Max = 0;
		Cargar.Min = 0;
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Deporte),1,Archivo);	
	}
	cout << "_______________________________________________________" << endl;
    cout << "|            A R C H I V O  D E P O R T E S           | " << endl;
    cout << "|                     C R E A D O                     | " << endl;
    cout << "|_____________________________________________________|" << endl;
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
				
			case 2:
				do{
					op = MENU_DEPORTES();	
					switch(op){
						case 1:
							Pedir_Datos_del_deporte();
							system("pause");
							break;
						case 2:
							Consultar_Archivo_Deportes();
							system("pause");
							break;
						case 3:
							
							break;
						case 4:
							
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


