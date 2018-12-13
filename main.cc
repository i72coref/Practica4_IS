#include <iostream>
#include <string>
#include <cstdlib>
#include "Profesor.h"
#include "Agenda.h"
#include "Alumno.h"


using namespace std;

//Prototipos de funciones
void firstmenu(Profesor prof, Agenda age, vector <Alumno> aux);
void menu(Profesor prof, Agenda age, vector <Alumno> aux);


int main(){
	Agenda age;
	Profesor prof;
	vector <Alumno> aux;
//	Menu inicial, al abrir el programa.
	firstmenu(prof, age, aux);

	return 0;
}

void firstmenu(Profesor prof, Agenda age, vector <Alumno> aux){
	int opcion=0, intentos=5;
	cout<<">.----------------------------------------------------------------------.<"<<endl;
	cout<<"\tHOLA, BIEN VENIDO AL SISTEMA."<<endl;
	cout<<"\t"<<endl;
	cout<<"\t 1. Introduce tus credenciales para continuar."<<endl;
	cout<<"\n\t 2. Salir."<<endl;
	cout<<">.----------------------------------------------------------------------.<"<<endl;
	cout<<"opcion: ";
	cin>>opcion;

	/*	if(opcion>2 || opcion<1){
		cout<<"ERROR! Vuelva a introducir la opcion"<<endl;} //Falta hacer esto */

	while(intentos>0){
		switch(opcion){
			case 1:
				if (prof.login() == 0){
					intentos=0;
					cout<<"EXITO!"<<endl;
					menu(prof, age, aux);
				}
				else{
					intentos--;
					cout<<"Vuelve a intentarlo quedan: "<<intentos<<" intentos."<<endl;
					if(intentos==0){
						cout<<"Has acabado tus intentos..."<<endl;
						exit(-1);
					}
				}
			break;

			case 2:
				exit(0);
			break;
		}
	}
}

void menu(Profesor prof, Agenda age, vector <Alumno> aux){

int opcion=0;
	age.setAlumnos(prof.cargar_almacenamiento());
	cout<<"Los datos se han cargado correctamente"<<endl;

while(opcion>=0){
 cout<<">.----------------------------------------------------------------------.<"<<endl;
 cout<<"\tEstas logueado como: "<< prof.getRol() <<"."<<endl;
 cout<<"\t"<<endl;
cout<<"\n\t 1. Salir"<<endl;
 cout<<"\t 2. Introducir alumnos."<<endl;
 cout<<"\n\t 3. Borrar Alumno."<<endl;
 cout<<"\n\t 4. Mostrar Alumnos."<<endl;
	if(prof.getRol()=="coordinador"){
	 cout<<"\n\t5. Hacer Backup."
	 <<"\n\t6. Cargar Backup."<<endl;
 }
 cout<<">.----------------------------------------------------------------------.<"<<endl;
 cout<<"opcion: ";
 cin>>opcion;
 	switch(opcion){

	 case 1:

	/*Al elegir la opcion del salir del programa,
	vamos a guardar todos los datos trabajados*/

		cout<<"SALIENDO..."<<endl;
		cout<<endl;
		aux = age.getAlumnos();
		if(prof.guardar_almacenamiento(aux) == -1){
						cout<<"No hay alumnos en el sistema"<<endl;
		}
 		exit(0);
	 break;

	 case 2:
	 	age.introducirAlumnos();
	 break;

	 case 3:
	age.borrarAlumno();
	 break;

	 case 4:
	 	age.mostrarAlumnos();
	 break;

	 case 5:
	 	aux = age.getAlumnos();
		if(prof.hacer_backup(aux) == -1){
			cout<<"No hay alumnos en el sistema"<<endl;
		}

	 break;

	 case 6:
	 age.setAlumnos(prof.cargar_backup());
	 cout<<"Los datos se han cargado correctamente!! "<<endl;
	 break;

  }
 }
}
