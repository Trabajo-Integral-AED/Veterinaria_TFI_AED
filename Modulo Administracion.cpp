/*
=========================
MODULO DE ADMINISSTRACION
=========================
*/

#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

struct Fecha{
	int dd,mm,aaaa;
};

struct Veterinaio{
	char ApellidoyNombre[60]
	int Matricula;
	int DNI;
	char Telefono[25];
};

struct Usuarios{
	char Usuario[10];
	char Contraseña[10];
	char ApellidoyNombre[10];
};

struct Turnos{
	int Matricula;
	Fecha FechaConsulta;
	int DNIDuenio;
	char Detalle[380];
};

void gotoxy(int x, int y);
int imprimir_menu(const char *titulo, const char *opciones[],int n);


void Registrar_veterinario  




int main(){
	
	const char *titulo = "Modulo Administracion";
	const char *opciones[] = {"Registrar Veterinario",
							"Registrar Usuario Asistente",
							"Atenciones por Veterinarios",
							"Ranking de Veterinarios por Atenciones",
							"Cerrar la Aplicacion"};
	int co = sizeof(opciones)/sizeof(opciones[0]);
	bool repeat=1;
	int opc;
	
	do{
		opc = imprimir_menu(titulo,opciones,co);
		
		switch(opc){
			case 1:
				
				break;
			
			case 2:
				
				break;
			
			case 3:
				
				break;
			
			case 4:
				
				break;
			
			case 5:
				repeat = 0;
				exit(1);
				break;
		}
		
	}while(repeat);
	
	getch();
	return 0;
}

















int imprimir_menu(const char *titulo, const char *opciones[],int n) //recibe un menu en forma de vector y realiza la impresion de la flecha de selccion
{
	int opcionSeleccionada=1;
	int tecla;
	bool repetir=1;
	
	do{
		system("cls");
		gotoxy(5,3+ opcionSeleccionada ); cout<<"-->";
		
		//Imprime el titulo
		gotoxy(15,2); cout<<titulo;
		
		//Imprime las opciones
		for(int i =0;i<n;i++){
			gotoxy(10,4+i); cout<<i+1<<") "<<opciones[i];
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

void gotoxy(int x, int y){
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
