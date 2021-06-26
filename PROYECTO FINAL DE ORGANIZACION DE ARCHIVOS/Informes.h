//Librerias de c y c++
#include <stdio.h>
#include<stdlib.h>
#include<string.h> //Para manejo de cadenas de caracteres
#include "CRUDS.h"


int contarAsistentes(int claveCursoSeleccionado){
	int i=0;
	FILE *archivo;
	Alumno cantidad;
	archivo = fopen("Alumnos.DIR", "rb");
	if(archivo != NULL){
		fread(&cantidad,sizeof(Alumno),1,archivo);
		while(!feof(archivo)){
			if(cantidad.claveCurso == claveCursoSeleccionado){
				
				fread(&cantidad, sizeof(cantidad), 1, archivo);
				i++;
			}
			fread(&cantidad, sizeof(Alumno), 1, archivo);
		}
		
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(archivo);
	return (i);
	
}

void consultarNombreAlumno(int claveCursoSeleccionado){
	FILE *Archivo;
	Archivo = fopen("Alumnos.DIR","rb");
	Alumno Consulta;
	if(Archivo != NULL){
		fread(&Consulta,sizeof(Alumno),1,Archivo);
		while(!feof(Archivo)){
			if(Consulta.claveCurso == claveCursoSeleccionado){
				strcpy(arrayIdBusquedas,Consulta.nombre);
			
				fclose(Archivo);
				return;
			}
			fread(&Consulta,sizeof(Alumno),1,Archivo);
		}
		
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);	
}

void consultarNombreProfesor(int claveCursoSeleccionado){
	FILE *Archivo;
	
	Archivo = fopen("Instructores.DIR","rb");
	Instructor Consulta;
	if(Archivo != NULL){
		fread(&Consulta,sizeof(Instructor),1,Archivo);
		while(!feof(Archivo)){
			if(Consulta.claveCurso == claveCursoSeleccionado){
				strcpy(arrayIdBusquedas,Consulta.nombre);
			
				fclose(Archivo);
				return;
			}
			fread(&Consulta,sizeof(Instructor),1,Archivo);
		}
		
	}else{
		cout<<"El archivo no se ha encontrado"<<endl;
	}
	fclose(Archivo);
}

void reporteCursos(){
	//variable que se usa para el No.
	int contador = 1;
	int mayorr = 0, menorr = 0;
	char mayor[arrayNomCur];
	char menor [arrayNomCur];
	
	FILE *Archivo;
	Archivo = fopen("Cursos.DIR","rb");
	Curso Consulta;	
	fread(&Consulta,sizeof(Curso),1,Archivo);
	
	while(!feof(Archivo)){
		if(Consulta.claveCurso != 0){
			cout<<"No. :"<<contador<<endl;
			cout<<"Nombre del curso: "<<Consulta.nombreCurso<<endl;
			cout<<"Clave del curso: "<<Consulta.claveCurso<<endl;
			
			//se adjunta el nombre del instructor si es que se encuentra
			consultarNombreProfesor(Consulta.claveCurso);
			cout<<"Instructor del curso: "<<arrayIdBusquedas<<endl;
			cout<<"Numero de asistentes: "<<contarAsistentes(Consulta.claveCurso)<<endl;
			cout<<endl<<endl;
			contador++;	
			contador++;
			if(contarAsistentes(Consulta.claveCurso) > mayorr){
				strcpy(mayor,Consulta.nombreCurso);
				mayorr = contarAsistentes(Consulta.claveCurso);
			}else if(contarAsistentes(Consulta.claveCurso) <= menorr){
				strcpy(menor,Consulta.nombreCurso);
				menorr = contarAsistentes(Consulta.claveCurso);
			}
		}
		fread(&Consulta,sizeof(Curso),1,Archivo);
	}
	printf("El curso con mas asistentes es: %s \n", mayor);
	printf("El curso con menos asistentes es: %s \n", menor);

	fclose(Archivo);
}

void reporteHistorico(){
		system("cls");
	//variable que se usa para el No.
	int numero = 1;
	FILE *Archivo;
	Archivo = fopen("Index.DIR","rb");
	Index Consulta;
	if(Archivo != NULL){
		if(ftell(Archivo) == 0){
			fread(&Consulta,sizeof(Index),1,Archivo);
			while(!feof(Archivo)){
				
					cout<<"No. :"<<numero<<endl;
					cout<<"Clave del curso: "<<Consulta.claveCurso<<endl;
					//lo mismo que en profesores paro ahora en alumnos si y solo si hace match
					consultarNombreAlumno(Consulta.claveCurso);
					cout<<"Alumno: "<<arrayIdBusquedas<<endl;
					//se adjunta el nombre del instructor si y solo si hace match
					consultarNombreProfesor(Consulta.claveCurso);
					cout<<"Instructor: "<<arrayIdBusquedas<<endl;
					cout<<endl<<endl;
					numero++;	
			
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
