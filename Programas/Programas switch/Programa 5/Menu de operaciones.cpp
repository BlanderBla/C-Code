/*
Realizar  un programa que presente al usuario un menú con las siguientes opciones:
a) Sumar dos números: Solicitar al usuario dos números y sumarlos.
b) Elevar un número al cubo: Solicitar al usuario un número y elevarlo al cubo. Imprimir el número en pantalla.
c) Obtener un promedio: De tres Calificaciones dadas por el usuario 

*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

int N, V1, V2, SN;
float N3, PN, Cal1, Cal2, Cal3, SumCal, PromCal;

main()
{
	printf("Menu\n1. Sumar dos numeros.\n2. Elevar un numero al cubo.\n3. Obtener un promedio.\n\nQue operacione desea realizar: ");
	scanf("%d",&N);
	system("cls");
	
	switch(N)
	{
	case 1:
		printf("--------Suma de dos numero.--------\nIngrese un primer valor");
		scanf("%d",&V1);		// V1 = Valor 1
		printf("Ingrese un segundo valor: ");
		scanf("%d",&V2);
		SN = V1 + V2;		// SN = Suma de numeros (de los dos valores)
		printf("La suma de los valores es: %d",SN);
		break;
	case 2: 
		printf("--------Elevar un numero al cubo--------\nIngrese el numero que desea elevar al cuadrado: ");
		scanf("%f",&N3);		// N3 = Numero que se quiere elevar al cubo 
		PN = (N3*N3*N3);		// PN = resultado del numero elevado al cuadrado
		printf("El numero %.2f elevado al cuadrado es: %.2f",N3,PN);
		break;
	case 3:
		printf("--------Promedio de 3 calificaciones--------\nIngrese primera calificacion: ");
		scanf("%f",&Cal1);
		printf("Ingrese segunda calificacion: ");
		scanf("%f",&Cal2);
		printf("Ingrese tercera calificacion: ");
		scanf("%f",&Cal3);
		SumCal = Cal1 + Cal2 + Cal3;		//Suma calificaciones
		PromCal = SumCal/3;			//PromCal = Promedio de las calificaciones ingresadas
		printf("El promedio de las 3 calificaciones es: %.2f",PromCal);
		break;	
	default:
		printf("ERROR\n Numero no valido");
		break;	
	}
	
	getch();
}
