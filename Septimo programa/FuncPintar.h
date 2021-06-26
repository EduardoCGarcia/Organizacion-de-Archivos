#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Menus.h"

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
	printf("%c    DIRECCION %c     ID       %c Deporte   %C ",186, 186,186,186);
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



void PintarD(int a){
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

void PintarCamposD(){
	PintarD(0);
	printf("%c    DIRECCION %c     CLAVE    %c     NOMBRE   %cCATEGORIA     %cRANGO         %cSEXO\t  %cEDAD MAXIMA\t %cEDAD MINMA\t %c", 186, 186, 186, 186, 186, 186, 186, 186, 186);
	PintarD(1);
	fflush(stdin);
}

void escribirRegistrosD(Deporte Consulta, int r,int i){
	fflush(stdin);
	GOTOXY(0, r);
    printf("%c", 186);
	GOTOXY(1, r);
    printf("%i", i);
	
    GOTOXY(15, r);
    printf("%c", 186);

    GOTOXY(16, r);
    printf("%i", Consulta.Clave);
	

    GOTOXY(30,r);
    printf("%c", 186);

    GOTOXY(31, r);
    printf("%s", Consulta.NombreDep);
	

    GOTOXY(45, r);
    printf("%c", 186);
    GOTOXY(46, r);
    printf("%s", Consulta.Categoria);
	
    GOTOXY(60, r);
    printf("%c", 186);
    GOTOXY(61, r);
    printf("%s", Consulta.Rango);

    GOTOXY(75, r);
    printf("%c", 186);
    GOTOXY(76, r);
    printf("%s", Consulta.Sexo);
   	
	
    GOTOXY(90, r);
    printf("%c", 186);
    GOTOXY(91, r);
    printf("%i", Consulta.Max);
	
    GOTOXY(105, r);
    printf("%c", 186);
    GOTOXY(106, r);
    printf("%i", Consulta.Min);
	
    GOTOXY(120, r);
    printf("%c", 186);
    PintarD(1);
	

}



