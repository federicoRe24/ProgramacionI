#ifndef client_H_INCLUDED
#define client_H_INCLUDED
#define LONG_NOMBRE 128
#define LONG_CUIT 13
#define MAX_INT 999999
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[LONG_NOMBRE];
    char apellido[LONG_NOMBRE];
    char cuit[LONG_CUIT];
}Client;

Client* client_new();
Client* client_newParametrosStr(char* idStr,char* nombre,char* apellido, char* cuit);
Client* client_newParametros(int id,char* nombre,char* apellido, char* cuit);
void client_delete(Client* this);

int client_setId(Client* this,int id);
int client_getId(Client* this);

int client_setNombre(Client* this,char* nombre);
char* client_getNombre(Client* this);

int client_setApellido(Client* this,char* apellido);
char* client_getApellido(Client* this);

int client_setCuit(Client* this,char* cuit);
char* client_getCuit(Client* this);

int client_compararNombre(void* thisA,void* thisB);
int client_compararId(void* thisA,void* thisB);

int isValidName(char* nombre, int limite);

int client_load(int* id,char* nombre,char* apellido, char* cuit, LinkedList* pArrayListClient);

#endif // client_H_INCLUDED
