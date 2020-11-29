#include <stdio.h>
#include <stdlib.h>
#include "Sale.h"
#include "Client.h"
#include "LinkedList.h"
#include "SaleController.h"
#include "Controller.h"

/** \brief Función parámetro para filtrar lista de ventas, devuelve TRUE si el clientId coincide con el recibido por parámetro
 *
 * \param pElement void*
 * \param id int
 * \return int
 *
 */

int IsClientId(void* pElement, int id)
{
	int retorno = 0;
	if(((Sale*)pElement)->clientId == id)
		retorno = 1;
	return retorno;
}

/** \brief Función parámetro para filtrar lista de ventas, devuelve la cantidad de afiches comprados por el cliente
 *
 * \param pElement void*
 * \param id int
 * \return int
 *
 */
int GetVentasPorClientId(void* pElement, int id)
{
	int retorno = 0;
	if(((Sale*)pElement)->clientId == id)
		retorno = ((Sale*)pElement)->cantidadAfiches;
	return retorno;
}

/** \brief Guarda los datos de cada cliente junto a la cantidad de ventas cobradas en el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */

int controller_saveSaleReportAsText(char* path , LinkedList* pArrayListClient, LinkedList* pArrayListSale)
{
	int retorno = -1;
	if(path != NULL && pArrayListClient != NULL)
	{
		FILE *pFile;
		int lenClient = ll_len(pArrayListClient);
		int ventasPorCliente = 0;
		Client *pClient;
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			retorno = 0;
			fprintf(pFile,"id,nombre,apellido,cuit,ventas\n");
			for(int i=0;i<lenClient;i++)
			{
				pClient = ll_get(pArrayListClient,i);
				ventasPorCliente = ll_reduceIntById(pArrayListSale, IsClientId, pClient->id);
				fprintf(pFile,"%d,%s,%s,%s,%d\n",pClient->id,pClient->nombre,pClient->apellido,pClient->cuit, ventasPorCliente);
				ventasPorCliente = 0;
			}
		}
		fclose(pFile);
	}
    return retorno;
}

/** \brief Informa el cliente al que se le vendió mas afiches y al que se le vendió menos
 *
 * \param pArrayListClient LinkedList*
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int controller_PrintClienstWithMoreAndLessSales(LinkedList* pArrayListClient, LinkedList* pArrayListSale)
{
	int retorno = -1;
	if(pArrayListClient != NULL)
	{
		int max;
		int min;
		int lenClient = ll_len(pArrayListClient);
		int ventasPorCliente = 0;
		Client *pClient;
		Client *pClientMax;
		Client* pClientMin;
		retorno = 0;
		for(int i=0;i<lenClient;i++)
		{
			pClient = ll_get(pArrayListClient,i);
			ventasPorCliente = ll_reduceIntById(pArrayListSale, GetVentasPorClientId, pClient->id);
			if(i == 0 || ventasPorCliente > max)
			{
				max = ventasPorCliente;
				pClientMax = pClient;
			}
			if(i == 0 || ventasPorCliente < min)
			{
				min = ventasPorCliente;
				pClientMin = pClient;
			}
			ventasPorCliente = 0;
		}
		printf("El cliente con más afiches vendidos fue %s %s, id: %d, cuit: %s con: %d\n",pClientMax->nombre,pClientMax->apellido,pClientMax->id,
				pClientMax->cuit,max);
		printf("El cliente con menos afiches vendidos fue %s %s, id: %d, cuit: %s con: %d\n",pClientMin->nombre,pClientMin->apellido,pClientMin->id,
				pClientMin->cuit,min);
		retorno = 0;
	}
    return retorno;
}

/** \brief Informa el cliente al que se le vendió mas afiches y al que se le vendió menos
 *
 * \param pArrayListClient LinkedList*
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int controller_PrintSaleWithMorePosters(LinkedList* pArrayListClient, LinkedList* pArrayListSale)
{
	int retorno = -1;
	if(pArrayListClient != NULL)
	{
		int max;
		int lenSale = ll_len(pArrayListSale);
		Sale* pSale;
		Sale* pSaleMax;
		Client* pClient;
		retorno = 0;
		for(int i=0;i<lenSale;i++)
		{
			pSale = ll_get(pArrayListSale,i);
			if(i == 0 || pSale->cantidadAfiches > max)
			{
				max = pSale->cantidadAfiches;
				pSaleMax = pSale;
			}
		}
		pClient = ll_get(pArrayListClient, controller_findClientById(pArrayListClient, pSaleMax->clientId));
		if(pClient != NULL)
		{
			printf("La venta con más afiches vendidos fue id: %d, cuit del cliente: %s con %d afiches\n",pSaleMax->id, pClient->cuit,max);
			retorno = 0;
		}

	}
    return retorno;
}
