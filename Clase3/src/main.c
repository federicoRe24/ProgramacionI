
#include <stdio.h>
#include <stdio_ext.h>
#include "Ejercicio.h"


/* Noooooooooo
float resultadoFloat;
int resultadoInt;
*/

// \n --> Salto de línea.

int sumarConLimite(int operador1, int operador2); // Declaro el prototipo o firma de la funcion

int sumarEnteros(int operadoA, int operadorB);
int restarEnteros(int operadoA, int operadorB);
int multiplicarEnteros(int operadoA, int operadorB);
int dividirEnteros(int operadoA, int operadorB, float *resultado);

int main(void){

	int numeroUno;
	int numeroDos;
	int operacion;
	float resultado;

	// __fpurge(stdin); --> Para limpiar la consola
	// La operacion se puede pedir con un char (caracter)

	printf("Ingrese un número: ");
	scanf("%d",&numeroUno);
	printf("Ingrese la operación que desea realizar: 1)Suma - 2)Resta - 3)Multiplicación - 4)División: ");
	scanf("%d",&operacion);
	printf("Ingrese un segundo número: ");
	scanf("%d",&numeroDos);

	switch(operacion)
	{
		case 1:
			resultado = sumarEnteros(numeroUno, numeroDos);
			break;

		case 2:
			resultado = restarEnteros(numeroUno, numeroDos);
			break;

		case 3:
			resultado = multiplicarEnteros(numeroUno, numeroDos);
			break;

		case 4:
			if(dividirEnteros(numeroUno,numeroDos, &resultado) == 0)
			{
				printf("Se pudo dividir. \n");
			}
			else
			{
				printf("No se pudo dividir. \n");
			}
			break;

		default:
			printf("No ingresó un valor válido de operación.");
			break;
	}

	printf("El resultado es %f", resultado);

	return 0;
}

int sumarEnteros(int operadoA, int operadorB)
{
	int resultado;
	resultado = operadoA + operadorB;
	return resultado;
}

int restarEnteros(int operadoA, int operadorB)
{
	int resultado;
	resultado = operadoA - operadorB;
	return resultado;
}

int multiplicarEnteros(int operadoA, int operadorB)
{
	int resultado;
	resultado = operadoA * operadorB;
	return resultado;
}

int dividirEnteros(int operadoA, int operadorB, float *resultado)
{
	int retorno = 0;
	if(operadorB != 0)
	{
		*resultado = (float)operadoA / operadorB;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}

int sumarConLimite(int operador1, int operador2)
{
	int resultado; // variable local
	resultado = operador1 + operador2;
	if(resultado>100)
	{
		resultado=100;
	}
	// retornar valor
	return resultado;
}


