
#include <stdio.h>
#include "ArrayClientes.h"
#include "publicacion.h"
#include "utn.h"
#include "informes.h"

int informes(Cliente *arrayClientes, Publicacion *arrayPublicaciones, int avisosPausados)
{
	int opcion;
	int respuesta;
	int auxiliarId;

	do
	{
		respuesta = getInt("Seleccione una opción\n\n1-Cliente con más avisos\n2-Cantidad de avisos pausados\n3-Rubro con más avisos\n"
				"4-Cliente con más avisos activos\n5-Cliente con más avisos pausados\n6-Volver\n","No es una opción válida\n",&opcion,3,6,1);
		if(!respuesta)
		{
			switch(opcion)
			{
				case 1:
					auxiliarId = getIdClienteConMasAvisos(arrayPublicaciones, LEN_PUBLICACIONES);
					if(auxiliarId != -1)
					{
						printf("El cliente con más publicaciones es: \n");
						printCliente(arrayClientes, LEN_CLIENTES, auxiliarId);
					}
					else
					{
						printf("No hay publicaciones cargadas\n");
					}
					break;
				case 2:
					printf("La cantidad de avisos pausados es %d\n", avisosPausados);
					break;
				case 3:
					break;
				case 4:
					auxiliarId = getIdClienteConMasAvisosActivos(arrayPublicaciones, LEN_PUBLICACIONES);
					if(auxiliarId != -1)
					{
						printf("El cliente con más publicaciones activas es: \n");
						printCliente(arrayClientes, LEN_CLIENTES, auxiliarId);
					}
					else
					{
						printf("No hay publicaciones activas\n");
					}
					break;
				case 5:
					auxiliarId = getIdClienteConMasAvisosPausados(arrayPublicaciones, LEN_PUBLICACIONES);
					if(auxiliarId != -1)
					{
						printf("El cliente con más publicaciones pausadas es: \n");
						printCliente(arrayClientes, LEN_CLIENTES, auxiliarId);
					}
					else
					{
						printf("No hay publicaciones pausadas\n");
					}
					break;
			}
		}
	}while(opcion!=6);

	return 0;
}

