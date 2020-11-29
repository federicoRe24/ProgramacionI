
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayClientes.h"
#include "utn.h"

/* Para la estructura de cada entidad
 *
 * new
 * delete
 * getXXXX
 * setXXXX
 *
 * initArray
 * findById
 * generarId
 *
 * alta
 * baja
 * modif
 * imprimir
 */

static int generarIdNuevo(void);

Cliente* cliente_newConParametros(int id, char* name, char* lastName, char* cuit)
{
	Cliente* pc = NULL;
	if(id>0 && name!=NULL && lastName!=NULL && cuit!=NULL)
	{
		pc = (Cliente*)malloc(sizeof(Cliente));
		if(pc!=NULL)
		{
			pc->id= id;
			pc->isEmpty=0;
			strncpy(pc->name,name,sizeof(pc->name));
			strncpy(pc->lastName,lastName,sizeof(pc->lastName));
			strncpy(pc->cuit,cuit,sizeof(pc->cuit));
		}
	}
	return pc;
}

void cliente_delete(Cliente* pc)
{
	if(pc!=NULL)
		free(pc);
}

// Encapsular los campos en funciones -> getters y setters
int cliente_getId(Cliente* pc, int* pVal)
{
	int ret=-1;
	if(pc!=NULL)
	{
		*pVal = pc->id;
		ret = 0;
	}
	return ret;
}

int cliente_setId(Cliente* pc, int val)
{
	int ret=-1;
	if(pc!=NULL && val>0)
	{
		 pc->id = val;
		ret = 0;
	}
	return ret;
}


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initClientes(Cliente* list[], int len) // Cliente* también se puede pasar como Cliente** list
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i] = NULL;
			//*(list+i) = NULL;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/

/*Busca el primero vacio y le carga los valores que se le pasen*/
int addCliente(Cliente* list, int len, int id, char name[],char lastName[],char cuit[])
{
	int retorno = -1;
	if(	list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				list[i].id = id;
				strncpy(list[i].name,name,LONG_NOMBRE);
				strncpy(list[i].lastName,lastName,LONG_NOMBRE);
				strncpy(list[i].cuit,cuit,LONG_CUIT);
				list[i].isEmpty = FALSE;
				return 0;
			}
		}
	}
	return retorno;
}

/** \brief find a Cliente by Id en returns the index position in array.
*
* \param list Cliente*
* \param len int
* \param id int
* \return Return cliente index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findClienteById(Cliente* list[], int len,int id)
{
	int retorno = -1;
	if(list != NULL && len > 0 && id > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i]!=NULL) // Podria poner tambien if((*(list+i))->id == id)
			{
				if(list[i]->id == id)
				{
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

/** \brief Remove a Cliente by Id (put isEmpty Flag in 1)
*
* \param list Cliente*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a cliente] - (0) if Ok
*
*/
int removeCliente(Cliente* list[], int len, int id)
{
	int retorno = -1;
	int indiceABorrar;
	if(list != NULL && len > 0 && id > 0)
	{
		indiceABorrar = findClienteById(list, len, id);
		if(indiceABorrar != -1)
		{
			// borro cliente posicion "IndiceABorrar"

			// 1) free en direccion de memoria de cliente
			cliente_delete(list[indiceABorrar]);

			// 2) NULL en array
			list[indiceABorrar] = NULL;

			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
/*int sortEmployees(Employee* list, int len, int order)
{
	int flagSwap;
	int i;
	int contador=0;
	int retorno = -1;
	Employee buffer;

	if(list != NULL && len >= 0)
	{
		do
		{
			flagSwap=0;
			for(i=0;i<len-1;i++)
			{
				contador++;
				if(strncmp(list[i].lastName,list[i+1].lastName,LONG_NOMBRE)>0)
				{
					flagSwap = 1;
					buffer = list[i];
					list[i] = list[i+1];
					list[i+1] = buffer;
				}
			}
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}*/


/** \brief print the content of clientes array
*
* \param list Cliente*
* \param length int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printClientes(Cliente* list[], int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			printf("Id: %d - Nombre: %s - Apellido: %s - Cuit: %s\n",list[i]->id,list[i]->name, list[i]->lastName,list[i]->cuit);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief print one client required by ID
*
* \param list Cliente*
* \param len int
* \oara id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or id < 1] - (0) if Ok
*
*/

int printCliente(Cliente* list[], int len, int id)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0 && id > 0)
	{
		i = findClienteById(list, len, id);
		if(i != -1)
		{
			printf("Id: %d - Nombre: %s - Apellido: %s - Cuit: %s\n",list[i]->id,list[i]->name, list[i]->lastName,list[i]->cuit);
		}
		else
		{
			printf("No se encontró el cliente con el Id solicitado\n");
		}
		retorno = 0;
	}
	return retorno;
}

int CargarCliente(Cliente* list, int len)
{
	int resultado;
	Cliente bufferCliente;

	resultado =  getNombre("Ingrese el nombre del cliente\n", "Debe ingresar un nombre válido\n", bufferCliente.name,
			3, LONG_NOMBRE);

	if(resultado == -1)
		return 1;

	resultado =  getNombre("Ingrese el apellido del cliente\n", "Debe ingresar un apellido válido\n", bufferCliente.lastName,
			3, LONG_NOMBRE);

	if(resultado == -1)
		return 1;

	resultado = getCuit("Ingrese el cuit del cliente, sin puntos ni guiones\n", "Debe ingresar un cuit válido\n", bufferCliente.cuit, 3, LONG_CUIT);

	if(resultado == -1)
		return 1;

	bufferCliente.id = generarIdNuevo();

	if(addCliente(list, len, bufferCliente.id, bufferCliente.name, bufferCliente.lastName, bufferCliente.cuit) == 0)
	{
		printf("El cliente fue cargado correctamente\n");
	}
	else
	{
		printf("No se pudo cargar el cliente\n");
	}

	return 0;
}

int ModificarCliente(Cliente* list, int len)
{
	int retorno = -1;
	int opcion;
	int respuesta;
	int id;
	int posicion;
	int resultado;
	Cliente bufferCliente;

	if(getInt("Ingrese el id del cliente a modificar","Ingrese un id válido\n",&id,3,MAX_ID,1) == 0)
	{
		posicion = findClienteById(list,len,id);
		if(posicion != -1)
		{
			respuesta = getInt("Seleccione un valor a modificar\n\n1-Modificar nombre\n2-Modificar apellido\n3-Modificar cuit\n",
					"No es una opción válida\n",&opcion,3,3,1);
			if(!respuesta)
			{
				switch(opcion)
				{
					case 1:
						resultado =  getNombre("Ingrese el nombre del cliente\n", "Debe ingresar un nombre válido\n", bufferCliente.name,
								3, LONG_NOMBRE);
						if(resultado == -1)
							return 1;
						strncpy(list[posicion].name,bufferCliente.name,LONG_NOMBRE);
						break;
					case 2:
						resultado =  getNombre("Ingrese el apellido del cliente\n", "Debe ingresar un apellido válido\n", bufferCliente.lastName,
								3, LONG_NOMBRE);
						if(resultado == -1)
							return 1;
						strncpy(list[posicion].lastName,bufferCliente.lastName,LONG_NOMBRE);
						break;
					case 3:
						resultado = getCuit("Ingrese el cuit del cliente, sin puntos ni guiones\n", "Debe ingresar un cuit válido\n",
								bufferCliente.cuit, 3, LONG_CUIT);
						if(resultado == -1)
							return 1;
						strncpy(list[posicion].cuit,bufferCliente.cuit,LONG_CUIT);
						break;
				}
				retorno = 0;
			}
		}
		else
		{
			printf("No se encontró ningún cliente con el id solicitado");
		}
	}
	else
	{
		printf("No se ingresó un id válido\n");
	}
	return retorno;
}

int BorrarCliente(Cliente* list, int len)
{
	int retorno = -1;
	int resultado;
	int id;

	resultado = getInt("Ingrese el id del cliente a borrar\n", "Debe ingresar un id válido [0 - 1000]\n",
										   &id, 3, len-1, 1);
	if(resultado == 0)
	{
		resultado = removeCliente(list, len, id);
		if(resultado == 0)
		{
			printf("Cliente eliminado\n");
			retorno = 0;
		}
		else
		{
			printf("No se encontró un cliente con el id ingresado\n");
		}
	}
	else
	{
		printf("No se ingresó un id válido\n");
	}
	return retorno;
}


// Cada vez que la llamo me devuelve un ID nuevo que nunca me devolvio antes
static int generarIdNuevo(void)
{
	static int id=0; //es global pero solo la funcion puede usarla

    //guardar el ultimo que asigne (ultimo que devolvi)
    //para devolver 1+
	id++;
	return id;
}


int altaForzadaClientes(Cliente* list[])
{
	int retorno = -1;
	Cliente *pc;
	if(	list != NULL)
	{
		// 1) construyo el cliente
		pc = cliente_newConParametros(generarIdNuevo(), "Federico", "Re", "20362214166");

		// 2) agrego el cliente al array
		list[0] = pc;

		pc = cliente_newConParametros(generarIdNuevo(), "Juan", "Perez", "18362214165");
		list[1] = pc;

		pc = cliente_newConParametros(generarIdNuevo(), "Nicolas", "Gimenez", "25362214160");
		list[2] = pc;

		retorno = 0;
	}
	return retorno;
}

/** \brief indicates if there's at least one Cliente loaded on the array
* \param list Cliente*
* \param len int
* \oara id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or id < 1] - (0) if Ok
*
*/

int primerCliente(Cliente* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
