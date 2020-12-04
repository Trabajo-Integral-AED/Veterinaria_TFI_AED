#include <stdio.h>
#include <string.h>

struct Personales
{
	char 	apellido_nombre[60];
	int 	matricula;
	int 	dni;
	char 	telefono[60];
	char	contrasena[33];
};

Personales veterinario;

void Opcion_1 ( Personales veterinario )
{
	char Abecedario[28]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'P', 'O', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',' '};
	char Digitos[11]={'0','1','2','3','4','5','6','7','8','9'};
	int i, x, correcto=0;
	
	Apellido_Nombre:
		correcto=0;
		printf("\n\n	APELLIDO Y NOMBRE: ");
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
	
	printf("\n\n	MATRICULA: ");
	scanf("%d",&veterinario.matricula);
	printf("\n\n	D.N.I.: ");
	scanf("%d",&veterinario.dni);
	
	Telefono:
		correcto=0;
		printf("\n\n	TELEFONO: ");
		gets(veterinario.telefono);
		
		if ( strlen(veterinario.telefono)==0 )
		{
			goto Telefono;
		}
		
		for ( i=0 ; i<strlen(veterinario.telefono) ; i++ )
		{
			for ( x=0 ; x<strlen(Abecedario) ; x++ )
			{
				if ( veterinario.telefono[i]==Abecedario[x] )
				{
					correcto++;
				}
			}
		}
		
		if ( strlen(veterinario.telefono)!=correcto )
		{
			goto Telefono;
		}
}
