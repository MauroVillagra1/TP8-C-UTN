#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


void CARGA(FILE *text,int N);
int CONTAR(FILE *text);
//SI SIRVE EL WHILE (!FEOF) PARA LOS TEXTOS
//NO OLVIDAR ATRIBUTOS
//R LECTURA
// W CREA

main()
{
	int N;
	FILE *text;
	system("CLS");
	printf("EJERCICIO 7");
	printf("\n\n Indique la cantidad de cadenas de caracteres a ingresar:  ");
	scanf("%d",&N);
	CARGA(text,N);
	system("CLS");
	printf("EJERCICIO 7");
	printf("\n La cantidad de  palabras guardadas es de: %d",CONTAR(text));
	getch();
	
}
void CARGA(FILE *text,int N)//CARGA EL ARCHIVO
{
	int i;
	char cadena[50];
	text = fopen("Cadena.txt","w");
	for(i=0;i<N;i++)
	{
		system("CLS");
		printf("EJERCICIO 7");
		printf("\n\n Ingrese la cadena %d:  ",i+1);
		_flushall();
		gets(cadena);
		fprintf(text,"%s\n",cadena);//GUARDA EN EL ARCHIVO
	}
	fclose(text);
}
int CONTAR(FILE *text)//CUENTA LA CANTIDAD DE PALABRAS
{
	int i, c;
	char cadena[51];
	text = fopen("Cadena.txt","r");
	fgets(cadena,50,text);//OBTIENE DEL ARCHIVO
	while (!feof(text))
	{
		for(i=0;i<strlen(cadena);i++)//ASI SE CUENTA PALABRAS
		{
			if (cadena[i]== ' ' || cadena[i] == '\n')
			{
				c++;
			}
		}
		fgets(cadena,50,text);
		
	}
	c--;//SE RESTA UNO PORQUE NOSE PORQUE CUENTA UNO DE MAS 
	fclose(text);
	return c;
}
