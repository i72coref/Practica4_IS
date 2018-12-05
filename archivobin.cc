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
	
credenciales c;

int cont=0;

	cout<<"¿Cuantos datos quieres? " <<endl;
	cin>>cont;

	ofstream f("credenciales.bin", ios::binary);

	if(f.is_open()){
			for(int i=0; i<cont; i++){
				cout<<"Enter the "<< i +1 << " user. (Poner : al final xd)"<< endl;
				cin>>c.user;
				cout<<"Enter the "<< i +1<< " password."<< endl;
				cin>>c.pass;
				f.write((char *) &c, sizeof(credenciales));
            }}
     else{
     	cout<<"ERROR!!!"<<endl;
     }


}