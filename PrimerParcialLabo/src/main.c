
#include <stdio.h>

#include "ArrayClientes.h"
#include "publicacion.h"
#include "utn.h"
#define ELEMENTOS_ARRAY 10
#define MAX_ID 1000


int main(void)
{
	int opcion;
	int respuesta;
	int primeraCarga = 1;
	int auxiliarId;
	Cliente arrayClientes[ELEMENTOS_ARRAY];
	initClientes(arrayClientes, ELEMENTOS_ARRAY);
	Publicacion arrayPublicaciones[ELEMENTOS_ARRAY];
	initPublicaciones(arrayPublicaciones, ELEMENTOS_ARRAY);

	do
	{
		respuesta = getInt("Seleccione una opción\n\n1-Dar de alta un cliente\n2-Modificar datos de un cliente\n3-Dar de baja un cliente\n"
				"4-Publicar un aviso\n5-Pausar publicación\n6-Reanudar publicación\n7-Imprimir clientes\n8-Informar\n9-Salir\n",
				"No es una opción válida\n",&opcion,3,9,1);
		if(!respuesta)
		{
			switch(opcion)
			{
				case 1:
					if(CargarCliente(arrayClientes, ELEMENTOS_ARRAY) != 0)
					{
						printf("El cliente no fue cargado ya que no se ingresaron valores válidos\n");
					}
					else
					{
						primeraCarga = 0;
					}
					break;
				case 2:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						ModificarCliente(arrayClientes, ELEMENTOS_ARRAY);
					}
					break;
				case 3:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						// Dar de baja primero las publicaciones y luego el cliente
						if(getInt("indique id de cliente a eliminar", "id invalido", &auxiliarId, 2, MAX_ID, 0)==0)
						{
							if(findClienteById(arrayClientes, ELEMENTOS_ARRAY, auxiliarId) != -1)
							{
								publicacion_imprimirPorCliente(arrayPublicaciones, ELEMENTOS_ARRAY, auxiliarId);
							}
							else
							{
								printf("No se encontró un cliente con el id solicitado\n");
							}
						}

						if(BorrarCliente(arrayClientes, ELEMENTOS_ARRAY) == 0)
						{
							primeraCarga = 1;
						}
					}
					break;
				case 4:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						publicacion_alta(arrayClientes, ELEMENTOS_ARRAY, arrayPublicaciones, ELEMENTOS_ARRAY);
					}
					break;
				case 5:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						if(getInt("Indique id de la publicación a pausar", "id invalido", &auxiliarId, 2, MAX_ID, 0)==0)
						{
							publicacion_pausar(arrayPublicaciones, ELEMENTOS_ARRAY, auxiliarId);
						}
						else
						{
							printf("No se ingresó un id válido\n");
						}

					}
					break;
				case 6:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						if(getInt("Indique id de la publicación a reanudar", "id invalido", &auxiliarId, 2, MAX_ID, 0)==0)
						{
							publicacion_reanudar(arrayPublicaciones, ELEMENTOS_ARRAY, auxiliarId);
						}
						else
						{
							printf("No se ingresó un id válido\n");
						}
					}
					break;
				case 7:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						publicacion_imprimirArray(arrayPublicaciones, ELEMENTOS_ARRAY);
					}
					break;
				case 8:
					break;
			}
		}
	}while(opcion!=9);

	return 0;
}

