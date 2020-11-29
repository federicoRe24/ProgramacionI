int controller_loadClientsFromText(char* path , LinkedList* pArrayListClient);
int controller_addClient(LinkedList* pArrayListClient);


int controller_loadFromText(char* path , LinkedList* pArrayListClient);
int controller_loadFromBinary(char* path , LinkedList* pArrayListClient);
int controller_addClient(LinkedList* pArrayListClient);
int controller_editClient(LinkedList* pArrayListClient);
int controller_removeClient(LinkedList* pArrayListClient);
int controller_ListClient(LinkedList* pArrayListClient);
int controller_sortClient(LinkedList* pArrayListClient);
int controller_sortClientById(LinkedList* pArrayListClient);
int controller_saveClientsAsText(char* path , LinkedList* pArrayListClient);
int controller_saveAsBinary(char* path , LinkedList* pArrayListClient);
int controller_findClientById(LinkedList* pArrayListClient, int id);
int controller_sellPoster(LinkedList* pArrayListClient, LinkedList* pArrayListSale);
int controller_printSale(LinkedList* pArrayListSale, int index);
int controller_ListSale(LinkedList* pArrayListSale);
int controller_findSaleById(LinkedList* pArrayListSale, int id);
int controller_editSale(LinkedList* pArrayListSale);
int controller_chargeSale(LinkedList* pArrayListClient, LinkedList* pArrayListSale);


