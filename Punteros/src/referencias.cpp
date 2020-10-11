#include "referencias.h"
#include <iostream>

void referencias(){

	int x=2;
	int & y = x;  // y es a referencia a x. Es decir, es un nombre alternativo para aquello que llamamos x.

	std::cout << x << std::endl;

	y= 6;  // el valor de x ahora es 6

	std::cout << x << std::endl; // Cualquier operación sobre y es equivalente a hacerla sobre x

	int a=3;

	const int &b = a; // Declaracion de una referencia constante.

	//b=6; // Mostratá un mensaje de error del compilador-

	std::cout << b << std::endl;

	int m= b+5;

	std::cout << m << std::endl;

}

void swap (int & r, int & s)
// r y s son referencias

{
	int c;
	c=r;
	r=s;
	s=c;
}

void pruebaSwap()
{
	int a=1;
	int b=2;
	std::cout << "a=" << a << std::endl;
	std::cout <<" b=" << b << std::endl;
	swap(a,b);
	std::cout << "a=" << a <<" b=" << b << std::endl;

}

