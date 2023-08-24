/*
Escriba un programa que muestre en pantalla la palabra Alto si el
valor de la variable puntuacion es mayor que 100, y que muestre la palabra
Bajo si el valor de la variable puntuacion es menor o igual que 100. La
variable puntuacion es de tipo int.
*/

#include<stdio.h>
#include<windows.h>

int N;

main(){
	printf("________ALTO Y/O BAJO________\nIngrese un valor entero: ");
	scanf("%d",&N);		// N = Numero (ingrresado por el usuario
	if(N>100){
		printf("Alto");
	}else{
		printf("Bajo");
	}
	
	return (0);
}

