/*
Determinar en un conjunto de n n�meros dados por el usuario 
� Cu�ntos son menores que 10 ?
� Cu�ntos son mayores que 50 ?
� Cu�ntos est�n en el rango entre 25 y 45 ?
Matr�cula 181112
*/
#include<stdio.h>
#include<conio.h>
int main(){
	int i, D, N, C10=0, CR=0, C50=0; 
	printf("_____CONJUNTO DE N NUMEROS_____\n\nCuantos numeros quiere ingresar: ");
	scanf("%d",&D);		//D = Dato de numeros ingresados por el usuario 
	for(i=1;i<=D;i++){
		printf("Ingrese el numero %d: ",i);
		scanf("%d",&N);	//N = Numero
		if(N<10){
			C10 = C10 + 1;		//C10 = Contador menor a 10
		}
		if(N>50){
			C50 = C50 + 1;		//C50 = Contador mayor a 50
		}
		if(N>=25 && N<=45){		//CR = Contador Rango; Entre 25 y 45
			CR = CR + 1;
		}
	}
	printf("\n\nLos numeros menores a 10 son: %d\n",C10);
	printf("Los numeros entre 25 y 45 son: %d\n",CR);
	printf("Los numeros mayores a 50 son: %d",C50);
	
	getch();
}
