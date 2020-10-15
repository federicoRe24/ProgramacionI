
#include <stdio.h>
#include "ArrayClientes.h"
#include "publicacion.h"
#include "informes.h"
#include "utn.h"

int main(void)
{
	int opcion;
	int respuesta;
	int primeraCarga = 1;
	int auxiliarId;
	int avisosPausados = 0;
	Cliente arrayClientes[ELEMENTOS_ARRAY];
	initClientes(arrayClientes, ELEMENTOS_ARRAY);
	Publicacion arrayPublicaciones[ELEMENTOS_ARRAY];
	initPublicaciones(arrayPublicaciones, ELEMENTOS_ARRAY);

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
					if(altaForzadaClientes(arrayClientes, ELEMENTOS_ARRAY) != 0)
					//if(CargarCliente(arrayClientes, ELEMENTOS_ARRAY) != 0)
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
						//Borra pero si se recrea el cliente se habilitan las publicaciones
						borrarPublicacionesYCliente(arrayPublicaciones,ELEMENTOS_ARRAY, arrayClientes, ELEMENTOS_ARRAY);
						primeraCarga = 1;
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
							publicacion_pausar(arrayPublicaciones, ELEMENTOS_ARRAY, auxiliarId, &avisosPausados);
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
							publicacion_reanudar(arrayPublicaciones, ELEMENTOS_ARRAY, auxiliarId, &avisosPausados);
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
					if(primeraCarga != 0)
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

