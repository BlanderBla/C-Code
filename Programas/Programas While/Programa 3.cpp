/*  Generar un programa que lea cantidades y precios y al final indique el total de la factura
	Introducimos primero la cantidad vendida, despues le precio y cuando la lectura sea cero escribir� el total	
	Matr�cula 181112 
*/
#include<stdio.h>
#include<conio.h>
int main(){
	int i = 1, C;
	float P, PI ,PagoI, PrecioT, Sum, SumT;
	printf("_____FACTURA_____\n\n%d Ingrese la cantidad: ",i);
	scanf("%d",&C);		//C = Cantidad Inicio; Ind�ca el precio del art�culo pero es el inicial para poder agregar los dem�s
	printf("   Precio: ");
	scanf("%f",&P);		//P = Precio Inicio; Ind�ca el precio del art�culo pero es el inicial para poder comparar los dem�s
	PagoI = C * P;		//PagoI = Pago Inicial; Guarda la cantidad de inicio para posteriormente sumarla
	while(C>0){
		i++;
		printf("%d Ingrese la cantidad: ",i);
		scanf("%d",&C);
		printf("   Precio: ");
		scanf("%f",&P);		//P = Precio; Ind�ca el precio del art�culo
		if(C>0){
			C = C * P ;		//PA = Precio Art�culos; resulta el precio del art�culo por la cantidad a llevar
			Sum = Sum + C;	
		}
	}
	SumT= PagoI + Sum; // Realiza la suma del precio de los articulos iniciales m�s toda la suma de los dem�s art�culos
	printf("El total a pagar eses %.2f",SumT);
	getch();
}
