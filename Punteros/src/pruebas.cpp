#include <iostream>
#include "pruebas.h"

void prueba(){

	// void *t; //Puntero a void.

	/*
	int *p;
	int a = 1;
	//p = NULL;
	p = &a;
	std::cout << p << std::endl;
	std::cout << &p << std::endl;
	std::cout << *p << std::endl;

	*p = *p +1;
	std::cout << *p << std::endl;
	p = p + 1;
	std::cout << p << std::endl;
	std::cout << &p << std::endl;
	std::cout << *p << std::endl;

	float *q, b;
	q = &b;
	std::cout << q << std::endl;
	std::cout << &q << std::endl;
	std::cout << *q << std::endl;
	*/

	// Punteros constantes

	int x=2; //, y=3;
	int* const  p = &x; // p siempre va a apuntar a x

	//p = &y; --> No se puede modificar la posicion a la que apunta p.

	std::cout << x << std::endl;
	*p = 3;							//  Si puede cambiar el contenido de la dirección apuntada.
	std::cout << x << std::endl;

}

