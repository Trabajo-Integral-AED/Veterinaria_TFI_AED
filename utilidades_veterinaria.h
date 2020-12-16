#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;
void gotoxy(int x, int y)
{	
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void marco()
{
	gotoxy(0,0);
	printf("같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같");
	gotoxy(0,12);
	printf("같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같");
	
}
void texto_diagnostico(char diagnostico[])
{
	char caracter; 
	int maximo=380;	
	int i=0,j=0;
	marco();
	gotoxy(2,2);
	printf("     ");
	gotoxy(2,2);
	printf("(%d)",maximo);
	gotoxy(27,2);
	printf("Informe Diagnostico");
	gotoxy(27,3);
	for(j=0;j<19;j++)
	{
		printf("-");
		Sleep(30);
	}
	gotoxy(2,6);
	while(caracter=getch()) 
	{		
		if(caracter==13 || maximo==0) 
		{
			diagnostico[i]= '\0';	
			break;					
		} 
		else if(caracter==8) 
		{	
		if(i>0) 
		{		
			i--; 				
			maximo++;					
//////////////////////////////////////////////////
			gotoxy(2,2);
			printf("     ");
			gotoxy(2,2);
			printf("(%d)",maximo);
			gotoxy(2,6);		
			diagnostico[i]='\0';
			printf("%s",diagnostico);
			printf(" \b \b");				
		}
		} 
		else 
		{		
			maximo--;		
//////////////////////////////////////////////////
			gotoxy(2,2);
			printf("     ");
			gotoxy(2,2);
			printf("(%d)",maximo);
			gotoxy(2,6);
			diagnostico[i]=caracter;
			diagnostico[i+1]='\0';			
			printf("%s",diagnostico);
			i++;						
		}
	}
	system("cls");
} 

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

int imprimir_menu(const char *titulo, const char *opciones[],int n) //recibe un menu en forma de vector y realiza la impresion de la flecha de selccion
{
	int opcionSeleccionada=1;
	int tecla;
	bool repetir=1;
	
	do{
		system("cls");
		marco();
		gotoxy(18,3+ opcionSeleccionada ); cout<<"-->";
		
		//Imprime el titulo
		gotoxy(23,2); cout<<titulo;
		
		//Imprime las opciones
		for(int i =0;i<n;i++){
			gotoxy(23,4+i); cout<<i+1<<") "<<opciones[i];
		}
		gotoxy(21,3+ opcionSeleccionada );
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
