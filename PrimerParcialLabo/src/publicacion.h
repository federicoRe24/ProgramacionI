

#ifndef SRC_PUBLICACION_H_
#define SRC_PUBLICACION_H_

#include "ArrayClientes.h"
#define AVISO_LEN 64
#define ACTIVA 1
#define PAUSADA 0
#define MAX_ID 1000

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
int publicacion_imprimirPorCliente(Publicacion *array, int limite, int idCliente);
int publicacion_buscarId(Publicacion *array, int limite,int valorBuscado);
int publicacion_pausar(Publicacion *array, int limite, int id, int *avisosPausados);
int publicacion_reanudar(Publicacion *array, int limite, int id, int *avisosPausados);
int publicacion_borrar(Publicacion *array, int limite, int idCliente);
int borrarPublicacionesYCliente(Publicacion *arrayPublicaciones, int limitePublicaciones, Cliente *arrayClientes,
		int limiteClientes);
int publicacionesPorCliente(Publicacion *array, int limite,int idCliente);
int getIdClienteConMasAvisos(Publicacion* list, int len);

#endif /* SRC_PUBLICACION_H_ */
