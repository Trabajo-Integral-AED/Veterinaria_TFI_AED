#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
struct fecha_nac
{
	int dia,mes,anio;
};
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
	fecha_nac fecha_nacimiento;
	float peso;
};
struct turnos
{
	int matricula,dni_dueno;
	fecha fecha_atencion;
	char detalle_atencion[380];
};

void lectura();

int main ()
{
	int i=0,j=0;
	FILE*p;
	usuarios regi;
	veterinario vete;
	turnos tur;
	mascota masco;
//USUARIOS
	p=fopen("Usuarios.dat","w+b");
	if(p==NULL)
	{
		printf("Error no se pudo abrir el archivo..");
		return 0;
	}
	for(int i=0;i<3;i++)
	{
	printf("USUARIOS\n\n");
	printf("Ingrese usuario: ");
	fgets(regi.usuario,10,stdin);
	_flushall();
	printf("\nIngrese contrasena: ");
	fgets(regi.contrasena,10,stdin);
	_flushall();
	printf("\nIngrese Nombre/s y Apellido/s: ");
	fgets(regi.apeynom,60,stdin);
	fwrite(&regi,sizeof(usuarios),1,p);
	system("cls");
	}
	fclose(p);

//TURNOS
	p=fopen("turnos.dat","w+b");
	if(p==NULL)
	{
		printf("Error no se pudo abrir el archivo..");
		return 0;
	}
	
	for(i=0;i<3;i++)
	{
		printf("TURNOS\n\n");
		printf("Ingrese fecha de atencion dd/mm/aaaa: ");
		scanf("%d",&tur.fecha_atencion.dia);
		_flushall();
		scanf("%d",&tur.fecha_atencion.mes);
		_flushall();
		scanf("%d",&tur.fecha_atencion.anio);
		_flushall();
		printf("\nIngrese DNI dueño: ");
		scanf("%d",&tur.dni_dueno);
		_flushall();
//		printf("\nIngrese Matricula Veteriania/o: ");
//		scanf("%d",&tur.matricula);
		fwrite(&tur,sizeof(turnos),1,p);
		system("cls");
		
	}
	fclose(p);
//VETERINARIO

	p=fopen("veterinarios.dat","w+b");
	if(p==NULL)
	{
		printf("Error no se pudo abrir el archivo..");
		return 0;
	}
	
	for(i=0;i<3;i++)
	{
		printf("VETERINARIOS\n\n");
		printf("Ingrese Apellido y Nombres: ");
		fgets(vete.apeynom,60,stdin);
		_flushall();
		printf("\nIngrese DNI Veterinario: ");
		scanf("%d",&vete.dni);
		_flushall();
		printf("\nIngrese Matricula Veteriania/o: ");
		scanf("%d",vete.matricula);
		printf("\nIngrese telefono");
		_flushall();
		fgets(vete.telefono,25,stdin);
		fwrite(&vete,sizeof(veterinario),1,p);
		system("cls");
		
	}
	fclose(p);
	
//MASCOTA

	p=fopen("mascotas.dat","w+b");
	if(p==NULL)
	{
		printf("Error no se pudo abrir el archivo..");
		return 0;
	}
	
	for(i=0;i<3;i++)
	{
		printf("MASCOTAS\n\n");
		printf("Ingrese Apellido y Nombres: ");
		fgets(masco.apeynom,60,stdin);
		_flushall();
		printf("\nDomicilio: ");
		fgets(masco.domicilio,60,stdin);
		_flushall();
		printf("\nIngrese DNI Dueno: ");
		scanf("%d",&masco.dni_dueno);
		_flushall();
		printf("\nLocalidad: ");
		fgets(masco.localidad,60,stdin);
		_flushall();
		printf("\nIngrese fecha de nacimiento dd/mm/aaaa: ");
		scanf("%d",&masco.fecha_nacimiento.dia);
		scanf("%d",&masco.fecha_nacimiento.mes);
		scanf("%d",&masco.fecha_nacimiento.anio);
		_flushall();
		printf("\nIngrese Peso: ");	
		scanf("%f",&masco.peso);
		_flushall();
		printf("\nIngrese telefono");
		fgets(masco.telefono,25,stdin);
		fwrite(&masco,sizeof(mascota),1,p);
		system("cls");
		
	}	
	fclose(p);
//
////	if(strcmp(c1,c2)==0)
////	{
////		printf("Son iguales");
////	}
////	else
////	{
////		printf("No son iguales\n");
////		printf("%s %s",c1,c2);
////	}
//	
	getch();
	return 0;
}
