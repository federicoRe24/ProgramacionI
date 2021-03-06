/*
 * calculosArray.h
 *
 *  Created on: Sep 8, 2020
 *      Author: Mauro
 */

#ifndef CALCULOSARRAY_H_
#define CALCULOSARRAY_H_

int calcularMaximo(int pArray[], int cantidadElementos,int *pResultado);
int alumno_printById(Alumno* pArray, int limit, int index);
int alumno_devolverVacio(Alumno* pArray, int limit, int *indiceItemVacio);
int alumno_devolverIndiceByID(Alumno* pArray, int limit, int id, int *indiceDeId);

#endif /* CALCULOSARRAY_H_ */
