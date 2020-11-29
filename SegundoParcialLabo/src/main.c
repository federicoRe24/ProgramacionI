#include <stdio.h>
#include <stdlib.h>
#include "Client.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "ReportController.h"
#include "SaleController.h"

//Ctrl + B para buildear

int main()
{
	int opcion;
	int respuesta;

    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas = ll_newLinkedList();
    controller_loadClientsFromText("clientes.txt",listaClientes);
    controller_loadSalesFromText("ventas.txt",listaVentas);
    LinkedList* ventasACobrar;
    LinkedList* ventasCobradas;

    // Zona con numeros

	do
	{
		respuesta = getInt("Seleccione una opción\n\n1-Agregar cliente\n2-Vender afiches\n3-Modificar venta\n4-Cobrar venta\n5-Generar informe "
				"de cobros\n6-Generar informe de deudas\n7-Generar estadísticas\n8-Salir\n", "No es una opción válida\n",&opcion,3,8,1);
		if(!respuesta)
		{
			switch(opcion)
			{
				case 1:
					controller_addClient(listaClientes);
					controller_ListClient(listaClientes);
	                break;
				case 2:
					controller_ListClient(listaClientes);
					controller_sellPoster(listaClientes, listaVentas);
					controller_ListSale(listaVentas);
					break;
				case 3:
					ventasACobrar = controller_filterListByEstate(listaVentas, IsVentaCobrada);
					if(ll_len(ventasACobrar) > 0)
					{
						controller_ListSale(ventasACobrar);
						if(controller_editSale(ventasACobrar) == 0)
						{
							printf("La venta fue modificada correctamente\n");
						}
						else
						{
							printf("No se pudo modificar la venta solicitada\n");
						}
					}
					else
					{
						printf("Actualmente no hay ventas en estado 'a cobrar'\n");
					}
					break;
				case 4:
					ventasACobrar = controller_filterListByEstate(listaVentas, IsVentaCobrada);
					if(ll_len(ventasACobrar) > 0)
					{
						controller_ListSale(ventasACobrar);
						controller_chargeSale(listaClientes, ventasACobrar);
					}
					else
					{
						printf("Actualmente no hay ventas en estado 'a cobrar'\n");
					}
					break;
				case 5:
					ventasCobradas = controller_filterListByEstate(listaVentas, IsVentaACobrar);
					controller_saveSaleReportAsText("cobradas.txt", listaClientes, ventasCobradas);
					break;
				case 6:
					ventasACobrar = controller_filterListByEstate(listaVentas, IsVentaCobrada);
					controller_saveSaleReportAsText("a_cobrar.txt", listaClientes, ventasACobrar);
					break;
				case 7:
					ventasCobradas = controller_filterListByEstate(listaVentas, IsVentaACobrar);
					controller_PrintClienstWithMoreAndLessSales(listaClientes, ventasCobradas);
					controller_PrintSaleWithMorePosters(listaClientes, ventasCobradas);
					break;
				case 8:
					controller_ListClient(listaClientes);
					controller_ListSale(listaVentas);
					controller_saveClientsAsText("clientes.txt", listaClientes);
					controller_saveSalesAsText("ventas.txt", listaVentas);
					break;
			}
		}
	}while(opcion!=8);

	return 0;
}
