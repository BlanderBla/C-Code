#include <stdio.h>
#include <windows.h>

#define PI 3.1416

float triangle();
float square();
float rectangle();
float circle();

int main(){	
	bool flag = true;
	int option = 0;
	float area;
	
	do{
		printf("\n\tSelect the operation:\n\t1. Triangle\n\t2. Square\n\t3. Rectangle\n\t4. Circle\n\t5. Salir\n\n\t>");
		scanf("%i",&option);
		switch(option){
			case 1: 
				printf("\n\tTriangle\n\t");
				area = triangle();
				printf("\n\tThe traingle's area is > %.2f",area);
				break;
			case 2:
				printf("\n\tSquare\n\t");
				area = square();
				printf("\n\tThe square's area is > %.2f",area);
				break;
			case 3:
				printf("\n\tRectangle\n\t");
				area = rectangle();
				printf("\n\tThe rectangle's area is > %.2f",area);
				break;
			case 4:
				printf("\n\tCircle\n\t");
				area = circle();
				printf("\n\tThe circle's area is > %.2f",area);
				break;
			case 5:
				printf("\n\tSalir");
				flag = false;
				break;
			default:
				printf("\n\tChoose the correct option");			
		}
	}while(flag);
	return 0;
}

float triangle(){
	float b=0,h=0;
	printf("Put the base > ");
	scanf("%f",&b);
	printf("Put the high > ");
	scanf("%f",&h);
	return (b*h)/2;
}

float square(){
	float l=0;
	printf("Put the size > ");
	scanf("%f",&l);
	return l*l;
}

float rectangle(){
	float b=0,h=0;
	printf("Put the base > ");
	scanf("%f",&b);
	printf("Put the high > ");
	scanf("%f",&h);
	return (b*h);
}

float circle(){
	float r=0;
	printf("Put the radio > ");
	scanf("%f",&r);
	return PI*r*r;
}
