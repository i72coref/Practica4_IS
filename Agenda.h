#ifndef Agenda_h
#define Agenda_h
#include <iostream>
#include <vector>
#include "Alumno.h"
using namespace std;

class Agenda{
  private:
vector<Alumno> v_;//vector principal de alumnos


  public:
    Agenda(){
    }
inline void setAlumno(vector<Alumno> aux){v_ = aux;}
inline vector <Alumno> getAlumno(){return v_;}
void borrarAlumno(string dato, int tipo);// 1 = apellido ; 2 = dni
};








#endif
