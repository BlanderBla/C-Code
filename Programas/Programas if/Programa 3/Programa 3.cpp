/*
Considere dos variables de tipo int llamadas temperatura y presion. Escriba
una sentencia if-else que muestre en pantalla la palabra Alarma si la
variable presion es mayor a 200 o si la variable temperatura es mayor a
100. En caso contrario, se debe mostrar en pantalla la palabra Normal
*/
#include<stdio.h>
#include<windows.h>

int P, T; // P = Presión ; T = Temperatura

main()
{
	printf("________ALARMA________\n\nIngrese la presion: ");
	scanf("%d",&P);
	printf("Ingrese la temperatura: ");
	scanf("%d",&T);
	
	if(P>200 || T>100){
		printf("\n\nALARMA");
	}else{
		printf("Normal");
	}
	
	return(0);
}
