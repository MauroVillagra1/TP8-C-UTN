#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void CARGA(FILE *arch, int N);
float PROMEDIO(FILE *arch,int &arriba, int &abajo,int N);
//EN EL TP ANTERIOR RECIEN ME ENTERO QUE LAS CON TIPO PUEDEN DEVOLVER MAS DE UN VALOR 
//HAY QUE USAR PARAMETROS DE REFERENCIA :O
//HAGO TODO EN LA MISMA FUNCION PARA NO TENER QUE HACER MAS FUNCIONES
//TRATO DE AHORRAR LINEAS :D
main()
{
	int N,arriba,abajo;
	FILE *arch;
	system("CLS");
	printf("EJERCICIO 6");
	printf("\n\n Indique la cantidad de reales a ingresar:  ");
	scanf("%d",&N);
	CARGA(arch,N);
	system("CLS");
	printf("EJERCICIO 6");
	printf("\n\n El promedio de la muestra es de:  %.2f",PROMEDIO(arch,arriba,abajo,N));
	getch();
	printf("\n\n La cantidad de valores que superan el promedio es de: %d",arriba);
	printf("\n La cantidad de valores que estan debajo del promedio es de: %d",abajo);
	getch();
}
void CARGA(FILE *arch, int N)//Carga del archivo
{
	int i;
	float num;
	arch = fopen("Ejercicio6.dat","w+b");
	for(i=0;i<N;i++)
	{
		system("CLS");
		printf("EJERCICIO 6");
		printf("\n\n Ingrese el %d° numero real:  ",i+1);
		scanf("%f",&num);
		fwrite(&num,sizeof(int),1,arch);
	}
	fclose(arch);
}
float PROMEDIO(FILE *arch,int &arriba, int &abajo,int N)//SACA PROMEDIO Y LA CANT QUE PASA EL PROMEDIO
{
	float num,s,prom;
	arch = fopen("Ejercicio6.dat","r");
	s =0 ;
	arriba = 0;
	abajo = 0;
	fread(&num,sizeof(float),1,arch);
	while(!feof(arch))
	{
		s = s +num ;
		fread(&num,sizeof(float),1,arch);
		
	}
	prom = s / (float)N;
	rewind(arch);
	fread(&num,sizeof(float),1,arch);
	while(!feof(arch))
	{
		if(num<prom)
		{
			abajo++;
		}
		else
		{
			if(num>prom)
			{
				arriba++;
			}
		}
		fread(&num,sizeof(float),1,arch);
	}
	fclose(arch);
	return(prom);
	
}
