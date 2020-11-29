
#include "Sale.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Client.h"

static int generarIdNuevo(LinkedList* pArrayListSale);

Sale* sale_new()
{
	return (Sale*)malloc(sizeof(Sale));
}

Sale* sale_newParametrosStr(char* idStr, char* cantidadAfichesStr, char* nombreImagen, char* zona, char* estadoStr, char* clientIdStr)
{
	Sale* this = sale_new();
	if(this != NULL)
	{
		if(sale_setId(this,atoi(idStr)) != -1 && sale_setCantidadAfiches(this,atoi(cantidadAfichesStr)) != -1
				&& sale_setNombreImagen(this,nombreImagen) != -1 && sale_setZona(this,zona) != -1 && sale_setEstado(this,atoi(estadoStr)) != -1
				&& sale_setClientId(this,atoi(clientIdStr)) != -1)
		{
			return this;
		}
	}
	return NULL;
}

Sale* sale_newParametros(int id, int cantidadAfiches, char* nombreImagen,char* zona, int estado, int clientId)
{
	Sale* this = sale_new();
	if(this != NULL)
	{
		if(sale_setId(this,id) != -1 && sale_setCantidadAfiches(this,cantidadAfiches) != -1 && sale_setNombreImagen(this,nombreImagen) != -1
				&& sale_setZona(this,zona) != -1 && sale_setEstado(this,estado) != -1 && sale_setClientId(this,clientId) != -1)
		{
			return this;
		}
	}
	return NULL;
}

// this -> contexto (a quién estás apuntando)
void sale_delete(Sale* this)
{
	free(this);
}


int sale_getId(Sale* this)
{
	if(this!=NULL)
	{
		return this->id;
	}
	return -1;
}

int sale_setId(Sale* this,int id)
{
	int retorno = -1;
	if(this!=NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int sale_getCantidadAfiches(Sale* this)
{
	if(this!=NULL)
	{
		return this->cantidadAfiches;
	}
	return -1;
}

int sale_setCantidadAfiches(Sale* this,int cantidadAfiches)
{
	int retorno = -1;
	if(this!=NULL && cantidadAfiches > 0)
	{
		this->cantidadAfiches = cantidadAfiches;
		retorno = 0;
	}
	return retorno;
}


char* sale_getNombreImagen(Sale* this)
{
	if(this!=NULL)
	{
		return this->nombreImagen;
	}
	return NULL;
}

int sale_setNombreImagen(Sale* this,char* nombreImagen)
{
	int retorno = -1;
	if(this!=NULL && nombreImagen != NULL)
	{
		strncpy(this->nombreImagen,nombreImagen,sizeof(this->nombreImagen));
		retorno = 0;
	}
	return retorno;
}


char* sale_getZona(Sale* this)
{
	if(this!=NULL)
	{
		return this-> zona;
	}
	return NULL;
}

int sale_setZona(Sale* this,char* zona)
{
	int retorno = -1;
	if(this!=NULL && esUnaZonaValida(zona,LONG_NOMBRE))
	{
		strncpy(this->zona,zona,sizeof(this->zona));
		retorno = 0;
	}
	return retorno;
}


int sale_getEstado(Sale* this)
{
	if(this!=NULL)
	{
		return this->estado;
	}
	return -1;
}

int sale_setEstado(Sale* this,int estado)
{
	int retorno = -1;
	if(this!=NULL && (estado == 0 || estado == 1))
	{
		this->estado = estado;
		retorno = 0;
	}
	return retorno;
}


int sale_getClientId(Sale* this)
{
	if(this!=NULL)
	{
		return this->clientId;
	}
	return -1;
}

int sale_setClientId(Sale* this,int clientId)
{
	int retorno = -1;
	if(this!=NULL && clientId > 0)
	{
		this->clientId = clientId;
		retorno = 0;
	}
	return retorno;
}

/*int isValidName(char* nombre, int limite)
{
	int respuesta = 1; // TODO OK

	for(int i=0; i<=limite && nombre[i] != '\0';i++)
	{
		//esta mal <----- A - Z -----> Esta mal
		if(	(nombre[i] < 'A' || nombre[i] > 'Z') &&
			(nombre[i] < 'a' || nombre[i] > 'z') &&
			nombre[i] != '.' && nombre[i] != '-' &&
			nombre[i] != ' ')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}*/

/*int sale_compararNombre(void* thisA,void* thisB)
{
	int retorno;
	if(thisA != NULL && thisB != NULL)
	{
		char bufferNombreA[256];
		char bufferNombreB[256];
		int respuesta;

		// Casteo el void a Sale
		//sale_getNombre((Sale*)thisA,bufferNombreA);
		//sale_getNombre((Sale*)thisB,bufferNombreB);

		strncpy(bufferNombreA, sale_getNombre((Sale*)thisA), LONG_NOMBRE);
		strncpy(bufferNombreB, sale_getNombre((Sale*)thisB), LONG_NOMBRE);

		// Devuelve positivo, negativo o 0
		respuesta = strcmp(bufferNombreA,bufferNombreB);
		if(respuesta > 0)
		{
			retorno = 1;
		}
		else if(respuesta < 0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}*/

int sale_compararId(void* thisA,void* thisB)
{
	int retorno;
	if(thisA != NULL && thisB != NULL)
	{
		int bufferIdA;
		int bufferIdB;

		bufferIdA = sale_getId((Sale*)thisA);
		bufferIdB = sale_getId((Sale*)thisB);

		if(bufferIdA > bufferIdB)
		{
			retorno = 1;
		}
		else if(bufferIdA > bufferIdB)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
	return retorno;
}


int sale_load(int* id, int* cantidadAfiches, char* nombreImagen, char* zona, int* estado, LinkedList* pArrayListSale)
{
	int resultado;

	resultado = getInt("Ingrese la cantidad de afiches a vender\n","Ingrese una cantidad válida\n",cantidadAfiches,3,MAX_INT,1);

	if(resultado == -1)
		return resultado;

	resultado =  getNombre("Ingrese el nombre del archivo con la imagen del afiche\n", "Debe ingresar un nombre válido\n", nombreImagen,
			3, LONG_NOMBRE);

	if(resultado == -1)
		return resultado;

	resultado =  getZona("Ingrese la zona donde se pegarán los afiches: CABA, ZONA SUR ó ZONA OESTE\n", "Debe ingresar una zona válida\n", zona,
			3, LONG_NOMBRE);

	if(resultado == -1)
		return resultado;

	*estado = A_COBRAR;
	*id = generarIdNuevo(pArrayListSale);
	resultado = 0;

	return resultado;
}

/**
 * \Cada vez que la llamo busca el ID más alto que encuentre en la lista y me devuelve el próximo ó -1 si hubo error.
 */

static int generarIdNuevo(LinkedList* pArrayListSale)
{
	int retorno = -1;
	int len;
	int max;
	Sale* bufferVenta;
	if(pArrayListSale != NULL)
	{
		len = ll_len(pArrayListSale);
		if(len == 0)
		{
			max = 1;
		}
		else
		{
			for(int i = 0; i< len; i++)
			{
				bufferVenta = ll_get(pArrayListSale, i);
				retorno = sale_getId(bufferVenta) + 1;
				if (i == 0 || retorno > max)
				{
					max = retorno;
				}

			}
		}
		retorno = max;
	}
	return retorno;
}
