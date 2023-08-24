#include <stdio.h>
#include <windows.h>

/*
	Brayan Adrian Galvan Flores
	Program 2: Operations with two values
	Description: Make the operations { sum, rest, multiplication and division with only twho inputs }
*/


//	Global Variables
float a=0,b=0;

//	Functions
void show(float a, float b);
float sum(float a, float b);
float rest(float a, float b);
float product(float a, float b);
float div(float a, float b);

int main(){
	
	bool flag = true;
	int option = 0;
	do{
		
		printf("\tFirt value > ");
		scanf("%f",&a);
		printf("\tSecond value > ");
		scanf("%f",&b);

		show(a,b);
		
		printf("\n\tDo you want to repeat? 1. Yes | 2. N0 \n\t> ");
		scanf("%i",&option);
		switch(option){
			case 1: 
				system("cls");
				break;
			case 2: 
				printf("\n\t2. NO");
				flag = false;
				break;
			default: 
				printf("Choose the correct option"); 
		}
	}while(flag);
	
	return 0;
}

void show(float a, float b){
	printf("\n\tSum = %.2f\n",sum(a,b));
	printf("\tRest = %.2f\n",rest(a,b));
	printf("\tMultiplication = %.2f\n",product(a,b));
	printf("\tDivision = %.2f\n",div(a,b));
}

float sum(float a, float b){
	return a + b;
}

float rest(float a, float b){
	return a - b;
}

float product(float a, float b){
	return a * b;
}

float div(float a, float b){
	if(b == 0){
		printf("It's imposible to divide by 0'");
		return 0;
	}else{
		return a / b;	
	}
}
