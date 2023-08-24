/*
Generar un programa que muestre los numeros de 1 a  50 y mueste la suma de ellos 
Matrícula 181112
*/
#include<stdio.h>
#include<conio.h>

int main(){
	
	int i, Sum;
	
	printf("______MOSTRAR 1 - 50 Y SUMAR_____\n");
	for(i=1;i<=50;i++){
		printf("%d\n",i);
		Sum = Sum + i;
	}
	printf("La suma de los numeros de 1 a 50 es: %d",Sum);
	
	getch();
}
