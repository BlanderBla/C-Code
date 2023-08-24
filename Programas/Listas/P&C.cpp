#include <stdio.h>
#include <conio.h>
#include <windows.h>

//Estructura Pila
struct Pila{
	int datoPila;
	struct Pila *siguientePila;
};
struct Pila *primeroPila = NULL;

//Estructura Cola
struct Cola{
	int datoCola;
	struct Cola *siguienteCola;
};
struct Cola *primeroCola = NULL, *ultimoCola = NULL;

//Prototipos de las funcionres
void insertarPila();
void mostrarPila();
void eliminarPila();
void buscarPila();
void modificarPila();

void insertarCola();
void mostrarCola();
void eliminarCola();

void menu();

main()
{
	int opcion=0;
	
	do{
		menu();
		printf("\n\tOpcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				system("cls");
					insertarPila();
				getch();
				system("cls");
			break;
			case 2:
				system("cls");
					mostrarPila();
				getch();
				system("cls");
			break;
			case 3:
				system("cls");
					eliminarPila();
				getch();
				system("cls");
			break;
			case 4:
				system("cls");
					buscarPila();
				getch();
				system("cls");
			break;
			case 5:
				system("cls");
					modificarPila();
				getch();
				system("cls");
			break;
			case 6:
				system("cls");
					insertarCola();
				getch();
				system("cls");
			break;
			case 7:
				system("cls");
					mostrarCola();
				getch();
				system("cls");
			break;
			case 8:
				system("cls");
					eliminarCola();
				getch();
				system("cls");
			break;
		}
		system("cls");
	}while(opcion!=9);
	
	getch();
	return(0);
}

void menu()
{
	printf("\n\t\t\t.:MENU:.\n"); 
	printf("\n\tPILA\n");
	printf("\t  1. Insertar elemento\n");
	printf("\t  2. Mostrar pila\n");
	printf("\t  3. Eliminar un nodo\n");
	printf("\t  4. Buscar un elemento\n");
	printf("\t  5. Modificar un elemento\n");
	printf("\n\tCOLA\n");
	printf("\t  6. Insertar elemento\n");
	printf("\t  7. Mostrar cola\n");
	printf("\t  8. Eliminar un nodo\n");
	printf("\t  9. Salir\n");
}

//Pila
void insertarPila(){
	int opc=0;
	do{
		//PASO 1 - Se crea un nodo llamado nuevo
		struct Pila *nuevo;
		//Paso 2 - Se reserva memoria para el nodo
		nuevo = (struct Pila*) malloc (sizeof(struct Pila));
		//Paso 3 - Se llena el nodo el el dato del nodo
		printf("\n\tIngresar dato a la pila: ");
		scanf("%d", &nuevo->datoPila);
		//Paso 4 - El puntero nuevo de siguiente apunta a primera Pila o la posicion 1 de la pila
		nuevo->siguientePila = primeroPila;
		primeroPila = nuevo;		//	primera Pila o la posicion 1 de la pila es igual al nodo nuevo
		
		printf("\n\tDesea ingresar un nuevo dato\?\t1. Si\t2. No\n\t> ");
			fflush(stdin);
			scanf("%i",&opc);
	}while(opc==1);
	
	printf("\n\n\tPresione cualquier tecla para continuar\n");
}

void mostrarPila(){
	// Paso 1 - Cramos un nodo llamado aux
	struct Pila *aux;
	// Paso 2 - Inicializamos el nodo auxiliar que apunte al primer nodo, auxiliar pasa a tomar el valor de primero nodo de la pila
	aux = primeroPila;
	// Paso 3 - Validamos si existen nodos
	if(primeroPila == NULL){		//Si primero es igual a nulo significa que no hay ningun nodo
		printf("\n\tLa pila esta vacia!!\n");
	}else{
		printf("\n\tMostrando pila\n");
		/*	Paso 4 - Mientras el nodo sea diferente de nulo va a imprimir el valor de dato en el nodo en el que este 
			y al final auxiliar se le asigna el siguente	*/
		while(aux!=NULL){
			printf("\t%d\n", aux->datoPila);
			aux = aux->siguientePila;
		}
	}
	printf("\n\n\tPresione cualquier tecla para continuar\n");
}

void eliminarPila(){
	// Paso 1 - Creamos dos nodos un auxiliar 
	struct Pila *aux, *anterior;
	// Paso 2 - El nodo auxiliar lo igualamos al primer nodo de la pila
	aux = primeroPila;
	//		  - El nodo anterior va a apuntar a nulo ya que es un anterior al primer nodo de la pila
	anterior = NULL;
	// Paso 3 - Validamos si hay elementos en nuestra pila
	if(primeroPila==NULL){
		printf("\n\tLa pila esta vacia!!\n\n");
	}else{//  - Si hay elementos en una pila
		// Si el nodo auxiliar esta en la posicion del primero 
		if(aux == primeroPila){
			/*	Entonces el primero ahora apuntara al siguiente elemnto de la pila y liberara el primer nodo
				Este caso siempre se va a cumplir ya que en la linea 154 aux = primeroPila	*/
			primeroPila = primeroPila->siguientePila;
			free(aux);
		}
		printf("\n\n\tPresione cualquier tecla para continuar\n");
	}
}

void buscarPila(){
	// Paso 1 - Creamos un nodo auxiliar llamado aux
	struct Pila *aux;
	int buscar=0, i=0, k=0;
	// Paso 2 - Inicializamos el nodo auxiliar para que se posione en la primera posicion de los nodos
	aux = primeroPila;
	// Paso 3 - Validamos si hay elementos en nuestra pila
	if(primeroPila==NULL){
		printf("\n\tLa pila esta vacia!!\n\n");
	}else{//  - Si hay elementos en una pila
		//Damos un scanf para que el usuario ingrese el elemento a buscar
		printf("\n\tDato a buscar: ");
		scanf("%d", &buscar);
		// Mientras la pila no se termina 
		while(aux!=NULL){
			//Si el dato en el auxiliar es igual al dato que ingreso el usuario
			if(aux->datoPila == buscar){
				printf("\n\tDato [%d] encontrado en la posicion [%i]\n\n",buscar,i);
				k++; //Creamos esta valiable ya que si se encontro el valor este se vuelve verdadeor osea 1 del caso contrario se queda como falos
			}
			//Mintras no se cumpla esta condicion el auxiliar pasa al siguiente nodo
			aux = aux->siguientePila;
			i++;
		}
		if(k==0){
			printf("\n\tDato [%d] no encontrado\n\n", buscar);
		} 
	}
	printf("\n\n\tPresione cualquier tecla para continuar\n");
}

void modificarPila(){
	//Paso 1 - Creamos un nodo auxiliar llamado aux
	struct Pila *aux;
	int modificar=0, k=0;
	// Paso 2 - Inicializamos el nodo auxiliar para que se posione en la primera posicion de los nodos
	aux = primeroPila;
	// Paso 3 - Validamos si hay elementos en nuestra pila
	if(primeroPila==NULL){
		printf("\n\tLa pila esta vacia!!\n\n");
	}else{
		/*	Para este caso, es como si buscaramos un dato, ingresamos un elemento a buscar y realizamos un while para buscar el elemento	
			Damos un scanf para que el usuario ingrese el elemento a buscar	*/
		printf("\n\tDato a modificar: ");
		scanf("%d",&modificar);
		// Mientras la pila no se termina 
		while(aux!=NULL){
			//Si el dato en el auxiliar es igual al dato que ingreso el usuario
			if(aux->datoPila == modificar){
				printf("\n\t\tDato [%d] encontrado\n",modificar);
				printf("\n\t\tIngresar nuevo dato: ");
				/*	En la posicion del nodo en el que el dato que se ingreso y el dato del nodo auxiliar sean iguales, 
					solamente se cambia el dato en ese nodo	*/
				scanf("%d", &aux->datoPila);
				k++;
			}
			aux = aux->siguientePila;
		}
		printf("\n");
		if(k==0){
			printf("\tDato [%d] no encontrado\n\n", modificar);	
		} 
	}
	printf("\n\n\tPresione cualquier tecla para continuar\n");
}

void insertarCola(){
	//PASO 1 - Se crea un nodo llamado nuevo
	struct Cola *nuevo;
	//Paso 2 - Se reserva memoria para el nodo
	nuevo = (struct Cola*) malloc (sizeof(struct Cola));
	//Paso 3 - Se llenan los datos del nodo
	printf("\n\tIngresar dato a la cola: ");
	scanf("%d", &nuevo->datoCola);
	//Paso 4 - Validamos si la cola esta vacio
	if(primeroCola==NULL){
		/*	Si esta vacia el primer elemento de los nodos es igual al nuevo nodo y el el primer nodo va a apuntar a nulo
			Y el ultimo nodo va a ser igual al nuevo nodo	*/
		primeroCola = nuevo;
		primeroCola->siguienteCola = NULL;
		ultimoCola = nuevo;
	}else{
		/*	De caso contrario, en el que ya haya una cola, entonces el ultimo nodo va a apuntar a nuevo
			El nodo nuevo va a apuntar a nulo y el ultimo va a ser igual al nuevo	*/
		ultimoCola->siguienteCola = nuevo;
		nuevo->siguienteCola = NULL;
		ultimoCola = nuevo;
	}
	printf("\n\n\tPresione cualquier tecla para continuar\n");
}

void mostrarCola(){
	// Paso 1 - Creamos un nodos un auxiliar llamado aux
	struct Cola *aux;
	// Paso 2 - Inicializamos el nodo auxiliar que apunte al primer nodo, auxiliar pasa a tomar el valor de primero nodo de la pila
	aux = primeroCola;
	// Paso 3 - Validamos si la cola existe 
	if(primeroCola == NULL){
		printf("\n\tLa cola esta vacia\n");
	}else{
		//Si existe, mientras el nodo auxiliar sea diferente de nulo va a imprimir los valores de la cola y el nodo auxiliar va a apuntar al siguiente
		printf("\n\t.:Mostrando cola:.\n");
		while(aux!=NULL){
			printf("\t%d\n", aux->datoCola);
			aux = aux->siguienteCola;
		}
	}
	printf("\n\n\tPresione cualquier tecla para continuar\n");
}

void eliminarCola(){
	// Paso 1 - Se crean dos nodos auxiliares llamados aux y anterior
	struct Cola *aux, *anterior;
	// Paso 2 - El nodo auxiliar lo igualamos al primer nodo de la pila
	aux = primeroCola;
		   // - El nodo anterior va a apuntar a nulo ya que es un anterior al primer nodo de la pila
	anterior = NULL;
	
	if(primeroCola==NULL){
		printf("\n\tLa cola esta vacia!!\n\n");
	}else{
		if(aux==primeroCola){
			primeroCola = primeroCola->siguienteCola;
		}
		else if(aux==ultimoCola){
			anterior->siguienteCola = NULL;
			ultimoCola = anterior;
		}
	}
	anterior = aux;
	aux = aux->siguienteCola;
	free(anterior);
	printf("\n\n\tPresione cualquier tecla para continuar\n");
}
