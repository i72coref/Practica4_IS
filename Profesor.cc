#include <iostream>
#include "Profesor.h"
#include "Alumno.h"
#include <list>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

int Profesor::login(){
  string contra , usuario;
  ifstream fichero;
  char us[35] , pass[30];
  int encontrados;


  cout<<"Introduzca credenciales: usuario: ";
  cin>>usuario;
  cout<<"Introduzca credenciales: contraseña: ";
  cin>>contra;
  string rol;

  fichero.open("credenciales.bin" , ios::in | ios::binary );//queda poner la ruta

  for(int i= 0 ; i< 5 ; i++){

    while(fichero.read((char *)&us , 35)){
      fichero.read((char *)&pass , 30);

        if(us == usuario){
          encontrados++;

            if(pass == contra){
              usuario_ = us;
              rol = usuario_.substr(0 , 3);

                if(rol == "cor"){rol_ = "coordinador";}
                if(rol == "ayu"){rol_ = "ayudante";}

              return 0; //Se ha logueado bien (las credenciales coinciden)
            }
        }
    }
  }

  return -1; //Se ha logueado mal.
}



vector<Alumno> Profesor::cargar_backup(){

  string ruta;
  fstream fichero;
  Alumno aux;
  Agenda ag;
  vector <Alumno> x;
  int variable = -1;

  char nombre[30], apellidos[30], fechanacimiento[30], email[30], direccion[30];
  string nombrex, apellidosx, fechanacimientox, emailx, direccionx;
  int dnix, tlfx, grupox, cursox;
  bool liderx;

while(variable == -1){
  cout<<"Introduce la ruta o dejalo vacío y se cargará la ruta predeterminada: ";
  cin>>ruta;


  if(ruta.empty()){
  fichero.open( "backup.bin" , ios::in | ios::binary);

    if(!fichero){
      cout<<"Error al abrir el back_up"<<endl;
      variable = -1;
    }
    else{
      cout<<"Exito al abrir el back_up"<<endl;
      variable = 0;
    }
  }//cierro if grande



  else{
    fichero.open( ruta.c_str() , ios::in | ios::binary);

      if(!fichero){
        cout<<"Error al abrir el back_up"<<endl;
        variable = -1;
      }
      else{
        cout<<"Exito al abrir el back_up"<<endl;
        variable = 0;
      }
    }//cierro else grande
}



x = ag.getAlumnos();

  while(fichero.read((char *)&dnix, sizeof(int))){
    fichero.read((char *)&cursox, sizeof(int));
    fichero.read((char *)&tlfx, sizeof(int));
    fichero.read((char *)&grupox, sizeof(int));
    fichero.read((char *)&nombre, 30);
    fichero.read((char *)&apellidos, 30);
    fichero.read((char *)&fechanacimiento, 30);
    fichero.read((char *)&email, 30);
    fichero.read((char *)&direccion, 30);
    fichero.read((char *)&liderx, sizeof(bool));


    nombrex = nombre;
    apellidosx = apellidos;
    fechanacimientox = fechanacimiento;
    emailx = email;
    direccionx = direccion;

      aux.setDNI(dnix);
      aux.setCurso(cursox);
      aux.setTlf(tlfx);
      aux.setGrupo(grupox);
      aux.setNombre(nombrex);
      aux.setApellidos(apellidosx);
      aux.setFecha_nacimiento(fechanacimientox);
      aux.setEmail(emailx);
      aux.setDireccion(direccionx);
      aux.setLider(liderx);

      x.push_back(aux);

  }

  fichero.close();
cout<<"Fichero cargado con exito"<<endl;
return x;
}


vector <Alumno> Profesor::cargar_almacenamiento(){

  Agenda ag;
  string ruta = "defecto";
  fstream fichero;
  Alumno aux;
  vector <Alumno> x;
char texto[200];


char nombre[30], apellidos[30], fechanacimiento[30], email[30], direccion[30];
string nombrex, apellidosx, fechanacimientox, emailx, direccionx;
int dnix, tlfx, grupox, cursox;
bool liderx;


  if(ruta == "defecto"){
  fichero.open( "almacenamiento.bin" , ios::in | ios::binary);//ruta predeterminada


    if(!fichero){
      cout<<"Error al abrir el fichero"<<endl;
    }
    else{
      cout<<"Exito al abrir"<<endl;
    }
  }//cierro if grande

x = ag.getAlumnos();


  while(fichero.read((char *)&dnix, sizeof(int))){
    fichero.read((char *)&cursox, sizeof(int));
    fichero.read((char *)&tlfx, sizeof(int));
    fichero.read((char *)&grupox, sizeof(int));
    fichero.read((char *)&nombre, 30);
    fichero.read((char *)&apellidos, 30);
    fichero.read((char *)&fechanacimiento, 30);
    fichero.read((char *)&email, 30);
    fichero.read((char *)&direccion, 30);
    fichero.read((char *)&liderx, sizeof(bool));




    nombrex = nombre;
    apellidosx = apellidos;
    fechanacimientox = fechanacimiento;
    emailx = email;
    direccionx = direccion;

      aux.setDNI(dnix);
      aux.setCurso(cursox);
      aux.setTlf(tlfx);
      aux.setGrupo(grupox);
      aux.setNombre(nombrex);
      aux.setApellidos(apellidosx);
      aux.setFecha_nacimiento(fechanacimientox);
      aux.setEmail(emailx);
      aux.setDireccion(direccionx);
      aux.setLider(liderx);

      x.push_back(aux);

  }

fichero.close();

  cout<<"Fichero almacenamiento cargado correctamente"<<endl;
  return x;
}


void Profesor::hacer_backup(vector <Alumno> x){

  Alumno aux;
  Agenda age;

    int xtam = x.size();


  char apellidos[30];
  char nombre[30];
  char fechanacimiento[30], email[30], direccion[30];
  int dni, tlf, grupo, curso;
  bool serlider;

  string ruta;

  cout<<"Introduce la Ruta: ";
  cin>>ruta;

  fstream file;
file.open(ruta.c_str(), ios::out| ios::binary);

cout <<"Exito al CREAR!!"<<endl;


    for(int i=0; i<x.size(); i++){

      dni = (x[i]).getDNI();
      curso = (x[i]).getCurso();
      tlf = (x[i]).getTlf();
      grupo = (x[i]).getGrupo();

      strcpy(nombre, ((x[i]).getNombre()).c_str());
      strcpy(apellidos, ((x[i]).getApellidos()).c_str());
      strcpy(fechanacimiento, ((x[i]).getFecha_nacimiento()).c_str());
      strcpy(email, ((x[i]).getEmail()).c_str());
      strcpy(direccion, ((x[i]).getDireccion()).c_str());
      serlider = (x[i]).getLider();

      file.write((char *) &dni, sizeof(int));
      file.write((char *) &curso, sizeof(int));
      file.write((char *) &tlf, sizeof(int));
      file.write((char *) &grupo, sizeof(int));
      file.write((char *) &nombre, 30);
      file.write((char *) &apellidos, 30);
      file.write((char *) &fechanacimiento, 30);
      file.write((char *) &email, 30);
      file.write((char *) &direccion, 30);
      file.write((char *) &serlider, sizeof(bool));
     }
file.close();

}

void Profesor::guardar_almacenamiento(vector <Alumno> x){

  Alumno aux;
  Agenda age;

    int xtam = x.size();


  char apellidos[30];
  char nombre[30];
  char fechanacimiento[30], email[30], direccion[30];
  int dni, tlf, grupo, curso;
  bool serlider;

  fstream file;
  file.open("almacenamiento.bin", ios::out| ios::binary);

    for(int i=0; i<x.size(); i++){

      dni = (x[i]).getDNI();
      curso = (x[i]).getCurso();
      tlf = (x[i]).getTlf();
      grupo = (x[i]).getGrupo();

      strcpy(nombre, ((x[i]).getNombre()).c_str());
      strcpy(apellidos, ((x[i]).getApellidos()).c_str());
      strcpy(fechanacimiento, ((x[i]).getFecha_nacimiento()).c_str());
      strcpy(email, ((x[i]).getEmail()).c_str());
      strcpy(direccion, ((x[i]).getDireccion()).c_str());
      serlider = (x[i]).getLider();

      file.write((char *) &dni, sizeof(int));
      file.write((char *) &curso, sizeof(int));
      file.write((char *) &tlf, sizeof(int));
      file.write((char *) &grupo, sizeof(int));
      file.write((char *) &nombre, 30);
      file.write((char *) &apellidos, 30);
      file.write((char *) &fechanacimiento, 30);
      file.write((char *) &email, 30);
      file.write((char *) &direccion, 30);
      file.write((char *) &serlider, sizeof(bool));
     }
     file.close();

}
