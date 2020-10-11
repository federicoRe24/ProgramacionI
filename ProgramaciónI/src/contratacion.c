

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contratacion.h"
#include "utn.h"

static int generarIdNuevo(void);

/*Contratar una publicidad: ​ Se listaran todas las pantallas y se le pedirá al usuario que
elija la pantalla donde se quiere publicar, ingresando su ID. Luego se pedirán los datos
asociados a la publicidad: cuit del cliente, cantidad de días que dura la publicación y
nombre​ ​ del​ ​ archivo​ ​ de​ ​ video​ ​ (p.ej.​ ​ Video1.avi). */

int contratacion_alta(Pantalla *pPantalla, int limitePantalla, Contratacion *pContratacion, int limiteContratacion)
{
	int opcion;
	Contratacion bufferContratacion;

	if(pant_imprimirArray(pPantalla, limitePantalla) == 0) // imprimir en main para no mezclar los 2
	{
		if(utn_getNumero("Ingrese el id de una pantalla para publicar en ella", "Debe ingresar un id válido", &opcion, 3, 1, 4) == 0)
		{
			bufferContratacion.idPantalla = opcion;
			utn_getNombre("Cuit?", "\nError",bufferContratacion.cuit, 2,NOMBRE_LEN);
			utn_getInt("Ingrese la cantidad de dias", "Error\n", &bufferContratacion.cantidadDias,3,10,1);
			utn_getString("Ingrese el nombre del video", "Error\n", bufferContratacion.nombreVideo, 2,NOMBRE_LEN);
		}
		bufferContratacion.idContratacion =generarIdNuevo();
		bufferContratacion.isEmpty =0;
		pContratacion[0]= bufferContratacion;
		contratacion_imprimirArray(pContratacion, limiteContratacion);
	}

	return 0;
}

int contratacion_imprimir(Contratacion* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty ==0)
	{
		retorno=0;
		printf("%5d %10s %10d %10s %10d\n",pElemento->idContratacion,pElemento->cuit,pElemento->cantidadDias,pElemento->nombreVideo,pElemento->idPantalla);
	}
	return retorno;
}
int contratacion_imprimirArray(Contratacion *array, int limite)
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
			contratacion_imprimir(&array[i]);
		}
	}
	return retorno;
}
/*
int contratacion_inicializarArray(Pantalla *array, int limite)
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
}*/

static int generarIdNuevo(void)
{
	static int id=0; //es global pero solo la funcion puede usarla, es como si estuviese arriba. s einicializa en 0 solo una vez
	id= id+1;
	return id;
}
/*
int contratacion_altaArray(Pantalla *array,int limite) // NO anidar mas de 3 ifs, concatenar en todo caso
{
	int retorno = -1;
	Pantalla bufferPantalla;
	int index;
	index= contratacion_getNextEmptyIndex(array, CANTIDAD_CONTRATACIONES);
	if(array !=NULL && limite>0 && index >= 0  && array[index].isEmpty==1)
	{
		if( utn_getNombre("nombre?", "\nError",bufferPantalla.nombre, 2,NOMBRE_LEN)==0 &&
		    utn_getString("direccion?", "\nError", bufferPantalla.direccion, 2,NOMBRE_LEN)==0 &&
		    utn_getFloat("precio?", "\nError", &bufferPantalla.precioDia, 2, 0, 99999)==0 &&
			utn_getNumero("tipo contratacion 1 led 2 lcd", "\nError", &bufferPantalla.tipoPantalla, 2, 1, 2)==0)
		{
			bufferPantalla.idPantalla =generarIdNuevo();
			bufferPantalla.isEmpty =0;
			array[index]= bufferPantalla;
			retorno=0;
		}
	}
	return retorno;
}
int contratacion_modificarArray(Pantalla *array,int limite)
{
	int retorno = -1;
	Pantalla bufferPantalla;
	int auxiliarId;
	int indice;
	contratacion_imprimirArray(array, CANTIDAD_CONTRATACIONES);
	if(utn_getNumero("indique id de contratacionente a modificar", "id invalido", &auxiliarId, 2, 0, CANTIDAD_CONTRATACIONES)==0)
	{
		indice = contratacion_buscarId(array, CANTIDAD_CONTRATACIONES, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
			if(utn_getNombre("nombre?", "\nError",bufferPantalla.nombre, 2,NOMBRE_LEN)==0 &&
				    utn_getString("direccion?", "\nError", bufferPantalla.direccion, 2,NOMBRE_LEN)==0 &&
				    utn_getFloat("precio?", "\nError", &bufferPantalla.precioDia, 2, 0, 99999)==0 &&
					utn_getNumero("tipo contratacion 1 led 2 lcd", "\nError", &bufferPantalla.tipoPantalla, 2, 1, 2)==0)
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
int contratacion_bajaArray(Pantalla *array,int limite)
{
	int retorno = -1;
	int auxiliarId;
	int indice;
	contratacion_imprimirArray(array, CANTIDAD_CONTRATACIONES);
	if(utn_getNumero("indique id de cliente a modificar", "id invalido", &auxiliarId, 2, 0, CANTIDAD_CONTRATACIONES)==0)
	{
		indice = contratacion_buscarId(array, CANTIDAD_CONTRATACIONES, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
				array[indice].isEmpty= 1;
				retorno=0;
		}
	}
	return retorno;
}
int contratacion_buscarId(Pantalla *array, int limite,int valorBuscado)
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
int contratacion_getNextEmptyIndex(Pantalla *array, int limite)
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
}*/
