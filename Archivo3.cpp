#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define nn 164 //Ñ 
#define NN 165 // ñ 
//SOLO sirven para que el usuario cargue con ñ pero parece que no con printf
//\xA4 pone la ñ

struct Reg
{
	int ano;
	int tur;
	int n;//Lo uso para ver el ultimo año ingresado
	//no me acuerdo la funcion para volver al anterior
};
void CARGA(Reg Ficha,FILE *arch);
int MENOR(Reg Ficha,FILE *arch,int b);
void PROBABLE(Reg Ficha,FILE *arch);
main()
{
	int b;//la bandera para la funcion con tipo
	FILE*arch;
	Reg Ficha;
	CARGA(Ficha,arch);
	b=0;
	system("CLS");
	printf("EJERCICIO 3");
	printf("\n\n La menor cantidad de Turistas fue de :  %d",MENOR(Ficha,arch,b));
	b=1;
	printf("\n y ocurrio en el a\xA4o: %d",MENOR(Ficha,arch,b) );
	getch();
	PROBABLE(Ficha,arch);
	
	
	
}
void CARGA(Reg Ficha, FILE *arch)//Carga del archivo
{
	char dec;
	arch= fopen("Estadistica.dat","w+b");
	Ficha.n=1;
	do
	{
		system("CLS");
		printf("EJERCICIO 3");
		printf("\n\n Ingrese el a\xA4o:  ");
		scanf("%d",&Ficha.ano);
		printf("\n Ingrese la cantidad de Turistas que llego ese a\xA4o:  ");
		scanf("%d",&Ficha.tur);+
		fwrite(&Ficha,sizeof(Reg),1,arch);
		system("CLS");
		printf("EJERCICIO 3");
		printf("\n\n\t Desea ingresar otro a\xA4o [s/n]:  ");
		_flushall();
		scanf("%c",&dec);
		if(dec =='s' || dec == 'S')
		{
			Ficha.n++;
		}
		
	}while(dec == 's' || dec == 'S');
	fclose(arch);
}
int MENOR(Reg Ficha,FILE *arch,int b)//Obtiene la menor cant de turistas yelaño
{
	//como uso una sola funcion con la bandera devuelvo el valor que necesito
	int anio;
	int men;
	arch= fopen("Estadistica.dat","r");
	fread(&Ficha,sizeof(Reg),1,arch);
	men = Ficha.tur;
	anio = Ficha.ano;
	while(!feof(arch))
	{
		if(Ficha.tur < men)
		{
			anio = Ficha.ano;
			men = Ficha.tur;
		}
			fread(&Ficha,sizeof(Reg),1,arch);
	}
	rewind(arch);
	fclose(arch);
	if(b==0) return men;
	else
	{
		return anio;
	}
	
}
void PROBABLE(Reg Ficha,FILE *arch)//Saca la Probabilidad del año que viene
{
	//con el auxiliar obtengo el ultimo registro grabado
	Reg Aux;
	int may=0;
	int s;
	int r;
	arch= fopen("Estadistica.dat","r");
	fread(&Ficha,sizeof(Reg),1,arch);
	while(!feof(arch))
	{
		if(Ficha.n>may)
		{
			Aux.ano= Ficha.ano;
			Aux.tur= Ficha.tur;
		}
		fread(&Ficha,sizeof(Reg),1,arch);
	}
	//A partir de aca se trabaja con el auxiliar
	s = Aux.tur+50;
	r = s-137;
	system("CLS");
	printf("EJERCICIO 3");
	printf("\n\n Considerando que en el a\xA4o %d, hubo un ingreso de %d Turistas",Aux.ano,Aux.tur);
	printf("\n Esperando 50 turistas para el a\xA4o proximo");
	printf("\n\n Concluimos.......");
	if(r>0)
	{
		printf("\n\n Que habra un exceso de turistas en el a\xA4o %d y la cantidad de turistas sin alojar sera de %d",Aux.ano+1,r);
	}
	else
	{
		printf("\n\n Que en el a\xA4o %d sobrara una cantidad de camas de : %d",Aux.ano+1,r*(-1));
	} 
	fclose(arch);
	getch();
	
	
}


