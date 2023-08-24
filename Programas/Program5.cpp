#include<stdio.h>

main(){
	int cont=0;
	int n=0, i, j;
	printf("\tNumeros primos\n\t> ");	
	scanf("%i",&n);
	for(i=1; i<=n ;i++){
		if(n%i == 0){
			printf("\t[%i]\n",i);
		}	
	}
}
