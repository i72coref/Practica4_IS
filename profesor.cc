#include <iostream>
#include "profesor.h"
#include "Alumno.h"
#include <list>
#include <fstream>
#include <string>
#include <stdio.h>
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
  string ruta = "" ;
  ifstream fichero;
  Alumno aux;
  vector <Alumno> x;

  char nombre[30], apellidos[30], dni[30], tlf[30], grupo[30], fechanacimiento[30], email[30], lider[30], direccion[30], curso[30];
  string nombrex, apellidosx, dnix, tlfx, grupox, fechanacimientox, emailx, liderx, direccionx, cursox;

  if(rol_ != "coordinador"){return -1;
  cout<<"Debes ser coordinador"<<endl;}


cout<<"Introduce la ruta:";
cin>>ruta;


  if(ruta == ""){
  //  fichero.open(/*ruta defecto*/ , ios::in | ios::binary);//ruta por defecto
  }

  else{
    fichero.open( ruta.c_str() , ios::in | ios::binary);
  }

  while(fichero.read((char *)&nombre, 30)){
    fichero.read((char *)&apellidos, 30);
    fichero.read((char *)&dni, 30);
    fichero.read((char *)&fechanacimiento, 30);
    fichero.read((char *)&email, 30);
    fichero.read((char *)&direccion, 30);
    fichero.read((char *)&curso, 30);
    fichero.read((char *)&tlf, 30);
    fichero.read((char *)&grupo, 30);
    fichero.read((char *)&lider, 30);

    int curso2 = atoi(curso);
    int dni2 = atoi(dni);
    int tlf2 = atoi(tlf);
    int grupo2 = atoi(grupo);

    bool lider2 = lider;

      aux.setNombre();

  }

fichero.close();

}
