/*
Mostrar los multiplos de 3 hasta 60 e indicar cuantos numero son

Matrícula 181112
*/

#include<stdio.h>
#include<conio.h>

#define p (printf)

int main(){
	
	int Num = 0, i=0;
	
	p("_____MULTIPLOS DE 3 hasta 60_____\n\n");
	while(Num<60){
		Num = Num + 3;
		p("%d\n",Num);
		i++;
	}
	
	p("\n\nLos numeros multiplos de 3 de 3 a 60 son: %d",i);
	
	getch();	
}
