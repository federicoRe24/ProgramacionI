#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "Sale.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los clientes desde el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_loadClientsFromText(char* path , LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(path != NULL && pArrayListClient != NULL)
	{
		FILE *pFile = fopen(path,"r");
		retorno = parser_ClientFromText(pFile,pArrayListClient);
		fclose(pFile);
	}
		return retorno;
}

/** \brief Carga los datos de los clientes desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(path != NULL && pArrayListClient != NULL)
	{
		FILE *pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			retorno = parser_ClientFromBinary(pFile,pArrayListClient);
			fclose(pFile);
		}
	}
	return retorno;
}

/** \brief Alta de clientes
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_addClient(LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(pArrayListClient!=NULL)
	{
	    int id;
	    char nombre[LONG_NOMBRE];
	    char apellido[LONG_NOMBRE];
	    char cuit[LONG_CUIT];
		if(client_load(&id, nombre, apellido, cuit, pArrayListClient) == 0)
		{
			Client* pBuffer;
			pBuffer = client_newParametros(id, nombre, apellido, cuit);
			if(pBuffer != NULL)
			{
				ll_add(pArrayListClient,pBuffer);
				printf("El cliente fue cargado correctamente\n");
			}
			else
			{
				printf("No se pudo cargar el cliente\n");
			}
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief find an Client by Id en returns the index position in array.
*
* \param pArrayListClient LinkedList*
* \param id int
* \return Return client index position or (-1) if NULL LinkedList* or !(Id >0) or client not found]
*
*/
int controller_findClientById(LinkedList* pArrayListClient, int id)
{
	int retorno = -1;
	if(pArrayListClient != NULL && id > 0)
	{
		int len = ll_len(pArrayListClient);
		Client* bufferClient;
		for(int i=0; i < len; i++)
		{
			bufferClient = ll_get(pArrayListClient, i);
			if(client_getId(bufferClient) == id)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de cliente
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_editClient(LinkedList* pArrayListClient)
{
	int retorno = -1;

	if(pArrayListClient != NULL)
	{
		int opcion;
		int id;
		int posicion;
		Client* bufferClient;
		char nombre[LONG_NOMBRE];
		char apellido[LONG_NOMBRE];
		char cuit[LONG_NOMBRE];

		if(getInt("Ingrese el id del cliente a modificar: ","Ingrese un id válido\n",&id,3,MAX_INT,1) == 0)
		{
			posicion = controller_findClientById(pArrayListClient, id);
			if(posicion != -1)
			{
				bufferClient = ll_get(pArrayListClient, posicion);
				retorno = getInt("Seleccione un valor a modificar\n\n1-Modificar nombre\n2-Modificar apellido\n3-Modificar cuit\n",
						"No es una opción válida\n",&opcion,3,3,1);
				if(retorno == 0)
				{
					switch(opcion)
					{
						case 1:
							retorno =  getNombre("Ingrese el nombre del cliente\n", "Debe ingresar un nombre válido\n", nombre,
									3, LONG_NOMBRE);
							retorno = client_setNombre(bufferClient, nombre);
							break;
						case 2:
							retorno =  getNombre("Ingrese el apellido del cliente\n", "Debe ingresar un apellido válido\n", apellido,
									3, LONG_NOMBRE);
							retorno = client_setApellido(bufferClient, apellido);
							break;
						case 3:
							retorno =  getNombre("Ingrese el cuit del cliente\n", "Debe ingresar un cuit válido\n", cuit,
									3, LONG_NOMBRE);
							retorno = client_setCuit(bufferClient, nombre);
							break;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Baja de cliente
 *
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_removeClient(LinkedList* pArrayListClient)
{
	int retorno = -1;
	int id;
	int posicion;
	if(pArrayListClient)
	{
		if(getInt("Ingrese el id del cliente a eliminar: ","Ingrese un id válido\n",&id,3,MAX_INT,1) == 0)
		{
			posicion = controller_findClientById(pArrayListClient, id);
			if(posicion != -1)
			{
				ll_remove(pArrayListClient, posicion);
				retorno = 0;
			}
		}
	}

    return retorno;
}

/** \brief Imprime un cliente
 *
 * \param pArrayListClient LinkedList*
 * \param id int
 * \return int
 *
 */
int controller_printClient(LinkedList* pArrayListClient, int index)
{
	int retorno = -1;
	if(pArrayListClient != NULL && index >= 0)
	{
		Client* bufferClient;
		bufferClient = (Client*)ll_get(pArrayListClient, index);
		printf("Id: %d - Nombre: %s - Apellido: %s - Cuit: %s\n",bufferClient->id, bufferClient->nombre,
				bufferClient->apellido, bufferClient->cuit);
		retorno = 0;
	}
    return retorno;
}

/** \brief Listar clientes
 *
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_ListClient(LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(pArrayListClient != NULL)
	{
		Client* bufferClient;
		printf("Clientes:\n");
		for(int i=0; i< ll_len(pArrayListClient); i++)
		{
			bufferClient = (Client*)ll_get(pArrayListClient, i);
			printf("Id: %d - Nombre: %s - Apellido: %s - Cuit: %s\n",bufferClient->id, bufferClient->nombre,
					bufferClient->apellido, bufferClient->cuit);
		}
		retorno = 0;
	}

    return retorno;
}

/** \brief Ordenar clientes
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_sortClient(LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(pArrayListClient != NULL)
	{
		if(pArrayListClient != NULL)
		{
			ll_sort(pArrayListClient,client_compararNombre,1);
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Ordenar clientes por ID
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_sortClientById(LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(pArrayListClient != NULL)
	{
		if(pArrayListClient != NULL)
		{
			ll_sort(pArrayListClient,client_compararId,1);
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los clientes en el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_saveClientsAsText(char* path , LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(path != NULL && pArrayListClient != NULL)
	{
		FILE *pFile;
		int len = ll_len(pArrayListClient);
		Client *pClient;
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			retorno = 0;
			fprintf(pFile, "id,nombre,apellido,cuit\n");
			for(int i=0;i<len;i++)
			{
				pClient = ll_get(pArrayListClient,i);
				fprintf(pFile,"%d,%s,%s,%s\n",pClient->id,pClient->nombre,pClient->apellido,pClient->cuit);
			}
		}
		fclose(pFile);
	}
    return retorno;
}

/** \brief Guarda los datos de los clientes en el archivo clientes.txt (modo binario).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListClient)
{
	int retorno = -1;
	if(path != NULL && pArrayListClient != NULL)
	{
		FILE *pFile;
		int len = ll_len(pArrayListClient);
		Client *pClient;
		pFile = fopen(path,"wb");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i=0;i<len;i++)
			{
				pClient = ll_get(pArrayListClient,i);
				fwrite(pClient,sizeof(Client),1,pFile);
			}
		}
		fclose(pFile);
	}
    return retorno;
}


int controller_sellPoster(LinkedList* pArrayListClient, LinkedList* pArrayListSale)
{
	int retorno = -1;
	if(pArrayListClient!=NULL && pArrayListClient!=NULL)
	{
		int id;
	    int clientId;
	    int cantidadAfiches;
	    char nombreImagen[LONG_NOMBRE];
	    char zona[LONG_NOMBRE];
	    int estado;
		if(getInt("Ingrese el id del cliente que realizará la compra\n","Ingrese un id válido\n",&clientId,3,MAX_INT,1) == 0
		   && controller_findClientById(pArrayListClient, clientId) != -1)
		{
			if(sale_load(&id, &cantidadAfiches, nombreImagen, zona, &estado, pArrayListSale) == 0)
			{
				Sale* pBuffer;
				pBuffer = sale_newParametros(id, cantidadAfiches, nombreImagen, zona, estado, clientId);
				if(pBuffer != NULL)
				{
					ll_add(pArrayListSale,pBuffer);
					printf("La venta fue cargada correctamente\n");
				}
				else
				{
					printf("No se pudo cargar la venta\n");
				}
			}
		}
		else
		{
			printf("No se encontró el cliente con el id solicitado\n");
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Imprime una venta
 *
 * \param pArrayListSale LinkedList*
 * \param id int
 * \return int
 *
 */
int controller_printSale(LinkedList* pArrayListSale, int index)
{
	int retorno = -1;
	if(pArrayListSale != NULL && index >= 0)
	{
		Sale* bufferSale;
		bufferSale = (Sale*)ll_get(pArrayListSale, index);
		char* estado = "A cobrar";
		if(bufferSale->estado == 1)
			estado = "Cobrada";
		printf("Id: %d - Cantidad de afiches: %d - Nombre Imagen: %s - Zona: %s - Estado: %s - clientId: %d\n", bufferSale->id,
				bufferSale->cantidadAfiches, bufferSale->nombreImagen, bufferSale->zona, estado, bufferSale->clientId);
		retorno = 0;
	}
    return retorno;
}

/** \brief Listar ventas
 *
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int controller_ListSale(LinkedList* pArrayListSale)
{
	int retorno = -1;
	if(pArrayListSale != NULL)
	{
		printf("Ventas:\n");
		for(int i=0; i< ll_len(pArrayListSale); i++)
		{
			controller_printSale(pArrayListSale, i);
		}
		retorno = 0;
	}

    return retorno;
}

/** \brief find a Sale by Id en returns the index position in array.
*
* \param pArrayListSale LinkedList*
* \param id int
* \return Return sale index position or (-1) if NULL LinkedList* or !(Id >0) or sale not found]
*
*/
int controller_findSaleById(LinkedList* pArrayListSale, int id)
{
	int retorno = -1;
	if(pArrayListSale != NULL && id > 0)
	{
		int len = ll_len(pArrayListSale);
		Sale* bufferSale;
		for(int i=0; i < len; i++)
		{
			bufferSale = ll_get(pArrayListSale, i);
			if(sale_getId(bufferSale) == id)
			{
				retorno = i;
			}
		}
	}
	return retorno;
}


/** \brief Modificar datos una venta en estado "a cobrar"
 *
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int controller_editSale(LinkedList* pArrayListSale)
{
	int retorno = -1;

	if(pArrayListSale!= NULL)
	{
		int opcion;
		int id;
		int posicion;
		Sale* bufferSale;
	    int cantidadAfiches;
	    char nombreImagen[LONG_NOMBRE];
	    char zona[LONG_NOMBRE];

		if(getInt("Ingrese el id de la venta a modificar: ","Ingrese un id válido\n",&id,3,MAX_INT,1) == 0)
		{
			posicion = controller_findSaleById(pArrayListSale, id);
			if(posicion != -1)
			{
				bufferSale = ll_get(pArrayListSale, posicion);
				retorno = getInt("Seleccione un valor a modificar\n\n1-Modificar cantidad de afiches\n2-Modificar el nombre de la imagen"
						"\n3-Modificar zona\n", "No es una opción válida\n",&opcion,3,3,1);
				if(retorno == 0)
				{
					switch(opcion)
					{
						case 1:
							retorno =  getInt("Ingrese la cantidad de afiches a vender\n", "Debe ingresar una cantidad válida\n", &cantidadAfiches,
									3, LONG_NOMBRE, 1);
							retorno = sale_setCantidadAfiches(bufferSale, cantidadAfiches);
							break;
						case 2:
							retorno =  getNombre("Ingrese el nuevo nombre de la imagen\n", "Debe ingresar un nombre válido\n", nombreImagen,
									3, LONG_NOMBRE);
							retorno = sale_setNombreImagen(bufferSale, nombreImagen);
							break;
						case 3:
							retorno =  getZona("Ingrese la nueva zona: CABA, ZONA SUR ó ZONA OESTE\n", "Debe ingresar una zona válida\n", zona,
									3, LONG_NOMBRE);
							retorno = sale_setZona(bufferSale, zona);
							break;
					}
				}
			}
		}
	}
	return retorno;
}


/** \brief Modifica una venta de estado "a cobrar" a "cobrada"
 *
 * \param pArrayListSale LinkedList*
 * \return int
 *
 */
int controller_chargeSale(LinkedList* pArrayListClient, LinkedList* pArrayListSale)
{
	int retorno = -1;

	if(pArrayListSale!= NULL)
	{
		int opcion;
		int id;
		int posicion;
		Sale* bufferSale;

		if(getInt("Ingrese el id de la venta a cobrar: ","Ingrese un id válido\n",&id,3,MAX_INT,1) == 0)
		{
			posicion = controller_findSaleById(pArrayListSale, id);
			if(posicion != -1)
			{
				bufferSale = ll_get(pArrayListSale, posicion);
				posicion = controller_findClientById(pArrayListClient, bufferSale->clientId);
				controller_printClient(pArrayListClient, posicion);

				retorno = getInt("¿Está seguro que desea cobrar la venta\n\n1-Aceptar\n2-Cancelar", "No es una opción válida\n",&opcion,3,3,1);
				if(retorno == 0)
				{
					if(opcion == 1)
					{
						sale_setEstado(bufferSale, COBRADA);
					}
				}
			}
			else
			{
				printf("No se encontró la venta con el id solicitado\n");
			}
		}
	}
	return retorno;
}
