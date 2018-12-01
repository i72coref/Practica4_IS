#include <iostream>
#include "Agenda.h"
#include <cstdio>

void Agenda::borrarAlumno(string dato, int tipo = 0){ //tipo de dato : 1 apellido, 2 dni
	switch(tipo){
		case 1:{
			printf("W.I.P, tipo = apellido\n");
			break;
		}
		case 2:{
			printf("W.I.P, tipo = dni\n");
			break;
		}
		default:{
			printf("ERROR, Tipo no conocido.\n");
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
				printf("Error, tipo a buscar inválido\n");
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