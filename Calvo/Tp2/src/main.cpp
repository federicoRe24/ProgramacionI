/*
 * main.cpp
 *
 *  Created on: 13 oct. 2019
 *      Author: brian
 */

#include "Lista.h"
#include "lectura.h"
#include "EstacionDeFerrocarril.h"
#include "EstacionDeMetrobus.h"
#include "EstacionDeSubte.h"
#include "Garaje.h"
#include "ParadaDeColectivo.h"



int main(){

	Lista<EstacionDeFerrocarril> estacionesDeFerrocarril;
	Lista<EstacionDeMetrobus> estacionesDeMetrobus;
	Lista<EstacionDeSubte> estacionesDeSubte;
	Lista<Garaje> listaDeGarajes;
	Lista<ParadaDeColectivo> paradasDeColectivo;

	leerArchivoDeEstacionDeFerrocarril("datos1/estaciones-de-ferrocarril.csv", estacionesDeFerrocarril);
	leerArchivoDeEstacionDeMetrobus("datos1/estaciones-de-metrobus.csv", estacionesDeMetrobus);
	leerArchivoDeEstacionDeSubte("datos1/bocas-de-subte.csv", estacionesDeSubte);
	leerArchivoDeGaraje("datos1/garajes-comerciales.csv", listaDeGarajes);
	leerArchivoDeParadaDeColectivo("datos1/paradas-de-colectivo.csv", paradasDeColectivo);

	estacionesDeFerrocarril.~Lista();
	estacionesDeMetrobus.~Lista();
	estacionesDeSubte.~Lista();
	listaDeGarajes.~Lista();
	paradasDeColectivo.~Lista();



	return 0;
}



