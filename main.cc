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
	cout<<"\n\e[1;32m >.----------------------------------------------------------------------.<\e[0m"<<endl;
	cout<<"\t\e[1;32m HOLA, BIENVENIDO AL SISTEMA.\e[0m"<<endl;
	cout<<"\t"<<endl;
	cout<<"\t \e[1;32m 1.\e[0m Introduce tus credenciales para continuar."<<endl;
	cout<<"\t \e[1;32m 2.\e[0m Salir."<<endl;
	cout<<"\n\e[1;32m >.----------------------------------------------------------------------.<\e[0m"<<endl;
	cout<<"\nOpción: ";
	cin>>opcion;

	/*	if(opcion>2 || opcion<1){
		cout<<"ERROR! Vuelva a introducir la opcion"<<endl;} //Falta hacer esto */

	while(intentos>0){
		switch(opcion){
			default:{
	cout<<"Opcion no encontrada."<<endl;
	break;
}
			case 1:
				if (prof.login() == 0){
					intentos=0;
					menu(prof, age, aux);
				}
				else{
					intentos--;
					cout<<"Vuelve a intentarlo quedan: "<<intentos<<" intentos.\n"<<endl;
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


while(opcion>=0){
 cout<<"\n\e[1;32m >.----------------------------------------------------------------------.<\e[0m"<<endl;
 cout<<"\tEstas logueado como: \e[1;32m"<< prof.getRol() <<"\e[0m"<<endl;
 cout<<"\t"<<endl;
cout<<"\t\e[1;32m 1.\e[0m Salir"<<endl;
 cout<<"\t\e[1;32m 2.\e[0m Introducir alumnos."<<endl;
 cout<<"\t\e[1;32m 3.\e[0m Borrar Alumno."<<endl;
 cout<<"\t\e[1;32m 4.\e[0m Mostrar Alumnos."<<endl;
 cout<<"\t\e[1;32m 5.\e[0m Modificar Alumno."<<endl;
	if(prof.getRol()=="coordinador"){
	 cout<<"\t\e[1;32m 6.\e[0m Hacer Backup."<<endl;
	 cout<<"\t\e[1;32m 7.\e[0m Cargar Backup."<<endl;
 }
 cout<<"\n\e[1;32m >.----------------------------------------------------------------------.<\e[0m"<<endl;

 cout<<"\nOpcion: ";
 cin>>opcion;


 	switch(opcion){

		default:{
	cout<<"Opcion no encontrada."<<endl;
	break;
}

	 case 1:

	/*Al elegir la opcion del salir del programa,
	vamos a guardar todos los datos trabajados*/

		cout<<"SALIENDO...";
		cout<<endl;
		aux = age.getAlumnos();
		if(prof.guardar_almacenamiento(aux) == -1){
						cout<<"No se creó 'almacenamiento.bin' porque no hay alumnos en el sistema\n"<<endl;
		}
		else{
			cout<<"Se creó 'almacenamiento.bin' con los alumnos cargados\n"<<endl;
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
	 age.modificarAlumno();
	 break;

	 case 6:
if(prof.getRol() == "coordinador"){

	 	aux = age.getAlumnos();
		if(prof.hacer_backup(aux) == -1){
			cout<<"No hay alumnos en el sistema"<<endl;
		}
}
else{
	cout<<"Opcion no encontrada."<<endl;
}
	 break;

	 case 7:
if(prof.getRol() == "coordinador"){
	 age.setAlumnos(prof.cargar_backup());
	 cout<<"Los datos se han cargado correctamente!! "<<endl;
	 break;
}
else{
		cout<<"Opcion no encontrada."<<endl;
}

  }
 }
}
