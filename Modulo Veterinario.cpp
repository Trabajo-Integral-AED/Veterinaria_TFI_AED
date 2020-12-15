#include<utilidades_veterinaria.h>

struct fecha
{
	int dia,mes,anio;
};
struct usuarios
{
	char usuario[10],contrasena[10],apeynom[60];
};
struct veterinario
{
	char apeynom[60],telefono[25];
	int matricula, dni;
};
struct mascota
{
	char apeynom[60], domicilio[60],localidad[60],telefono[25];
	int dni_dueno;
	fecha fecha_nacimiento;
	float peso;
};
struct turnos
{
	int matricula,dni_dueno;
	fecha fecha_atencion;
	char detalle_atencion[380];
};

main()
{
	FILE*p;
	usuarios reg;
	turnos atencion;
	char texto[380],Usuario[10],Contrasena[10];
	bool validado=false;
	int salir=3;
////////////////////////////////////////////////
	principio:
	const char *titulo="MODULO CONSULTORIO VETERINARIO";
	const char *opciones[]={"Iniciar/Cambiar Sesion",
							"Visualizar Lista De Turnos",
							"Registrar Evolucion De La Mascota",
							"Salir"};
	int cant_op= sizeof(opciones)/sizeof(opciones[0]);
	bool repetir=1;
	int opcion;
	do
	{
		opcion=imprimir_menu(titulo,opciones,cant_op);
		switch(opcion)
		{
			case 1:
				system("cls");
				marco();
				gotoxy(23,2);
				if(validado==true)
				{
					const char *titulo2="UD. YA INICIO SESION";
					const char *opciones2[]={"Continuar con sesion actual",
											"Volver al menu principal para cambiar de usuario",
                                           };
					int cant_op2= sizeof(opciones2)/sizeof(opciones2[0]);
					bool repetir2=1;
					int opcion2;
					do
					{
						opcion2=imprimir_menu(titulo2,opciones2,cant_op2);
						switch(opcion2)
						{
							case 1:
									repetir2=0;
									goto principio;
									break;
							case 2:
									validado=false;
									repetir2=0;
									goto principio;
									break;							
						}

					}
					while(repetir2==1);
				}
				p=fopen("Usuarios.dat","rb");
				if(p==NULL)
				{
					printf("Error, no se pudo abrir el archivo (Usuarios.dat)");
					Sleep(3000);
					break;
				}
				system("cls");
				marco();
				gotoxy(23,2);
				printf("INGRESE NOMBRE DE USUARIO");
				gotoxy(23,3);
				fgets(Usuario,10,stdin);
				gotoxy(23,5);
				printf("INGRESE CONTRASENA");gotoxy(39,4);printf("_");
				_flushall();
				gotoxy(23,6);
				fgets(Contrasena,10,stdin);
				fread(&reg,sizeof(usuarios),1,p);	
				while(!feof(p))
				{
					if(strcmp(Usuario,reg.usuario)==0 && strcmp(Contrasena,reg.contrasena)==0)
					{
						system("cls");
						marco();
						gotoxy(23,4);
						printf("DATOS CORRECTOS --> INGRESO PERMITIDO");
						gotoxy(23,6);
						system("pause");
						validado=true;
					}
					fread(&reg,sizeof(usuarios),1,p);
				}
					if(validado==false)
					{
						system("cls");
						marco();
						gotoxy(23,4);
						salir--;
						printf("DATOS INCORRECTOS, LE QUEDAN (%d) INTENTOS\n",salir);
						gotoxy(23,6);
						system("pause");
						if(salir==0)
						{
							system("cls");
							marco();
							gotoxy(23,4);
							printf("COMUNIQUESE CON SU SOPORTE");
							gotoxy(23,6);
							system("pause");
							return 0;
						}
					}
				fclose(p);
				break;
			case 2:
				break;
			case 3:
				if(validado==true)
				{
					system("cls");
					texto_diagnostico(atencion.detalle_atencion);
					marco();
					gotoxy(27,2);
					printf("DIAGNOSTICO GUARDADO");
					gotoxy(27,3);
					for(int sub;sub<20;sub++)
					{
						printf("-");
						Sleep(40);
					}
					Sleep(2500);
					break;
				}
				else
				{
					system("cls");
					marco();
					gotoxy(23,4);
					printf("PRIMERO DEBE INGRESAR CON USUARIO Y CLAVE");
					gotoxy(23,6);
					system("pause");
					break;
				}

				break;
			case 4:
				repetir=0;
				exit(1);
				break;
				
		}
	}
	while(repetir==1);

	
	getch();
	return 0;
}
