#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int dia_actual;

typedef struct{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct{
	int matriculavet;
	fecha fecturno;
	int dni2;
	char detalle[60];
}info;

typedef struct{
	char nombrep[60];
	int dia;
	int numturno;
	char horario[15];
	char nombredia[15];
	int disponible;
	info  informacion;
}tur;

tur turnos;

void gestionturnos(){

	FILE *gestion;
	FILE *auxgestion;
	
	gestion=fopen("turnos.dat","r");
	auxgestion=fopen("auxturnos.dat","wb");
	
	int dia3,resp=0,i;
	printf("\tReservar turno para el Dia: ");
	scanf("%i",&dia3);
	system("cls");
	fread(&turnos,sizeof(tur),1,gestion);
	
	while(!feof(gestion)){

	if(dia3==turnos.dia && resp==0){
		
		if(turnos.disponible==0 && resp==0){
		printf(" DATOS DE LA RESERVACION\n");
		printf(" -----------------------");
		turnos.disponible=1;			
		printf("\n\n Introduzca la matricula del Veterinario: ");
		scanf("%i",&turnos.informacion.matriculavet);
		printf(" ------------------------------------------------------\n");
		printf(" Introduzca el DNI del Duenio de la mascota: ");
		scanf("%i",&turnos.informacion.dni2);
		printf(" ------------------------------------------------------\n");		
		printf(" Detalles de atencion: ");
		fflush(stdin);
		gets(turnos.informacion.detalle);
		printf(" ______________________________________________________\n");	
		
		resp=1;
		}
		
		
	 }
		
	fwrite(&turnos,sizeof(tur),1,auxgestion);
	fread(&turnos,sizeof(tur),1,gestion);
	}
	
	if(resp==1){
		Sleep(400);
		printf("\n\n  같같같같같같같같같같같같같같같같같같같같같같같같\n");
		printf("  �   El turno ah sido reservado exitosamente!   �\n");
		printf("  같같같같같같같같같같같같같같같같같같같같같같같같\n");										
	}
	
	else{puts("\nEl dia ingresado no es valido\n");
	}
	
	printf("\n\n\n");
	fclose(gestion);
	fclose(auxgestion);
	
	remove("turnos.dat");
	rename("auxturnos.dat","turnos.dat");
}

void mostrarturnos(){
	FILE *gestion;
	
	gestion=fopen("turnos.dat","r");
	printf("\t\t    HORARIOS DE LOS TURNOS:\n\n");
	printf("     Turno 1: 09:00hs  | Turno 4: 10:30hs  | Turno 7: 12:00hs\n");
	printf("     Turno 2: 09:30hs  | Turno 5: 11:00hs  | Turno 8: 12:30hs\n");
	printf("     Turno 3: 10:00hs  | Turno 6: 11:30hs  | Turno 9: 13:00hs\n");	
	printf("\n\n");				
	printf("   * Nota: Al elegir el dia, siempre se tomara el turno mas proximo.\n\n");
	
	puts("\t\tTURNOS DISPONIBLES EN EL MES\n");
	
	puts("\t\tDIA     |        TURNOS");
	puts("\t\t------------------------------\n");
	
	int sal=0,cont=0;
	

	fread(&turnos,sizeof(tur),1,gestion);	
	while(!feof(gestion)){
		if(cont==5){printf("\n");
		cont=0;
		}
		printf("\t\t%s %i:     ",turnos.nombredia,turnos.dia);
		if(turnos.dia<10){
			printf(" ");
		}
		while(sal!=1){
			
			if(turnos.disponible==0){
				
				printf("%i",turnos.numturno);
				
				if(turnos.numturno<9){
					printf("-");
				}
			}
			
			if(turnos.disponible==1){
				printf("  ");
			}
			
			
			if(turnos.numturno==9){
				sal=1;
			}

			fread(&turnos,sizeof(tur),1,gestion);
		}
		
		sal=0;
		printf("\n");
		cont++;
	}
	printf("\n");
	fclose(gestion);
}

void vacio(){
	FILE *gestion;
	
	gestion=fopen("turnos.dat","wb");
	int i,j,sal=0,cont=1;
	
	sal!=1;
	
	for(i=1;sal!=1;i++){
    	for(j=1;j<10;j++){
		
		if(i==6 || i==13 || i==20 || i==27){
			i+=2;
		}
		
		turnos.numturno=j;
		turnos.dia=i;
		turnos.disponible=0;
		turnos.informacion.fecturno.dia=turnos.dia;
		turnos.informacion.fecturno.mes=2;
		turnos.informacion.fecturno.anio=2020;		
		
		switch(j){
			case 1: strcpy(turnos.horario,"09:00 hs");
			break;
			case 2: strcpy(turnos.horario,"09:30 hs");
			break;
			case 3: strcpy(turnos.horario,"10:00 hs");
			break;
			case 4: strcpy(turnos.horario,"10:30 hs");
			break;
			case 5: strcpy(turnos.horario,"11:00 hs");
			break;
			case 6: strcpy(turnos.horario,"11:30 hs");
			break;
			case 7: strcpy(turnos.horario,"12:00 hs");
			break;
			case 8: strcpy(turnos.horario,"12:30 hs");
			break;
			case 9: strcpy(turnos.horario,"13:00 hs");
			break;
			default:printf("Error al cargar horario.");
			break;																						
		}
		
		if(i==1 || i==8|| i==15 || i==22 || i==29){
			strcpy(turnos.nombredia,"Lun");
		}
		else if(i==2 || i==9 || i==16 || i==23 || i==30){
			strcpy(turnos.nombredia,"Mar");
		}
		else if(i==3 || i==10 || i==17 || i==24 || i==31){
			strcpy(turnos.nombredia,"Mie");
		}
		else if(i==4 || i==11 || i==18 || i==25){
			strcpy(turnos.nombredia,"Jue");
		}
		else if(i==5 || i==12 || i==19 || i==26){
			strcpy(turnos.nombredia,"Vie");
		}
		else{
			strcpy(turnos.nombredia,"FIN");
		}
		
		if(i==31){
			sal=1;
		}
		
		fwrite(&turnos,sizeof(tur),1,gestion);
    	}

//		getch();
//		printf("%i",i);
	}
	printf("\n");
	fclose(gestion);
}

void turnosocupados(){
	FILE *gestion;
	
	gestion=fopen("turnos.dat","r");
	
	fread(&turnos,sizeof(tur),1,gestion);
	system("cls");
	printf("\n\t\tINFORMACION DE LAS RESERVACIONES DEL DIA\n\n");
		
	while(!feof(gestion)){
		
		if(turnos.disponible==1 && turnos.dia==dia_actual){
			
			printf("\tNro de Turno: %i\n",turnos.numturno);
			printf("\tFecha y hora: %i/%i/%i  a %s\n",turnos.informacion.fecturno.dia,turnos.informacion.fecturno.mes,turnos.informacion.fecturno.anio,turnos.horario);
			printf("\tMatricula del Especialista: %i\n",turnos.informacion.matriculavet);
			printf("\tDNI Duenio de la mascota: %i\n",turnos.informacion.dni2);
			printf("\tDetalles de la consulta: %s\n",turnos.informacion.detalle);
			printf("\n\t------------------------------------------------------\n\n");
			
		}
			fread(&turnos,sizeof(tur),1,gestion);
	}
      
	  getch();


	
	feof(gestion);
}
