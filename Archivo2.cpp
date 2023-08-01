#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>//Libreria de C++ que sirve para Hacer mayusculas caracteres
#define nn 164
#define nn 165
//Ejercicio 2 del Tp8
struct Reg
{
	char cat;
	char nom[50];
	float precio;
};
void CARGA(Reg Lista,FILE *arch,int &n);
int CUENTA(Reg Lista, int i, FILE *arch);
void LISTAR(Reg Lista,FILE *arch, char bcat);
main()
{
	int i,n;
	char bcat;
	Reg Lista;
	FILE *arch;
	CARGA(Lista,arch,n);
	system("CLS");
	printf("EJERCICIO 2");
	for(i=1;i<4;i++)//Lo hice asi para hacer una sola funcion con tipo
	{
		if ( i==1)
		{
			printf("\n\nLa cantidad de autos de alta gama es de %d",CUENTA(Lista,i,arch));
		}
		else
		{
			if(i == 2)
				{
					printf("\nLa cantidad de autos de baja gama es de %d",CUENTA(Lista,i,arch));
				}
				else
				if (i ==3)
				{
					printf("\nLa cantidad de autos de media gama es de %d",CUENTA(Lista,i,arch));
				}
		}
	}
	getch();
	system("CLS");
	printf("EJERCICIO 2");
	printf("\n\n Ingrese la categoria de autos de la que desea obtener informacion:  ");
	_flushall();
	scanf("%c",&bcat);
	LISTAR(Lista,arch,bcat);
	
	
}

void CARGA(Reg Lista,FILE *arch,int &n)//Carga del Archivo
{
	char dec;
	n =0;//Con N verifico que carguen como minimo tres elementos
	arch = fopen("Vehiculos.dat","w+b");
	do
	{
		system("CLS");
		printf("EJERCICIO 2");
		printf("\n\n Ingrese la categoria del vehiculo");
		printf("\n Pulse A para alta gama");
		printf("\n Pulse B para baja gama");
		printf("\n Pulse M para media gama");
		printf("\n Categoria:  ");
		_flushall();
		scanf("%c",&Lista.cat);
		toupper(Lista.cat);//Hace Mayusculas caracteres
		printf("\n\n Ingrese el nombre del vehiculo:  ");
		_flushall();
		gets(Lista.nom);
		printf("\n\n Ingrese el precio del vehiculo:  ");
		scanf("%f",&Lista.precio);
		fwrite(&Lista,sizeof(Reg),1,arch);
		system("CLS");
		printf("EJERCICIO 2");
		printf("\n\n Desea ingresar otro vehiculo:[s/n] ");
		_flushall();
		scanf("%c",&dec);
		if (dec != 'S' &&  dec != 's')
		{
			if(n <3)//Si es menor Automaticamente obliga a cargar otro
			{
				system("CLS");
				printf("EJERCICIO 2");
				printf("\n\n ERROR - Debe ingresar al menos tres vehiculos");
				getch();
				printf("\n\n A continuacion, debera ingresar otro vehiculo");
				printf("\n Pulse una tecla para ingresar otro vehiculo.....");
				getch();
				_flushall();
				dec = 's';
				
			}
		}
		if (dec =='s' || dec == 'S') n++;
	}while(dec == 's' || dec == 'S');
	fclose (arch);
}
int CUENTA(Reg Lista, int i, FILE *arch)//Cuenta cant de autos de cada categoria
{

	int a,b,c;
	a =0;
	b =0;
	c =0;
	arch = fopen("Vehiculos.dat","r");
	fread(&Lista,sizeof(Reg),1,arch);
	while(!feof(arch))
	{
		
		if (Lista.cat == 'A' || Lista.cat == 'a')
		{
			a++;
		}
		else
		{
			if(Lista.cat == 'B' || Lista.cat == 'b')
			{
				b++;
			}
			else
			{
				if (Lista.cat == 'M' || Lista.cat == 'm')
				{
					c++;
				}
			}
		}
		fread(&Lista,sizeof(Reg),1,arch);
	}
	fclose(arch);
	if (i == 1) return a;
	if (i == 2) return b;
	if (i == 3) return c;

	
}
void LISTAR(Reg Lista,FILE *arch, char bcat)//Muestra autos de una categoria
{
	
	arch = fopen("Vehiculos.dat","r");
	fread(&Lista,sizeof(Reg),1,arch);
	toupper(bcat);
	system("CLS");
	printf("EJERCICIO 2");
	printf("\n\n Categoria\t\t\tNombre del auto\t\t\tPrecio");
	printf("\n");
	while(!feof(arch))
	{
		if( Lista.cat == bcat)
		printf("\n   %c\t\t\t\t%s\t\t\t\t%f",Lista.cat,Lista,Lista.nom,Lista.precio);
		fread(&Lista,sizeof(Reg),1,arch);
		
	}
	getch();
}

