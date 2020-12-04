#include <stdio.h>
#include <string.h>
#include <conio.h>

bool valida_user_pass ( /*FILE* arch,*/ char user[11], char password[33] , char apellido_nombre[60])
{
	struct Registro
	{
		char user[11];
		char pass[33];
		char apellido_nombre[60];
	};
	
	Registro user_pass_registrados;
	/*FILE* arch*/
	char Abecedario[27]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'P', 'O', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char Digitos[11]={'0','1','2','3','4','5','6','7','8','9'};
	int i, x, minusculas=0, mayusculas=0, digitos=0, longitud=0;
	bool minuscula=false, letras_consecutivas=false, numeros_consecutivos=false;
	
	/*VALIDACION DEL USUARIO*/
	
	/*Falta validar la autenticidad del nombre del usuario*/
	/*LEER Y COMPARAR*/
	/*SINO CREAR E INSERTAR*/
	
	/*arch=fopen("Usuarios.dat","wb");
	rewind(arch);
	fread(&user_pass_registrados, sizeof(Registro), 1, arch);
	
	while ( !feof(arch) )
	{
		if ( strcmp(user_pass_registrados.user,user)==0 )
		{
			printf("\n\nUSUARIO- El usuario ya existe.\n");
		}
		
		fread(&user_pass_registrados, sizeof(Registro), 1, arch);
	}
	*/
	
	if ( strlen(user)<6 or strlen(user)>10 )
	{
		printf("\n\nUSUARIO- DEBE CONTENER MINIMO 6 Y MAXIMO 10 CARACTERES.\n");
		getch();
		return false;
	}
	
	strlwr(Abecedario);
	
	for ( x=0 ; x<strlen(Abecedario) ; x++ )
	{
		if ( user[0]==Abecedario[x] )
		{
			minuscula=true;
		}
	}
	
	strupr(Abecedario);
	
	for ( i=1 ; i<strlen(user) ; i++ )
	{	
		for ( x=0 ; x<strlen(Abecedario) ; x++ )
		{
			if ( user[i]==Abecedario[x] )
			{
				mayusculas++;
			}
		}
	}
	
	for ( i=1 ; i<strlen(user) ; i++ )
	{	
		for ( x=0 ; x<strlen(Digitos) ; x++ )
		{
			if ( user[i]==Digitos[x] )
			{
				digitos++;
			}
		}
	}
	
	if ( minusculas==false  )
	{
		printf("\n\nUSUARIO- LA PRIMERA LETRA DEBE SER MINUSCULA\n");
		getch();
		return false;
	}
	
	if ( mayusculas<2  )
	{
		printf("\n\nUSUARIO- DEBE CONTENER AL MENOS DOS LETRAS MAYUSCULAS\n");
		getch();
		return false;
	}
	
	if ( digitos>3 )
	{
		printf("\n\nUSUARIO- DEBE CONTENER MAXIMO TRES NUMEROS\n");
		getch();
		return false;
	}
	
	/*VALIDACION DE LA CONTRASEÑA*/
	
	if ( strlen(password)<6 or strlen(password)>32 )
	{
		printf("\n\nLA CONTRASEÑA DEBE CONTENER ENTRE 6 Y 32 CARACTERES\n");
		getch();
		return false;
	}
	
	minusculas=0;
	mayusculas=0;
	digitos=0;
	strlwr(Abecedario);
	
	for ( i=0 ; i<strlen(password) ; i++ )
	{	
		for ( x=0 ; x<strlen(Abecedario) ; x++ )
		{
			if ( password[i]==Abecedario[x] )
			{
				minusculas++;
			}
		}
	}
	
	strupr(Abecedario);
	
	for ( i=0 ; i<strlen(password) ; i++ )
	{	
		for ( x=0 ; x<strlen(Abecedario) ; x++ )
		{
			if ( password[i]==Abecedario[x] )
			{
				mayusculas++;
			}
		}
	}
	
	for ( i=0 ; i<strlen(password) ; i++ )
	{	
		for ( x=0 ; x<strlen(Digitos) ; x++ )
		{
			if ( password[i]==Digitos[x] )
			{
				digitos++;
			}
		}
	}
	
	if ( minusculas<1 and mayusculas<1 and digitos<1 )
	{
		printf("\n\nDEBE CONTENER CARACTERES ALFANUMERICOS\n");
		getch();
		return false;
	}
	
	if ( minusculas<1  )
	{
		printf("\n\nDEBE CONTENER AL MENOS UNA LETRA MINUSCULA\n");
		getch();
		return false;
	}
	
	if ( mayusculas<1  )
	{
		printf("\n\nDEBE CONTENER AL MENOS UNA LETRA MAYUSCULA\n");
		getch();
		return false;
	}
	
	if ( digitos<1  )
	{
		printf("\n\nDEBE CONTENER AL MENOS UN NUMERO\n");
		getch();
		return false;
	}
	
	for ( i=0 ; i<strlen(password) ; i++ )
	{	
		for ( x=0 ; x<strlen(Digitos) ; x++ )
		{
			if ( 	  password[i]==Digitos[x] 	and
					password[i+1]==Digitos[x+1]	and
					password[i+2]==Digitos[x+2] 	)
			{
				numeros_consecutivos=true;
			}
		}
	}
	
	strlwr(Abecedario);
	strlwr(password);
	
	for ( i=0 ; i<strlen(password) ; i++ )
	{	
		for ( x=0 ; x<strlen(Abecedario) ; x++ )
		{
			if ( 	  password[i]==Abecedario[x] 	and
					password[i+1]==Abecedario[x+1]		)
			{
				letras_consecutivas=true;
			}
		}
	}
	
	if ( numeros_consecutivos==true )
	{
		printf("\n\nNO DEBEN HABER TRES NUMEROS CONSECUTIVOS\n");
		getch();
		return false;
	}
	
	if ( letras_consecutivas==true )
	{
		printf("\n\nNO DEBEN HABER DOS LETRAS CONSECUTIVOS\n");
		getch();
		return false;
	}
	
	/*VALIDACION DE APELLIDO Y NOMBRE*/
	if ( strlen(apellido_nombre)==0 )
	{
		printf("\n\nAPELL_NOM: NO HA INGRESADO VALORES.\n");
		return false;
	}
		
	for ( i=0 ; i<strlen(apellido_nombre) ; i++ )
	{
		for ( x=0 ; x<strlen(Abecedario) ; x++ )
		{
			if ( apellido_nombre[i]==Abecedario[x] or apellido_nombre[i]==' ' )
			{
				longitud++;
			}
		}
	}
	
	if ( strlen(apellido_nombre)!=longitud )
	{
		printf("\n\nAPELL_NOM: NO HA INGRESADO VALORES CORRECTOS.\n");
		return false;
	}
	
	/*
	strcpy(user_pass_registrados.user,user);
	strcpy(user_pass_registrados.pass,password);
	fwrite(&user_pass_registrados, sizeof(float), 1, arch);
	*/
	return true;
}

main()
{
	bool validacion=false;
	
	char user[7], pass[33], apellido_nombre[60];
	int cod_vet=1;
	
	while ( validacion==false )
	{
		printf("\nINGRESE USUARIO: ");
		gets(user);
		printf("\nINGRESE PASS: ");
		gets(pass);
		printf("\nAPELLIDO Y NOMBRE: ");
		gets(apellido_nombre);
		
		validacion = valida_user_pass(user,pass,apellido_nombre);
		
		if (validacion==true)
		{
			printf("\n\nLOS DATOS INGRESADOS SON CORRECTOS");
		}
		else
		{
			printf("\n\nLOS DATOS INGRESADOS SON INCORRECTOS\n");
		}
	}
}
