#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define nn 164 
#define NN 165
// para admitir ñ y Ñ
void CARGA(FILE *text);
void MOSTRAR(FILE *text);
//struppr para mayusculas (cadena)
// strlwr para minusculas (cadena)
// toupper para mayusculas (caracteres) usar libreria <ctype.h>
// tolower para minusculas (caracteres) usar libreria <ctype.h>
// otra manera de pasar de minuscula a mayuscula es restarle a la palabra 32
main()
{
	FILE *text;
	char nombres[50];
	CARGA(text);
	MOSTRAR (text);
}
void CARGA(FILE *text)//CREA EL ARCHIVO DE TEXTO
{
	int i;
	char nombres[50];
	text = fopen("Nombres.txt","w");
	for(i=0;i<20;i++)
	{
		system("CLS");
		printf("EJERCICIO 8");
		printf("\n\n Ingrese el nombre %d :  ",i+1);
		_flushall();
		gets(nombres);
		fprintf(text,"%s\n",nombres);
	}
	fclose(text);
	
}
void MOSTRAR(FILE *text)//MUESTRA EL ARCHIVO PASADO A MINUSCULAS
{
	//USO strlwr
	char nombres[50];
	text = fopen("Nombres.txt","r");
	fgets(nombres,50,text);
	system("CLS");
	printf("EJERCICIO 8");
	printf("\n\n\t\t\t\t Nombres:\n\n\t\t\t\t");
	while(!feof(text))
	{
		strlwr(nombres);
		printf("%s\n\t\t\t\t",nombres);
		fgets(nombres,50,text);
	}
	getch();
}
