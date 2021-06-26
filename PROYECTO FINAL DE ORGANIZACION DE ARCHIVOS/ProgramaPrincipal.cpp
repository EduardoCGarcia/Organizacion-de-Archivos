//Librerias de c y c++
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h> //Para manejo de cadenas de caracteres
#include <conio.h>
#include <windows.h> //Para GOTOXY
#include <cctype>  //Para hacer el cambio entre tipos de datos
#include <time.h>
#include <Winuser.h> 
#include <cstdlib>

#include "manejoArchivos.h"


using namespace std;



int main(){

	presentacion();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	system("pause");
	system("cls");
	if (verificaArchivos() == false){
		advertencia();
	}

	int usuario;
	int op;
	do{
		system("cls");
		op = menuPrincipal();
		switch(op){
			case 1:
				if (verificaArchivos() == false){
					advertencia();
				}else{
					do{
					system("cls");
					GOTOXY(10,1);cout <<arrayline<< endl;
	    			GOTOXY(10,2);cout <<arrayTitleAlumno<< endl;
	    			GOTOXY(10,3);cout <<arrayline<< endl;
					op = CRUD();
					crudAlumnos(op);
					}while(op != 6);
				}
				
				
				break;
			case 2:
				if (verificaArchivos() == false){
					advertencia();
				}else{
					do{
						system("cls");
						GOTOXY(10,1);cout <<arrayline<< endl;
		    			GOTOXY(10,2);cout <<arrayTitleInst<< endl;
		    			GOTOXY(10,3);cout <<arrayline<< endl;
		    			op = CRUD();
	    				crudInstructor(op);
					}while(op != 6);
				}
				
				break;
			case 3:
				if (verificaArchivos() == false){
					advertencia();
				}else{
					do{
						system("cls");
						GOTOXY(10,1);cout <<arrayline<< endl;
						GOTOXY(10,2);cout <<arrayTitleCur<< endl;
						GOTOXY(10,3);cout <<arrayline<< endl;
						op = CRUD();
	    				crudCurso(op);
					}while(op != 6);
				}
				
				break;
			case 4:system("cls");
				
				if (verificaArchivos() == false ){
					advertencia();
				}else{
					do{
						op = menuInformes();
						Informes(op);	
					}while(op != 3);
				}
			
				break;
			case 5:system("cls");
				char password[10], clave[10], caracter;
				strcpy(password, "12345");
								
				GOTOXY(10,1);cout <<arrayline<< endl;
				GOTOXY(10,2);cout << "                  PARA CONTINUAR CON LA OPERACION POR FAVOR DIGITE LA CONTRASEÑA                   " << endl;
				GOTOXY(10,3);cout << arrayline<< endl;		
				GOTOXY(10,4);cout <<"Contraseña:";
				for(int i=0; i<10; i++){
					caracter = getch();
					if(caracter != 13){
					clave[i] = caracter;
					cout << "*";
					
				}
					if(caracter == 13){
						break;
					}
				}
				
				if(strcmp(password, clave) == 0){
					do{
						op = menuAdministacion();
						administrar(op);
						system("pause");
					}while(op != 3);
				}
				else{
				GOTOXY(10,1);cout <<arrayline<< endl;
				GOTOXY(10,2);cout << "                       CONTRASEÑA INCORRECTA POR FAVOR VUELVA A INTENTARLO                         " << endl;
				GOTOXY(10,3);cout << arrayline<< endl;
				system("pause");
				}
				break;
			case 6:system("cls");
				do{
					op = menuAyuda();
					ayuda(op);
				}while(op != 3);
				break;
			case 7:system("cls");
				cout<<"Fue un placer atenderle..."<<endl;
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				system("pause");
				break;
		}
	}while(op != 7);
	getch();
	return 0;
}









