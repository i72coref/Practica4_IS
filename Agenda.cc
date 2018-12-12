#include <iostream>
#include "Agenda.h"
#include <cstdio>
#include <cstdlib>

void Agenda::borrarAlumno(string dato, int tipo = 0){ //tipo de dato : 1 apellido, 2 dni
	switch(tipo){
		case 1:{
			cout<<"W.I.P, tipo = apellido"<<endl;
			break;
		}
		case 2:{
			cout<<"W.I.P, tipo = dni"<<endl;
			break;
		}
		default:{
			cout<<"ERROR, tipo de dato no conocido."<<endl;
			break;
		}
	}

}
bool Agenda::gestionLideres(){
	printf("Gestionando lideres.\n");
	return true;
}

vector<int> Agenda::buscarAlumno(int entero=-1, string apellido="Vacio", int tipo = 1){// tipo de dato =1 apellido , 2 dni ó 3 grupo
//	Creo el vector de indices
	vector<int> indices;

//	Recorro la agenda en busca de coincidencias
	for(int i=0; i < v_Alumnos.size(); i++){
		switch(tipo){
			default:
				cout<<"Error, tipo a buscar inválido"<<endl;
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
//	En el caso de que se busque por apellido y existan varias coinciidencias hay que buscar por DNI
	if((indices.size() > 1 )&&(tipo = 1)){
		cout<<"Hay mas de un alumno con los mismos apellidos, asi que se va a buscar por DNI"<<endl;
		cout<<"Indique que DNI desea buscar: ";
		cin>>entero;
		indices.clear();
		for(int i=0; i < v_Alumnos.size(); i++){
			if(v_Alumnos[i].getDNI() == entero){
				indices.push_back(i);
			}		
		}
	}

//	Devuelvo los indices encontados
	return indices;
}

void Agenda::mostrarAlumnos(){
	vector<Alumno> v_aux;
	int op = 1;
	cout<<"Elija una opcion:\n"
	<<"\t1 Mostrar todos los alumnos.\n"
	<<"\t2 Mostrar uno o varios alumnos."
	<<"\nOpcion: ";
	cin>>op;

	switch(op){
		default:{
			cout<<"Opcion no encontrada"<<endl;
			break;
		}
		case 1:{
			v_aux = ordenar();
			for(int i=0; i<v_aux.size(); i++){
				//Creo un vector auxiliar, para al ordenar no modificar el vector orginal

				if(v_aux[i].getLider() == true){
					cout<<"\e[1m "/*Activa resaltado*/<<"--> Nombre: "<<v_aux[i].getNombre()<<"\e[0m"/*desactiva resaltado*/<<endl;
				}
				else{
					cout<<"Nombre: "<<v_aux[i].getNombre()<<endl;
				}
				cout<<"El alumno numero "<< i+1 <<" es:"
				<<"\nApellidos: "<<v_aux[i].getApellidos()
				<<"\nDNI: "<<v_aux[i].getDNI()
				<<"\nFecha de nacimiento: "<<v_aux[i].getFecha_nacimiento()
				<<"\nEmail: "<<v_aux[i].getEmail()
				<<"\nDireccion: "<<v_aux[i].getDireccion()
				<<"\nCurso mas alto en el que esta matriculado: "<<v_aux[i].getCurso()
				<<"\nTelefono: "<<v_aux[i].getTlf()
				<<"\nGrupo: "<<v_aux[i].getGrupo()<<"\n"<<endl;
			}
			break;
		}
		case 2:{
			vector<int> indices;
			cout<<"Como desea buscar\n\t1.Por DNI\n\t2.Por Grupo\n\t3.Por apellidos\nOpcion:";
			cin>>op;
			switch(op){
				default:{
					cout<<"ERROR, opcion no encontrada"<<endl;
				break;
				}
				case 1:{
					int auxDNI;
					cout<<"Que DNI desea buscar: ";
					cin>>auxDNI;
					indices = buscarAlumno(auxDNI, "empty", 2);
				break;
				}
				case 2:{
					int auxGrupo;
					cout<<"Que Grupo desea buscar: ";
					cin>>auxGrupo;
					indices = buscarAlumno(auxGrupo, "empty", 3);					
				break;
				}
				case 3:{
					string auxAp;
					cout<<"Que Apellidos desea buscar: ";
					getline(cin, auxAp);
					indices = buscarAlumno(-1, auxAp, 1);
				break;
				}
			};
		break;
		}
	}
	for(int i=0; i<indices.size(); i++){
		if(v_aux[i].getLider() == true){
			cout<<"\e[1m "/*Activa resaltado*/<<"--> Nombre: "<<v_Alumnos[v_aux[i]].getNombre()<<"\e[0m"/*desactiva resaltado*/<<endl;
		}
		else{
			cout<<"Nombre: "<<v_Alumnos[v_aux[i]].getNombre()<<endl;
		}
		cout<<"El alumno numero "<< i+1 <<" es:"
		<<"\nApellidos: "<<v_Alumnos[v_aux[i]].getApellidos()
		<<"\nDNI: "<<v_Alumnos[v_aux[i]].getDNI()
		<<"\nFecha de nacimiento: "<<v_aux[i].getFecha_nacimiento()
		<<"\nEmail: "<<v_Alumnos[v_aux[i]].getEmail()
		<<"\nDireccion: "<<v_Alumnos[v_aux[i]].getDireccion()
		<<"\nCurso mas alto en el que esta matriculado: "<<v_aux[i].getCurso()
		<<"\nTelefono: "<<v_Alumnos[v_aux[i]].getTlf()
		<<"\nGrupo: "<<v_Alumnos[v_aux[i]].getGrupo()<<"\n"<<endl;
	}
}

void Agenda::introducirAlumnos(){
	int nal = 1;
	do{
		cout<<"Indique cuantos alumnos desea introducir: ";
		cin>>nal;
		if(nal + v_Alumnos.size() > 150){
			cout<<"ERROR, no se pueden introducir tantos alumnos, que espacio para "<<150 - v_Alumnos.size()<<" alumnos"<<endl;
		}
	}
	while(nal + v_Alumnos.size() > 150);
	string auxS; //Auxiliar para strings
	int aunI; //Auxiliar para Enteros
	bool auxB;
	Alumno aux;
	for(int i=0; i<nal; i++){
		cout<<"Alumno numero "<< i+1<<endl;
		
		do{
			cout<<"Nombre: ";
			setbuf(stdin, NULL);
			getline(cin, auxS);
			if(auxS.empty()){
				cout<<"El nombre es obligatorio"<<endl;
			}
			aux.setNombre(auxS);
		}
		while(auxS.empty());
		auxS.clear(); //para que la cadena vuelva a estar vacia

		do{
			cout<<"Apellidos: ";
			setbuf(stdin, NULL);
			getline(cin, auxS);
			aux.setApellidos(auxS);
			if(auxS.empty()){
				cout<<"Los apellidos son obligatorios"<<endl;
			}
		}
		while(auxS.empty());
		auxS.clear();		

		cout<<"DNI: ";
		cin>>aunI;
		aux.setDNI(aunI);

		do{
			cout<<"Fecha de nacimiento: ";
			setbuf(stdin, NULL);
			getline(cin, auxS);
			aux.setFecha_nacimiento(auxS);
		}
		while(auxS.empty());
		auxS.clear();		

		do{
			cout<<"Email: ";
			setbuf(stdin, NULL);
			getline(cin, auxS);
			aux.setEmail(auxS);
		}
		while(auxS.empty());
		auxS.clear();		

		do{
			cout<<"Direccion: ";
			setbuf(stdin, NULL);
			getline(cin, auxS);
			aux.setDireccion(auxS);
		}
		while(auxS.empty());
		auxS.clear();		

		cout<<"Curso mas alto en el que esta matriculado: ";
		cin>>aunI;
		aux.setCurso(aunI);

		cout<<"Telefono: ";
		cin>>aunI;
		aux.setTlf(aunI);

//		Variables opcionales
		int op = 0;
		cout<<"¿Desea introducir las opciones de grupo? (1 = SI, 0 = NO)\nOpcion: ";
		cin>>op;
		if(op == 1){
			cout<<"Grupo: ";
			cin>>aunI;
			aux.setGrupo(aunI);
			
			cout<<"¿Lider? (0 = NO, 1 = SI), Opcion:";
			cin>>auxB;
			aux.setLider(auxB);
		}
		else{ //Si el grupo es -1 significa que no tiene grupo
			aux.setGrupo(-1);
			aux.setLider(false);
		}

		v_Alumnos.push_back(aux);
		system("clear");
	}
	cout<<"En el sistema hay un total de "<<v_Alumnos.size()<<endl;
}

vector<Alumno> Agenda::ordenar(){
	int op;
	vector<Alumno> v_aux;
	v_aux = v_Alumnos;
	Alumno a_aux;

	cout<<"Como desea ordenar el vector."
	<<"\n\t1. Por DNI ascendente."
	<<"\n\t2. Por DNI descendente."
	<<"\n\t3. Por apellidos."
	<<"\n\t4. Por curso mas alto ascendente."
	<<"\n\t5. Por curso mas alto descendente."
	<<"\n\t6. Por nommbre."<<endl;
	cin>>op;

	switch(op){
		default:{
			cout<<"Opcion no encontrada."<<endl;
			break;
		}
		case 1:{
			for(int i=0; i<v_aux.size(); i++){
				for(int j=i; j<v_aux.size(); j++){
					if(v_aux[i].getDNI() > v_aux[j].getDNI()){
						a_aux = v_aux[i];
						v_aux[i] = v_aux[j];
						v_aux[j] = a_aux;
					}
				}
			}
			break;
		}
		case 2:{
			for(int i=0; i<v_aux.size(); i++){
				for(int j=i; j<v_aux.size(); j++){
					if(v_aux[i].getDNI() < v_aux[j].getDNI()){
						a_aux = v_aux[i];
						v_aux[i] = v_aux[j];
						v_aux[j] = a_aux;
					}
				}
			}
			break;
		}
		case 3:{//Ordena alfabeticamente los apellidos
			for(int i=0; i<v_aux.size(); i++){
				for(int j=i; j<v_aux.size(); j++){
					if(v_aux[i].getApellidos() < v_aux[j].getApellidos()){
						a_aux = v_aux[i];
						v_aux[i] = v_aux[j];
						v_aux[j] = a_aux;
					}
				}
			}
			break;
		}
		case 4:{
			for(int i=0; i<v_aux.size(); i++){
				for(int j=i; j<v_aux.size(); j++){
					if(v_aux[i].getCurso() > v_aux[j].getCurso()){
						a_aux = v_aux[i];
						v_aux[i] = v_aux[j];
						v_aux[j] = a_aux;
					}
				}
			}
			break;	
		}
		case 5:{
			for(int i=0; i<v_aux.size(); i++){
				for(int j=i; j<v_aux.size(); j++){
					if(v_aux[i].getCurso() < v_aux[j].getCurso()){
						a_aux = v_aux[i];
						v_aux[i] = v_aux[j];
						v_aux[j] = a_aux;
					}
				}
			}
			break;	
		}
		case 6:{ //Ordeno alfabeticamente 
			for(int i=0; i<v_aux.size(); i++){
				for(int j=i; j<v_aux.size(); j++){
					if(v_aux[i].getNombre() < v_aux[j].getNombre()){
						a_aux = v_aux[i];
						v_aux[i] = v_aux[j];
						v_aux[j] = a_aux;
					}
				}
			}
			break;
		}
	}
	return v_aux;
}