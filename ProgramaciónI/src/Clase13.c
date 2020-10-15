#include <stdio.h>
#include "Clase13.h"

int clase13(void) /* Rellenamos una matriz */
{
	int x,i,numeros[3][4];

	int numeros[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};

	numeros[0][0]=1;

	//quedarían asignados de la siguiente manera:

	/*numeros[0][0]=1 numeros[0][1]=2 numeros[0][2]=3 numeros[0][3]=4
	numeros[1][0]=5 numeros[1][1]=6 numeros[1][2]=7 numeros[1][3]=8
	numeros[2][0]=9 numeros[2][1]=10 numeros[2][2]=11 numeros[2][3]=12*/
	for (x=0;x<3;x++)
		for (i=0;i<4;i++)
			printf("%d",numeros[x][i]);

	return 0;
}
