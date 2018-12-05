#include <iostream>
#include "profesor.h"

using namespace std;

//Prototipos de funciones
void menu();

int main(){
	Profesor prof;
	int opcion;
//	cin>>opcion;
//	menu();
	prof.login();


	return 0;
}

void menu(){
//	Menu reducido, o para ayudantes
	cout<<"Elija una opcion:"<<endl;
	cout<<"\t1. Introducir alumnos."
	<<"\n\t2. Borrar alumno."
	<<"\n\t3. Modificar alumno."<<endl;
//	if(prof.getRol()){
 		cout<<"\t4. Guardar Backup."
		<<"\t5. Cargar Backup."<<endl;
//	}
	cout<<"Opcion: ";
}