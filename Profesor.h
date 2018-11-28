#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
using namespace std;

class Profesor{
private:
	string usuario_, rol_;
	Agenda *ptragenda;
public:
	Profesor(){*ptragenda = NULL;}
};

#endif