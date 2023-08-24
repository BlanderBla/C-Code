#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;	
};
Nodo *arbol = NULL;

void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
main(){
	menu();
}

void menu(){
	int dato, opcion, contador = 0;
	do{
		printf("\t.: MENU :. ");
		printf("\n\t\t1. Insertar un nuevo nodo");
		printf("\n\t\t2. Mostrar arbol");
		printf("\n\t\t3. Salir");
		printf("\n\tOpcion: ");
			fflush(stdin);
			scanf("%i",&opcion);
		
		switch(opcion){	
			case 1:
				printf("\n\t.: Ingresar datos :. ");
				printf("\n\n\t\tIngrese un numero: ");
					fflush(stdin);
					scanf("%i",&dato);
					insertarNodo( arbol, dato);
				break;
			case 2:
				cout<<"\n\t.:  Mostrar el arbol :. \n\n";	
				mostrarArbol(arbol,contador);
				cout<<"\n";
				system("pause");
				break;
			case 3:
				printf("\n\tPresione cualquier tecla para salir");	
				break;	
			default:
				printf("\n\tValor erroneo\n\tPresione cualquier tecla para continuar");	
				break;
		}		
		printf("\n\t\tPresione cualquier tecla para continuar");
		getch();
			system("cls");
	}while(opcion != 3);
}

Nodo *crearNodo(int dato){
	Nodo *nuevo_nodo;
	nuevo_nodo = (Nodo * )malloc(sizeof(struct Nodo));
	
	nuevo_nodo->dato = dato;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int dato){
	if(arbol == NULL){		// Si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(dato);
		arbol = nuevo_nodo;
	}else{					// Si el arbol tiene uno o mas de un nodo
		int valorRaiz = arbol->dato;
		if(dato < valorRaiz){	// Si el elemento es menor a la raiz
			insertarNodo(arbol->izq,dato);
		}else{				// Si el elemento es mayor a la raiz
			insertarNodo(arbol->der,dato);
		}
	}
}

void mostrarArbol(Nodo *arbol, int contador){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der,contador+1);
		for(int i=0; i<contador; i++){
			cout<<"      ";
		}
		cout<<arbol->dato<<endl;	//
		mostrarArbol(arbol->izq,contador+1);
		
	}
}
