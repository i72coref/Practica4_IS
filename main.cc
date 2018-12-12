#include <iostream>
#include <string>
#include <cstdlib>
#include "Profesor.h"
#include "Agenda.h"
#include "Alumno.h"


using namespace std;

//Prototipos de funciones
void firstmenu(Profesor prof);
void menu(Profesor prof, Agenda age);


int main(){
	Agenda age;
	Profesor prof;

//	Menu inicial, al abrir el programa.
	firstmenu(prof);

	return 0;
}

void firstmenu(Profesor prof){
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
					menu(prof);
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
void menu(Profesor prof, Agenda age){

//	Menu reducido para ayudantes
//	string rol= prof.getRol();
int opcion;
// age.cargarAlmacenamiento();
while(opcion>0){
 cout<<">.----------------------------------------------------------------------.<"<<endl;
 cout<<"\tEstas logueado como: "<<"rol"<<"."<<endl;
 cout<<"\t"<<endl;
 cout<<"\t 1. Introducir alumnos."<<endl;
 cout<<"\n\t 2. Borrar Alumno."<<endl;
 cout<<"\n\t 3. Mostrar Alumnos."<<endl;
	/*if(prof.getRol()){
	 cout<<"\n\t4. Hacer Backup."
	 <<"\n\t5. Cargar Backup."<<endl;
 }*/
 cout<<">.----------------------------------------------------------------------.<"<<endl;
 cout<<"opcion: ";
 cin>>opcion;
 	switch(opcion){

	 case 1:
	 	age.introducirAlumnos();
	 break;

	 case 2:
	 //	age.BorrarAlumno();
	 break;

	 case 3:
	 	age.MostrarAlumnos();
	 break;

	 case 4:


	 break;


	 case 5:

	 break;

	 case 6:
	 	exit(0); //Exit Coordinador.
	 break;

	 case 7:
	 	exit(0); //Exit ayudante.
	 break;
  }
 }
}

