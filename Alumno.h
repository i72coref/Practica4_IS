#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <string>
using namespace std;

class Alumno{
private:
	int DNI_, curso_, tlf_;
	string nombre_, apellidos_, fecha_nacimiento_, email_, direccion_;
	bool lider_;
public:
//	Setters
	inline void setDNI(int DNI){DNI_ = DNI;}
	inline void setCurso(int curso){curso_ = curso;}
	inline void setTlf(int tlf){tlf_ = tlf;}
	inline void setNombre(string nombre){nombre_ = nombre;}
	inline void setApellidos(string apellidos){apellidos_ = apellidos;}
	inline void setFecha_nacimiento(string fecha_nacimiento){fecha_nacimiento_ = fecha_nacimiento;}
	inline void setEmail(string email){email_ = email;}
	inline void setDireccion(string direccion){direccion_ = direccion;}
	inline void setLider(bool lider){lider_ = lider;}
//	Getters
	inline int getDNI(){return DNI_;}
	inline int getCurso(){return curso_;}
	inline string getNombre(){return nombre_;}
	inline string getApellidos(){return apellidos_;}
	inline string getFecha_nacimiento(){return fecha_nacimiento_;}
	inline string getEmail(){return email_;}
	inline string getDireccion(){return direccion_;}
	inline bool getLider(){return lider_;}

};

#endif