/*
 * main.cpp
 *
 *  Created on: 13 oct. 2019
 *      Author: brian
 */

#include "Lista.h"
#include "lectura.h"
#include "Estaciones.h"
#include "Garaje.h"
#include <iostream>
#include "buscarCamino.h"



int main(){

	Lista<Estaciones>* estacionesDeFerrocarril=new Lista<Estaciones>;
	Lista<Estaciones>* estacionesDeMetrobus=new Lista<Estaciones>;
	Lista<Estaciones>* estacionesDeSubte=new Lista<Estaciones>;
	Lista<Garaje>* listaDeGarajes=new Lista<Garaje>;
	Lista<Estaciones>* paradasDeColectivo=new Lista<Estaciones>;


	leerArchivoDeEstacionesDeFerrocarril("estaciones-de-ferrocarril.csv",estacionesDeFerrocarril);
//	leerArchivoDeEstacionDeMetrobus("estaciones-de-metrobus.csv", estacionesDeMetrobus);
	leerArchivoDeEstacionDeSubte("bocas-de-subte.csv", estacionesDeSubte);
//	leerArchivoDeGaraje("garajes-comerciales.csv", listaDeGarajes);
	leerArchivoDeParadaDeColectivo("paradas-de-colectivo.csv", paradasDeColectivo);

	double latitudOrigen,longitudOrigen, latitudDestino, longitudDestino;
	std::cout<<"Ingrese la latitud de origen: ";
	std::cin>>latitudOrigen;
	std::cout<<"Ingrese la longitud de origen:";
	std::cin>>longitudOrigen;
	std::cout<<"Ingrese la latitud de destino: ";
	std::cin>>latitudDestino;
	std::cout<<"Ingrese la longitud de destino: ";
	std::cin>>longitudDestino;
	BuscarCamino prueba1(latitudOrigen,longitudOrigen,latitudDestino, longitudDestino);
	prueba1.buscadorDeLineas(estacionesDeFerrocarril,paradasDeColectivo,estacionesDeSubte);


	estacionesDeFerrocarril->~Lista();
	estacionesDeMetrobus->~Lista();
	estacionesDeSubte->~Lista();
	listaDeGarajes->~Lista();
	paradasDeColectivo->~Lista();

	return 0;
}



