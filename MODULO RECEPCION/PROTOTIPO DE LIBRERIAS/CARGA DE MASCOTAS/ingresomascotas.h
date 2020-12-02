#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct{
	int matriculavet;
	fecha fecturno;
	int dni2;
	char detalle;
}info;

typedef struct{
	char nombrep[60];
	int dia;
	int numturno;
	int disponible;
	info  informacion;
}tur;



typedef struct{
	char ayn[60];
	char domicilio[60];
	int dni;
	char localidad[60];
	int baja;
	fecha fnac;
	float peso;
	char telefono[60];
}vet;

vet pacientes;
tur turno;
 
void carga(){
	FILE *registro;
	registro=fopen("pacientes.dat","wb");
	
	puts("REGISTRO DE MASCOTAS\n");
	
	printf(" Nombre y Apellido: ");
	fflush(stdin);
	gets(pacientes.ayn);
	printf(" Nro de Documento: ");
	scanf("%i",&pacientes.dni);
	printf(" Localidad: ");
	fflush(stdin);
	gets(pacientes.localidad);
	printf(" Domicilio: ");
	fflush(stdin);
	gets(pacientes.domicilio);
	printf(" Peso(kg): ");
	scanf("%f",&pacientes.peso);
	printf(" Fecha de Nacimiento\n");
	printf(" Dia: ");
	scanf("%i",&pacientes.fnac.dia);
	printf(" Mes: ");
	scanf("%i",&pacientes.fnac.mes);
	printf(" Anio: ");
	scanf("%i",&pacientes.fnac.anio);		
	printf(" Nro Telefonico: ");
	scanf("%i",&pacientes.telefono);	
	pacientes.baja=0;
	
	fwrite(&pacientes,sizeof(vet),1,registro);
	
	printf("\n\nCargando");
	Sleep(100);printf(".");
	Sleep(100);printf(".");
	Sleep(100);printf(".");
	Sleep(100);printf(".");
	Sleep(100);printf(".");		
	Sleep(100);
	
	fclose(registro);
	
	system("cls");
	puts("\n\n\tLa mascota ah sido registrada exitosamente!");
	Sleep(2000);
	system("cls");
}
