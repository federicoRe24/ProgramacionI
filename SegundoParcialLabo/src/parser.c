#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "LinkedList.h"
#include "Sale.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int parser_ClientFromText(FILE* pFile , LinkedList* pArrayListClient)
{
	int retorno = -1;
	Client* pBuffer;
	int retornoLectura;
	char idStr[LONG_NOMBRE];
	char nombre[LONG_NOMBRE];
	char apellido[LONG_NOMBRE];
	char cuitStr[LONG_NOMBRE];

	if(pFile != NULL && pArrayListClient != NULL)
	{
		retorno = 0;
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombre,apellido,cuitStr); // Para saltear el header
		do
		{
			// fscanf() devuelve la cantidad de variables que pudo escribir
			retornoLectura = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombre,apellido,cuitStr);
			if(retornoLectura == 4)
			{
				//ATOI de texto a INT
				pBuffer = client_newParametrosStr(idStr, nombre, apellido, cuitStr);
				//printf("%s\n", pBuffer->nombre);
				ll_add(pArrayListClient,pBuffer);
			}
			else
			{
				client_delete(pBuffer);
			}
		}while(!feof(pFile));
	}

    return retorno;
}


/** \brief Parsea los datos los datos de las ventas desde el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int parser_SaleFromText(FILE* pFile , LinkedList* pArrayListSale)
{
	int retorno = -1;
	Sale* pBuffer;
	int retornoLectura;
	char idStr[LONG_NOMBRE];
	char cantidadAfichesStr[LONG_NOMBRE];
    char nombreImagen[LONG_NOMBRE];
    char zona[LONG_NOMBRE];
    char estadoStr[LONG_NOMBRE];
    char clientIdStr[LONG_NOMBRE];

	if(pFile != NULL && pArrayListSale != NULL)
	{
		retorno = 0;
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,cantidadAfichesStr,nombreImagen,zona,estadoStr,clientIdStr);
		do
		{
			retornoLectura = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,cantidadAfichesStr,nombreImagen,zona,estadoStr,clientIdStr);
			if(retornoLectura == 6)
			{
				//ATOI de texto a INT
				pBuffer = sale_newParametrosStr(idStr,cantidadAfichesStr,nombreImagen,zona,estadoStr,clientIdStr);
				ll_add(pArrayListSale,pBuffer);
			}
			else
			{
				sale_delete(pBuffer);
			}
		}while(!feof(pFile));
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los clientes desde el archivo clientes.txt (modo binario).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int parser_ClientFromBinary(FILE* pFile , LinkedList* pArrayListClient)
{
	int retorno = -1;
	Client* pBuffer;
	int retornoLectura;
	if(pFile != NULL && pArrayListClient != NULL)
	{
		do
		{
			pBuffer = client_new();
			retornoLectura = fread(pBuffer,sizeof(Client),1,pFile);
			if(retornoLectura == 1)
			{
				ll_add(pArrayListClient,pBuffer);
			}
			else
			{
				client_delete(pBuffer);
				break;
			}
		}while(!feof(pFile));
		retorno = 0;
	}

    return retorno;
}
