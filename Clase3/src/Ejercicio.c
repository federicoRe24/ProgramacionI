/* Pedir al usuario dos numeros float
 *
 * Funcion sumar -> Si no hay error, imprimir el resultado: "La suma es.."
 * Funcion restar
 * Funcion multiplicar
 * Funcion dividir
 * Todas las funciones, en caso de exito return 0 y en caso de error return -1
 */

#include <stdio.h>
#include <stdio_ext.h>
#include "Ejercicio.h"

int ejercicio(void)
{
	float numeroUno;
	float numeroDos;
	float *resultado;

	/* Validar el ingreso */
	printf("Ingrese un número: ");
	scanf("%f", &numeroUno);
	printf("Ingrese otro número: ");
	scanf("%f", &numeroDos);

	if(sumarNumeros(numeroUno, numeroDos, &resultado) == 0)
	{
		printf("La suma de los números es: %f\n", resultado);
	}

	if(restarNumeros(numeroUno, numeroDos, &resultado) == 0)
	{
		printf("La resta entre los números es: %f\n", resultado);
	}

	if(multiplicarNumeros(numeroUno, numeroDos, &resultado) == 0)
	{
		printf("El producto entre los números es: %f\n", resultado);
	}

	if(dividirNumeros(numeroUno, numeroDos, &resultado) == 0)
	{
		printf("El cociente entre los números es: %f\n", resultado);
	}

	return 0;
}

float sumarNumeros(float numeroUno, float numeroDos,float *resultado)
{
	int retorno;
	*resultado = numeroUno + numeroDos;
	printf("La suma de los números es: %f\n", *resultado);
	retorno = 0;
	return retorno;
}

float restarNumeros(float numeroUno, float numeroDos,float *resultado)
{
	int retorno;
	*resultado = numeroUno - numeroDos;
	retorno = 0;
	return retorno;
}


float multiplicarNumeros(float operadoA, float operadorB, float *resultado)
{
	int retorno;
	*resultado = operadoA * operadorB;
	retorno = 0;
	return retorno;
}

float dividirNumeros(float operadoA, float operadorB, float *resultado)
{
	int retorno;
	if(operadorB != 0)
	{
		*resultado = operadoA / operadorB;
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}





