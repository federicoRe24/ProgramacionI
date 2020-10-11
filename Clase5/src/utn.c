
#include "utn.h"

#define CANTIDAD_ELEMENTOS 5 //Constante

/*
* \brief - Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int maximo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 */

// Primero le paso un mensaje
// char* --> Puntero a string

int getInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo)
{
	int retorno = -1;
	int bufferInt; // Variable descartable
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo) // Como mínimo, que máx sea mayor que mín para que tenga sentido

	do
	{
		printf("%s", mensaje);
		__fpurge(stdin); // stdin --> standard input
		resultadoScanf = scanf("%d", &bufferInt);
		if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		else
		{
			//Error
			printf("%s",mensajeError);
			reintentos --;
		}
	}while(reintentos >= 0);

	return retorno;
}

/*
* \brief Calcula el numero maximo del array recibido como parametro
 * \param int pArray[], Array a ser procesado
 * \param imt cantidadElementos, cantidad de elementos a ser procesados
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 */

int calcularMaximo(int pArray[], int cantidadElementos,int *pResultado)
{
	int retorno = -1;
	int maximo;
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	for(int i=1;i< CANTIDAD_ELEMENTOS ;i++)
	{
		if(i== 0 || pArray[i] > maximo)
		{
			maximo = pArray[i];
		}
	}
	*pResultado = maximo;
	return retorno;
}

void ordenarArray(int array[], int len)
{
	int indice;
	int aux;
	int flagEstadoDesordenado=1;
	while(flagEstadoDesordenado==1)// no esta ordenado
	{
		flagEstadoDesordenado=0;
		for(indice=0 ; indice<(len-1)  ; indice++)
		{
			if(array[indice] > array[indice+1])
			{
				// intercambiar (swap)
				aux = array[indice];
				array[indice] = array[indice+1];
				array[indice+1] = aux;
				flagEstadoDesordenado=1;
			}
		}
	}
}

void imprimirArray(int array[], int len)
{
	int indice;

	for(indice=0 ; indice<(len)  ; indice++)
	{
		printf("%d ", array[indice]);
	}
	printf("\n");
}

