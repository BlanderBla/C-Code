/*
Generar un programa que imprima la suma de todos los numeros que van del 1 al 100 y diga cuantos hay 

Matrícula 181112
*/

#include<stdio.h>
#include<conio.h>

#define p (printf)

int main(){
	
	int i=0, Sum;
	p("_____SUMA DE VALORES DEL 1 AL 100_____\n\n");
	while(i<100){
		i++;
		Sum = Sum + i;
	}	
	p("La suma de los digitos del 1 al 100 es: %d", Sum);
	
	getch();
}
