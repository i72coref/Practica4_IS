#ifndef Agenda_h
#define Agenda_h
#include <iostream>
#include <vector>
#include "Alumno.h"
using namespace std;

class Agenda{
 private:
	vector<Alumno> v_Alumnos;//vector principal de alumnos


 public:
    Agenda(){}
	inline void setAlumnos(vector<Alumno> aux){v_Alumnos = aux;}
	inline vector<Alumno> getAlumnos(){return v_Alumnos;}
	void borrarAlumno();
	vector<int> buscarAlumno(int, string, int);// tipo de dato =1 apellido , 2 dni ó 3 grupo
	void mostrarAlumnos();
	void introducirAlumnos();
	vector<Alumno> ordenar();
	void modificarAlumno();
  	int lideres(int grupo);

};

#endif
