/*	Calcular el factorial de un nímero entero positivo (n!)
	Ejemplo: El favtor de 5!= 5x4x3x2x1=120
	Matrícula 181112
*/
#include <conio.h>
#include <stdio.h> 
int main() {
	int Num,C = 1,i = 1;
	printf("_____FACTORIAL DE N!_____\n\nDame el numero para el factorial: ");
	scanf("%d",&Num);
	while(i<=Num){
 		C = C * i;	/* 
 						C inicia en 1 ya que sí fuera 0, todo numero multiplicado por 0 da 0 y el contado siempre nos daría 0; 
						 sucedería lo mismo sí inicializamos i en 0.
		 					C = Contador; Almacena el producto del factorial: 1*1=1; 1*2=2; 2*3=6; 6*4=24; 24*5=120... 
							Como se ve se esta almacenando el resultado e inicia con el mismo resultado en el siguiente ciclo
 						
						Dado que el factorial es la multiplicación de todos los números que anteceden a un numero
						lo que podemos ver C=C*i; donde C va a ir guardando el resultado y ese resultado lo va a multiplicar por el incremento de i
						ya que antes de que termine el ciclo, tiene un incremento de 1(i++) 
						Ej. 1*1=1; 1*2=2; 2*3=6; 6*4=24; 24*5=120; 120*6=720; 720*7=5040; 5040*8=40320...
						donde el incremento es el numero hasta el cual se va a querer sacar el factorial
					*/
 		i++;	// i = incremento; Inicia en 1 y termina en el numero dado.
	}
 	printf("El factorial de %d es: %d",Num,C);
	getch();
}
