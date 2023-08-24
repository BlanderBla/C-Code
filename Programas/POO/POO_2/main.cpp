#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

using namespace std;
//	CLASE
class Automovil{
	// ATRIBUTOS
	private:
		int matricula;
		string marca;
		string modelo;
	//	METODOS
	public:
		//	CONTRUCTOR
		Automovil(int, string, string);
		
		void dato();
};

Automovil::Automovil(int _matricula, string _marca, string _modelo){
	matricula = _matricula;
	marca = _marca;
	modelo = _modelo;
}

void Automovil::dato(){
	cout<<"----- OBJETO -----"<<endl;
	cout<<"El automovil "<< modelo <<" de la marca "<< marca <<" tiene una matricula "<< matricula <<"."<<endl;
}

int main() {
		Automovil objeto1(181112,"Abarth","500Abarth");
		objeto1.dato();
		Automovil objeto2(191112,"BMW","i8");
		objeto2.dato();
		
		return (0);
}
