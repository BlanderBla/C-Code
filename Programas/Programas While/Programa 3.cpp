/*  Generar un programa que lea cantidades y precios y al final indique el total de la factura
	Introducimos primero la cantidad vendida, despues le precio y cuando la lectura sea cero escribirá el total	
	Matrícula 181112 
*/
#include<stdio.h>
#include<conio.h>
int main(){
	int i = 1, C;
	float P, PI ,PagoI, PrecioT, Sum, SumT;
	printf("_____FACTURA_____\n\n%d Ingrese la cantidad: ",i);
	scanf("%d",&C);		//C = Cantidad Inicio; Indíca el precio del artículo pero es el inicial para poder agregar los demás
	printf("   Precio: ");
	scanf("%f",&P);		//P = Precio Inicio; Indíca el precio del artículo pero es el inicial para poder comparar los demás
	PagoI = C * P;		//PagoI = Pago Inicial; Guarda la cantidad de inicio para posteriormente sumarla
	while(C>0){
		i++;
		printf("%d Ingrese la cantidad: ",i);
		scanf("%d",&C);
		printf("   Precio: ");
		scanf("%f",&P);		//P = Precio; Indíca el precio del artículo
		if(C>0){
			C = C * P ;		//PA = Precio Artículos; resulta el precio del artículo por la cantidad a llevar
			Sum = Sum + C;	
		}
	}
	SumT= PagoI + Sum; // Realiza la suma del precio de los articulos iniciales más toda la suma de los demás artículos
	printf("El total a pagar eses %.2f",SumT);
	getch();
}
