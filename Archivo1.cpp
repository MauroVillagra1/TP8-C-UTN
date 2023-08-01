#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define nn 164 //Ñ 
#define NN 165 // ñ
//Ejercicio Uno
//Hay una parte en que cierro el archivo y lo vuelvo a abrir pero con otra
//variable, lo hice adrede para probar que el archivo se puede leer

struct Reg
{
 	   char ape[50];
 	   char nom[50];
       float prom1;
       float prom2;
       float prom3;
};
float GENERAL(Reg Lista);
float PROMEDIO (int n, int exim);
main()
{
     Reg Ficha,Lista;//Pongo dos solo para poder demostrar que el archivo esta creado
     FILE *arch;
     char dec;
     int n=1;
     int exim,dic,mar;
     
     dec = 's';
     arch= fopen("HISTORIA_2A.dat","w+b");
     //Tambien se puede hacer con do while pero me gusta trabajar con el while
	 while( dec == 's' || dec == 'S')//Creando el archivo
     {
	  		system("CLS");
	  		printf("EJERCICIO 1");
			printf("\n\n Ingrese el apellido del alumno:  ");
	  		_flushall();
	  		gets(Ficha.ape);
	  		printf("\n\n Ingrese el nombre  del alumno:  ");
	  		_flushall();
	  		gets(Ficha.nom);
	  		printf("\n\n Ingrese el promedio del alumno en el primer trimestre:  ");
	  		scanf("%f",&Ficha.prom1);
	  		printf("\n\n Ingrese el promedio del alumno en el segundo trimestre:  ");
	  		scanf("%f",&Ficha.prom2);
 	  		printf("\n\n Ingrese el promedio del alumno en el tercer trimestre:  ");
	  		scanf("%f",&Ficha.prom3);
	  		fwrite(&Ficha,sizeof(Reg),1,arch);
	  		system("CLS");
	  		printf("EJERCICIO 1");
	  		printf("\n\n Desea ingresar otro alumno?[s/n]:   ");
	  		_flushall();
	  		scanf("%c",&dec);
	  	
     }
     fclose(arch);//cierro el archivo para abrilo de nuevo despues en variable lista
     arch = fopen("HISTORIA_2A.dat","r");
     system("CLS");
     printf("EJERCICIO 1");
     fread(&Lista,sizeof(Reg),1,arch);//Muestro el archivo creado en pantalla
     while(!feof(arch))
     {
	  		printf("\n\n Apellido:  %s",Lista.ape);
	  		printf("\n Nombre:  %s",Lista.nom);
	  		printf("\n Promedio primer trimestre:  %.2f",Lista.prom1);
	  	    printf("\n Promedio segundo trimestre:  %.2f",Lista.prom2);
	  	    printf("\n Promedio tercer trimestre:  %.2f",Lista.prom3);
	  	    printf("\n Promedio General: %.2f",GENERAL(Lista));
	  	     fread(&Lista,sizeof(Reg),1,arch);
	  	    //Uso una funcion con tipo para calcular el prom general porque 
	  	    //es mas facil trabajarlo y lo uso mas de una vez a esa funcion
  	       
     
     
	 }
     getch();
     exim =0;
     dic =0;
     mar =0;
    rewind (arch);//Vital sino la cuenta del archivo da cero
    fread(&Lista,sizeof(Reg),1,arch);
    while(!feof(arch))//Cuenta eximidos, que rinden en dic y marzo
    {
    	if(GENERAL(Lista) >=7)//Uso de nuevo la funcion
    	{
    		exim++;
    	}
    	else
    	{
    		if(GENERAL(Lista) >= 4)
    		{
    			dic++;
    		}
    		else
    		{
    			mar++;
    		}
    	}
    	
    
    	n= n +1;
    	fread(&Lista,sizeof(Reg),1,arch);
    }
    system("CLS");
    printf("EJERCICIO 1");
    printf("\n\n La cantidad de alumnos exhimidos es de : %d",exim);
    printf("\n\n La cantidad de alumnos que rinden en diciembre es de : %d",dic);
    printf("\n\n La cantidad de alumnos que rinden en marzo es de : %d",mar);
    printf("\n\n El promedio de alumnos exhimidos es de : %.2f",PROMEDIO(n,exim));
    getch();
    fclose(arch);
    //La funcion con tipo la use desde el printf o desde el condicional
      
}

float GENERAL(Reg Lista)//Calcula promedio general
{
    float general;
    
    general = (Lista.prom1+Lista.prom2 +Lista.prom3)/3;
    
    return general;
}
float PROMEDIO (int n, int exim)//Calcula el promedio de eximidos
{
	float p;
	p = (float) exim/n;
	return p;
}

