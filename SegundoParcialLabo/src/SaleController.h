#ifndef SALECONTROLLER_H_
#define SALECONTROLLER_H_

int controller_loadSalesFromText(char* path , LinkedList* pArrayListSale);
LinkedList* controller_FilterListSaleByClient(LinkedList* pArrayListSale, int clientId);
int controller_saveSalesAsText(char* path , LinkedList* pArrayListSale);
int IsVentaCobrada(void* pElement);
int IsVentaACobrar(void* pElement);
LinkedList* controller_filterListByEstate(LinkedList* pArrayListSale, int (*pFunc)(void*));

#endif
