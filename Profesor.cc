#include <iostream>
#include "Profesor.h"
#include "Alumno.h"
#include <list>
#include <fstream>
#include <string>
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



int Profesor::cargar_backup(){

  string ruta = "";
  fstream fichero;
  Alumno aux;
  Agenda ag;
  vector <Alumno> x;
char texto[200];
  int variable = -1;

  char nombre[30], apellidos[30], dni[30], tlf[30], grupo[30], fechanacimiento[30], email[30], lider[30], direccion[30], curso[30];
  string nombrex, apellidosx, fechanacimientox, emailx, direccionx;
  int dnix, tlfx, grupox, cursox;

//  if(rol_ != "coordinador"){
//  cout<<"Debes ser coordinador"<<endl;
//  return -1;}


while(variable == -1){
  cout<<"Introduce la ruta o escribe 'defecto' y se cargará la ruta predeterminada: ";
  cin>>ruta;


  if(ruta == "defecto"){
  fichero.open( "backup.bin" , ios::in | ios::binary);


    if(!fichero){
      cout<<"Error al abrir"<<endl;
      variable = -1;
    }
    else{
      cout<<"Exito al abrir"<<endl;
      variable = 0;
    }
  }//cierro if grande

  else{
    fichero.open( ruta.c_str() , ios::in | ios::binary);

      if(!fichero){
        cout<<"Error al abrir"<<endl;
        variable = -1;
      }
      else{
        cout<<"Exito al abrir"<<endl;
        variable = 0;
      }
    }//cierro else grande
}

x = ag.getAlumnos();

  while(fichero.read((char *)&dni, 30)){
    fichero.read((char *)&curso, 30);
    fichero.read((char *)&tlf, 30);
    fichero.read((char *)&grupo, 30);
    fichero.read((char *)&nombre, 30);
    fichero.read((char *)&apellidos, 30);
    fichero.read((char *)&fechanacimiento, 30);
    fichero.read((char *)&email, 30);
    fichero.read((char *)&direccion, 30);
    fichero.read((char *)&lider, 30);

    cursox = atoi(curso);
    dnix = atoi(dni);
    tlfx = atoi(tlf);
    grupox = atoi(grupo);

    bool liderx = lider;

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
  ag.setAlumnos(x);
cout<<"Fichero cargado con exito"<<endl;
}

  
  int Profesor::cargar_almacenamiento(){

  Agenda ag;
  string ruta = "defecto";
  fstream fichero;
  Alumno aux;
  vector <Alumno> x;
char texto[200];


  char nombre[30], apellidos[30], dni[30], tlf[30], grupo[30], fechanacimiento[30], email[30], lider[30], direccion[30], curso[30];
  string nombrex, apellidosx, fechanacimientox, emailx, direccionx;
  int dnix, tlfx, grupox, cursox;

//  if(rol_ != "coordinador"){
//  cout<<"Debes ser coordinador"<<endl;
//  return -1;}



  if(ruta == "defecto"){
  fichero.open( "backup.bin" , ios::in | ios::binary);//ruta predeterminada


    if(!fichero){
      cout<<"Error al abrir"<<endl;
    }
    else{
      cout<<"Exito al abrir"<<endl;
    }
  }//cierro if grande

x = ag.getAlumnos();
int i = 0;

  while(fichero.read((char *)&dni, 30)){
    fichero.read((char *)&curso, 30);
    fichero.read((char *)&tlf, 30);
    fichero.read((char *)&grupo, 30);
    fichero.read((char *)&nombre, 30);
    fichero.read((char *)&apellidos, 30);
    fichero.read((char *)&fechanacimiento, 30);
    fichero.read((char *)&email, 30);
    fichero.read((char *)&direccion, 30);
    fichero.read((char *)&lider, 30);

    cursox = atoi(curso);
    dnix = atoi(dni);
    tlfx = atoi(tlf);
    grupox = atoi(grupo);

    bool liderx = lider;

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

  ag.setAlumnos(x);

fichero.close();

  cout<<"Fichero cargado correctamente"<<endl;
}

int Profesor::hacer_backup(){
  vector <Alumno> x;
  Alumno aux;
  Agenda age;

  x = age.getAlumnos();

    int xtam = x.size();


  char nombre[30], apellidos[30], dni[30], tlf[30], grupo[30], fechanacimiento[30], email[30], lider[30], direccion[30], curso[30];
  string nombrex, apellidosx, fechanacimientox, emailx, direccionx, dnis, grupos, tlfs, grupos;
  int dnix, tlfx, grupox, cursox;
  bool liderx;

  if(rol_ != "coordinador"){
  cout<<"Debes ser coordinador"<<endl;
  return -1;}
  string ruta;

  cout<<"Introduce la Ruta: ";
  cin>>ruta;
  fstream f;
  f.open(ruta, ios::out|ios::binary);
    cout <<"Exito al CREAR!!"<<endl;
    for(int i=0; i<x.size(); i++){

      dnix = x[i].getDNI();
      dnis = to_string(dnix); //Pasamos el int a string
      dni = dnis.c_str(); //Se pasa el string a char
      cursox = x[i].getCurso();

      tlfx = x[i].getTlf();
      tlfs = to_string(tlfx);
      tlf = tlfs.c_str();
      grupox = x[i].getGrupo();
      nombrex = x[i].getNombre();
      apellidosx = x[i].getApellidos();
      fechanacimientox = x[i].getFecha_nacimiento();
      emailx = x[i].getEmail();
      direccionx = x[i].getDireccion();
      liderx = x[i].getLider();

      //f.write((char *) &dni, 30);

    }
  f.close();
}


  
