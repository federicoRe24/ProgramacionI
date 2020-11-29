#ifndef SRC_SALE_H_
#define SRC_SALE_H_
#define LONG_NOMBRE 128
#define A_COBRAR 0
#define COBRADA 1
#include "LinkedList.h"

typedef struct
{
    int id;
    int cantidadAfiches;
    char nombreImagen[LONG_NOMBRE];
    char zona[LONG_NOMBRE];
    int estado;
    int clientId;
}Sale;

Sale* sale_new();
Sale* sale_newParametrosStr(char* idStr, char* cantidadAfichesStr, char* nombreImagen, char* zona, char* estadoStr, char* clientIdStr);
Sale* sale_newParametros(int id, int cantidadAfiches, char* nombreImagen,char* zona, int estado, int clientId);
void sale_delete(Sale* this);

int sale_setId(Sale* this,int id);
int sale_getId(Sale* this);

int sale_getCantidadAfiches(Sale* this);
int sale_setCantidadAfiches(Sale* this,int cantidadAfiches);

char* sale_getNombreImagen(Sale* this);
int sale_setNombreImagen(Sale* this,char* nombreImagen);

char* sale_getZona(Sale* this);
int sale_setZona(Sale* this,char* zona);

int sale_getEstado(Sale* this);
int sale_setEstado(Sale* this,int estado);

int sale_getClientId(Sale* this);
int sale_setClientId(Sale* this,int clientId);

int isValidName(char* nombre, int limite);

int sale_load(int* id, int* cantidadAfiches, char* nombreImagen, char* zona, int* estado, LinkedList* pArrayListSale);

#endif /* SRC_SALE_H_ */
