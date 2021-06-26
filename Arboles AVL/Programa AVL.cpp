#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Estructuras.h"
#include "FuncionesAVL.h"
#include "Menus.h"

using namespace std;




int main(){
	int op = 0;
	do{
		op = MENU_PRINCIPAL();
		switch(op){
			case 1:
				
				break;
			case 2:
				break;
			case 3:
				break;
			default: cout<<"¡¡¡¡ Dato no validio !!!!"<<endl;
		}
	}while(op =! 7);
	
	getch();
	return 0;
}

