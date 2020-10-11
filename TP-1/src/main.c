#include <stdio.h>


int main() {

	int numero1;
	int numero2;
	int resultado;
	int resultadoScan;

	printf("Numero 1? ");
	resultadoScan = scanf("%d", &numero1); /* TIPOS int %d - float %f - char %c */
	printf("Numero 2? ");
	resultadoScan = scanf("%d", &numero2); /*& para indicar la posicion de memoria de la variable --> puntero */

	resultado = numero1 + numero2;

	printf("La suma es %d", resultado);

   return 0;

}
