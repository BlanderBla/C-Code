/*
	Brayan Adrian Galvan Flores | 181112
	Unico creador del laberinto
*/
// LIBRERIAS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

// CONSTANTES
#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define ESC 27
#define ENTER 13

// FUNCIONES
void logo1 (void);
void logo2 (void);
void textoError(void);
void cambiosPantalla(void);
void reglas(void);
void Datos(char (*nombre)[30], char (*password)[30]);
void Load(void);
void menu(void);
int scroll_Menu(void);
void Juego(char tecla);
void Score(char nombre[30], char password[30]);
void Ayuda(void);
void Salir(void);
//VARIABLES GLOBALES
int i,j, nivel=1, puntos=0, vidas=3;
char cuadros[27][36]={
	{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},//1
	{15,0,15,15,15,0,15,15,0,0,15,15,0,0,0,15,0,0,0,15,0,15,0,15,15,0,15,0,0,0,15,15,0,0,15,15},//2
	{15,0,15,15,0,15,0,15,0,15,0,15,0,15,15,15,0,15,0,15,0,15,0,15,15,0,15,15,0,15,15,0,15,15,0,15},//3
	{15,0,15,15,0,0,0,15,0,0,15,15,0,0,15,15,0,0,15,15,0,15,0,0,15,0,15,15,0,15,15,0,15,15,0,15},//4
	{15,0,15,15,0,15,0,15,0,15,0,15,0,15,15,15,0,15,0,15,0,15,0,15,0,0,15,15,0,15,15,0,15,15,0,15},//5
	{15,0,0,15,0,15,0,15,0,0,15,15,0,0,0,15,0,15,0,15,0,15,0,15,15,0,15,15,0,15,15,15,0,0,15,15},//6
	{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},//7
	{15,0,0,0,0,0,0,0,0,0,15,0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,15},//	8
	{15,0,15,15,15,0,15,0,15,15,15,0,15,15,15,15,15,0,15,0,15,15,15,0,15,15,15,15,15,0,15,0,0,0,0,15},	//	9
	{15,0,15,0,0,0,15,0,15,0,15,0,15,0,0,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,0,15},//	10
	{15,0,15,15,15,15,15,0,15,0,15,0,15,0,15,15,15,15,15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,0,15},//	11
	{15,0,15,0,0,0,0,0,15,0,15,0,15,0,0,0,0,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,0,15},//12
	{15,0,15,0,15,15,15,0,15,0,15,0,15,15,15,0,15,15,15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,0,15},//13
	{15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,0,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,0,15},//	14
	{15,4,15,15,15,0,15,15,15,0,15,0,15,15,15,15,15,0,15,0,15,0,15,15,15,0,15,0,15,15,15,0,0,0,0,15},//15
	{15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,15},//16
	{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},//1
	{15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,15},//18
	{15,0,15,15,15,15,15,15,15,0,15,0,15,15,15,0,15,15,15,0,15,15,15,15,15,0,15,15,15,4,15,0,0,0,0,15},//19
	{15,0,15,0,15,0,0,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,15,0,15,0,15,0,0,0,0,15},//20
	{15,0,15,0,15,15,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15,15,15,0,15,0,15,0,0,0,0,15},//21
	{15,0,15,0,0,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,15,0,0,0,0,0,15,0,15,0,0,0,0,15},//22
	{15,0,15,0,15,15,15,0,15,0,15,15,15,0,15,0,15,0,15,15,15,0,15,15,15,0,15,15,15,0,15,0,0,0,0,15},//23
	{15,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,15,0,0,0,15,0,0,0,15,0,15,0,0,0,15,0,0,0,0,15},//24
	{15,0,15,0,15,15,15,0,15,15,15,0,15,15,15,15,15,15,15,0,15,0,15,15,15,15,15,15,15,0,15,0,0,0,0,15},//25
	{15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,0,0,0,0,15},//26
	{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},//1
};

char perder[20][33]={
	{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},//1
	{15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//2
	{15,0,15,0,0,15,0,0,15,0,0,0,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//3
	{15,0,15,0,0,15,0,15,0,15,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//4
	{15,0,15,0,0,15,0,15,0,15,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//5
	{15,0,15,15,15,15,0,15,15,15,0,0,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//6
	{15,0,15,0,0,15,0,15,0,15,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//7
	{15,0,15,0,0,15,0,15,0,15,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//8
	{15,0,15,0,0,15,0,15,0,15,0,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//9
	{15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//11
	{15,0,15,15,0,0,15,15,15,0,15,15,15,0,0,15,15,15,0,0,15,0,15,15,15,0,0,0,15,15,0,0,15},//12
	{15,0,15,0,15,0,15,0,0,0,15,0,0,15,0,15,0,0,15,0,15,0,15,0,0,15,0,15,0,0,15,0,15},//13
	{15,0,15,0,15,0,15,0,0,0,15,0,0,15,0,15,0,0,15,0,15,0,15,0,0,15,0,15,0,0,15,0,15},//14
	{15,0,15,15,0,0,15,15,0,0,15,15,15,0,0,15,0,0,15,0,15,0,15,0,0,15,0,15,0,0,15,0,15},//15
	{15,0,15,0,0,0,15,0,0,0,15,15,0,0,0,15,0,0,15,0,15,0,15,0,0,15,0,15,0,0,15,0,15},//16
	{15,0,15,0,0,0,15,0,0,0,15,0,15,0,0,15,0,0,15,0,15,0,15,0,0,15,0,15,0,0,15,0,15},//17
	{15,0,15,0,0,0,15,0,0,0,15,0,0,15,0,15,0,0,15,0,15,0,15,0,0,15,0,15,0,0,15,0,15},//18
	{15,0,15,0,0,0,15,15,15,0,15,0,0,15,0,15,15,15,0,0,15,0,15,15,15,0,0,15,15,15,0,0,15},//19
	{15,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},//20
	{15,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},//21
};

//FUNCION GOTOXY
void gotoxy(int x,int y){
 HANDLE hcon;
 hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y= y;
 SetConsoleCursorPosition(hcon,dwPos);
} 

main(){
	int i; // i --> incremento
	char nombre[30];	// Guarda el nombre del usuario
	char password[30];	// Guarda la contraseña del usuario
	char tecla;	// Guarda el valor de una tecla dada por el usuario
	int opc;	// Guarda el valor que retorna de la función scroll_Menu --> Guarda la opción que selecciona el usuario
	
	system("MODE 130 , 40");	// Modifica el tamaño de la consola
	
	srand(time(0));
	
	logo1();		// Llama a la función 'logo' --> Solamente muestra el logo
	Sleep(5000);
	system("cls");
	
	textoError();	// Llama a la función 'textError' --> Muestra el mensaje de error
	Sleep(2500);
	system("cls");
	
	cambiosPantalla();	// Llama a la funcion 'cambiosPantalla'
	
	Load();		// Llama a la función 'Load'
	
	printf("\n\nPresiona cualquier boton para continuar.");
	getch();
	
	system("cls");
	
	Datos(&nombre,&password); // Llama a la funcion 'Datos'
	
	system("cls");
	
	do{
		logo2();
		gotoxy(90,4);printf("Bienvenido %s",nombre);
		menu();
		opc = scroll_Menu();
		system("cls");
		switch(opc){
			case 1: 
				Juego(tecla);
				break;
			case 2: 
				Ayuda();
				break;
			case 3: 
				Score(nombre,password);
				break;
			case 4: 
				Salir();
				break;	
		}
		getch();
		system("cls");
	}while(opc!=4);
}
/*
	FUNCION LOGO --> Esta función esta encargada de mostrar la imagen (carácteres)
	del arreglo de cuadros[][], CON un tiempo de espera
*/
void logo1 (void){
	int x=8,y=4;
	for(i=0;i<31;i++,y++){
		gotoxy(x=8,y);
		printf("%c\n",219);
	}
	for(j=0;j<77;j++,x++){
		gotoxy(x,y);
		printf("%c",219);
	}
	for(i=0;i<31;i++,y--){
		gotoxy(x,y);
		printf("%c\n",219);
	}
	for(j=0;j<77;j++,x--){
		gotoxy(x,y);
		printf("%c",219);
	}
	x=10;
	y=6;
	for(i=0;i<27;i++,y++){
		gotoxy(x=10,y);	//Indica la posición en la cual empezaremos
		for(j=0;j<36;j++){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cuadros[i][j]);		//cuadros en una variable global
			printf("%c",219);
			Sleep(1);
		}
		for(j=36;j>=0;j--){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cuadros[i][j]);		//cuadros en una variable global
			printf("%c",219);
		}
		printf("\n");
	}
}	
/*
	FUNCION textoError --> Esta función se encarga de mostrar en pantalla un texto de error
*/
void textoError(void){
	system("color 17");
	Sleep(10);
	printf("A problem has been detected and windows has been shut down to prevent damage\nto your computer.\n\n");
	printf("END_OF_NT_EVALUATION_PREIOD\n\n");
	printf("If this is the first time you've seen this stop error screen,\n restart your computer. I this screen appears again, follow these steps:\n\n");
	printf("Check to make sure any new hardware or software is properly installed.\nIf this is a new installation, ask your hardware or software manufacturer for any windows updates you might need\n");
	printf("If problems continue, disable or remove any newly installed hardware or software. Disable BIOS memory options such as caching or shadowing.\n");
	printf("If you need to use safe Mode to remove or disable components, restart your computer, press F8 to select Advance Startup Options, and then select safe Mode\n\nTechnical information:\n\n");
	printf("*** STOP: 0x00000098 (0x986c83A0,0x01c7DAB7, 0x0002A300, 0x00000000)");
}
/*
	FUNCION cambiosPantalla --> Esta función se encarga de simular los cambios de pantalla 
	posterior al mensaje de error
*/
void cambiosPantalla(void){
	Sleep(1000);
	system("color 41");
	Sleep(250);
	system("color 07");
	Sleep(250);
	system("cls");
	printf("Univerdidad Politecnica de San Luis Potosi\nBrayan Adrian Galvan Flores\nProgramacion I\n");
}

/*
	FUNCION Load --> Se encarga de mostrar en pantalla valores del 1 al 10 simulando que 
	esta cargando el contenido
*/
void Load(){
	int i;
	gotoxy(10,5);
	printf("\n\tCargando...\n\t");
	for(i=1;i<11;i++){
		Sleep(1000);
		printf("%i ",i);
	}
}
/*
	FUNCION Datos --> Esta función se encarga de solicitar los datos del usuario
	Su nombre y contraseña, la función es paso por parámetro
*/
void Datos(char (*nombre)[30], char (*password)[30]){
	
	FILE *ftp;
	
	printf("\n\t------ %c BIENVENIDO AL LABERINTO %c -----\n\n\tNombre del jugador: ",219,219);
	gets(*nombre);
	printf("\tContrasena: ");
	gets(*password);
	
	ftp=fopen("Jugadores.txt","a");
	if(ftp != NULL){
		fprintf(ftp,"%s\n",*nombre);
		fprintf(ftp,"%s\n",*password);
		fprintf(ftp,"\n");
	    fclose(ftp);
	    printf("\n\tDatos guardados\n\n\tPresione cualquier tecla para continuar");
	    getch();
	}else{
		printf("NO se existe el archivo");
	}
}
/*
	FUNCION Logo2 --> Esta función esta encargada de mostrar la imagen (carácteres)
	del arreglo de cuadros[][], SIN un tiempo de espera
*/
void logo2(void){
	int x=8,y=4;
	for(i=0;i<31;i++,y++){
		gotoxy(x=8,y);
		printf("%c\n",219);
	}
	for(j=0;j<77;j++,x++){
		gotoxy(x,y);
		printf("%c",219);
	}
	for(i=0;i<31;i++,y--){
		gotoxy(x,y);
		printf("%c\n",219);
	}
	for(j=0;j<77;j++,x--){
		gotoxy(x,y);
		printf("%c",219);
	}
	x=10;
	y=6;
	for(i=0;i<27;i++,y++){
		gotoxy(x=10,y);	//Indica la posición en la cual empezaremos
		for(j=0;j<36;j++){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cuadros[i][j]);		//cuadros en una variable global
			printf("%c",219);
		}
		for(j=36;j>=0;j--){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cuadros[i][j]);		//cuadros en una variable global
			printf("%c",219);
		}
		printf("\n");
	}
}
/*
	FUNCION menu --> Esta función solamente muestra el menu del inicio
*/
void menu(void){
	gotoxy(95,8);printf("JUGAR");
	gotoxy(95,9);printf("AYUDA");
	gotoxy(95,10);printf("SCORE");
	gotoxy(95,11);printf("SALIR");
}
/*
	FUNCION scroll_Menu --> Esta función permite desplasarze por el menu ademas de que 
	guarda la opción que se selecciono y la retorna al main
*/
int scroll_Menu(void){
	char tecla;		// Variable que almacena cualquier dato ingresado por teclado
	int opcion = 1,y;	
			/* Variable opcion --> Almacena dependiendo de la posición en la que se encuentre
				el valor de la opcion, esta retorna para evaluar la opcion seleccionada 
				y poder saber que realizae (switch)		*/
	
	gotoxy(93,y=8); 	// A partir de esta cordenada indicamos donde se va a posicionar el cursor
	printf("%c",219);	//Imprime el cursos
	
	do{
		tecla=getch(); 
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0);
	 	
		gotoxy(93,y);
		printf("%c",219);
	 	
		if(tecla==80 && y<11){ 	// 'P' 80 ABAJO
			y++;
			opcion++;	//Incrementa la opcion
	 	}
	 	if(tecla==72 && y>8){ //'H' ARRIBA 	
		 	y--;
			opcion--;
	 	}
	 	
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);	//Cambia el color
	 	
		gotoxy(93,y);
			printf("%c",219);	//	
	 	
	 }while(tecla!=ESC && tecla!=ENTER);	// Se realizará mientras no se presione la(s) tecla(s) 27 --> ESC && 13 --> ENTER
	 return opcion;	//Retornará la opción que se eligio
}
/*
	FUNCION Ayuda  --> Muestra ayuda referente al juego.
*/
void Ayuda(void){
	gotoxy(85,3);
	printf("Universidad Politecnica de San  Luis Potosi");
	gotoxy(85,4);
	printf("Brayan Adrian Galvan Flores | 181112");
	gotoxy(0,0);
	printf("\n\t\t\t-----   AYUDA   ----\n\n\tAcademia de Tecnolog%cas de la Informaci%cn y Telem%ctica\n\t\t    Centro de Nuevas Tecnologias",161,162,160);
	printf("\n\n\n\n\tCarrera\t\tCiclo\t\t\tAsignatura\n\tITI\t\tPrimavera 2018\t\tProgramacion I\n\n\n");
	printf("\t%c",1);
	printf(" --> TU PERSONAJE");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	printf("\n\t%c",3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); 		
	printf("--> Vidas\n\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	printf("W");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf(" --> Monstrous\n\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("%c",219);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("--> Muro\n\t");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("%c",219);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf(" --> Objetivo");
	printf("\n\n\n\t\t1. El jugador dispone de 3 vidas.\n\t\t2. El jugador puede moverse hacia arriba, abajo, derecha, izquierda con las flechas del teclado.\n\t\t3. Si cae en una casilla donde este una criatura perder%c 1 vida.\n\t\t4. El juego terminar%c cuando llegue al objetivo o pierda ssu vidas.\n\t\t5. En el transcurso puede encontrar m%cs vidas.\n\n\n\tPresione cualquier tecla para regresar ",160,160,160);
}
void Vida(void){
	gotoxy(95,6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("VIDAS");
	for(i=0;i<3;i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		printf("%c",3);
	}
}

void Juego(char tecla){
	int juego[30][78], cM=0;
	
	int x=8,y=4;
	for(i=0;i<31;i++,y++){
		gotoxy(x=8,y);
		printf("%c\n",219);
	}
	for(j=0;j<79;j++,x++){
		gotoxy(x,y);
		printf("%c",219);
	}
	for(i=0;i<31;i++,y--){
		gotoxy(x,y);
		printf("%c\n",219);
	}
	for(j=0;j<79;j++,x--){
		gotoxy(x,y);
		printf("%c",219);
	}
	
	gotoxy(95,4);
		printf("NIVEL: %i",nivel);
	gotoxy(110,4);
		printf("PUNTOS: %i",puntos);
	gotoxy(95,6);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("VIDAS: %i",vidas);
	
	for(i=0, y=5;i<30;i++, y++,cM++){
		gotoxy(9,y);
		int a=8,b=4;
	
		for(j=0;j<78;j++){
			
			juego[i][j] = rand()%15+1;	
			juego[29][77]=16;					
			
			if(juego[i][j]==1){		// IMPRIME UN BORDE
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);	
				printf("%c",219);
			}else if(juego[i][j]==2){	// IMPRIME UN BORDE
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);	
				printf("%c",219);
			}else if(juego[i][j]==3){	// IMPRIME UN BORDE
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);	
				printf("%c",219);}
			else if(juego[i][j]==5 && cM!=5){		// IMPRIME UN MONSTRUO
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);	
				printf("W");
			}else if(juego[i][j]==4){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);	
				printf("%c",3);
			}else if(juego[i][j]==16){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);	
				printf("%c",219);
			}else{	// IMPRIME UN ESPACIO EN BLANCO --> UN CAMINO
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);	
				printf(" ");
			}
		}
		printf("\n");
	}
	//Realiza el desplazamiento dentro del juego
	
	x=9;
	y=5;
	gotoxy(0,0);
	do{
		tecla = getch();
		gotoxy(x,y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);	
		printf("%c",219);
		
		//DERECHA
		if(tecla == DERECHA && x<86){
			if( juego[y-5][x+1-9]!=1 && juego[y-5][x+1-9]!=2 && juego[y-5][x+1-9]!=3) {
				x++;
			}if(juego[y-5][x-9]==4){
				juego[y-5][x-9]=20;
				vidas++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}if(juego[y-5][x-9]==5){
				juego[y-5][x-9]=20;
				vidas--;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}if(juego[y-5][x-9]==16){
				nivel++;
				puntos+=10;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
				Juego(tecla);
			}	
		}
		//IZQUIERDA
		if(tecla == IZQUIERDA && x>9){
			if( juego[y-5][x-1-9]!=1 && juego[y-5][x-1-9]!=2 && juego[y-5][x-1-9]!=3){
				x--;
			}if(juego[y-5][x-9]==4){
				juego[y-5][x-9]=20;
				vidas++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}if(juego[y-5][x-9]==5){
				juego[y-5][x-9]=20;
				vidas--;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}	
		}
		//ABAJO
		if(tecla == ABAJO && y<34){
			if(juego[y+1-5][x-9]!=1 && juego[y+1-5][x-9]!=2 && juego[y+1-5][x-9]!=3){
				y++;
			}if(juego[y-5][x-9]==4){
				juego[y-5][x-9]=20;
				vidas++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}if(juego[y-5][x-9]==5){
				juego[y-5][x-9]=20;
				vidas--;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}if(juego[y-5][x-9]==16){
				nivel++;
				puntos+=10;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
				Juego(tecla);
			}	
		}
		//ARRIBA
		if(tecla == ARRIBA && y>5){
			if( juego[y-1-5][x-9]!=1 && juego[y-1-5][x-9]!=2 && juego[y-1-5][x-9]!=3 ){
				y--;
			}if(juego[y-5][x-9]==4){
				juego[y-5][x-9]=20;
				vidas++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}if(juego[y-5][x-9]==5){
				juego[y-5][x-9]=20;
				vidas--;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				gotoxy(95,4);
					printf("NIVEL: %i",nivel);
				gotoxy(110,4);
					printf("PUNTOS: %i",puntos);
				gotoxy(95,6);
					printf("VIDAS: %i",vidas);
			}
		}
		gotoxy(x,y);
		if(vidas==0){
			gotoxy(x=95,y=10);
			for(i=0;i<21;i++,y++){
				gotoxy(x,y);
				for(j=0;j<33;j++){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),perder[i][j]);
					printf("%c",219);
				}
				printf("\n");
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);	
		printf("%c",1);
	}while(tecla!=ESC && vidas!=0);	
	vidas = 3;
	nivel = 1;
	puntos = 0;
}

void Score(char nombre[30], char password[30]){
	printf("\n\tSCORE\n\n");
		FILE *ftp;
		int i,n=0;
	ftp = fopen("Jugadores.txt","r");
	if(ftp != NULL ){
   		while(!feof(ftp)){
			fscanf(ftp,"%[^\n]\n",nombre);
			fscanf(ftp,"%[^\n]\nContrasena",password);
			printf("Jugador: %s\tContrasena: %s\n",nombre,password);
		}
	}else{
		printf("NO se existe el archivo");
	}
}

void Salir(){
	int y = 4;
	printf("\n\n\tAcademia de Tecnologias de la Informacion y Telematica\n\t\t    Centro de Nuevas Tecnologias");
	printf("\n\n\n\t\tUniverdidad Politecnica de San Luis Potosi\n\t\tBrayan Adrian Galvan Flores\n\t\tProgramacion I\n");
	printf("\n\n\t-->Presione cualquier tecla para salir\n\n");
}
