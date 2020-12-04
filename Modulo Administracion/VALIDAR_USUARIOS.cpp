#include <stdio.h>
#include <string.h>
#include <conio.h>

struct Usuarios
{
	char 	user[11];
	char 	password[33];
	char 	apellido_nombre[60];
};

void Opcion_2 ( Usuarios Datos )
{
	bool valido;
	/*Se abre aqui el archivo o en la funcion*/
	
	printf("\nINGRESE USUARIO: ");
	_flushall();
	gets(Datos.user);
	printf("\nINGRESE CONTRASENA: ");
	_flushall();
	gets(Datos.password);
	printf("\nAPELLIDO Y NOMBRE: ");
	_flushall();
	gets(Datos.apellido_nombre);
	
	/*nombre_de_funcion_validar (  )*/
	valido=valida_user_pass ( /*FILE* arch,*/ Datos.user,Datos.password,Datos.apellido_nombre);
	
	if ( valido==true)
	{
		/*Grabar datos de la estructura en el archivo correspondiente*/
	}
}
