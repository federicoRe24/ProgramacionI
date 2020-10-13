

#include "publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int generarIdNuevo(void);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Publicacion* Pointer to array of publicaciones
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPublicaciones(Publicacion* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].estado = ACTIVA;
		}
		retorno = 0;
	}
	return retorno;
}

/*Contratar una publicidad: ​ Se listaran todas las pantallas y se le pedirá al usuario que
elija la pantalla donde se quiere publicar, ingresando su ID. Luego se pedirán los datos
asociados a la publicidad: cuit del cliente, cantidad de días que dura la publicación y
nombre​ ​ del​ ​ archivo​ ​ de​ ​ video​ ​ (p.ej.​ ​ Video1.avi). */

int publicacion_alta(Cliente *pCliente, int limiteCliente, Publicacion *pPublicacion, int limitePublicacion)
{
	int opcion;
	Publicacion bufferPublicacion;

	if(printClientes(pCliente, limiteCliente) == 0) // imprimir en main para no mezclar los 2
	{
		if(getInt("Ingrese el id del cliente para crear un nuevo aviso", "Debe ingresar un id válido", &opcion, 3, 4, 1) == 0)
		{
			bufferPublicacion.idCliente = opcion;
			getInt("Ingrese el número de rubro: ", "Error\n", &bufferPublicacion.numeroRubro,3,10,1);
			getNombre("Ingrese el texto del aviso (hasta 64 caracteres): ", "\nError",bufferPublicacion.textoAviso, 2,AVISO_LEN);
			//utn_getString("Ingrese el nombre del video", "Error\n", bufferPublicacion.nombreVideo, 2,NOMBRE_LEN);
		}
		for(int i=0;i<limitePublicacion;i++)
		{
			if(pPublicacion[i].isEmpty == TRUE)
			{
				bufferPublicacion.idPublicacion = generarIdNuevo();
				bufferPublicacion.isEmpty = FALSE;
				pPublicacion[i]= bufferPublicacion;
				break;
			}
		}
		publicacion_imprimirArray(pPublicacion, limitePublicacion);
	}
	return 0;
}


int publicacion_imprimirArray(Publicacion *array, int limite)
{
	int retorno = -1;
	if(array !=NULL && limite>0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			if(array[i].isEmpty == FALSE && array[i].estado == ACTIVA)
			{
				printf("idPublicacion: %d, N° Rubro: %d, Aviso: %s, idCliente: %d\n",array[i].idPublicacion, array[i].numeroRubro, array[i].textoAviso,
						array[i].idCliente);
			}
		}
	}
	return retorno;
}

int publicacion_imprimirPorCliente(Publicacion *array, int limite, int idCliente)
{
	int retorno = -1;
	if(array !=NULL && limite>0 && idCliente > 0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == idCliente && array[i].isEmpty == FALSE)
			{
				printf("idPublicacion: %d, N° Rubro: %d, Aviso: %s, idCliente: %d\n",array[i].idPublicacion, array[i].numeroRubro, array[i].textoAviso,
						array[i].idCliente);
			}
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

int publicacion_pausar(Publicacion *array, int limite, int id)
{
	int retorno = -1;
	int idPausa;
	if(array !=NULL && limite>0)
	{
		idPausa = publicacion_buscarId(array, limite, id);
		if(idPausa != -1)
		{
			array[idPausa].estado = PAUSADA;
		}
		else
		{
			printf("No se encontró niguna publicación con el id solicitado\n");
		}
		retorno = 0;
	}
	return retorno;
}

int publicacion_reanudar(Publicacion *array, int limite, int id)
{
	int retorno = -1;
	int idPausa;
	if(array !=NULL && limite>0)
	{
		idPausa = publicacion_buscarId(array, limite, id);
		if(idPausa != -1)
		{
			array[idPausa].estado = ACTIVA;
		}
		else
		{
			printf("No se encontró niguna publicación con el id solicitado\n");
		}
		retorno = 0;
	}
	return retorno;
}


/*
int contratacion_altaArray(Cliente *array,int limite) // NO anidar mas de 3 ifs, concatenar en todo caso
{
	int retorno = -1;
	Cliente bufferCliente;
	int index;
	index= contratacion_getNextEmptyIndex(array, CANTIDAD_CONTRATACIONES);
	if(array !=NULL && limite>0 && index >= 0  && array[index].isEmpty==1)
	{
		if( utn_getNombre("nombre?", "\nError",bufferCliente.nombre, 2,NOMBRE_LEN)==0 &&
		    utn_getString("direccion?", "\nError", bufferCliente.direccion, 2,NOMBRE_LEN)==0 &&
		    utn_getFloat("precio?", "\nError", &bufferCliente.precioDia, 2, 0, 99999)==0 &&
			utn_getNumero("tipo contratacion 1 led 2 lcd", "\nError", &bufferCliente.tipoCliente, 2, 1, 2)==0)
		{
			bufferCliente.idCliente =generarIdNuevo();
			bufferCliente.isEmpty =0;
			array[index]= bufferCliente;
			retorno=0;
		}
	}
	return retorno;
}
int contratacion_modificarArray(Cliente *array,int limite)
{
	int retorno = -1;
	Cliente bufferCliente;
	int auxiliarId;
	int indice;
	contratacion_imprimirArray(array, CANTIDAD_CONTRATACIONES);
	if(utn_getNumero("indique id de contratacionente a modificar", "id invalido", &auxiliarId, 2, 0, CANTIDAD_CONTRATACIONES)==0)
	{
		indice = contratacion_buscarId(array, CANTIDAD_CONTRATACIONES, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
			if(utn_getNombre("nombre?", "\nError",bufferCliente.nombre, 2,NOMBRE_LEN)==0 &&
				    utn_getString("direccion?", "\nError", bufferCliente.direccion, 2,NOMBRE_LEN)==0 &&
				    utn_getFloat("precio?", "\nError", &bufferCliente.precioDia, 2, 0, 99999)==0 &&
					utn_getNumero("tipo contratacion 1 led 2 lcd", "\nError", &bufferCliente.tipoCliente, 2, 1, 2)==0)
			{
				bufferCliente.idCliente=auxiliarId;
				bufferCliente.isEmpty =0;
				array[indice]= bufferCliente;
				retorno=0;

			}
		}
	}
	return retorno;
}*/


int publicacion_borrar(Publicacion *array, int limite, int id)
{
	int retorno = -1;
	int auxiliarId;
	int indice;
	if(getInt("indique id de cliente a eliminar", "id invalido", &auxiliarId, 2, 0,limite)==0)
	{
		//contratacion_imprimirArray(array, CANTIDAD_CONTRATACIONES);
		//indice = contratacion_buscarId(array, CANTIDAD_CONTRATACIONES, auxiliarId);
		if(array !=NULL && limite>0 && indice >= 0 && array[indice].isEmpty==0)
		{
				array[indice].isEmpty= 1;
				retorno=0;
		}
	}
	return retorno;
}


int publicacion_buscarId(Publicacion *array, int limite,int valorBuscado)
{
	int retorno=-1;
	int i;

	if(array != NULL && limite >0 && valorBuscado > 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(array[i].idCliente== valorBuscado)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/*
int contratacion_getNextEmptyIndex(Cliente *array, int limite)
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
