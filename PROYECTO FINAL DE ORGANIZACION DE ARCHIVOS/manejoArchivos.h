//Librerias de c y c++
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h> //Para manejo de cadenas de caracteres
//Funciones creadas por nosotros en .h
#include "Informes.h"



/*
=============================================================================================
									Creacion de archivos
=============================================================================================
*/


/*	
crearArchivoAlumnos: Crear el archivo directo de alumnos con 120 registros. Los ulitimos 20
					 son el area de desborde
*/
void crearArchivoAlumnos(){
	FILE *Archivo;
	Archivo = fopen("Alumnos.DIR","wb");
	Alumno Cargar;
	int DIR_FIS = 0;
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Alumno),1,Archivo);
	for(int i=0;i<120;i++){
		DIR_FIS = i;
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		strcpy(Cargar.nombre,"-------");
		strcpy(Cargar.primAp,"-------");
		strcpy(Cargar.secAp,"-------");
		strcpy(Cargar.domicilio,"-------");
		strcpy(Cargar.id,"-------");
		strcpy(Cargar.sexo,"-------");
		Cargar.claveCurso = 0;
		Cargar.edad = 0;
		Cargar.estatura = 0;
		Cargar.peso = 0;
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Alumno),1,Archivo);	
	}
	cout <<endl<< "                                   -------------------------------------------------------" << endl;
    cout << "                                                A R C H I V O  A L U M N O S              " << endl;
    cout << "                                                         C R E A D O                      " << endl;
	cout << "                                   -------------------------------------------------------" << endl;
	fclose(Archivo);
	
}

/*
crearArchivoInstructores: Crear el archivo directo de instructores con 120 registros. Los ulitimos 20
					 	  son el area de desborde
*/
void crearArchivoInstructores(){
	FILE *Archivo;
	Archivo = fopen("Instructores.DIR","wb");
	Instructor Cargar;
	int DIR_FIS = 0;
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Instructor),1,Archivo);
	for(int i=0;i<120;i++){
		DIR_FIS = i;
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		strcpy(Cargar.nombre,"-------");
		strcpy(Cargar.primAp,"-------");
		strcpy(Cargar.secAp,"-------");
		strcpy(Cargar.domicilio,"-------");
		strcpy(Cargar.id,"-------");
		strcpy(Cargar.correo,"-------");
		strcpy(Cargar.curp,"-------");
		strcpy(Cargar.rfc,"-------");
		strcpy(Cargar.telefono,"-------");
		Cargar.claveCurso = 0;
		Cargar.codigoPostal = 0;
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Instructor),1,Archivo);	
	}
	cout <<endl<< "                                   -------------------------------------------------------" << endl;
    cout << "                                          A R C H I V O  I N S T R U C T O R E S          " << endl;
    cout << "                                                         C R E A D O                      " << endl;
    cout << "                                   -------------------------------------------------------" << endl;
	fclose(Archivo);
	
}

/*
crearArchivoCursos: Crear el archivo directo de cursos con 120 registros. Los ulitimos 20
					  son el area de desborde
*/
void crearArchivoCursos(){
	FILE *Archivo;
	Archivo = fopen("Cursos.DIR","wb");
	Curso Cargar;
	int DIR_FIS = 0;
	fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
	fread(&Cargar,sizeof(Curso),1,Archivo);
	for(int i=0;i<30;i++){
		DIR_FIS = i;
		DIR_FIS = DIR_FIS*sizeof(Cargar);
		strcpy(Cargar.nombreCurso,"-------");
		strcpy(Cargar.categoria,"-------");
		strcpy(Cargar.sexo,"-------");
		strcpy(Cargar.rango,"-------");
		strcpy(Cargar.horario,"-------");
		Cargar.claveCurso = 0;
		Cargar.max = 0;
		Cargar.min = 0;
		fseek(Archivo,DIR_FIS,SEEK_SET); //Posicionar el apuntador del archivo
				
		fwrite(&Cargar,sizeof(Curso),1,Archivo);	
	}
	cout <<endl<< "                                   -------------------------------------------------------" << endl;
    cout << "                                                A R C H I V O  D E P O R T E S            " << endl;
    cout << "                                                         C R E A D O                      " << endl;
    cout << "                                   -------------------------------------------------------" << endl;
	fclose(Archivo);
}

/*
crearIndex: Crear el archivo directo Index sin un tama?o definido
*/
void crearArchivoIndex(){
	FILE *Archivo;
	Archivo = fopen("Index.DIR","wb");
	cout <<endl<< "                                   -------------------------------------------------------" << endl;
    cout << "                                               A R C H I V O   I  N  D  E  X              " << endl;
    cout << "                                                        C R E A D O                       " << endl;
	cout << "                                   -------------------------------------------------------" << endl;
	fclose(Archivo);
}


/*
=============================================================================================
								      	Administracion
=============================================================================================
*/
//Funcion para hacer respaldo de los archivos alumnos, deportes e instructores
void respaldo() {
    FILE *archivo, *copia; //se crean los punteros para manejar los archivos

    //Genera el respaldo y copia los datos alumnos
    //Verifica que no exista antes un respaldo, si existe, lo borra
    archivo = fopen("Alumnos.DIR", "r+b");
    if (archivo == NULL) { //para ver si el archivo esta vacio
    }
    else {
        copia = fopen("Alumnos(copia).DIR", "r+b"); // se abre el archivo para copiar
        if (copia == NULL) {
            copia = fopen("Alumnos(copia).DIR", "ab"); //se crea el archivo para copiar
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Alumno alumno;
                fread(&alumno, sizeof(Alumno), 1, archivo); //se lee el archivo de alumnos
                while (!feof(archivo)) {
                    fwrite(&alumno, sizeof(Alumno), 1, copia); //va escribiendo el respaldo en el archivo copia
                    fread(&alumno, sizeof(Alumno), 1, archivo); //lectura del archivo alumnos
                }
                fclose(copia); //se cierra el archivo de respaldo
            }
        }
        else {
            fclose(copia);
            system("del \"Alumnos(copia).DIR\""); //borra el archivo en caso de existir

            copia = fopen("Alumnos(copia).DIR", "ab"); //se crea un nuevo archivo para copiar todo
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Alumno alumno;
                fread(&alumno, sizeof(Alumno), 1, archivo);
                while (!feof(archivo)) {
                    fwrite(&alumno, sizeof(Alumno), 1, copia);
                    fread(&alumno, sizeof(Alumno), 1, archivo);
                }
                fclose(copia);
            }
        }
    }
    fclose(archivo);

    //Genera el respaldo y copia los datos cursos/deportes
    //Verifica que no exista antes un respaldo, si existe, lo borra
    archivo = fopen("Cursos.DIR", "r+b");
    if (archivo == NULL) { //para ver si el archivo esta vacio
    }
    else {
        copia = fopen("Cursos(copia).DIR", "r+b"); // se abre el archivo para copiar
        if (copia == NULL) {
            copia = fopen("Cursos(copia).DIR", "ab");
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Curso curso;
                fread(&curso, sizeof(Curso), 1, archivo);
                while (!feof(archivo)) {
                    fwrite(&curso, sizeof(Curso), 1, copia);
                    fread(&curso, sizeof(Curso), 1, archivo);
                }
                fclose(copia);
            }
        }
        else {
            fclose(copia);
            system("del \"Cursos(copia).DIR\""); //borra el archivo en caso de existir

            copia = fopen("Cursos(copia).DIR", "ab"); //se crea un nuevo archivo para copiar todo
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Curso curso;
                fread(&curso, sizeof(Curso), 1, archivo);
                while (!feof(archivo)) {
                    fwrite(&curso, sizeof(Curso), 1, copia);  //va escribiendo el respaldo en el archivo copia
                    fread(&curso, sizeof(Curso), 1, archivo); //lectura del archivo alumnos
                }
                fclose(copia);
            }
        }
    }
    fclose(archivo);

    //Genera el respaldo y copia los datos instructores
    //Verifica que no exista antes un respaldo, si existe, lo borra
    archivo = fopen("Instructores.DIR", "r+b");
    if (archivo == NULL) { //para ver si el archivo esta vacio
    }
    else {
        copia = fopen("Instructores(copia).DIR", "r+b"); // se abre el archivo para copiar
        if (copia == NULL) {
            copia = fopen("Instructores(copia).DIR", "ab");
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Instructor instructores;
                fread(&instructores, sizeof(Instructor), 1, archivo);
                while (!feof(archivo)) {
                    fwrite(&instructores, sizeof(Instructor), 1, copia); //va escribiendo el respaldo en el archivo copia
                    fread(&instructores, sizeof(Instructor), 1, archivo); //lectura del archivo alumnos
                }
                fclose(copia);
            }
        }
        else {
            fclose(copia);
            system("del \"Instructores(copia).DIR\""); //borra el archivo en caso de existir

            copia = fopen("Instructores(copia).DIR", "ab"); //se crea un nuevo archivo para copiar todo
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Instructor instructores;
                fread(&instructores, sizeof(Instructor), 1, archivo);
                while (!feof(archivo)) {
                    fwrite(&instructores, sizeof(Instructor), 1, copia); //va escribiendo el respaldo en el archivo copia
                    fread(&instructores, sizeof(Instructor), 1, archivo);  //lectura del archivo alumnos
                }
                fclose(copia); //se cierra el archivo de respaldo
            }
        }
    }
    fclose(archivo); //se cierra el archivo alumnos
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// si quieres copia otra vez todo el modulo o a partir de aqui xd////
	//Genera el respaldo y copia los datos index
    //Verifica que no exista antes un respaldo, si existe, lo borra
    archivo = fopen("Index.DIR", "r+b");
    if (archivo == NULL) { //para ver si el archivo esta vacio
    }
    else {
        copia = fopen("Index respaldo.DIR", "r+b"); // se abre el archivo para copiar
        if (copia == NULL) {
            copia = fopen("Index respaldo.DIR", "ab");
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Index index;
                fread(&index, sizeof(Index), 1, archivo);
                while (!feof(archivo)) {
                    fwrite(&index, sizeof(Index), 1, copia); //va escribiendo el respaldo en el archivo copia
                    fread(&index, sizeof(Index), 1, archivo); //lectura del archivo alumnos
                }
                fclose(copia);
            }
        }
        else {
            fclose(copia);
            system("del \"Index respaldo.DIR\""); //borra el archivo en caso de existir

            copia = fopen("Index respaldo.DIR", "ab"); //se crea un nuevo archivo para copiar todo
            if (copia == NULL) {
            	cout<<"\n\tArchivo vacio"<<endl;
            }
            else {
                Index index;
                fread(&index, sizeof(Index), 1, archivo);
                while (!feof(archivo)) {
                    fwrite(&index, sizeof(Index), 1, copia); //va escribiendo el respaldo en el archivo copia
                    fread(&index, sizeof(Index), 1, archivo);  //lectura del archivo alumnos
                }
                fclose(copia); //se cierra el archivo de respaldo
            }
        }
    }
    fclose(archivo); //se cierra el archivo index
    
    cout<<"\n\tArchivos respaldados"<<endl;
}

/*
verificaArchivos: verifica que los 4 archivos esten creados
					Se manda el mensaje al inicio del programa para advertir al usuario que debe crearlos
					Si el usuario no los crea previamente no se podra ingresar a los apartados exceptuando a administracion para crearlos
*/
bool verificaArchivos(){
	FILE *Alumnos = fopen("Alumnos.DIR","rb");
	FILE *Instructores = fopen("Instructores.DIR","rb");
	FILE *Cursos = fopen("Cursos.DIR","rb");
	FILE *Index = fopen("Index.DIR","rb");
	
	if(Alumnos == NULL || Instructores == NULL || Cursos == NULL || Cursos == NULL ){
		return false;
	}
	return true;
}

/*
administrar: permite crear y respaldar los archivos
*/
void administrar(int op){
	switch(op){
		case 1:
			crearArchivoAlumnos(); //creacion de archivo.dr
			crearArchivoCursos(); //creacion de archivo deportes.dir                ----> tambien aca le cambie lo de crear archivos, le habia puesto deportes xd
			crearArchivoInstructores(); //creacion de archivo instructores.dir
			crearArchivoIndex();
			break;
		case 2:
			respaldo();
			break;
		case 3:
			break;
		default:
			cout<<"\n\tElige una opcion correcta"<<endl;
		break;
	
	}

}


/*
=============================================================================================
								      	     Ayuda
=============================================================================================
*/
/*
ayuda: muestra cualquiera de los 2 manuales de ayuda para el usuario

*/
void ayuda(int op){
	
	switch(op){
		case 1:
            ShellExecute(NULL, "open", "Manual de usuario ESDEP (2).pdf",  NULL, NULL, SW_SHOWNORMAL); //abre el manual tecnico
        break;

    	case 2: 
            ShellExecute(NULL, "open", "Manual tecnico ESDEP .pdf", NULL, NULL, SW_SHOWNORMAL); //abre el manual de usuario
        break;
        case 3:
        	break;
                     
        default: 
           cout << "Digite una opcion correcta" << endl; //en caso de que el usuario no digite una opcion correcta
        break;            
	}
}

/*
=============================================================================================
								      	   Informes
=============================================================================================
*/


void Informes(int op){
	switch(op){
		case 1:
			reporteCursos();
			system("pause");
			break;
		case 2:
			reporteHistorico();
			system("pause");
			break;

		default:
			cout<<"Error, ingresa una opcion valida"<<endl;
			break;	
	}
}




/*
=============================================================================================
								      	   CRUDS
=============================================================================================
*/


void crudAlumnos(int op){
	switch(op){
		case 1:
			pedirDatosAlumno();
			system("pause");
			break;
		case 2:
			eliminarAlumno();
			system("pause");
			break;
		case 3:
			modificarAlumno();
			system("pause");
			break;
		case 4:
			consultarAlumno();
			system("pause");
			break;
		case 5:
			consultarArchivoAlumnos();
			system("pause");
			break;
		case 6:
			system("pause");
			break;
	}
}


void crudCurso(int op){
	switch(op){
		case 1:
			pedirDatosCurso();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 2:
			eliminarCurso();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 3:
			modificarCurso();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 4:
			consultarCurso();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 5:
			consultarArchivoCursos();
			system("pause");
			cout<<endl;
			break;
		case 6:
			system("pause");
			break;
	}
}

void crudInstructor(int op){
	switch(op){
		case 1:
			pedirInstructor();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 2:
			eliminarInstructor();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 3:
			modificarInstructor();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 4:
			consultarInstructor();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 5:
			consultarArchivoInstructores();
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			system("pause");
			break;
		case 6:
			
			
			system("pause");
			break;
	}
}








