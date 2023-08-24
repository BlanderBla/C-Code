/*
Genere  un programa que lea un importe bruto y calcule su importe neto, si es mayor de 15,000 se le aplicará un 16% 
 de impuestos, en caso contrario se le aplicará un 10%.
*/

#include<stdio.h>

float VR, VcI, VN, VNcImp, VNT;

main(){
	printf("________IMPUESTO________\nIngrese el valor real del producto o servicio: ");
	scanf("%f",&VR); // VR = Valor real del producto
	VcI = VR * 0.16;	//VcI Valor con 16% de impuseto (Valor neto)
	printf("\nEl valor neto es: %.2f\n",VcI);
	VN = VcI + VR;		// VN = Valor Neto
	if(VN>=15000){
		printf("Se le aplica impuesto del 16\n");
		VNcImp = VN * 0.16;		//VNcImp = Valor neto con impuesto del 16 %
		VNT = VNcImp + VN;		//VNT = Valor neto total del 16%
		printf("El valor es: %.2f",VNT);		//Solamente muestra centenas de millar
	}else{
		printf("Se le aplica impuesto del 10\n");
		VNcImp = VN * 0.10;		//VNcImp = Valor neto con impuesto del 10 %
		VNT = VNcImp + VN;		//VNT = Valor neto total del 10%
		printf("El valor es: %.2f",VNT);	//Solamente muestra centenas de millar
	}
}
