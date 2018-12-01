#include <iostream>
#include "Agenda.h"
#include <cstdio>

void Agenda::borrarAlumno(string dato, int tipo = 0){ //tipo de dato : 1 apellido, 2 dni
	switch(tipo){
		case 1:{
			cout<<"W.I.P, tipo = apellido"<<endl;
			break;
		}
		case 2:{
			cout<<"W.I.P, tipo = dni"<<endl;
			break;
		}
		default:{
			cout<<"ERROR, Tipo no conocido."<<endl;
			break;
		}
	}

}
bool Agenda::gestionLideres(){
	printf("Gestionando lideres.\n");
	return true;
}

vector<int> Agenda::buscarAlumno(int entero=-1, string apellido="Vacio", int tipo = 2){// tipo de dato =1 apellido , 2 dni ó 3 grupo
//	Creo el vector de indices
	vector<int> indices;

//	Recorro la agenda en busca de coincidencias
	for(int i=0; i < v_Alumnos.size(); i++){
		switch(tipo){
			default:
				cout<<"Error, tipo a buscar inválido"<<endl;
			break;
			case 1:
				if(v_Alumnos[i].getApellidos() == apellido){
					indices.push_back(i);
				}
			break;
			case 2:
				if(v_Alumnos[i].getDNI() == entero){
					indices.push_back(i);
				}
			break;
			case 3:
				if(v_Alumnos[i].getGrupo() == entero){
					indices.push_back(i);
				}
			break;
		}
	}
//	Devuelvo los indices encontados
	return indices;
}

void Agenda::mostrarAlumnos(){
	int op = 1;
	cout<<"Elija una opcion:\n"
	<<"\t1 Mostrar todos los alumnos.\n"
	<<"\t2 Mostrar uno o varios alumnos."
	<<"Opcion: ";
	cin>>op;

	switch(op){
		default:{
			cout<<"Opcion no encontrada"<<endl;
			break;
		}
		case 1:{
//TODO		v_Alumnos.ordenar();
			for(int i=0; i<v_Alumnos.size(); i++){
				if(v_Alumnos[i].getLider() == true){
					cout<<"\e[1m "/*Activa resaltado*/<<"Nombre: "<<v_Alumnos[i].getNombre()<<"\e[0m non-bold"/*desactiva resaltado*/<<endl;
				}
				else{
					cout<<"Nombre: "<<v_Alumnos[i].getNombre()<<endl;
				}
				cout<<"El alumno numero"<< i+1 <<"es:"
				<<"\nApellidos: "<<v_Alumnos[i].getApellidos()
				<<"\nDNI: "<<v_Alumnos[i].getDNI()
				<<"\nFecha de nacimiento: "<<v_Alumnos[i].getFecha_nacimiento()
				<<"\nEmail: "<<v_Alumnos[i].getEmail()
				<<"\nDireccion: "<<v_Alumnos[i].getDireccion()
				<<"\nCurso mas alto en el que esta matriculado: "<<v_Alumnos[i].getCurso()
				<<"\nTelefono: "<<v_Alumnos[i].getTlf()
				<<"\nGrupo: "<<v_Alumnos[i].getGrupo()<<endl;
			}
			break;
		}
		case 2:{
			cout<<"W.I.P"<<endl;
			break;
		}
	}
}

void Agenda::intoducirAlumnos(){
	int nal = 1;
	do{
		cout<<"Indique cuantos alumnos desea introducir: ";
		cin>>nal;
		if(nal + v_Alumnos.size() > 150){
			cout<<"ERROR, no se pueden introducir tantos alumnos, que espacio para "<<150 - v_Alumnos.size()<<" alumnos"<<endl;
		}
	}
	while(nal + v_Alumnos.size() > 150);
	string auxS; //Auxiliar para strings
	int aunI; //Auxiliar para Enteros
	for(int i=0; i<=nal; i++){
		cout<<"Alumno numero"<< i+1
		<<"Nombre: ";
		setbuf(stdin, NULL);
		getline(cin, auxS);
		v_Alumnos[i].setNombre(auxS);
		cout<<"Apellidos: ";
		setbuf(stdin, NULL);
		getline(cin, auxS);
		v_Alumnos[i].setApellidos(auxS);
		cout<<"DNI: ";
		cin>>aunI;
		v_Alumnos[i].setDNI(aunI);
		cout<<"Fecha de nacimiento: ";
		setbuf(stdin, NULL);
		getline(cin, auxS);
		v_Alumnos[i].setFecha_nacimiento(auxS);
		cout<<"Email: ";
		setbuf(stdin, NULL);
		getline(cin, auxS);
		v_Alumnos[i].setEmail(auxS);
		cout<<"Direccion: ";
		setbuf(stdin, NULL);
		getline(cin, auxS);
		v_Alumnos[i].setDireccion(auxS);
		cout<<"Curso mas alto en el que esta matriculado: ";
		cin>>aunI;
		v_Alumnos[i].setCurso(aunI);
		cout<<"Telefono: ";
		cin>>aunI;
		v_Alumnos[i].setTlf(aunI);
		cout<<"Grupo: ";
		cin>>aunI;
		v_Alumnos[i].setGrupo(aunI);
		system("clear");
	}
}