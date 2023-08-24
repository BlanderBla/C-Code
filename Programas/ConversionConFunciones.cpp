#include<stdio.h>
#include<conio.h>
#include<windows.h>

void titulo(void);
void binario();
void octal();
void hexadecimal();
char funcion(int);

main(){
	int selector;
	
	titulo();
	fflush(stdin);
	scanf("%i",&selector);
	system("cls");
	switch(selector){
		case 1:
				binario();
			break;
		case 2:
				octal();
			break;
		case 3:
				hexadecimal();
			break;
		default:					
			break;
	}
	
	
	getch();
}
//	-->		TITULO		<--	//
void titulo(void){
	printf("\t----- %c CONVERSIONES %c -----\n\nConvierte numeros decimales a cualquiera de las siguientes bases",299,299);
	printf("\nSelecciones a que base desea convertir\n\t1. Binario\n\t2. Octal\n\t3. Hexadecimal\n\t4. Salir\n");
}
//	-->		BINARIO		<--	//
void binario(void){
	int num,mod=0,res=0,a[10],i=0,j;
	printf("\n---- BINARIO ----\nIngrese numero a convertir: ");
	fflush(stdin);
	scanf("%i",&num);
	do{
		res=num/2;
		mod=num%2;
		a[i]=mod;
		num=res;
		i++;
	}while(num>0);
	printf("\nLa conversión es: ");
	for(i=i-1;i>(-1);i--){
		printf("%i",a[i]);
	}
}
//	-->		OCTAL	<--	//
void octal(void){
	int num,mod,res,a[10],i=0;
	printf("\n---- OCTAL ----\nIngrese numero a convertir: ");
	fflush(stdin);
	scanf("%i",&num);
	do{
		res=num/8;
		mod=num%8;
		a[i]=mod;
		num=res;
		i++;
	}while(num>0);
	printf("\nLa conversión es: ");
	for(i=i-1;i>(-1);i--){
		printf("%i",a[i]);
	}
}
void hexadecimal(void){
	int num,mod,res,a[10],i;
	printf("\n---- HEXADECIMAL ----\nIngrese numero a convertir: ");
	fflush(stdin);
	scanf("%i",&num);
	do{
		res=num/16;
		mod=num%16;
		a[i]=mod;
		num=res;
		i++;
	}while(num>0);
	printf("\nLa conversion es: ");
	for(i=i-1;i>(-1);i--){
		if(a[i]>=1 && a[i]<=9){
			printf("%i",a[i]);
		}else if(a[i]>=10 && a[i]<=15){
			if(a[i]==10){
				printf("A");
			}else if(a[i]==11){
				printf("B");
			}else if(a[i]==12){
				printf("C");
			}else if(a[i]==13){
				printf("D");
			}else if(a[i]==14){
				printf("E");
			}else if(a[i]==15){
				printf("F");
			}
		}
	}
}

