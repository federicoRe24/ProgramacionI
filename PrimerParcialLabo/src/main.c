
#include <stdio.h>

#include "ArrayClientes.h"
#include "publicacion.h"
#include "utn.h"
#define ELEMENTOS_ARRAY 10


int main(void)
{
	int opcion;
	int respuesta;
	int primeraCarga = 1;
	int id;
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
						//Pedir ID acá, imprimir los clientes desde acá, borrar las publis y luego el cliente
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
						id = Getid(); // hacer
						publicacion_pausar(arrayPublicaciones, ELEMENTOS_ARRAY, id);
					}
					break;
				case 6:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						id = Getid(); // hacer
						publicacion_reanudar(arrayPublicaciones, ELEMENTOS_ARRAY, id);
					}
					break;
				case 7:
					if(primeraCarga != 0)
					{
						printf("Debe cargar al menos un cliente antes de poder acceder a esta opción\n");
					}
					else
					{
						id = Getid(); // hacer
						publicacion_reanudar(arrayPublicaciones, ELEMENTOS_ARRAY, id);
					}
					break;
				case 8:
					break;
			}
		}
	}while(opcion!=9);

	return 0;
}

