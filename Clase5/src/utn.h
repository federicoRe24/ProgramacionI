
//#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#ifndef SRC_UTN_H_
#define SRC_UTN_H_

int getInt(char* mensaje, char* mensajeError, int* resultado, int reintentos, int maximo, int minimo);
int calcularMaximo(int pArray[], int cantidadElementos,int *pResultado);
void ordenarArray(int array[], int len);

// Warning implict declaration (falta el prototipo de la funcion)

#endif /* SRC_UTN_H_ */
