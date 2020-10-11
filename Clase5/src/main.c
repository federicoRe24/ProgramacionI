
//#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <limits.h> // Biblioteca con valores máximos y mínimos
#include "utn.h" // Las bibliotecas del sistema se incluyen entre <>, las propias van entre " (referencia relativa)

/* Pedir 5 numeros
 * -Op1 - Calcular Maximo
 * -OP2- Calcular Promedio
 */

#define CANTIDAD_ELEMENTOS 5 //Constante

int main(void)
{
	int variableInt;
	char aMensaje[200];
	int arrayInt[CANTIDAD_ELEMENTOS];
	int flagCargaCorrecta = 0;
	int maximo;

	for(int i=0;i< CANTIDAD_ELEMENTOS ;i++)
	{
		sprintf(aMensaje,"Numero %d: ",i+1);
		if(getInt(aMensaje,"Fuera de rango [0-1000]\n",&variableInt,5,1000,0) != 0)
		{
			printf("GAME OVER");
			flagCargaCorrecta = -1;
			break;
		}
		else
		{
			arrayInt[i] = variableInt;
		}
	}
	if(flagCargaCorrecta == 0)
	{
		if(calcularMaximo(arrayInt, CANTIDAD_ELEMENTOS,&maximo) == 0)
		{
			printf("El máximo ingresado es %d", maximo);
		}
		imprimirArray(arrayInt, CANTIDAD_ELEMENTOS);
		ordenarArray(arrayInt, CANTIDAD_ELEMENTOS);
		imprimirArray(arrayInt, CANTIDAD_ELEMENTOS);
	}

	return 0;
}
