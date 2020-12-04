#include<stdio.h>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//agrego algo
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

struct Veterinarios
{
	char 	apellido_nombre[60];
	char 	matricula[8];
	char 	dni[9];
	char 	telefono[60];
	char	contrasena[33];
};


void Opcion_1 ( Veterinarios veterinario )
{
	char Abecedario[28]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'P', 'O', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',' '};
	char Digitos[11]={'0','1','2','3','4','5','6','7','8','9'};
	int i, x, correcto=0;
	
	Apellido_Nombre:
		correcto=0;
		printf("\n\n	APELLIDO Y NOMBRE: ");
		_flushall();
		gets(veterinario.apellido_nombre);
		
		strupr(veterinario.apellido_nombre);
		
		if ( strlen(veterinario.apellido_nombre)==0 )
		{
			goto Apellido_Nombre;
		}
		
		for ( i=0 ; i<strlen(veterinario.apellido_nombre) ; i++ )
		{
			for ( x=0 ; x<strlen(Abecedario) ; x++ )
			{
				if ( veterinario.apellido_nombre[i]==Abecedario[x] )
				{
					correcto++;
				}
			}
		}
		
		if ( strlen(veterinario.apellido_nombre)!=correcto )
		{
			goto Apellido_Nombre;
		}
	
	
	Matricula:
		correcto=0;
		printf("\n\n	MATRICULA (7 digitos): ");
		_flushall();
		gets(veterinario.matricula);
		
		if ( strlen(veterinario.apellido_nombre)==0 )
		{
			goto Matricula;
		}
		
		if(strlen(veterinario.matricula)>7 || strlen(veterinario.matricula)<7){
			printf("No se ingreso el la cantidad correcta de digitos!!");
			goto Matricula;
		}
		
		for ( i=0 ; i<strlen(veterinario.matricula) ; i++ )
		{
			for ( x=0 ; x<strlen(Digitos) ; x++ )
			{
				if ( veterinario.matricula[i]==Digitos[x] )
				{
					correcto++;
				}
			}
		}
		
		if ( strlen(veterinario.matricula)!=correcto )
		{	
			printf("Solo debe ingresar numeros!!");
			goto Matricula;
		}
		
	
	
	
	
	DNI:
		correcto=0;
		printf("\n\n	D.N.I. (8 digitos): ");
		_flushall();
		gets(veterinario.dni);
		if ( strlen(veterinario.dni)==0 )
		{
			goto DNI;
		}
		
		if(strlen(veterinario.dni)>8 || strlen(veterinario.dni)<8){
			printf("No se ingreso el la cantidad correcta de digitos!!");
			goto DNI;
		}
		
		for ( i=0 ; i<strlen(veterinario.dni) ; i++ )
		{
			for ( x=0 ; x<strlen(Digitos) ; x++ )
			{
				if ( veterinario.dni[i]==Digitos[x] )
				{
					correcto++;
				}
			}
		}
		
		if ( strlen(veterinario.dni)!=correcto )
		{
			printf("Solo debe ingresar numeros!!");
			goto DNI;
		}
		
		
	Telefono:
		correcto=0;
		printf("\n\n	TELEFONO: ");
		_flushall();
		gets(veterinario.telefono);
		
		if ( strlen(veterinario.telefono)==0 )
		{
			goto Telefono;
		}
		
		for ( i=0 ; i<strlen(veterinario.telefono) ; i++ )
		{
			for ( x=0 ; x<strlen(Digitos) ; x++ )
			{
				if ( veterinario.telefono[i]==Digitos[x] )
				{
					correcto++;
				}
			}
		}
		
		if ( strlen(veterinario.telefono)!=correcto )
		{
			printf("Solo debe ingresar numeros!!");
			goto Telefono;
		}
}








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
