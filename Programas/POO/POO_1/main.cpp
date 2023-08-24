#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

using namespace std;

class Persona{	
	//	ATRIBUTOS
	private:
		int edad;
		string nombre;
	//	METODOS
	public:
		//	CONSTRUCTOR
		Persona(int, string);
		
		//	No llevan parámetros
		void leer();
		void comer();
};

Persona::Persona(int _edad, string _nombre){
	edad = _edad;
	nombre = _nombre;
}

void Persona::leer(){
	cout<<"\nLEER\nMi nombre es: "<< nombre << " tengo la edad de "<< edad <<" y estoy en mi clase de Programacion"<<endl;
}

void Persona::comer(){
	cout<<"\nCOMER\nMi nombre es "<< nombre << " y me gusta comer tamales"<<endl;
}

int main(){
	//	CREACION DEL OBJETO	
	cout<<"----- Objeto 1 -----"<<endl;
	Persona objeto1(15,"Enrique");
	objeto1.leer();
	objeto1.comer();
	
	cout<<"\n\n----- Objeto 2 -----"<<endl;
	Persona objeto2(20,"Maria");
	objeto2.leer();
	objeto2.comer();
	
	
	return(0);
}
