/*
Escriba un programa que muestre en pantalla la palabra Aprobado
si el valor de la variable examen (variable de tipo int) es mayor o igual a
70 y en caso contrario, el programa muestra en pantalla la palabra Reprobado.
*/

#include<stdio.h>

int examen;

main(){
	printf("________APROBADO O REPROBADO________\nIngrese la calificacion: ");
	scanf("%d",&examen);
	if(examen>=70 && examen<=100){
		printf("APROBADO");
	}
	if(examen<=69){
		printf("REPROBADO");	
	}
	if(examen>=101){
		printf("ERROR, VALOR %d",examen);
	}
	
	
	return(0);
}
