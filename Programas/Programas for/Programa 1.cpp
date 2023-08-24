/*
Generar un programa que pida al usuario 10 numeros 
Mostrar cual es el mayor y menor de los numeros ingresados
Matrícula 181112
*/
#include<stdio.h>
#include<conio.h>

int main(){
	
	int i=1, N=1, Max=1;
	
	printf("MAYOR---FOR---\n\n");
	for(i;i<=10;i++){
		printf("Ingrese la cantidad %d: ",i);
		scanf("%d",&N);
		if (N>0){
			if(N>Max){
			Max=N;
			}
		}
	}
	printf("El mas alto es: %d",Max);
	
	
	getch();
}
