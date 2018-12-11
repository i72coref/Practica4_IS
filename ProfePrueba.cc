#include <iostream>
#include "profesor.cc"
#include <string>

using namespace std;

int main(){
	Profesor p;
	if(p.login()==-1){
		cout<<"error"<<endl;}
	else {
		cout<<"Acierto!!"<<endl;
	}

	return 0;
}