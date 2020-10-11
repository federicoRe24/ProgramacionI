
#include <stdio.h>

#include <stdio_ext.h>

/* setbuf(NULL,stdin) para Windows */

/* Pedir 5 números y calcular promedio */

int main()
{
    int numero;
    float promedio;
    int i;
    int resultadoScan;

    promedio = 0;

    for(i = 0; i < 5; i++)
    {
    	printf("Ingrese un número: ");
        resultadoScan = scanf("%d", &numero);
        while(resultadoScan == 0)
        {
            printf("Error - Numero? ");
            //Antes de volver a pedir con el scanf, debemos reiniciar los valores de la variable
            __fpurge(stdin); // fflush(stdin)
            resultadoScan = scanf("%d", &numero);
        }
    	/*scanf("%d", &numero);*/
    	promedio += numero;
    }

    promedio = promedio / i;
    /* En lugar de declarar promedio como float, podria castear antes de asignar el promedio (y asignarlo a una variable de tipo float). */

    /* %.2f para mostar 2 decimales; */
    printf("El promedio es %.2f", promedio);
}

