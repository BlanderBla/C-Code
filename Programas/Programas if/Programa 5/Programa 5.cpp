/*
Diseñe un programa que, dado un número float que entra como dato, nos indique si está contenido dentro de los
límites predeterminados. El límite inferior es de 100 y el superior de 200.
*/

#include<stdio.h>
#include<conio.h>
float N;		// N = Numero (Ingresado por el usuario)

main()
{
	printf("________LIMITE INFERIOR Y SUPERIOR________\n\nIngrese un valor: ");
	scanf("%f",&N);
	if(N<=200 && N>=100){
		printf("El valor SI entre los límites predeterminados");
	}else{
		printf("El valor NO esta entre los limites");
	}
	
	getch();
}
