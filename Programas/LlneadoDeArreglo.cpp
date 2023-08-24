#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

	#define ARRIBA 72
	#define ABAJO 80
	#define DERECHA 77
	#define IZQUIERDA 75
	#define ESC 27
	#define ENTER 13

/*
	1 = BLOQUE
	2 = VIDA
	3 = MOSNTRUO
	4 = VACIO
*/

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
SetConsoleCursorPosition(hcon,dwPos);
} 

main(){
	
	int array[10][15], i , j , x , y , vida=3 ;
	char tecla;
	/*
		Asigna numeros aleatorios y los almacena en la 
		posición i y j del arreglo bidimensional
	*/
	for(i=0;i<10;i++){
		for(j=0;j<15;j++){
			array[i][j] = rand()%4+1;
		}
	}	
	/*
		Asigna los numeros aleatorios que almacenó en la 
		posición i y j del arreglo bidimensional
	*/
	for(i=0, y=0;i<10;i++, y++){
		for(j=0, x=0;j<15;j++, x++){
			if(array[i][j] == 1){
				printf("%c",219);
			}
			if(array[i][j] == 2){
				printf("%c",3);
			}
			if(array[i][j] == 3){
				printf("W");
			}
			if(array[i][j] == 4){
				printf(" ");
			}
		}
		printf("\n");
	}
	x=0;
	y=0;
	gotoxy(0,0);
	do{
		tecla = getch();
		
		//DERECHA
		if(tecla == DERECHA && x<14){
			x++;
		}
		//IZQUIERDA
		if(tecla == IZQUIERDA && x>0){
			x--;
		}
		//ABAJO
		if(tecla == ABAJO && y<9){
			y++;
		}
		//ARRIBA
		if(tecla == ARRIBA && y>0){
			y--;
		}
		gotoxy(x,y);
		printf("%c",1);
	}while(tecla!=ESC);	
	
	getch();
	return 0;
}
