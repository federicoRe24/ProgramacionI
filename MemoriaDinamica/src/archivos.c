
#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"
#include "ArrayClientes.h"
#include <string.h>

// fwrite() - fread(): variables
// fprintf() - fscanf(): SOLO texto

typedef struct {
	char name[8];
	int  edad;
}Empleado;


int escritura(void)
{
	// escribir un archivo con 1 byte que valga 108
	//char variable = 108;
	//int variable = 255;
	//int numeros[5] = {255,8,7,50,78000};

	Empleado cliente;
	cliente.edad = 15;
	sprintf(cliente.name,"Pepe");

	//fopen("/home/totinho91/Descargas/archivo.prueba"); // ruta absoluta;

	FILE* fp = fopen("archivo.prueba", "w"); // ruta relativa
	// Devuelve un puntero a un archivo

	if(fp!=NULL)
	{
		// Uso funciones para leer y escribir
		//fprint(); // escribe archivo

		fwrite(&cliente,sizeof(Cliente),1,fp); // escribe archivo

		fclose(fp);
		// No hacer nada más con el archivo
	}

	return 0;
}

int lectura(void)
{
	Empleado cliente;
	FILE* fp = fopen("arhivo.prueba","r");
	if(fp!=NULL)
	{
		fread(&cliente,sizeof(Cliente),1,fp);
		fclose(fp);
	}

	printf("datos escritos:\n");
	printf("edad:%d nombre:%s\n:",cliente.edad,cliente.name);


	cliente.edad = 15;
	sprintf(cliente.name,"Pepe");


	return 0;
}

int escrituraDos(void)
{
	// fwrite() - fread(): variables : BINARIO

	char cadena[64];

	sprintf(cadena,"Pepe");

	printf("La cadena vale:%s\n",cadena);

	FILE* fp = fopen("prueba.txt", "w");
	if(fp!=NULL)
	{
		fwrite(cadena,strlen(cadena),1,fp);
		fclose(fp);
	}

	return 0;
}

int prueba(void)
{
	int r;
	char cadena[64];
	FILE* fp = fopen("prueba.txt", "w");
	if(fp!=NULL)
	{
		//Para definir lo que toma el scanf
		r = scanf(fp,"%[a-zA-Z ]",cadena);
	}

	return r;

	//TP3 - opcion 1 y 2, levantar lista vacia y llenarla desde el archivo. Despues se trabaja desde el archivo.
}


