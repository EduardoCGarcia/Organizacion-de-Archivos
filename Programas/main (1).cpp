#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <cctype> // libreria necesaria

using namespace std;

int main() {
	
	char minuscula[]={"hol1546a"};
	cout<<"Ingresa el texto"<<endl;
	//cin.getline(minuscula,10);		
	

	
	
	for(int i=0; i<10; i++){	
		minuscula[i]=toupper(minuscula[i]);		
	}
	
		
		cout<<minuscula<<endl;			
	
	
		cout<<endl;
	for(int i=0; i<10; i++){	
		minuscula[i]=tolower(minuscula[i]);		
	}
		cout<<endl;
		
		cout<<minuscula;			
	
	 printf("%c",02);
	
	
	return 0;
}
