
#include <stdio.h>
#include "ArrayClientes.h"
#include "publicacion.h"
#include "informes.h"
#include "utn.h"

int main(void)
{
	int opcion;
	int respuesta;
	int auxiliarId;
	int avisosPausados = 0;

	Cliente* arrayClientes[LEN_CLIENTES];
	initClientes(arrayClientes, LEN_CLIENTES);


	Publicacion arrayPublicaciones[LEN_PUBLICACIONES];
	initPublicaciones(arrayPublicaciones, LEN_PUBLICACIONES);

	do
	{
		respuesta = getInt("Seleccione una opción\n\n1-Dar de alta un cliente\n2-Modificar datos de un cliente\n3-Dar de baja un cliente\n"
				"4-Publicar un aviso\n5-Pausar publicación\n6-Reanudar publicación\n7-Imprimir publicaciones\n8-Informar\n9-Salir\n",
				"No es una opción válida\n",&opcion,3,9,1);
		if(!respuesta)
		{
			switch(opcion)
			{
				case 1:
					if(altaForzadaClientes(arrayClientes) != 0)
					//if(CargarCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("El cliente no fue cargado ya que no se ingresaron valores válidos\n");
					}
					break;
				case 2:
					if(primerCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						ModificarCliente(arrayClientes, LEN_CLIENTES);
					}
					break;
				case 3:
					if(primerCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						borrarPublicacionesYCliente(arrayPublicaciones,LEN_PUBLICACIONES, arrayClientes, LEN_CLIENTES);
					}
					break;
				case 4:
					if(primerCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						printClientes(arrayClientes, LEN_CLIENTES);
						publicacion_alta(arrayClientes, LEN_CLIENTES, arrayPublicaciones, LEN_PUBLICACIONES);
					}
					break;
				case 5:
					if(primerCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						if(getInt("Indique id de la publicación a pausar: ", "id invalido\n", &auxiliarId, 3, MAX_ID, 1)==0)
						{
							publicacion_pausar(arrayPublicaciones, LEN_PUBLICACIONES, auxiliarId, &avisosPausados);
						}
						else
						{
							printf("No se ingresó un id válido\n");
						}
					}
					break;
				case 6:
					if(primerCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						if(getInt("Indique id de la publicación a reanudar: ", "id invalido\n", &auxiliarId, 2, MAX_ID, 0)==0)
						{
							publicacion_reanudar(arrayPublicaciones, LEN_PUBLICACIONES, auxiliarId, &avisosPausados);
						}
						else
						{
							printf("No se ingresó un id válido\n");
						}
					}
					break;
				case 7:
					if(primerCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						publicacion_imprimirArray(arrayPublicaciones, LEN_PUBLICACIONES);
					}
					break;
				case 8:
					if(primerCliente(arrayClientes, LEN_CLIENTES) != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						informes(arrayClientes, arrayPublicaciones, avisosPausados);
					}
			}
		}
	}while(opcion!=9);

	return 0;
}

