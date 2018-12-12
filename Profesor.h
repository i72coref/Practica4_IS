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
	int cargar_backup();
	inline string getRol(){return rol_;}
	int cargar_almacenamiento();

};




#endif
