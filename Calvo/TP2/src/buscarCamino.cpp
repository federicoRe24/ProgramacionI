/*
 * buscarCamino.cpp
 *
 *  Created on: 28 oct. 2019
 *      Author: martin
 */

#include "buscarCamino.h"
#include <math.h>
#include <iostream>
#include <stdio.h>

BuscarCamino::BuscarCamino(double latitudOrigen, double longitudOrigen, double latitudDestino, double longitudDestino){
	this->latitudOrigen=latitudOrigen;
	this->longitudOrigen=longitudOrigen;
	this->latitudDestino=latitudDestino;
	this->longitudDestino=longitudDestino;
	//los inicializo en un numero alto ya que ese numero es un aproximado a 1000000km en la tierra
	this->distaciaMinimaOrigen=9999;
	this->distanciaMinimaDestino=9999;
}
double BuscarCamino::calcularDistancia(double lat1,double lat2, double lon1, double lon2){
	double restaLatitud=lat1-lat2;
	double restaLongitud=lon1-lon2;
	double pitagoras = pow(restaLatitud,2) + pow(restaLongitud,2);
	double modulo = sqrt(pitagoras);
	return modulo;
}


void BuscarCamino::estacionMasCercana(Lista<Estaciones>* listaDeEstaciones)
{
	listaDeEstaciones->iniciarCursor();
	while (listaDeEstaciones->avanzarCursor()){
		double latitud=listaDeEstaciones->obtenerCursor().obtenerLatitud();
		double longitud=listaDeEstaciones->obtenerCursor().obtenerLongitud();
		if (this->distaciaMinimaOrigen>calcularDistancia(this->latitudOrigen,latitud,this->longitudOrigen,longitud)){
			this->distaciaMinimaOrigen=calcularDistancia(this->latitudOrigen,latitud,this->longitudOrigen,longitud);
			this->opcion1.setEstacionOrigen(listaDeEstaciones->obtenerCursor());
		}
		if (this->distanciaMinimaDestino>calcularDistancia(this->latitudDestino,latitud,this->longitudDestino,longitud)){
			this->distanciaMinimaDestino=calcularDistancia(this->latitudDestino,latitud,this->longitudDestino,longitud);
			this->opcion1.setEstacionDestino(listaDeEstaciones->obtenerCursor());
		}
	}
}

void BuscarCamino::estacionMasCercana(Lista<Estaciones>* lineasDeOrigen, Lista<Estaciones>* lineasDeDestino)
{
	//lo inicializo en un numero alto ya que ese numero es un aproximado a 1000000km en la tierra
	double distanciaMinima=999;
		lineasDeOrigen->iniciarCursor();
		while(lineasDeOrigen->avanzarCursor()){
			lineasDeDestino->iniciarCursor();
			while(lineasDeDestino->avanzarCursor()){
				if (distanciaMinima>calcularDistancia(lineasDeOrigen->obtenerCursor().obtenerLatitud(),lineasDeDestino->obtenerCursor().obtenerLatitud(),
														lineasDeOrigen->obtenerCursor().obtenerLongitud(),lineasDeDestino->obtenerCursor().obtenerLongitud()))
				{
					distanciaMinima=calcularDistancia(lineasDeOrigen->obtenerCursor().obtenerLatitud(),lineasDeDestino->obtenerCursor().obtenerLatitud(),
									lineasDeOrigen->obtenerCursor().obtenerLongitud(),lineasDeDestino->obtenerCursor().obtenerLongitud());
					this->opcion1.setEstacionDeConexion(lineasDeOrigen->obtenerCursor(),lineasDeDestino->obtenerCursor());
				}
			}
		}
}

void BuscarCamino::buscarEstacionesDeMismaLinea(Lista<Estaciones>* estaciones,Lista<Estaciones>* origen,Lista<Estaciones>* destino){
	estaciones->iniciarCursor();
	while (estaciones->avanzarCursor()){
		if (estaciones->obtenerCursor().obtenerLinea()==this->opcion1.obtenerOrigen()->obtenerLinea()){
			origen->agregar(estaciones->obtenerCursor());
		}
		if (estaciones->obtenerCursor().obtenerLinea()==this->opcion1.ObtenerDestino()->obtenerLinea()){
			destino->agregar(estaciones->obtenerCursor());
		}
	}
}

Camino BuscarCamino::buscadorDeLineas(Lista<Estaciones>* estacionesDeFerrocarril,Lista<Estaciones>*  paradasDeColectivo,Lista<Estaciones>* estacionesDeSubte){
	estacionMasCercana(estacionesDeFerrocarril);
	estacionMasCercana(paradasDeColectivo);
	estacionMasCercana(estacionesDeSubte);
//	estacionMasCercana(estacionesDeMetrobus);
	if (this->opcion1.obtenerOrigen()->obtenerLinea()!=this->opcion1.ObtenerDestino()->obtenerLinea()){
		Lista<Estaciones>* origen=new Lista<Estaciones>;
		Lista<Estaciones>* destino=new Lista<Estaciones>;
		std::cout<<"entro en intercambios"<<std::endl;

		if (this->opcion1.obtenerOrigen()->obtenerTransporte()=="Subte" || this->opcion1.ObtenerDestino()->obtenerTransporte()=="Subte"){
			buscarEstacionesDeMismaLinea(estacionesDeSubte,origen,destino);
		}
		if (this->opcion1.obtenerOrigen()->obtenerTransporte()=="Tren"|| this->opcion1.ObtenerDestino()->obtenerTransporte()=="Tren"){
			buscarEstacionesDeMismaLinea(estacionesDeFerrocarril,origen,destino);
		}
		if (this->opcion1.obtenerOrigen()->obtenerTransporte()=="Colectivo"|| this->opcion1.ObtenerDestino()->obtenerTransporte()=="Colectivo"){
			buscarEstacionesDeMismaLinea(paradasDeColectivo,origen,destino);
		}
//		if (this->opcion1.obtenerOrigen()->obtenerTransporte()=="Metrobus"|| this->opcion1.ObtenerDestino()->obtenerTransporte=="Metrobus"){
//			buscarEstacionesDeMismaLinea(estacionesDeMetrobus,origen,destino);
//		}
		estacionMasCercana(origen,destino);
		origen->~Lista();
		destino->~Lista();
	}
	this->opcion1.explicarRecorrido();
	return this->opcion1;
}





