/*
Genera un programa que evalue una calificacion Entera :
      10 - Excelente
      9 - Muy bien
      8 - Bien 
      7  - Suficiente 
      6  - Reprobado
      Otro Numero : Opc No valida 
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

int Cal;

main()
{
	printf("Ingrese una calificación del 6 al 10\n");
	scanf("%d",&Cal);		// Cal = Calificación que ingreso el usuario
	
	switch (Cal)
	{
	case 6:
		printf("Reprobado");
		break;
	case 7:
		printf("Suficiente");
		break;
	case 8:
		printf("Bien");
		break;
	case 9:
		printf("Muy bien");
		break;
	case 10:
		printf("Excelente");
		break;		
	default:
		printf("Opción no valida");
	}
	
	getch();
}

