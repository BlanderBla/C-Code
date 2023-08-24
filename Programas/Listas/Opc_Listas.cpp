#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct agenda{
	char nombre[20];
    char telefono[12];
    int elemento;
    struct agenda *siguiente;
};

struct agenda *primero, *ultimo,*eliminar,*nuevo,*insertar;

/*
	-->INSERTAR AL INICIO DE LA LISTA
	-->INSERTAR AL FINAL DE LA LISTA
	INSERTAR EN CUALQUIER LUGAR DE LA LISTA
	-->ELIMINAR AL INICIO DE LA LISTA
	ELIMINAR AL FINAL DE LA LISTA
	ELIMINAR EN CUALQUIER LUGAR DE LA LISTA
	--> MOSTRAR
*/

void insertar_Inicio();
void insertar_Final();
void mostrar_lista();
void eliminar_Primer_Elemento();
void eliminar_Ultimo_Elemento();

main(){   
	int opc=0;
	 do{
	 	printf("\n\t----- LISTAS -----\n\t\t1. Insertar al inicio\n\t\t2. Insertar al final de la lista\n\t\t3. Insertar en cualquier lugar de la lista\n\t\t4. Eliminar al inicio de la lista\n\t\t5. Eliminar al final de la lista\n\t\t6. Eliminar en cualquier lugar de la lista\n\t\t7. Mostrar\n\t\t8. Salir\n\tOpcion > ");
    	scanf("%i",&opc);
	    switch(opc){
	    	case 1:
	    		system("cls");
	    		printf("\n\tInsertar al inicio\n\t");
	    		insertar_Inicio();
	    		printf("\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");
	    		break;
	    	case 2:
	    		system("cls");
	    		printf("\n\tInsertar al final de la lista\n\t");
	    			insertar_Final();
	    			
	    		printf("\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");	
				break;
			case 3:
				system("cls");
	    		printf("\n\tInsertar en cualquier lugar de la lista\n\t");
	    		
	    		printf("\n\tSalir\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");
				break;
			case 4:
				system("cls");
	    		printf("\n\tEliminar al inicio de la lista\n\t");
	    		eliminar_Primer_Elemento();
	    		
	    		printf("\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");
				break;
			case 5:
				system("cls");
	    		printf("\n\tEliminar al final de la lista\n\t");
	    		eliminar_Ultimo_Elemento;
	    		printf("\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");
				break;
			case 6:
				system("cls");
	    		printf("\n\tEliminar en cualquier lugar de la lista\n\t");
	    		
	    		printf("\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");
				break;
			case 7:
				system("cls");
	    		printf("\n\tMostrar\n\t");
	    			mostrar_lista();
	    			
	    		printf("\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");	
				break;
			case 8:
				system("cls");
				printf("\n\tSalir\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");
				break;		
			default:
				system("cls");
				printf("\n\tOpcion no valida\n\tPresione cualquier tecla para continuar");
				getch();
				system("cls");
				break;			
		}
	 }while(opc!=8);	
	 mostrar_lista();
	 getch();
	 printf("\n\n\t----> Fin del Programa <-----");
	 getch();  
  
}
//Inserta los datos al inicio
void insertar_Inicio(){
	int i=1;
	//PASO 1 - CREAR UN NUEVO NODO
	struct agenda *insertar; 
	insertar = (struct agenda *) malloc (sizeof(struct agenda));
	//PASO 2 - VERIFICAR SI HAY ESPACIO PARA ESE NODO
    if (insertar==NULL){
    	printf("\n\tNo hay memoria disponible!\n");	
	}
	//PASO 3 - CREAR DOS NODOS AUXILIARES Y ASIGNAR LISTA AL PRIMERO DE ELLOS	
		insertar->siguiente=primero;
		primero=insertar;
	//PASO 4 - INSERTAR EL ELEMENTO A LA LISTA
		printf("\n\tInserte un elemento [%i]\n\tNombre: ",i); 
		  	fflush(stdin);
			scanf("%s",&insertar->nombre);
		printf("\tTeléfono: "); 
		   	fflush(stdin);
		   	scanf("%s",&insertar->telefono);
}
//Inserta los datos al final
void insertar_Final(){
	//PASO 1 - CREAR UN NODO
    struct agenda *nuevo; 
	int n=0,i=0;
	do{
		i++;
		//PASO 1.1 - RESERVAR MEMORIA (Va dentro del do while ya que se van a ir agregando datos y va a ir cambiando su espacio en memoria)	
	    nuevo = (struct agenda *) malloc (sizeof(struct agenda));
	    //PASO 2 - VERIFICAR SI HAY ESPACIO PARA ESE NODO
	    if (nuevo==NULL){
			printf( "No hay memoria disponible!\n");
	  	}else{
	  		//PASO 3 - INSERTAR EL ELEMENTO A LA LISTA
	  		printf("\n\tElemento [%i]\n\tNombre: ",i); 
	  			fflush(stdin);
		    	scanf("%s",&nuevo->nombre);
		    printf("\tTeléfono: "); 
		    	scanf("%s",&nuevo->telefono);
			//PASO 4 - CREAR DOS NODOS AUXILIARES Y ASIGNAR LISTA AL PRIMERO DE ELLOS    	
		    nuevo->siguiente = NULL; 
		    if (primero==NULL){
			    // Primer elemento
			    primero = nuevo;
			    ultimo = nuevo;
			}else{
		    	ultimo->siguiente = nuevo;
		    	ultimo = nuevo;
		    }	
	  	}
	      
	    printf("\n\tDesea insertar otro elemento ? 1. Si 2. No");
	    scanf("%d",&n);
	}while(n==1);    
      
}
//ELimina el primer elemento de la lista
void eliminar_Primer_Elemento(){
	struct agenda *auxiliar;
	printf("Eliminar datos");
	if(ultimo==NULL){
		printf("No se puede eliminar el dato");
	}else{
		auxiliar=primero;
		primero=auxiliar->siguiente;
	}
	free(auxiliar);
}
//Eliminar el ultimo elemento de la lista
void eliminar_Ultimo_Elemento(){
	eliminar=ultimo;
	if(ultimo->siguiente!=NULL);
	{
		ultimo->siguiente=ultimo;
		
	}
	free(eliminar);
}
//Muestra los elementos de la lista
void mostrar_lista(){
	struct agenda *auxiliar; /* lo usamos para recorrer la lista */
	int i=0;
 
	auxiliar = primero;
	printf("\nMostrando la lista completa:");
	while (auxiliar!=NULL) {
		printf( "\n\tNombre: %s \n\tTelefono: %s\n\n",auxiliar->nombre,auxiliar->telefono);
		auxiliar = auxiliar->siguiente;
		i++;
	}
    if (i==0){
      	printf( "\n\tLa lista está vacía!!\n" );
	} 
}
