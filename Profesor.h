#ifndef PROFESOR_H
#define PROFESOR_H
#include "Agenda.h"

using namespace std;


class Profesor{

private:
	string usuario_;
	string rol_;
public:
	Profesor(){}

	int login();
	inline string getRol(){return rol_;}

	vector<Alumno> cargar_backup();
	vector<Alumno> cargar_almacenamiento();

    int hacer_backup();
    int guardar_almacenamiento();


};




#endif
