/*
Ingresar el último término de la serie mostrando a continuación 2, 4, 6, 8, 10, ... , n;
Mostrar la suma toral de la serie completa en la pantalla

Matrícula 181112
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

#define p (printf)
#define s (scanf)

int i=0, n, Sum;

int main(){
		
	p("_____SERIE_____\n\nIngrese hasta que numero quiere ingresar la serie\n(Que sea numero par)\nR. ");
	s("%d",&n);
	while(i<n){
		i= i+2;
		p("%d\n",i);
		Sum = Sum + i; 				
	}
	p("La suma de los numeros es: %d",Sum);
	
	getch();
}
