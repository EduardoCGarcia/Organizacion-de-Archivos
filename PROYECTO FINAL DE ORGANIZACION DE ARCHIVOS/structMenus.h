//Librerias de c y c++
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h> //Para manejo de cadenas de caracteres
#include <conio.h>
#include <windows.h> //Para GOTOXY
using namespace std;



// Declaracion de constantes
int const arrayNombre = 30;
int const arrayPriAp = 20;
int const arraySecAp = 20;
int const arrayDomicilio = 50;
int const arrayId = 7;
int const arrayEdad = 2;
int const arrayCategoria = 20;
int const arrayRango = 15;
const int arrayMinima = 13;
const int arrayMaxima = 35;
const int arrayNomCur = 20;
const int arraySexo = 8;
const int arrayRFC = 13;
const int arrayCURP = 50;
const int arrayCorreo = 50;
const int arrayTel = 12;
const int arrayhor = 50;

char arrayIdBusquedas[10]; //array exclusivo para las busquedas utilizado para guardar las claves de tipo cadena
const char arraySexoH[] = "HOMBRE";
const char arraySexoM[] = "MUJER";
const char arrayCatV[] = "VARONIL";
const char arraycatF[] = "FEMENIL";
const char arrayCatA[] = "ADOLESCENTE";
const char arrayCatJ[] = "JUVENIL";
const char arrayCatVet[] = "VETERANO";
const char arrayRangP[] = "PRINCIPIANTE";
const char arrayHorario1[] = "LUNES MIERCOLES VIERNES (12:00 - 14:00)";
const char arrayHorario2[] = "LUNES MIERCOLES VIERNES (14:00 - 16:00)";
const char arrayHorario3[] = "MARTES JUEVES (12:00 - 14:00)";
const char arrayHorario4[] = "MARTES JUEVES (14:00 - 16:00)";
const char arrayRangA[] = "AVANZADO";
const char arrayTitleAlumno[] = "                         	 A P A R T A D O       D E        A L U M N O S                                    ";
const char arrayTitleInst[] =   "                     	A P A R T A D O       D E        I N S T R U C T O R E S                                 ";
const char arrayTitleCur[] =    "                             	A P A R T A D O       D E        C U R S O S                                     ";
const char arrayTitleEscDep[] =    "E S C U E L A       D E        D E P O R T E S                                ";
const char arrayTitleAdmin[] =    "                 	A P A R T A D O       D E      A D M I N I S R A C I O N                              ";
const char arrayTitleAyuda[] =    "                          A P A R T A D O       D E      A Y U D A                                      ";
const char arrayTitleInfo[] =    "                        A P A R T A D O       D E      I N F O R M E S                                      ";
const char arrayTitleSex[] =    "                               S         E          X         O                                      ";
const char arrayTitleCat[] =    "                               C   A   T   E   G   O   R   I   A                                      ";
const char arrayTitleRang[] =    "                                        R  A  N  G  O                                     ";
const char arrayTitleHor[] =    "                                        H O R A R I O                                     ";
const char arrayline[] = "---------------------------------------------------------------------------------------------------";





struct Alumno{
	char id [arrayId];
	char nombre[arrayNombre];
	char primAp[arrayPriAp];
	char secAp[arraySecAp];
	char domicilio[arrayDomicilio];
	char sexo[arraySexo];
	int edad;
	float estatura;
	float peso;
	int claveCurso;
};

struct Instructor{
	char id [arrayId];
	char nombre[arrayNombre];
	char primAp[arrayPriAp];
	char secAp[arraySecAp];
	char domicilio[arrayDomicilio];
	char rfc[arrayRFC];
	char curp[arrayCURP];
	char correo[arrayCorreo];
	char telefono[arrayTel];
	int codigoPostal;
	int claveCurso;
};

typedef struct Curso{
	char nombreCurso[arrayNomCur];
	char categoria[arrayCategoria]; //le puse el nombre arrayCategoria
	char rango[arrayRango];          // le puse el nomnbre de arrayRango
	char sexo[arraySexo];        
	char horario[arrayhor]; // le agregue lo de arrayhor
	int min;
	int max;
	int claveCurso;
}Curso;

struct Index{
	int dirFis;
	char claveAlumno[6];
	int claveCurso;
	char claveInstructor[6];
};




/*
GOTOXY: Permite manipular la posicion del puntero en la consola
*/
void GOTOXY(int x, int y){ //Ancho=80  ,  Alto=25
        HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.X = x;
        dwPos.Y = y;
        SetConsoleCursorPosition(hcon,dwPos);
}

/*
presentacion: Muestra la caratula del programa
*/
void presentacion(){
	GOTOXY(10,1);cout <<arrayline<< endl;
    GOTOXY(10,2);cout << "                               NOMBRE DE LA ESCUELA DE DEPORTES                                    " << endl;
    GOTOXY(10,3);cout << arrayline<< endl;
	GOTOXY(10,4);cout << "                           UNIVERSIDAD AUTONOMA DEL ESTADO DE MEXICO                               " << endl;
    GOTOXY(10,5);cout << "                                     FACULTAD DE INGENIERIA                                        " << endl;
    GOTOXY(10,6);cout << "                                    INGENIERIA EN COMPUTACION                                      " << endl;
    GOTOXY(10,7);cout << "                                     ORGANIZACION DE ARCHIVOS                                      " << endl;
    GOTOXY(10,8);cout << "                                       ESCUELA DE DEPORTES                                         " << endl;
    GOTOXY(10,9);cout << "                                              Por:                                                 " << endl;
    GOTOXY(10,10);cout << "                                  Mabelyn Nataly Quiroz Salinas:                                  " << endl;
    GOTOXY(10,11);cout << "                                      Eduardo Chavez Garcia                                       " << endl;
    GOTOXY(10,12);cout << "                                      Gonzalo Chavez Mercado                                      " << endl;
    GOTOXY(10,13);cout << "                                    Jesus Enrique Ramos Flores                                    " << endl;
    GOTOXY(10,14);cout <<arrayline<< endl;
}

int menuPrincipal(){
	system("cls");
	int opc;
	GOTOXY(10,1);cout <<arrayline<< endl;
    GOTOXY(40,2);cout << arrayTitleEscDep << endl;
    GOTOXY(10,3);cout <<arrayline<< endl;
	GOTOXY(10,4);cout << "                                  [ 1 ]  Apartado de Alumnos                                      " << endl;
	GOTOXY(10,6);cout << "                                  [ 2 ]  Apartado de Instructores                                 " << endl;
	GOTOXY(10,8);cout << "                                  [ 3 ]  Apartado de Cursos                                       " << endl;
	GOTOXY(10,10);cout << "                                  [ 4 ]  Apartado de Informes                                     " << endl;
	GOTOXY(10,12);cout << "                                  [ 5 ]  Apartado de Administracion                               " << endl;
	GOTOXY(10,14);cout << "                                  [ 6 ]  Apartado de ayuda                                        " << endl;
	GOTOXY(10,16);cout << "                                  [ 7 ]  Salir                                                    " << endl;
    GOTOXY(10,18);cout <<arrayline<< endl;
    GOTOXY(10,20);cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

int menuAdministacion(){
	system("cls");
	int opc;
	GOTOXY(10,1);cout << arrayline << endl;
    GOTOXY(10,2);cout << arrayTitleAdmin << endl;
    GOTOXY(10,3);cout << arrayline << endl;
	GOTOXY(10,4);cout << "                                  [ 1 ]  CREAR ARCHIVOS (TODOS)                                " << endl;
	GOTOXY(10,5);cout << "                                  [ 2 ]  RESPALDAR ARCHIVIOS (TODOS)                           " << endl;
	GOTOXY(10,6);cout << "                                  [ 3 ]  VOLVER                                                 " << endl;
    GOTOXY(10,7);cout << arrayline << endl<<endl;
    GOTOXY(10,8);cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}


//menu para mostrarlo en pantalla y regresa el valor de la opcion a elegir
int menuAyuda(){
	system("cls");
	int opc;
	GOTOXY(10,1);cout << arrayline << endl;
    GOTOXY(10,2);cout << arrayTitleAyuda	 << endl;
    GOTOXY(10,3);cout << arrayline << endl;
	GOTOXY(10,4);cout << "                                  [ 1 ]  MANUAL TECNICO                                 " << endl;
    GOTOXY(10,5);cout << "                                  [ 2 ]  MANUAL DE USUARIO                              " << endl;
    GOTOXY(10,6);cout << "                                  [ 3 ]  VOLVER                                          " << endl;
    GOTOXY(10,7);cout <<arrayline << endl;
    GOTOXY(10,8);cout<<"Selecione el manual que desea ver: ";	cin>>opc;
    return opc;
}

int menuInformes(){
	system("cls");
	int opc;
	GOTOXY(10,1);cout << arrayline << endl;
    GOTOXY(10,2);cout << arrayTitleInfo	 << endl;
    GOTOXY(10,3);cout << arrayline << endl;
	GOTOXY(10,4);cout << "                                  [ 1 ]  REPORTE DE CURSO                                 " << endl;
    GOTOXY(10,5);cout << "                                  [ 2 ]  REPORTE HISTORICO                              " << endl;
    GOTOXY(10,6);cout << "                                  [ 3 ]  VOLVER                                          " << endl;
    GOTOXY(10,7);cout <<arrayline << endl;
    GOTOXY(10,8);cout<<"Selecione el reporte que quiera ver: ";	cin>>opc;
    return opc;
}

int CRUD(){
	int opc;
	GOTOXY(10,4);cout << "                                  [ 1 ]  AGREGAR                                         " << endl;
    GOTOXY(10,5);cout << "                                  [ 2 ]  ELIMINAR                                        " << endl;
    GOTOXY(10,6);cout << "                                  [ 3 ]  MODIFICAR                                       " << endl;
    GOTOXY(10,7);cout << "                                  [ 4 ]  BUSCAR                                          " << endl;
    GOTOXY(10,8);cout << "                                  [ 5 ]  LISTAR                                          " << endl;
    GOTOXY(10,9);cout << "                                  [ 6 ]  VOLVER                                          " << endl;
    GOTOXY(10,10);cout <<arrayline << endl;
    GOTOXY(10,11);cout<<"Selecione el reporte que quiera ver: ";	cin>>opc;
    return opc;
}

int menu_sexo(){
	int opc;
    GOTOXY(10,1);cout << arrayline << endl; 
    GOTOXY(10,2);cout << arrayTitleSex << endl;
    GOTOXY(10,3);cout << arrayline << endl;
    GOTOXY(10,4);cout << "                                  	[ 1 ] MUJER                                         " << endl;
    GOTOXY(10,5);cout << "                                  	[ 2 ] HOMBRE                                         " << endl;
    GOTOXY(10,6);cout << arrayline << endl;
    GOTOXY(10,7);cout<<"Selecione su sexo: ";	cin>>opc;
    return opc;
}



int menu_categ(){
	system("cls");
	int opc;
    GOTOXY(10,1);cout << arrayline << endl;
    GOTOXY(10,2);cout << arrayTitleCat << endl;
    GOTOXY(10,3);cout << arrayline << endl;
    GOTOXY(10,4);cout << "                                  [ 1 ]  ADOLESCENTE (13-17)                                         "  << endl;
    GOTOXY(10,5);cout << "                                  [ 2 ]  JUVENIL (18-35)                                         "  << endl;
    GOTOXY(10,6);cout << "                                  [ 3 ]  VETERANO (36-50)                                         "  << endl;
    GOTOXY(10,7);cout << arrayline  << endl;
    GOTOXY(10,8);cout<<"Selecione una categoria: ";	cin >> opc;
    return opc;
}

int menu_rango(){
	system("cls");
	int opc;
    GOTOXY(10,1);cout << arrayline << endl;
    GOTOXY(10,2);cout << arrayTitleRang << endl;
    GOTOXY(10,3);cout << arrayline << endl;
    GOTOXY(10,4);cout << "                                  [ 1 ]  PRINCIPIANTE                                          "  << endl;
    GOTOXY(10,5);cout << "                                  [ 2 ]  AVANZADO                                          " << endl;
    GOTOXY(10,6);cout << arrayline << endl;
    GOTOXY(10,7);cout<<"Selecione su rango: ";	cin>>opc;
    return opc;
}

int categHorario(){
	system("cls");
	int opc;
    GOTOXY(10,1);cout << arrayline << endl;
    GOTOXY(10,2);cout << arrayTitleHor << endl;
    GOTOXY(10,3);cout << arrayline << endl;
	GOTOXY(10,4);cout << "                                  [ 1 ]  LUNES MIERCOLES VIERNES (12:00 - 14:00)   " <<endl;
	GOTOXY(10,5);cout << "                                  [ 2 ]  LUNES MIERCOLES VIERNES (14:00 - 16:00)   " <<endl;
	GOTOXY(10,6);cout << "                                  [ 3 ]  MARTES JUEVES (12:00 - 14:00)             " <<endl;
	GOTOXY(10,7);cout << "                                  [ 4 ]  MARTES JUEVES (14:00 - 16:00)             " <<endl;
	GOTOXY(10,8);cout << arrayline << endl;
    GOTOXY(10,9);cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

void advertencia(){
	cout<<arrayline<<endl;
	GOTOXY(10,10);cout<<"                                  A  D  V  E  R T  E  N  C  I  A                      "<<endl;
	GOTOXY(10,11);cout<<arrayline<<endl;
	GOTOXY(10,12);cout<<"                          No se han detectado todos los archivos necesarios              "<<endl;
	GOTOXY(10,13);cout<<"                            Entre a administracion para crearlos por favor.             "<<endl;
	GOTOXY(10,14);cout<<arrayline<<endl;
	GOTOXY(10,15);cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	GOTOXY(10,16);system("pause"); 
	
}









