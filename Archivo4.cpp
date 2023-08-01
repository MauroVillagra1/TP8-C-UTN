#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

//No entendi el tema de los promedios y nose porque cuando divido N/c me da error
 
void CARGA(int N,int i, FILE *arch);
int PROM1(FILE *arch, int N);
int PROM2(FILE *arch, int N);
main()
{
	FILE *arch;
	int N,i;
	system("CLS");
	printf("EJERCICIO 4");
	printf("\n\n Indique la cantidad de alumnos:  ");
	scanf("%d",&N);
	CARGA(N,i,arch);
	system("CLS");
	printf("EJERCICIO 4");
	printf("\n\n El promedio de alumnos que estan entre los 12 y 15 a\xA4os es de : %d por ciento",PROM1(arch,N));
	printf("\n\n El promedio de alumnos que estan entre los 8 y 11 a\xA4os es de : %d por ciento",PROM2(arch,N));
}
void CARGA(int N,int i, FILE *arch)//Carga archivo
{
	arch = fopen("Edades.dat","w+b");
	int edad;
	for (i=0;i<N;i++)
	{
		system("CLS");
		printf("EJERCICIO 4");
		printf("\n\n Ingrese la edad del alumno %d:    ",i+1);
		scanf("%d",&edad);
		fwrite(&edad,sizeof(int),1,arch);
	}
	fclose(arch);
}
int PROM2(FILE *arch, int N)//Calcula el porcentaje entre 8 y 11 
{
	int edad,c,b;
	int prom2;
	arch =fopen("Edades.dat","r");
	fread(&edad,sizeof(int),1,arch);
	while(!feof(arch))
	{
		if(edad >=8 && edad <= 11)
		{
			c++;
			b = 1;
		}
		fread(&edad,sizeof(int),1,arch);
	}
	fclose(arch);
	if (b ==1)
	{
			prom2 = (c*100)/N;
			return prom2;
	}
	else
	{
		return 0;
	}
}
int PROM1(FILE *arch, int N)//Calcula el porcentaje entre 12 y 15
{
	int edad,c,prom1,b;
	arch =fopen("Edades.dat","r");
	fread(&edad,sizeof(int),1,arch);
	while(!feof(arch))
	{
		if(edad >=12 && edad <= 15)
		{
			c++;
			b =1;
		}
		else
		{
			
		}
		fread(&edad,sizeof(int),1,arch);
	}
	fclose(arch);
	if (b == 1)
	{
			prom1 = (c*100)/N;
			return prom1;
	}
	else
	{
		return 0;
	}

	
}

