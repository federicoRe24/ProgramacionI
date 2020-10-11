/*
 * principal.cpp
 *
 *  Created on: 3 sep. 2019
 *      Author: brian
 */

#include "lectura.h"
#include "estaciones.h"
#include "opcionesDeUsuario.h"
#include<iostream>

int main(){

	EstacionesDeMetrobus arrayDeEstaciones[MAXIMO_FILAS];
	leerArchivo("datos/estaciones-de-metrobus.csv",arrayDeEstaciones);
	mostrarMensaje(MENSAJE_DE_BIENVENIDA);
	menuDeUsuario(arrayDeEstaciones);

	return 0;
}



