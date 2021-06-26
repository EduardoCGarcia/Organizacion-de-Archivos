//Librerias de c y c++
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h> //Para manejo de cadenas de caracteres
#include "structMenus.h"

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

void escribirRegistrosAlumnos(Alumno Consulta, int r){
		fflush(stdin);
		GOTOXY(0, r);
		printf("%c", 186);
		GOTOXY(1, r);
		printf("%s", Consulta.id);
		
		GOTOXY(15, r);
		printf("%c", 186);
		
		GOTOXY(16, r);
		printf("%s", Consulta.nombre);
		
		
		GOTOXY(30,r);
		printf("%c", 186);
		
		GOTOXY(31, r);
		printf("%s", Consulta.primAp);
		
		
		GOTOXY(45, r);
		printf("%c", 186);
		GOTOXY(46, r);
		printf("%s", Consulta.secAp);
		
		GOTOXY(60, r);
		printf("%c", 186);
		GOTOXY(61, r);
		printf("%s",Consulta.sexo);
		
		GOTOXY(75, r);
		printf("%c", 186);
		GOTOXY(76, r);
		printf("%i", Consulta.edad);
		
		GOTOXY(90, r);
		printf("%c", 186);
		GOTOXY(91, r);
		printf("%0.2f", Consulta.estatura);
		
		GOTOXY(105, r);
		printf("%c", 186);
		GOTOXY(106, r);
		printf("%0.2f", Consulta.peso);
		
		GOTOXY(120, r);
		printf("%c", 186);
		printf("%s",Consulta.domicilio);	
		
		GOTOXY(135, r);
		printf("%c", 186);
		printf("%i",Consulta.claveCurso);
		
		GOTOXY(150, r);
		printf("%c", 186);
		Pintar(1);
}


void PintarCamposAlumnos(){
	Pintar(0);
	printf("%c      ID      %c    NOMBRE    %c P. APPELLIDO %c S. APELLIDO  %c     SEXO     %c     EDAD     %c   ESTATURA   %c     PESO     %c  DOMICILIO   %c    CURSO     %c", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186,186);
	Pintar(1);
	fflush(stdin);
}



void PintarCurso(int a){
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
	while(i<120){
		if(i%15==0){
			if(a == 1 && i<80){
				printf("%c", 206);
			}else if(a==0 && i<80){
				printf("%c", 203);
			}else{
			if(a==0 && i<80){
				printf("%c", 202);
			}
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

void PintarCamposCurso(){
	PintarCurso(0);
	printf("%c NOMBRE CURSO %c    CLAVE     %c  CATEGORIA   %c    RANGO     %c     SEXO     %c                 HORARIO                  %c", 186, 186, 186, 186, 186, 186, 186);
	PintarCurso(1);
	fflush(stdin);
}

void escribirRegistrosCurso(Curso Consulta, int r){
		fflush(stdin);
		GOTOXY(0, r);
		printf("%c", 186);
		GOTOXY(1, r);
		printf("%s", Consulta.nombreCurso);
		
		GOTOXY(15, r);
		printf("%c", 186);
		
		GOTOXY(16, r);
		printf("%i", Consulta.claveCurso);
		
		
		GOTOXY(30,r);
		printf("%c", 186);
		
		GOTOXY(31, r);
		printf("%s", Consulta.categoria);
		
		
		GOTOXY(45, r);
		printf("%c", 186);
		GOTOXY(46, r);
		printf("%s", Consulta.rango);
		
		GOTOXY(60, r);
		printf("%c", 186);
		GOTOXY(61, r);
		printf("%s",Consulta.sexo);
		
		GOTOXY(75, r);
		printf("%c", 186);
		GOTOXY(76, r);
		printf("%s", Consulta.horario);
		
		GOTOXY(118, r);
		printf("%c", 186);

		PintarCurso(1);
}



void PintarCamposInstructores(){
	Pintar(0);
	printf("%c      ID      %c    NOMBRE    %c P. APPELLIDO %c S. APELLIDO  %c     RFC      %c     CURP     %c    CORREO    %c     C.P      %c   TELEFONO   %c    CURSO     %c", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186,186);
	Pintar(1);
	fflush(stdin);
}

void escribirRegistrosInstructores(Instructor Consulta, int r){
		fflush(stdin);
		GOTOXY(0, r);
		printf("%c", 186);
		GOTOXY(1, r);
		printf("%s", Consulta.id);
		
		GOTOXY(15, r);
		printf("%c", 186);
		
		GOTOXY(16, r);
		printf("%s", Consulta.nombre);
		
		
		GOTOXY(30,r);
		printf("%c", 186);
		
		GOTOXY(31, r);
		printf("%s", Consulta.primAp);
		
		
		GOTOXY(45, r);
		printf("%c", 186);
		GOTOXY(46, r);
		printf("%s", Consulta.secAp);
		
		GOTOXY(60, r);
		printf("%c", 186);
		GOTOXY(61, r);
		printf("%s",Consulta.rfc);
		
		GOTOXY(75, r);
		printf("%c", 186);
		GOTOXY(76, r);
		printf("%s", Consulta.curp);
		
		GOTOXY(90, r);
		printf("%c", 186);
		GOTOXY(91, r);
		printf("%s", Consulta.correo);
		
		GOTOXY(105, r);
		printf("%c", 186);
		GOTOXY(106, r);
		printf("%i", Consulta.codigoPostal);
		
		GOTOXY(120, r);
		printf("%c", 186);
		printf("%s",Consulta.telefono);	
		
		GOTOXY(135, r);
		printf("%c", 186);
		printf("%i",Consulta.claveCurso);
		
		GOTOXY(150, r);
		printf("%c", 186);
		Pintar(1);
}







