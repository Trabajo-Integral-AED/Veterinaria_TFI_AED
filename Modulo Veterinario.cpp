#include<utilidades_veterinaria.h>
#include<IntroVeterinaria.h>
struct fecha_nac // para el nacimiento de las mascotas
{
	int dia,mes,anio;
};

struct fecha // para usar en turnos
{
	int dia,mes,anio;
};
struct usuarios //para ingresar con usuario y contraseña (FILE*p)
{
	char usuario[10],contrasena[10],apeynom[60];
};
struct veterinario // para identificar al veterinario
{
	char apeynom[60],telefono[25];
	int matricula, dni;
};
struct mascota // para identificar a la mascota
{
	char apeynom[60], domicilio[60],localidad[60],telefono[25];
	int dni_dueno;
	fecha fecha_nacimiento;
	float peso;
};
struct turnos // para ver turnos asignados (atención)
{
	int matricula,dni_dueno;
	fecha fecha_atencion;
	char detalle_atencion[380];
	bool borrado;
};


main()
{
	IntroPrincipal();
	FILE*p; usuarios reg; // USUARIOS
	FILE*t; mascota ma; turnos atencion;// TURNOS
	FILE*m; // MASCOTAS
	FILE*v; veterinario ve; // VETERINARIOS
	   
	char Usuario[10],Contrasena[10];
	bool validado=false;
	int salir=3;
	char apeynom[60]; int matricula; //AUXILIARES
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
				p=fopen("usuarios.dat","r+b");
				if(p==NULL)
				{
					printf("Error, no se pudo abrir el archivo (usuarios.dat)");
					Sleep(3000);
					gotoxy(23,4);
					printf("Por tanto no podra iniciar sesion...");
					Sleep(4000);
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
						strcpy(apeynom,reg.apeynom); //COPIO DEL REGISTRO EL APELLIDO Y NOMBRE DEL VETERINARIO
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
				if(validado==true)
				{
					t=fopen("turnos.dat","a+b");
					m=fopen("mascotas.dat","a+b");
					if(v==NULL)
					{
						gotoxy(65,2);
						printf("Error leve turnos.dat");
						Sleep(1500);
						gotoxy(65,2);
						printf("                     ");
						break;
					}
					if(m==NULL)
					{
						gotoxy(65,2);
						printf("Error leve mascotas.dat");
						Sleep(1500);
						gotoxy(65,2);
						printf("                       ");
						break;
					}
					marco();
					fread(&atencion,sizeof(turnos),1,t);
					system("cls");
					marco();
					int col=0;
					while(!feof(t))
					{
						col++;
						gotoxy(2,1+col);
						printf("FECHA DE TURNO: %d/%d/%d",atencion.fecha_atencion.dia,atencion.fecha_atencion.mes,atencion.fecha_atencion.anio);
						gotoxy(2,2+col);
						printf("NOMBRE DE LA FLIA. DE MASCOTA: %s",ma.apeynom);
						fread(&atencion,sizeof(turnos),1,t);
						getch();
					}
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
			case 3:
				if(validado==true)
				{
					system("cls");
					v=fopen("veterinarios.dat","rb"); //ABRO DATOS DEL VETERINARIO
					if(v==NULL)
					{
						gotoxy(65,2);
						printf("Error leve veterinarios.dat");
						Sleep(1500);
						gotoxy(65,2);
						printf("             ");
					}
					fread(&ve,sizeof(veterinario),1,v);
					while(!feof(v))
					{
						if(strcmp(apeynom,ve.apeynom)==0)
						{
							matricula=ve.matricula;	
						}
						fread(&ve,sizeof(veterinario),1,v);
					}
	
					t=fopen("turnos.dat","a+b"); // ACCEDO A REGISTRO DE TURNOS PARA GRABAR INFORME
					if(t==NULL)
					{
						gotoxy(65,2);
						printf("Error leve turnos.dat");
						Sleep(1500);
						gotoxy(65,2);
						printf("             "); // PARA BORRAR EL MENSAJE
					}
					texto_diagnostico(atencion.detalle_atencion);
					gotoxy(2,6);
					printf("%s",atencion.detalle_atencion);
					marco();
					gotoxy(27,2);
					printf("DIAGNOSTICO GUARDADO");
					gotoxy(2,4);
					printf("Veterinario a cargo: %s",apeynom);
					gotoxy(27,3); getch();
					for(int sub;sub<20;sub++) //DETALLE DE SUBRAYADO
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
