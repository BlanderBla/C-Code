/*
Programa que pida una letra y detecte si es una vocal
Tipo de dato: char
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

char L;

main()
{
	printf("Ingrese una letra en minuscula: ");
	scanf("%c",&L);		// L = Letra que ingreso el usuario
	
	switch(L)
	{
		case 'a':
			printf("Es vocal");
			break;
		case 'e':
			printf("Es vocal");
			break;
		case 'i':
			printf("Es vocal");
			break;
		case 'o':
			printf("Es vocal");
			break;
		case 'u':
			printf("Es vocal");
			break;	
		default:
			printf("La letra ingresada no es vocal");
	}
	
	getch();
}

