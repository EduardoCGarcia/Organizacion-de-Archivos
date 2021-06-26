#include <iostream>
#include <string.h>
#include <conio.h>

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;


char Nombre[30];
char PA[30];	//Primer apellido 
char SA[30];	//Segundo apellido

float Estatura;
float Peso;
int Edad;

char Domicilio[50];

char Deporte[20];

int Num_Cta;


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

void MENU_PRINCIPAL(){

    GOTOXY(40,1);cout << "----------------------------------------" << endl;
    GOTOXY(40,2);cout << "|    1.-  Ingresar nuevo integrante    | " << endl;
    GOTOXY(40,3);cout << "|    2.-  Eliminar a un integrante     | " << endl;
    GOTOXY(40,4);cout << "|    3.-  Consultar                    | " << endl;
    GOTOXY(40,5);cout << "|    4.-  Modificar                    | " << endl;
    GOTOXY(40,6);cout << "|    5.-  Salir                        | " << endl;
    GOTOXY(40,7);cout << "----------------------------------------" << endl;

}




int main(){
	
	
	
	
	
	
	return 0;
}






