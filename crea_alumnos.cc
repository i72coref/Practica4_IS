#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdbool.h>
using namespace std;



int main(){
  int contador = 0;
char nombre[30], apellidos[30], dni[30], tlf[30], grupo[30], fechanacimiento[30], email[30], lider[30], direccion[30], curso[30];
fstream fichero;
fichero.open( "backup.bin" , ios::out | ios::binary);

cout<<"¿Cúantos alumnos quieres introducir?";
cin>>contador;

while(contador != 0){

  cout<<"dni: ";
  cin>>dni;
  cout<<"curso: ";
  cin>>curso;
  cout<<"Tlf: ";
  cin>>tlf;
  cout<<"grupo: ";
  cin>>grupo;
  cout<<"nombre: ";
  cin>>nombre;
  cout<<"apellidos: ";
  cin>>apellidos;
  cout<<"fecha de nacimento: ";
  cin>>fechanacimiento;
  cout<<"email: ";
  cin>>email;
  cout<<"direccion: ";
  cin>>direccion;
  cout<<"Lider (si o no)";
  cin>>lider;
  cout<<endl;

  fichero.write((char *)&dni, 30);
  fichero.write((char *)&curso, 30);
  fichero.write((char *)&tlf, 30);
  fichero.write((char *)&grupo, 30);
  fichero.write((char *)&nombre, 30);
  fichero.write((char *)&apellidos, 30);
  fichero.write((char *)&fechanacimiento, 30);
  fichero.write((char *)&email, 30);
  fichero.write((char *)&direccion, 30);
  fichero.write((char *)&lider, 30);

contador--;
}
  return 0;
}
