#include<stdio.h>
#include<windows.h>
#include<conio.h>

struct agenda{
	char nombre[20];
	char telefono[15];
	agenda *siguiente;
	agenda *anterior;
};

struct agenda *primero, *ultimo;

void menu();
void listaDoblementeEnlazadas(int *);
void mostrarListaFirstToLast();
void mostrarLastToFirst(int);

main(){
	int opc=0, total=0;
	do{
		menu();
		scanf("%i",&opc);
		switch(opc){
			case 1:
				system("cls");
					listaDoblementeEnlazadas(&total);
				system("cls");
				break;
			case 2:
				system("cls");
					mostrarListaFirstToLast();
				system("cls"); 
				break;
			case 3:
				system("cls");
					mostrarLastToFirst(total);
				getch();
				break;
			case 4:
				printf("Lista simplemente enlazada circular");
					
				break;	
			case 5:
				printf("Mostrar lista simplemente enlazada circular");
				break;
			case 6:
				printf("Salir");
				break;		
			default:
				system("cls");
				printf("\n\tError, opcion no encontrada\nPresione cualquier tecla para continaur");
				getch();
				system("cls");			
		}
	}while(opc != 6);
}
void menu(){
	int opc;
	printf("\n\tACTIVIDAD 2\n\t------------------------------\n\t1. Genera lista doblemente enlazada\n\t2. Mostrar lista de primero - ultimo\n\t3. Mostrar lista ultimo a primero\n\t4. Lista simplemente enlazada circular\n\t5. Mostrar lista simplemente enlazada circular\n\t6. Salir\n\t > ");
		fflush(stdin);

}

void listaDoblementeEnlazadas(int *total){
	//	CREAS NODOS
	struct agenda *nuevo;
	struct agenda *aux; 
	nuevo=(struct agenda*) malloc(sizeof(struct agenda));
	//	VALIDAS QUE SE HAYAN CREADO
	if (nuevo==NULL){
		printf("\n\tNo hay memoria disponible!");	
	}else{
		
    	printf("\n\tGenera lista doblemente enlazada\n\tNombre: "); 
            fflush(stdin);
			gets(nuevo->nombre);
    	printf("\tTelefono: "); 
    		fflush(stdin);
    	    gets(nuevo->telefono);
    	nuevo->siguiente = NULL; 
    	//	PARA EL PRIMER ELEMENTO DE LA LISTA
    	/*
			Si el primer elemento es nulo y el ultimo tamebien entonce :
			Ya que si no hay ningun nodo en nuestra lista enconces
			el primero va a ser igual un nuevo nodo, primero = nuevo;
			Y el ultimo que va a ser igual al que se cree entonces, ultimo = nuevo;
				YA que igualamos a primero = nuevo, entonces el primero de siguiente es NULL
				que indica que hasta ahí termina
				El primero de anterior es NULL ya que es el primer elemnto
		*/
    	if(primero==NULL  && ultimo==NULL){
        	primero = nuevo;
        	ultimo = nuevo;
        	primero->siguiente=NULL;
        	primero->anterior=NULL;
        //Otros elementos que no sea el primero
		/*
			
		*/
    	}else{
      		aux=ultimo;
        	ultimo->siguiente = nuevo;
        	nuevo->siguiente = NULL;
        	ultimo=nuevo;
        	aux->siguiente=ultimo;
        	ultimo->anterior=aux;
 		}
     	total++;	// Este contador nos va a ayudar para imprimir del ultimo al primero
	}
	printf("\n\tPresione cualquier tecla para continuar");
	getch();
}

void mostrarListaFirstToLast(int total){
	int i=0;
	
	//	CREAMOS UN NODO AUXILIAR
	struct agenda *auxiliar; 
	//	IGUALAMOS EL AUXILIAR A PRIMERO QUE ES AHI DONDE DEBE DE PARTIR
	auxiliar = primero;
	
	printf("\n\tMostrar lista de primero - ultimo\n\n");
	//	MIENTRAS QUE EL AUXILIAR NO HAYA LLEGADO A UN VALOR NULO O EL FINAL
	while (auxiliar!=NULL){
		printf( "\n\tNombre: %s, \n\tTelefono: %s\n\n",auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->siguiente;		//	AQUI NOS AYUDA PARA INCREMENTAR DE POSICION O APUNTAR AL SIGUIENTE NODO
		i++;	//EL INCREMENTO ES PARA VERIFICAR QUE HAYA DATOS,POR ESA RAZON ENTRO EN ESTE WHILE
	}
	//	VERIFICA QUE LA LISTA NO ESTE VACIA CON EL 	'i', POR ESO VA DESPUES DEL WHILE YA QUE SI NO ENTRO EN EL WHILE LA LISTA ESTA VACIA
	if(i==0){
		printf( "\nLa lista está vacía!!\n" );	
	}
	
	printf("\n\tPresione cualquier tecla para continuar");
	getch();
	
}

void mostrarLastToFirst(int total){
	int i=0;
	
	//	CREAMOS UN NODO AUXILIAR
	struct agenda *auxiliar; 
	//	IGUALAMOS EL AUXILIAR A ULTIMO QUE ES AHI DONDE DEBE DE PARTIR
	auxiliar = ultimo;
	
	printf("\n\tMostrar lista de primero - ultimo\n\n");
	//	MIENTRAS QUE EL AUXILIAR NO HAYA LLEGADO A UN VALOR NULO O EL FINAL (En este caso el nuestro final es el primero)
	while (auxiliar!=NULL){
		printf( "\n\tNombre: %s, \n\tTelefono: %s\n\n",auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->anterior;		//	AQUI NOS AYUDA PARA INCREMENTAR DE POSICION O APUNTAR AL SIGUIENTE NODO
		i--;	//EL INCREMENTO ES PARA VERIFICAR QUE HAYA DATOS,POR ESA RAZON ENTRO EN ESTE WHILE
	}
	//	VERIFICA QUE LA LISTA NO ESTE VACIA CON EL 	'i', POR ESO VA DESPUES DEL WHILE YA QUE SI NO ENTRO EN EL WHILE LA LISTA ESTA VACIA
	if(total==0){
		printf( "\nLa lista está vacía!!\n" );	
	}
	
	printf("\n\tPresione cualquier tecla para continuar");
	getch();
}
