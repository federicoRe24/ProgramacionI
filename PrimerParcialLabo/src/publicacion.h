

#ifndef SRC_PUBLICACION_H_
#define SRC_PUBLICACION_H_

#include "ArrayClientes.h"
#define AVISO_LEN 64
#define ACTIVA 1
#define PAUSADA 0

typedef struct
{
	int idPublicacion;
	int isEmpty;
	int numeroRubro;
	char textoAviso[AVISO_LEN];
	int idCliente;
	int estado;
}Publicacion;

int initPublicaciones(Publicacion* list, int len);
int publicacion_alta(Cliente *pCliente, int limiteCliente, Publicacion *pPublicacion, int limitePublicacion);
int publicacion_imprimirArray(Publicacion *array, int limite);
int publicacion_buscarId(Publicacion *array, int limite,int valorBuscado);
int publicacion_pausar(Publicacion *array, int limite, int id);
int publicacion_borrar(Publicacion *array, int limite, int id);

#endif /* SRC_PUBLICACION_H_ */
