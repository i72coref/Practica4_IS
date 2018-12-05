#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define maxpass 30
#define maxuser 35

struct credenciales{

	char user[maxuser];
	char pass[maxpass];

};

int main(){

credenciales aux;				

ifstream f("credenciales.bin", ios::binary);

	if( f.is_open() ){
		f.read( (char *)&aux, sizeof(credenciales));
		while(!f.eof() ){
			cout<<aux.user <<" "<<aux.pass<<endl;
			f.read( (char *)&aux, sizeof(credenciales));
		}
	}



}