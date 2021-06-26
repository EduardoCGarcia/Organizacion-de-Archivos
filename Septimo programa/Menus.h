// Mostrar menus 

#include <iostream>
#include <windows.h>

struct Alumno{
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


typedef struct Deporte{
	char NombreDep[15];
	char Categoria[20];
	char Rango[10];
	int Min;
	int Max;
	char Sexo[10];
	int Clave;
	int DIR_FIS;
}Deporte;

typedef struct Index{
	int DIR_FIS;
	char ID[6];
	int Clave_Dep;
};

using namespace std;

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
    GOTOXY(25,9);cout << "|                 [6] Tabla  index                    | " << endl;
    GOTOXY(25,10);cout << "|                 [7] Insertar alumno                 | " << endl;
    GOTOXY(25,11);cout << "|_____________________________________________________|" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}


int MENU_DEPORTES(){
	system("cls");
	int opc;
    GOTOXY(25,1);cout << "_______________________________________________________" << endl;
    GOTOXY(25,2);cout << "|          A R C H I V O S    D E P O R T E S         | " << endl;
    GOTOXY(25,3);cout << "|_____________________________________________________| " << endl;
    GOTOXY(25,4);cout << "|                 [1] Insertar deporte                | " << endl;
    GOTOXY(25,5);cout << "|                 [2] Mostrar Lista                   | " << endl;
    GOTOXY(25,6);cout << "|                 [3] Consulta deporte                | " << endl;
    GOTOXY(25,7);cout << "|                 [4] Baja Logica                     | " << endl;
    GOTOXY(25,8);cout << "|                 [5] Modificar deporte               | " << endl;
    GOTOXY(25,9);cout << "|                 [6] Tabla index                     | " << endl;
    GOTOXY(25,10);cout << "|                 [7] Salir                           | " << endl;
    GOTOXY(25,11);cout << "|_____________________________________________________|" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

int menu_sexo(){
	system("cls");
	int opc;
    GOTOXY(25,1);cout << "_______________________________________________________" << endl;
    GOTOXY(25,2);cout << "|                E L I G E  E L  S E X O              | " << endl;
    GOTOXY(25,3);cout << "|_____________________________________________________| " << endl;
    GOTOXY(25,4);cout << "|                 [1] Mujer                           | " << endl;
    GOTOXY(25,5);cout << "|                 [2] Hombre                          | " << endl;
    GOTOXY(25,6);cout << "|_____________________________________________________| " << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}

int menu_categ(){
	system("cls");
	int opc;
    GOTOXY(25,1);cout << "_______________________________________________________" << endl;
    GOTOXY(25,2);cout << "|          E L I G E  L A  C A T E G O R I A          | " << endl;
    GOTOXY(25,3);cout << "|_____________________________________________________| " << endl;
    GOTOXY(25,4);cout << "|                 [1] 13-17 Adolescente               | " << endl;
    GOTOXY(25,5);cout << "|                 [2] 18-35 Juveni                    | " << endl;
    GOTOXY(25,6);cout << "|                 [3] 36-50 Veterano                  | " << endl;
    GOTOXY(25,7);cout << "|_____________________________________________________| " << endl;
    cout<<"Selecione una opcion: ";	cin >> opc;
    return opc;
}

int menu_rango(){
	system("cls");
	int opc;
    GOTOXY(25,1);cout << "_______________________________________________________" << endl;
    GOTOXY(25,2);cout << "|              E L I G E  E L  R A N G O              | " << endl;
    GOTOXY(25,3);cout << "|_____________________________________________________| " << endl;
    GOTOXY(25,4);cout << "|                 [1] Principiante                    | " << endl;
    GOTOXY(25,5);cout << "|                 [2] Avanzado                        | " << endl;
    GOTOXY(25,6);cout << "|_____________________________________________________| " << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
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

