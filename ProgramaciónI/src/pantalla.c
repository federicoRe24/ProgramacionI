
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pantalla.h"
#include "utn.h"

static int generarIdNuevo(void);

int pant_imprimir(Pantalla* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty ==0)
	{
		retorno=0;
		printf("\n%5d %10s %10d %10s %10.2f",pElemento->idPantalla,pElemento->nombre,pElemento->tipoPantalla,pElemento->direccion,pElemento->precioDia);
	}
	return retorno;
}
int pant_imprimirArray(Pantalla *array, int limite)
{
	int retorno = -1;
	if(array !=NULL && limite>0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)  //recordar que va con ;
		{
			if(i==0)
			{
				printf("%5s %10s %10s %10s %10s","id","nombre","tipo","direccion","precio dia\n");
			}
			pant_imprimir(&array[i]);
		}
	}
	return retorno;
}
int pant_inicializarArray(Pantalla *array, int limite)
{
	int retorno=-1;

	if(array != NULL && limite >0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			array[i].isEmpty=1;  //si es verdadero, esta vacio
		}
	}
	return retorno;
}
static int generarIdNuevo(void)
{
	static int id=0; //es global pero solo la funcion puede usarla, es como si estuviese arriba. s einicializa en 0 solo una vez
	id= id+1;
	return id;
}
int pant_altaArray(Pantalla *array,int limite) // NO anidar mas de 3 ifs, concatenar en todo caso
{
	int retorno = -1;
	Pantalla bufferPantalla;
	int index;
	index= pant_getNextEmptyIndex(array, CANTIDAD_PANTALLAS);
	if(array !=NULL && limite>0 && index >= 0  && array[index].isEmpty==1)
	{
		if( utn_getNombre("nombre?", "\nError",bufferPantalla.nombre, 2,NOMBRE_LEN)==0 &&
		    utn_getString("direccion?", "\nError", bufferPantalla.direccion, 2,NOMBRE_LEN)==0 &&
		    utn_getFloat("precio?", "\nError", &bufferPantalla.precioDia, 2, 0, 99999)==0 &&
			utn_getNumero("tipo pantalla 1 led 2 lcd", "\nError", &bufferPantalla.tipoPantalla, 2, 1, 2)==0)
		{
			bufferPantalla.idPantalla =generarIdNuevo();
			bufferPantalla.isEmpty =0;
			array[index]= bufferPantalla;
			retorno=0;
		}
	}
	return retorno;
}
int pant_modificarArray(Pantalla *array,int limite)
{
	int retorno = -1;
	Pantalla bufferPantalla;
	int auxiliarId;
	int indice;
	pant_imprimirArray(array, CANTIDAD_PANTALLAS);
	if(utn_getNumero("indique id de pantente a modificar", "id invalido", &auxiliarId, 2, 0, CANTIDAD_PANTALLAS)==0)
	{
		indice = pant_buscarId(array, CANTIDAD_PANTALLAS, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
			if(utn_getNombre("nombre?", "\nError",bufferPantalla.nombre, 2,NOMBRE_LEN)==0 &&
				    utn_getString("direccion?", "\nError", bufferPantalla.direccion, 2,NOMBRE_LEN)==0 &&
				    utn_getFloat("precio?", "\nError", &bufferPantalla.precioDia, 2, 0, 99999)==0 &&
					utn_getNumero("tipo pantalla 1 led 2 lcd", "\nError", &bufferPantalla.tipoPantalla, 2, 1, 2)==0)
			{
				bufferPantalla.idPantalla=auxiliarId;
				bufferPantalla.isEmpty =0;
				array[indice]= bufferPantalla;
				retorno=0;

			}
		}
	}
	return retorno;
}
int pant_bajaArray(Pantalla *array,int limite)
{
	int retorno = -1;
	int auxiliarId;
	int indice;
	pant_imprimirArray(array, CANTIDAD_PANTALLAS);
	if(utn_getNumero("indique id de cliente a modificar", "id invalido", &auxiliarId, 2, 0, CANTIDAD_PANTALLAS)==0)
	{
		indice = pant_buscarId(array, CANTIDAD_PANTALLAS, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
				array[indice].isEmpty= 1;
				retorno=0;
		}
	}
	return retorno;
}
int pant_buscarId(Pantalla *array, int limite,int valorBuscado)
{
	int retorno=-1;
	int i;

	if(array != NULL && limite >0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(array[i].idPantalla== valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int pant_getNextEmptyIndex(Pantalla *array, int limite)
{
	int retorno=-1;
	int i;

	if(array != NULL && limite >0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno= i;
				break;
			}
		}
	}
	return retorno;
}
