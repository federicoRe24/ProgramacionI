
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
				"4-Volver\n","No es una opción válida\n",&opcion,3,4,1);
		if(!respuesta)
		{
			switch(opcion)
			{
				case 1:
					auxiliarId = getIdClienteConMasAvisos(arrayPublicaciones, ELEMENTOS_ARRAY);
					printf("El cliente con más publicaciones es: \n");
					printCliente(arrayClientes, ELEMENTOS_ARRAY, auxiliarId);
					break;
				case 2:
					printf("La cantidad de avisos pausados es %d\n", avisosPausados);
					break;
				case 3:
					break;
			}
		}
	}while(opcion!=4);

	return 0;
}

