#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void CARGA(FILE *arch, int N);
float MAYOR(FILE *arch, float &men);
void MOSTRAR(FILE *arch);
main()
{
	FILE *arch;
	int N;
	float men;
	do
	{
		system("CLS");
		printf("EJERCICIO 8");
		printf("\n\n Indique la cantidad de numeros a ingresar(minimo 10 numeros):  ");
		
		scanf("%d",&N);
		if(N<10)
		{
			printf("\n\n\aERROR - debe ingresar como minimo 10 digitos");
			printf("\n\n Por favor, vuelva a ingresar el numero");
			getch();
		}
		
	}while (N<10);
	CARGA(arch,N);
	system("CLS");
	printf("EJERCICIO 8");
	printf("\n\n El mayor valor cargado es : %.2f",MAYOR(arch,men));
	printf("\n El menor valor cargado es : %.2f",men);
	getch();
	system("CLS");
	printf("EJERCICIO 8");
	printf("\n\n A continuacion se listaran los reales en el orden ingresado");
	getch();
	MOSTRAR(arch);
	
}
void CARGA(FILE *arch, int N)
{
	int i;
	float num;
	arch = fopen("Ejercicio5.dat","w+b");
	for(i=0;i<N;i++)
	{
		system("CLS");
		printf("EJERCICIO 8");
		printf("\n\n Ingrese el %d° numero real(max dos digitos enteros):   ",i+1);
		scanf("%f",&num);
		if(num >= 100)
		{
			system("CLS");
			printf("EJERCICIO 8");
			printf("\n\n\a ERROR- Debe ingresar reales con un maximo de dos digitos enteros");
			printf("\n\t Por favor, ingrese de nuevo el numero");
			printf("\n\t Pulse una tecla para volver a ingresar numero...");
			getch();
			i--;
		}
		else
		{
			fwrite(&num,sizeof(float),1,arch);
		}
		
	}
	fclose(arch);
	
}
float MAYOR(FILE *arch, float &men)
{
	float may,num;
	arch = fopen("Ejercicio5.dat","r");
	may=0;
	men=9999;
	fread(&num,sizeof(float),1,arch);
	while(!feof(arch))
	{
		if(num <men)
		{
			men = num;
		}
		else
		{
		}
		if(num > may)
		{
			may = num;
		}
		fread(&num,sizeof(float),1,arch);
	}
	fclose(arch);
	return(may);

}
void MOSTRAR(FILE *arch)
{
	int i=0;
	float num;
	arch = fopen("Ejercicio5.dat","r");
	fread(&num,sizeof(float),1,arch);
	system("CLS");
	printf("EJERCICIO 8");
	printf("\n\n\t\tOrden\t\t\t\tValor");
	while(!feof(arch))
	{
		printf("\n\n\t\t%d\t\t\t\t%.2f",i+1,num);
		i++;
		fread(&num,sizeof(float),1,arch);
	}
	getch();
	
	
	
}

