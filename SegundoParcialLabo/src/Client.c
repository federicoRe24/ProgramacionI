
#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int generarIdNuevo(LinkedList* pArrayListClient);
static int IsCuitRepetido(LinkedList* pArrayListClient, char* cuit);

Client* client_new()
{
	return (Client*)malloc(sizeof(Client));
}

Client* client_newParametrosStr(char* idStr,char* nombre,char* apellido, char* cuit)
{
	Client* this = client_new();
	if(this != NULL)
	{
		//ATOI de texto a INT
		if(client_setId(this,atoi(idStr)) != -1 && client_setNombre(this,nombre) != -1
				&& client_setApellido(this,apellido) != -1 && client_setCuit(this,cuit) != -1)
		{
			return this;
		}
	}
	return NULL;
}

Client* client_newParametros(int id,char* nombre,char* apellido, char* cuit)
{
	Client* this = client_new();
	if(this != NULL)
	{
		if(client_setId(this,id) != -1 && client_setNombre(this,nombre) != -1
				&& client_setApellido(this,apellido) != -1 && client_setCuit(this,cuit) != -1)
		{
			return this;
		}
	}
	return NULL;
}

// this -> contexto (a quién estás apuntando)
void client_delete(Client* this)
{
	free(this);
}


int client_getId(Client* this)
{
	if(this!=NULL)
	{
		return this->id;
	}
	return -1;
}

int client_setId(Client* this,int id)
{
	int retorno = -1;
	if(this!=NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

char* client_getNombre(Client* this)
{
	if(this!=NULL)
	{
		return this->nombre;
	}
	return NULL;
}

int client_setNombre(Client* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && isValidName(nombre, LONG_NOMBRE) == 1)
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}


char* client_getApellido(Client* this)
{
	if(this!=NULL)
	{
		return this->apellido;
	}
	return NULL;
}

int client_setApellido(Client* this,char* apellido)
{
	int retorno = -1;
	if(this!=NULL && isValidName(apellido, LONG_NOMBRE) == 1)
	{
		strncpy(this->apellido,apellido,sizeof(this->apellido));
		retorno = 0;
	}
	return retorno;
}

char* client_getCuit(Client* this)
{
	if(this!=NULL)
	{
		return this->cuit;
	}
	return NULL;
}

int client_setCuit(Client* this,char* cuit)
{
	int retorno = -1;
	if(this!=NULL && esUnCuitValido(cuit, LONG_CUIT))
	{
		strncpy(this->cuit,cuit,sizeof(this->cuit));
		retorno = 0;
	}
	return retorno;
}

int isValidName(char* nombre, int limite)
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
}

int client_compararNombre(void* thisA,void* thisB)
{
	int retorno;
	if(thisA != NULL && thisB != NULL)
	{
		char bufferNombreA[256];
		char bufferNombreB[256];
		int respuesta;

		// Casteo el void a Client
		//client_getNombre((Client*)thisA,bufferNombreA);
		//client_getNombre((Client*)thisB,bufferNombreB);

		strncpy(bufferNombreA, client_getNombre((Client*)thisA), LONG_NOMBRE);
		strncpy(bufferNombreB, client_getNombre((Client*)thisB), LONG_NOMBRE);

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
}

int client_compararId(void* thisA,void* thisB)
{
	int retorno;
	if(thisA != NULL && thisB != NULL)
	{
		int bufferIdA;
		int bufferIdB;

		bufferIdA = client_getId((Client*)thisA);
		bufferIdB = client_getId((Client*)thisB);

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

int client_load(int* id,char* nombre,char* apellido, char* cuit, LinkedList* pArrayListClient)
{
	int resultado;

	resultado =  getNombre("Ingrese el nombre del cliente\n", "Debe ingresar un nombre válido\n", nombre,
			3, LONG_NOMBRE);

	if(resultado == -1)
		return resultado;

	resultado =  getNombre("Ingrese el apellido del empleado\n", "Debe ingresar un apellido válido\n", apellido,
			3, LONG_NOMBRE);

	if(resultado == -1)
		return resultado;

	resultado =  getCuit("Ingrese el cuit del empleado\n", "Debe ingresar un cuit válido\n", cuit,
			3, LONG_CUIT);

	if(resultado == -1)
		return resultado;

	resultado = IsCuitRepetido(pArrayListClient, cuit);

	if(resultado == -1)
		{
			printf("Error, ya existe un empleado con el cuit ingresado\n");
			return resultado;
		}

	*id = generarIdNuevo(pArrayListClient);
	resultado = 0;

	return resultado;
}

/**
 * \Cada vez que la llamo busca el ID más alto que encuentre en la lista y me devuelve el próximo ó -1 si hubo error.
 */

static int generarIdNuevo(LinkedList* pArrayListClient)
{
	int retorno = -1;
	int len;
	int max;
	Client* bufferCliente;
	if(pArrayListClient != NULL)
	{
		len = ll_len(pArrayListClient);
		for(int i = 0; i< len; i++)
		{
			bufferCliente = ll_get(pArrayListClient, i);
			retorno = client_getId(bufferCliente) + 1;
			if (i == 0 || retorno > max)
			{
				max = retorno;
			}

		}
		retorno = max;
	}
	return retorno;
}


static int IsCuitRepetido(LinkedList* pArrayListClient, char* cuit)
{
	int retorno = -1;
	if(pArrayListClient != NULL && cuit != NULL)
	{
		retorno = 0;
		int len = ll_len(pArrayListClient);
		Client* pClient;
		char* cuitActual;
		for(int i=0; i < len; i++)
		{
			pClient = ll_get(pArrayListClient, i);
			cuitActual = pClient->cuit;
			if(strncmp(cuitActual,cuit,LONG_CUIT) == 0)
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}


