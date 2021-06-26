#include <iostream>
#include <windows.h>
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
    GOTOXY(25,2);cout << "|                A R B O L E S    A V L               | " << endl;
    GOTOXY(25,3);cout << "|_____________________________________________________| " << endl;
    GOTOXY(25,4);cout << "|                 [1] Insertar un Nodo                | " << endl;
    GOTOXY(25,5);cout << "|                 [2] Eliminar un Nodo                | " << endl;
    GOTOXY(25,6);cout << "|                 [3] Pre-Orden                       | " << endl;
    GOTOXY(25,7);cout << "|                 [4] Pos-Orden                       | " << endl;
    GOTOXY(25,8);cout << "|                 [5] Orden                           | " << endl;
    GOTOXY(25,9);cout << "|                 [6] Buscar un Nodo                  | " << endl;
    GOTOXY(25,10);cout << "|                 [7] Salir                           | " << endl;
    GOTOXY(25,11);cout << "|_____________________________________________________|" << endl;
    cout<<"Selecione una opcion: ";	cin>>opc;
    return opc;
}
