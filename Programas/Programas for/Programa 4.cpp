/*
Realizar un programa que imprima por pantalla tántos asteriscos como diga el usuario.
Al ejecutarse debe preguntar “Cuantos asteriscos desea imprimir?”, leer el número que
introduce el usuario e imprimir los asteriscos
Matrícula 181112
*/
#include<stdio.h>
#include<conio.h>

int main(){
	
	int i, N;
	
	printf("_____ASTERIOSCOS_____\n\n¿Cuantos asteriscos quiere que se muestren?R. ");
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		printf("* ");
		}
	
	getch();
}
