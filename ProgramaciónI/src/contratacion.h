

#ifndef SRC_CONTRATACION_H_
#define SRC_CONTRATACION_H_

#include "pantalla.h"
#define CUIT_LEN 15

typedef struct
{
	int idContratacion;
	int isEmpty;
	char cuit [CUIT_LEN];
	int cantidadDias;
	char nombreVideo [NOMBRE_LEN];
	int idPantalla;
}Contratacion;

int contratacion_imprimirArray(Contratacion *array, int limite);
int contratacion_imprimir(Contratacion* pElemento);
int contratacion_alta(Pantalla *pPantallas, int limitePantallas, Contratacion *pContrataciones, int limiteContrataciones);


#endif /* SRC_CONTRATACION_H_ */
