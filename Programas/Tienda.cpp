#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

main(){
	
	srand(time(0));
	system("MODE 120 , 30");
	
	int vendedores, i,j;
	
	printf("\t-----  TIENDA PATITO  -----\n\nCuantos vendedores hay? ");
	scanf("%i",&vendedores);
	
	char lista_nombres[vendedores][20];
	int venta[vendedores][5];	//	Cada vendedor tiene 5 ventas venta[Numero de vendedores][5]
	int sum[vendedores];
	
	for(int i = 0 ; i < vendedores ; i++){
		printf("\n\tVendedor %i - Nombre: ",i+1);
		fflush(stdin);
		gets(lista_nombres[i]);
		for(int j = 0; j < 5 ; j++){
			venta[i][j] = rand()%20+1;
			sum[i] += venta[i][j]; 
		}
	}
	system("cls");
	printf("\t-----  TIENDA PATITO  -----\n\n");
	for(int i = 0 ; i < vendedores ; i++){
		printf("No.\tVendedor\tVenta 1\tVenta 2\tVenta 3\tVenta 4\tVenta 5\tTotal\n------------------------------------------------------------------------\n%i\t%s\t",i+1,lista_nombres[i]);
		for(int j = 0; j < 5 ; j++){
			printf("\t%i",venta[i][j]); 
		}
		printf("\t%i\n\n",sum[i]);
	}
}

