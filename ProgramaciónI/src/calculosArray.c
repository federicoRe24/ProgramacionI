/*
 * calculosArray.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

int alumno_devolverVacio(Alumno* pArray, int limit, int *indiceItemVacio);

/**
 * \brief Calcula el numro maximo del array recibido como parametro
 * \param int pArray[], Array a ser procesado
 * \param int cantidadElementos, cantidad de elementos a ser procesador
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 *
 */
int calcularMaximo(int pArray[], int cantidadElementos,int *pResultado)
{
	int retorno=-1;
	int maximo;
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	{
		for(int i=0; i < cantidadElementos; i++)
		{
			if(i==0 || pArray[i] > maximo)
			{
				maximo = pArray[i];
			}
		}
		*pResultado = maximo;
		retorno = 0;
	}
	return retorno;
}


//6) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).

int alumno_devolverVacio(Alumno* pArray, int limit, int *indiceItemVacio)
{
		int retorno = -1;
		if(pArray != NULL && limit > 0)
		{
			for(int i=0; i < limit; i++)
			{
				if(pArray[i].isEmpty == TRUE)
				{
					*indiceItemVacio = i;
					retorno = 0;
					break;
				}
			}
		}
		return retorno;
}

/*9) Realizar una funcion que reciba el array y un ID, y me devuelva el indice del item con dicho ID. (buscar por id)*/

int alumno_devolverIndiceByID(Alumno* pArray, int limit, int id, int *indiceDeId)
{
		int retorno = -1;
		if(pArray != NULL && id > 0)
		{
			for(int i=0; i < limit; i++)
			{
				if(pArray[i].id == id)
				{
					*indiceDeId = i;
					retorno = 0;
					break;
				}
			}
		}
		return retorno;
}

