/*
4-  Generar un programa que  calcule el area de          
     Area de un Triangulo
     Area de un Cuadrado
     Area de un Rectangulo
     Area de un Circulo
*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

int Opc;
float BT, HT, AT, LC, AC, BR, HR, AR, RC, AdC;

main()
{
	printf("1. Area de un triangulo.\n2. Area de un cuadrado\n3. Area de un rectangulo\n4. Area de un circulo\n¿Que opcion deseas realizar? ");
	scanf("%d",&Opc);
	system("cls");
	
	switch(Opc)
	{
		case 1:
			printf("Area de un traingulo\nIngrese la base del triangulo: ");
			scanf("%f",&BT);	//BT = Base del triangulo
			printf("Ingrese la altura del triangulo: ");
			scanf("%f",&HT);		//HT = Altura del triangulo
			AT = (BT*HT)/2;		//AT = Area del triangulo
			printf("el area del traingulo es: %.2f",AT);
			break;
		case 2:
			printf("Area de un cuadrado\nIngrese la medida de un lado del cuadrado: ");
			scanf("%f",&LC);		// LC = Lado cuadrado
			AC = LC*LC;			// AC = Area del cuadrado	
			printf("El area del cuadrado es: %.2f",AC);
			break;
		case 3:
			printf("Area de un rectangulo\nIngrese la base del rectangulo: ");
			scanf("%f",&BR);	// BT = Base del rectangulo
			printf("Ingrese la altura del rectangulo: ");
			scanf("%f",&HR);		// HT = Altura del Rectangulo
			AR = BR*HR;		// AR = Area del Rectangulo
			printf("el area del rectangulo es: %.2f",AR);
			break;
		case 4:
			printf("Area de un circulo\n(Tomando en cuenta pi como 3.14)\nIngrese el radio del circulo: ");
			scanf("%f",&RC);	// RC = Radio del circulo
			AdC = 3.14*(RC*RC);	// AdC = Area del Circulo
			printf("El area del ciruculo es: %.2f",AdC);
			break;
		default:
			printf("Error.");			
	}
	
	getch();
}
