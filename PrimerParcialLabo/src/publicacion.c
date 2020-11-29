

#include "publicacion.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define CANT_RUBROS 10

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
			//list[i].idPublicacion = -1;
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

	if(getInt("Ingrese el id del cliente para crear un nuevo aviso: ", "Debe ingresar un id válido\n", &opcion, 3, 4, 1) == 0)
	{
		if(findClienteById(pCliente, limiteCliente, opcion) != -1)
		{
			bufferPublicacion.idCliente = opcion;
			getInt("Ingrese el número de rubro: ", "Error\n", &bufferPublicacion.numeroRubro,3,CANT_RUBROS,1);
			utn_getChar("Ingrese el texto del aviso (hasta 64 caracteres): ", "\nError",bufferPublicacion.textoAviso, 3,AVISO_LEN);

			for(int i=0;i<limitePublicacion;i++)
			{
				if(pPublicacion[i].isEmpty == TRUE)
				{
					bufferPublicacion.idPublicacion = generarIdNuevo();
					bufferPublicacion.isEmpty = FALSE;
					bufferPublicacion.estado = ACTIVA;
					pPublicacion[i]= bufferPublicacion;
					break;
				}
			}
			publicacion_imprimirArray(pPublicacion, limitePublicacion);
		}
		else
		{
			printf("No se encontró ningún cliente con el id solicitado\n");
		}
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
				printf("idPublicacion: %d - N° Rubro: %d - Aviso: %s - idCliente: %d\n",array[i].idPublicacion, array[i].numeroRubro, array[i].textoAviso,
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
				printf("idPublicacion: %d - N° Rubro: %d - Aviso: %s - idCliente: %d\n",array[i].idPublicacion, array[i].numeroRubro, array[i].textoAviso,
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

/** \brief Sets a publicacion.estado to PAUSADA
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \param id int
* \param avisosPausados int* pointer to a counter
* \return int Return (-1) if Error [Invalid length or NULL pointer or ID < 1] - (0) if Ok
*/

int publicacion_pausar(Publicacion *array, int limite, int id, int *avisosPausados)
{
	int retorno = -1;
	int idPausa;
	if(array !=NULL && limite>0 && id > 0)
	{
		idPausa = publicacion_buscarId(array, limite, id);
		if(idPausa != -1)
		{
			array[idPausa].estado = PAUSADA;
			*avisosPausados += 1;
			printf("La publicación fue pausada\n");
		}
		else
		{
			printf("No se encontró niguna publicación con el id solicitado\n");
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Sets a publicacion.estado to ACTIVA
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \param id int
* \param avisosPausados int* pointer to a counter
* \return int Return (-1) if Error [Invalid length or NULL pointer or ID < 1] - (0) if Ok
*/

int publicacion_reanudar(Publicacion *array, int limite, int id, int *avisosPausados)
{
	int retorno = -1;
	int idPausa;
	if(array !=NULL && limite>0)
	{
		idPausa = publicacion_buscarId(array, limite, id);
		if(idPausa != -1)
		{
			array[idPausa].estado = ACTIVA;
			*avisosPausados -= 1;
			printf("Se reanudó la publicación\n");
		}
		else
		{
			printf("No se encontró niguna publicación con el id solicitado\n");
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Delete all publicaciones related to a cliente
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \param idCliente int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int publicacion_borrar(Publicacion *array, int limite, int idCliente)
{
	int retorno = -1;
	if(array !=NULL && limite>0 && idCliente >0)
	{
		for(int i;i<limite;i++)
		{
			if(array[i].idCliente == idCliente)
			{
				array[i].isEmpty = TRUE;
			}
		}
		retorno=0;
	}
	return retorno;
}


int publicacion_buscarId(Publicacion *array, int limite,int valorBuscado)
{
	int retorno=-1;
	int i;

	if(array != NULL && limite >0 && valorBuscado > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == FALSE && array[i].idPublicacion == valorBuscado )
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int borrarPublicacionesYCliente(Publicacion *arrayPublicaciones, int limitePublicaciones, Cliente *arrayClientes[],
		int limiteClientes)
{
	int retorno = -1;
	int auxiliarId;
	int respuesta;
	// Dar de baja primero las publicaciones y luego el cliente
	if(getInt("indique id de cliente a eliminar", "id invalido", &auxiliarId, 2, MAX_ID, 0)==0)
	{
		if(findClienteById(arrayClientes, LEN_CLIENTES, auxiliarId) != -1)
		{
			publicacion_imprimirPorCliente(arrayPublicaciones, LEN_PUBLICACIONES, auxiliarId);
			if(getInt("¿Está seguro que desea eliminar este cliente junto con sus publicaciones?\n1 - Si\n2 - No\n",
					 "Opción inválida", &respuesta, 3, 2, 1)==0)
			{
				if(respuesta == 1)
				{
					removeCliente(arrayClientes, limiteClientes, auxiliarId);
					publicacion_borrar(arrayPublicaciones, limitePublicaciones, auxiliarId);
				}
			}
		}
		else
		{
			printf("No se encontró un cliente con el id solicitado\n");
		}
	}
	return retorno;
}

/** \brief Get the number of publicaciones by cliente
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \param idCliente int
* \return int Return (-1) if Error [Invalid length or NULL pointer or idCliente < 1] or the number of publicaciones
*/

//Control + click sobre la funcion para ir a la definición
int publicacionesPorCliente(Publicacion *array, int limite,int idCliente)
{
	int retorno=-1;

	if(array != NULL && limite >0 && idCliente > 0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == idCliente && array[i].isEmpty == FALSE)
			{
				retorno += 1;
			}
		}
	}
	return retorno;
}

/** \brief Get the id of cliente with more publicaciones
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] or the id of cliente
*/
int getIdClienteConMasAvisos(Publicacion* list, int len)
{
	int retorno = -1;
	int maximo;
	int auxiliar;
	int primerCliente = TRUE;
	if(list != NULL && len > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				if(primerCliente == TRUE)
				{
					maximo = publicacionesPorCliente(list, len, list[i].idCliente);
					primerCliente = FALSE;
					retorno = list[i].idCliente;
				}
				else
				{
					auxiliar = publicacionesPorCliente(list, len, list[i].idCliente);
					if(auxiliar > maximo)
					{
						maximo = auxiliar;
						retorno = list[i].idCliente;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Get the number of publicaciones ACTIVAS by cliente
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \param idCliente int
* \return int Return (-1) if Error [Invalid length or NULL pointer or idCliente < 1] or the number of publicaciones
*/
int publicacionesActivasPorCliente(Publicacion *array, int limite,int idCliente)
{
	int retorno=-1;

	if(array != NULL && limite >0 && idCliente > 0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == idCliente && array[i].estado == ACTIVA && array[i].isEmpty == FALSE)
			{
				retorno += 1;
			}
		}
	}
	return retorno;
}

/** \brief Get the id of cliente with more publicaciones ACTIVAS
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] or the id of cliente
*/
int getIdClienteConMasAvisosActivos(Publicacion* list, int len)
{
	int retorno = -1;
	int maximo;
	int auxiliar;
	int primerCliente = TRUE;
	if(list != NULL && len > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].estado == ACTIVA)
			{
				if(primerCliente == TRUE)
				{
					maximo = publicacionesActivasPorCliente(list, len, list[i].idCliente);
					primerCliente = FALSE;
					retorno = list[i].idCliente;
				}
				else
				{
					auxiliar = publicacionesActivasPorCliente(list, len, list[i].idCliente);
					if(auxiliar > maximo)
					{
						maximo = auxiliar;
						retorno = list[i].idCliente;
					}

				}
			}
		}
	}
	return retorno;
}

/** \brief Get the number of publicaciones Pausadas by cliente
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \param idCliente int
* \return int Return (-1) if Error [Invalid length or NULL pointer or idCliente < 1] or the number of publicaciones
*
*/
int publicacionesPausadasPorCliente(Publicacion *array, int limite,int idCliente)
{
	int retorno=-1;

	if(array != NULL && limite >0 && idCliente > 0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			if(array[i].idCliente == idCliente && array[i].estado == PAUSADA && array[i].isEmpty == FALSE)
			{
				retorno += 1;
			}
		}
	}
	return retorno;
}

/** \brief Get the id of cliente with more publicaciones PAUSADAS
* \param list Publicacion* Pointer to array of publicaciones
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] or the id of cliente
*/
int getIdClienteConMasAvisosPausados(Publicacion* list, int len)
{
	int retorno = -1;
	int maximo;
	int auxiliar;
	int primerCliente = TRUE;
	if(list != NULL && len > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].estado == PAUSADA)
			{
				if(primerCliente == TRUE)
				{
					maximo = publicacionesPausadasPorCliente(list, len, list[i].idCliente);
					primerCliente = FALSE;
					retorno = list[i].idCliente;
				}
				else
				{
					auxiliar = publicacionesPausadasPorCliente(list, len, list[i].idCliente);
					if(auxiliar > maximo)
					{
						maximo = auxiliar;
						retorno = list[i].idCliente;
					}

				}
			}
		}
	}
	return retorno;
}

int getRubroConMasAvisos(Publicacion* list, int len)
{
	int retorno = -1;
	int rubros[CANT_RUBROS] = {0};
	int auxiliarRubro;
	if(list != NULL && len > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				auxiliarRubro = list[i].numeroRubro - 1;
				rubros[auxiliarRubro] += 1;
			}
		}
		retorno = GetMayorValorArray(rubros, CANT_RUBROS) + 1;
	}
	return retorno;
}
