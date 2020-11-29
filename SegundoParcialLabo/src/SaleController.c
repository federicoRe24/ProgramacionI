#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Sale.h"
#include "Client.h"
#include "parser.h"

/** \brief Carga los datos de las ventas desde el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_loadSalesFromText(char* path , LinkedList* pArrayListSale)
{
	int retorno = -1;
	if(path != NULL && pArrayListSale != NULL)
	{
		FILE *pFile = fopen(path,"r");
		retorno = parser_SaleFromText(pFile,pArrayListSale);
		fclose(pFile);
	}
		return retorno;
}


/** \brief Crear sublista con ventas por cliente
 *
 * \param pArrayListSale LinkedList*
 * \param clientId int
 * \return NULL or LinkedList*
 *
 */
LinkedList* controller_FilterListSaleByClient(LinkedList* pArrayListSale, int clientId)
{
	LinkedList* listaVentasPorCliente = NULL;
	if(pArrayListSale != NULL)
	{
		listaVentasPorCliente = ll_newLinkedList();
		Sale* pSale;
		int len = ll_len(pArrayListSale);
		for(int i = 0; i < len; i++)
		{
			pSale = ll_get(pArrayListSale, i);
			if(pSale != NULL && pSale->clientId == clientId)
			{
				ll_add(listaVentasPorCliente, pSale);
			}
		}
	}
    return listaVentasPorCliente ;
}


/** \brief Guarda los datos de las ventas en el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int controller_saveSalesAsText(char* path , LinkedList* pArrayListSale)
{
	int retorno = -1;
	if(path != NULL && pArrayListSale != NULL)
	{
		FILE *pFile;
		int len = ll_len(pArrayListSale);
		Sale *pSale;
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			retorno = 0;
			fprintf(pFile, "id,cantidadAfiches,nombreImagen,zona,estado,clientId\n");
			for(int i=0;i<len;i++)
			{
				pSale = ll_get(pArrayListSale,i);
				fprintf(pFile,"%d,%d,%s,%s,%d,%d\n",pSale->id,pSale->cantidadAfiches,pSale->nombreImagen,pSale->zona,pSale->estado,pSale->clientId);
			}
		}
		fclose(pFile);
	}
    return retorno;
}

/** \brief Función parámetro para filtrar lista de ventas, devuelve TRUE si la venta está en estado cobrado
 *
 * \param pElement void*
 * \return int
 *
 */

int IsVentaCobrada(void* pElement)
{
	int retorno = 0;
	if(((Sale*)pElement)->estado == COBRADA)
		retorno = 1;
	return retorno;
}


/** \brief Función parámetro para filtrar lista de ventas, devuelve TRUE si la venta está en estado a cobrar
 *
 * \param pElement void*
 * \return int
 *
 */

int IsVentaACobrar(void* pElement)
{
	int retorno = 0;
	if(((Sale*)pElement)->estado == A_COBRAR)
		retorno = 1;
	return retorno;
}

/** \brief Crear sublista de ventas utilizando la funcion criterio recibida como parametro
 *
 * \param pArrayListSale LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return NULL or LinkedList*
 *
 */

LinkedList* controller_filterListByEstate(LinkedList* pArrayListSale, int (*pFunc)(void*))
{
	LinkedList* listaFiltrada = NULL;
	if(pArrayListSale != NULL && pFunc != NULL)
	{
		listaFiltrada = ll_clone(pArrayListSale);
		if(ll_filter(listaFiltrada, pFunc) != 0)
		{
			listaFiltrada = NULL;
		}
	}
	return listaFiltrada;
}
