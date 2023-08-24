#include <stdio.h>

void validate(int a);

int main(){
	int a;
	printf("\n\tPut the value (int) > ");
	scanf("%i",&a);
	
	if(a%2 == 0){
		printf("\n\t%i is par",a);
		validate(a);
	}else{
		printf("\n\t%i is impar",a);
		validate(a);
	}
	return 0;
}

void validate(int a){
	if(a==0){
		printf("\n\tThe number is 0");
	}else if(a > 0){
		printf("\n\tThe number is positive");
	}else{
		printf("\n\tThe number is negative");
	}
}
