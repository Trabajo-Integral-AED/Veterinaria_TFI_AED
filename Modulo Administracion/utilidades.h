#include<stdio.h>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

int imprimir_menu(const char *titulo, const char *opciones[],int n) //recibe un menu en forma de vector y realiza la impresion de la flecha de selccion
{
	int opcionSeleccionada=1;
	int tecla;
	bool repetir=1;
	
	do{
		system("cls");
		gotoxy(5,3+ opcionSeleccionada ); printf("-->");
		
		//Imprime el titulo
		
		gotoxy(15,2); printf("%s",titulo);
		
		//Imprime las opciones
		for(int i =0;i<n;i++){
			gotoxy(10,4+i); printf("%d) %s",i+1,opciones[i]);
		}
		
		do{//recibe los comandos de acciones mediante su codigo ASCCI
			tecla=getch();
		}while(tecla!= TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!= ENTER);//Nos aseguramos de que solo sean admitidos las teclas que queremos
		
		switch(tecla){
			case TECLA_ARRIBA:
				
				opcionSeleccionada--;
				
				if (opcionSeleccionada==0){
					opcionSeleccionada=n;
				}			
				
				break;
				
			case TECLA_ABAJO:
				opcionSeleccionada++;
				
				if(opcionSeleccionada>n){
					opcionSeleccionada=1;
				}
				
				break;
				
			case ENTER:
				repetir=false;
				break;
		}		
	}while(repetir);
	return opcionSeleccionada;
}

int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}
int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}
