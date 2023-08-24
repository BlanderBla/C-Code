/*
Sumar todos los enteros pares desde 2 hasta 100
Matrícula 181112
*/

#include<stdio.h>
#include<conio.h>

int main(){
	
	int i, Sum;
	
	printf("_____SUMA DE ENTEROS PARES HASTA 100_____\n\n");
	
	for(i;i<=100;i=i+2){
		Sum = Sum + i;
	}
	printf("La suma de los pares es: %d", Sum);
	
	getch();
}
