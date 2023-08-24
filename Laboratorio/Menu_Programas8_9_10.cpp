/*
	
	Práctica 8 - Desarrolle un programa que simule la atención de pacientes en un hospital.
	Práctica 9 - Desarrolle un programa que imprima una serie de números impares en forma de matriz.
	Práctica 10 - Uso de GOTOXY

*/

#include<stdio.h>
#include<conio.h>
#include<windows.h>

int menu();
/*Funciones para la Práctica 8*/
void IngresoDatosHP8(int &, char nombre[30], int &, int &);
int DiagnosticoHP8 (int id, char nombre[], int edad, int tipoEnf); 
float GeneraCostoHP8(int id, int tipoEnf , int diagnostico);
void Imprimir(int id, char nombre[30], int tipoEnf, int edad, int tratamiento, float costo);

/*Funciones para la Práctica 9*/

void pideTam(int &tam);
void imprime(int tam, int &num);

/*Funciones para la Práctica 10*/
void titulo();
int valor1();
int valor2();
void izq(int);
void der(int);
void lineaAmarilla();
int suma(int, int);
void analisis(int);

/*Funcion GOTOXY*/
void gotoxy(int x,int y){
 HANDLE hcon;
 hcon = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD dwPos;
 dwPos.X = x;
 dwPos.Y= y;
 SetConsoleCursorPosition(hcon,dwPos);
} 

main(){
	
	int selector , diagnostico, v1, v2, sumaT, tam, num;
	float costo;
	int id, tipoEnf, edad;
	char nombre[30];
	
	/*-----------------------------------------------------------------------------------------------------------------------------------------------*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);	
	do{
		selector = menu();
		switch(selector){
			case 1: 
				system("cls");	// Limpia la pantalla para empezar el programa adecuadamente
				printf("Practica 8\n\n");
				IngresoDatosHP8(id,nombre,tipoEnf,edad);				
				diagnostico = DiagnosticoHP8 (id,nombre,edad,tipoEnf);
				costo = GeneraCostoHP8(id, tipoEnf, diagnostico);
				Imprimir(id,nombre,tipoEnf,edad,diagnostico,costo);
				getch();	// Cuando se termine de ejecutar la "Practica 8" se espera una tecla ingresada por pantalla
				system("cls");	//Limpia la pantalla para mostrar el menu otra vez.
				break;
			case 2:
				system("cls");
				printf("Practica 9");

				pideTam(tam);
				imprime(tam, num);
				
				getch();
				system("cls");
				break;
			case 3: 
				system("cls");
				printf("Practica 10");
				
				titulo();
				v1 = valor1();
				v2 = valor2();
				izq(v1);
				der(v2);
				gotoxy(0,10);
				lineaAmarilla();
				sumaT = suma(v1,v2); 
				analisis(sumaT);
				
				getch();
				system("cls");
				break;
			case 4:
				system("cls");
				printf("Salir");
				
				getch();
				system("cls");
				break;
			default:
				system("cls");
				printf("\n\tOPCION NO VALIDA\n\n\tPresione cualquier tecla para regresar");
				
				getch();
				system("cls");
				break;					
		}
	}while(selector!=4);
}

int menu(){
	int x;	//La variable 'x' va a almacenar la opcion y es la que va a retornar el valor a la variable 'selector'.
	printf("\n\tBIENVENIDO\n\tEstos son los programas realizados este 3er parcial \n\n\t\t1. Practica 8\n\t\t2. Practica 9\n\t\t3. Practica 10\n\t\t4. Salir\n\n\tCual es su eleccion? ");
		fflush(stdin);
	scanf("%i",&x);
	return x;
}
/* --> Funciones para la práctica 8 <-- */
void IngresoDatosHP8(int &id, char nombre[30], int &tipoEnf, int &edad){
	printf("\tIngrese su id: ");
		fflush(stdin);
	scanf("%i",&id);
	printf("\tIngrese su nombre: ");
		fflush(stdin);
	gets(nombre);
	printf("\n\tEnfermedades\n\n\t\t1. Diabetes\n\t\t2. Hipertensión\n\t\t3. Cirrosis\n\n\tDe las opciones, eliga su enfermedad: ");
		fflush(stdin);
	scanf("%i",&tipoEnf);
	printf("\tIngrese su edad: ");
		fflush(stdin);
	scanf("%i",&edad);
}

int DiagnosticoHP8 (int id, char nombre[],int edad, int tipoEnf){
	
	system("cls");
	
	int tratamiento;
	
	printf("\n\tId: %i\n\tNombre: %s\n\tEnfermedad: %i\n\tEdad: %i",id,nombre,tipoEnf,edad);
	
	printf("\n\n\tTrtatamiento\n\t-----------------------------------------------\n");
	switch(tipoEnf){
		case 1: 
			printf("\tTratamiento para la Diabetes\n");
			if(edad<=25){
				printf("\t\tTratamiento 1 - Diabetes");
				tratamiento = 1;
				printf("\n\t\t\tMetformina 500 - $100");
			}else if(edad>25 && edad<60){
				printf("\t\tTratamiento 2 - Diabetes");
				tratamiento = 2;
				printf("\n\t\t\tMetformina 500 - $100\n\t\t\tEnalapril 100 - $50");
			}else if(edad>=60){
				printf("\t\tTratamiento 3 - Diabetes");
				tratamiento = 3;
				printf("\n\t\t\tMetformina 500 - $100\n\t\t\tEnalapril 100 - $50\n\t\t\tRanitidaina 100 - $100");
			}
			break;
		case 2:
			printf("\tTratamiento para la Hipertension\n");
			if(edad<=25){
				printf("\t\tTratamiento 1 - Hipertension");
				tratamiento = 1;
				printf("\n\t\t\tMedicamento Hiper - $100");
			}else if(edad>25 && edad<60){
				printf("\t\tTratamiento 2 - Hipertension");
				tratamiento = 2;
				printf("\n\t\t\tMedicamento Hiper. - $100\n\t\t\tTabletas Hiper. - $75");
			}else if(edad>=60){
				printf("\t\tTratamiento 3 - Hipertension");
				tratamiento = 3;
				printf("\n\t\t\tMedicamento Hiper. - $100\n\t\t\tTabletas Hiper. - $75\n\t\t\tSolucion Hiper. - $200");
			}
			break;
		case 3:
			printf("\tTratamiento para la Cirrosis\n");
			if(edad<=25){
				printf("\t\tTratamiento 1 - Cirrosis");
				tratamiento = 1;
				printf("\n\t\t\tMedicamento Cirrosis - $200");
			}else if(edad>25 && edad<60){
				printf("\t\tTratamiento 2 - Cirrosis");
				tratamiento = 2;
				printf("\n\t\t\tMedicamento Cirrosis. - $200\n\t\t\tTabletas Cirrosis. - $125");
			}else if(edad>=60){
				printf("\t\tTratamiento 3 - Cirrosis");
				tratamiento = 3;
				printf("\n\t\t\tMedicamento Cirrosis. - $200\n\t\t\tTabletas Cirrosis. - $125\n\t\t\tSolucion Cirrosis. - $200");
			}
			break;
	}
	return tratamiento;
}

float GeneraCostoHP8(int id, int tipoEnf, int diagnostico){
	float costo;
	switch(tipoEnf){
		case 1:
			if(diagnostico == 1){
				costo = 100.00;
			}else if(diagnostico == 2){
				costo = 100.00 + 50.00;
			}else if(diagnostico == 3){
				costo = 100.00 + 50.00 + 100.00;
			}
			
			break;
		case 2:
			if(diagnostico == 1){
				costo = 100.00;
			}else if(diagnostico == 2){
				costo = 100.00 + 75.00;
			}else if(diagnostico == 3){
				costo = 100.00 + 75.00 + 200.00;
			}
			break;
		case 3:
			if(diagnostico == 1){
				costo = 200.00;
			}else if(diagnostico == 2){
				costo = 200.00 + 125.00;
			}else if(diagnostico == 3){
				costo = 200.00 + 125.00 + 200.00;
			}
			break;		
	}
	return costo;
}
void Imprimir(int id, char nombre[30], int tipoEnf, int edad, int diagnostico, float costo){
	printf("\n\n\t---------------------------------------------");
	printf("\n\tId: %i\n\tNombre: %s\n\tEnfermedad: %i\n\tEdad: %i\n\tDiagnostico: %i\n\tCosto: %.2f",id,nombre,tipoEnf,edad,diagnostico,costo);
	printf("\n\t---------------------------------------------");
}

/* --> Funciones para la práctica 9 <-- */

bool EsPar(int &num){
	float residuo=0;
	residuo=num%2;
	if (num%2==0){ //impar
		return true;
	}else{
		return false;		//par
	}		
}
// El numero de la matriz
void pideTam(int &tam){
	printf("\n\nIngresa el numero de la matriz: ");
	scanf("%d",&tam);
}
//En esta seccion se generan los numeros random
void GeneranumImpar(int inicio, int final, int num){
	inicio=1;
	final=10;
	num=rand()%10;
	while(EsPar(num) == true){ 
	num=inicio+rand()%(final+1 - inicio);
		}
		printf("%d",num);
}
//Impresion de datos
void imprime(int tam, int &num){
int inicio;
int final;
		for(int i=0; i<tam; i++){
			for(int j=0; j<tam; j++){
				GeneranumImpar(inicio,final,num);
				printf("\t");
			}
			printf("\n");
		}
}	

/* --> Funciones para la práctica 10 <-- */
void titulo(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(25,0);
	printf("Titulo");
}
int valor1(){
	int v1;
	gotoxy(2,5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Ingrese el primer valor: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	scanf("%i",&v1);
	return v1;
}
int valor2(){
	int v2;
	gotoxy(45,5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Ingrese el segundo valor: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	scanf("%i",&v2);
	return v2;
}
void izq(int v1){
	gotoxy(2,8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Par/Impar: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	if(v1%2==0){
		printf("Par");
	}else{
		printf("Impar");
	}
}
void der(int v2){
	gotoxy(45,8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Par/Impar: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	if(v2%2==0){
		printf("Par");
	}else{
		printf("Impar");
	}
}	
void lineaAmarilla(){
	for(int i=0; i<80; i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("_");
	}
}
int suma(int v1, int v2){
	gotoxy(30,12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	printf("Suma: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("%i",v1+v2);
	gotoxy(0,14);
	lineaAmarilla();
	return v1+v2;
}
void analisis(int sumaT){
	gotoxy(3,18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	printf("<<--Analisis-->>");
	
	gotoxy(25,18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	if(sumaT <25 ){
		printf("Sumatoria Basica");
	}else if(sumaT>=25 && sumaT<=80){
		printf("Sumatoria Intermedia");
	}else if(sumaT>80){
		printf("Sumatoria Avanzado");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
