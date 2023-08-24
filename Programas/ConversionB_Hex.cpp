#include<stdio.h>
#include<conio.h>
#include<windows.h>

void dec_bin(int x);
void dec_hex(int x);

main(){
	int i=0, j=0, num, menu, numD, numM;
	
	printf("-----CONVERTIDOR-----\nMENU\n\t1. Binario\n\t2. Hexadecimal\n\n");
	printf("\tBinario\n\t ... 1 | 2 | 4 | 8 | 16| 32 | 64 | 128 | 256 |\n\n");
	printf("\tHexadecimal\n\t ... | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | A | B | C | D | E | F |\n\n");
	printf("\tSeleccione la opcion: ");
	scanf("%i",&menu);
	
	switch(menu){
		case 1:
			system("cls");
			printf("\n\tDecimal a Binario\n\tIngrese un numero: ");
			scanf("%i",&num);
			dec_bin(num);
			break;
		case 2:
			system("cls");
			printf("\n\tDecimal a Hexadecimal\n\tIngrese un numero: ");
			scanf("%i",&num);
			dec_hex(num);
			break;
		default:
			printf("ERROR");
			break;		
		
	}
	getch();
	
}


void dec_bin(int x) {
    int binary[32];
    int index = 0;

    while (x > 0) {
        binary[index++] = x % 2;
        x /= 2;
    }
    printf("\n\tBinario: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}


void dec_hex(int x) {
    char hexadecimal[50];
    int index = 0;
    while (x > 0) {
        int remainder = x % 16;
        if (remainder < 10) {
            hexadecimal[index++] = remainder + '0';
        } else {
            hexadecimal[index++] = remainder - 10 + 'A';
        }
        x /= 16;
    }
    printf("\n\tHexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
}



