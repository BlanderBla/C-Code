/*
Que pida un número del 1 al 7 y diga el día de la semana correspondiente.
Tipo de dato int para numero
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

int Num;

main()
{
	printf("Ingrese un numero del 1 al 7: ");
	scanf("%d",&Num);
	
	system("cls");		//Limpia la pantalla
	
	switch(Num)
	{
		case 1:
			printf("Lunes");
			break;
		case 2:
			printf("Martes");
			break;
		case 3:
			printf("Miercoles");
			break;
		case 4:
			printf("Jueves");
			break;
		case 5:
			printf("Viernes");
			break;
		case 6:
			printf("Sabado");
			break;
		case 7:
			printf("Domingo");
			break;
		default:
			printf("Error");
			break;
	}		
		
	getch();
}
