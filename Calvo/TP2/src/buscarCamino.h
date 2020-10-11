/*
 * buscarCamino.h
 *
 *  Created on: 26 oct. 2019
 *      Author: martin
 */

#ifndef BUSCARCAMINO_H_
#define BUSCARCAMINO_H_

#include "Estaciones.h"
#include "Camino.h"
#include "Lista.h"
#include "Garaje.h"

class BuscarCamino{

private:
	double latitudOrigen;
	double longitudOrigen;
	double latitudDestino;
	double longitudDestino;
	Camino opcion1;
	double distanciaMinimaDestino;
	double distaciaMinimaOrigen;

public:
	/*
	 *post:
	 */
	BuscarCamino(double latitudOrigen, double longitudOrigen, double latitudDestino, double longitudDestino);

	/*
	 * post: devuelve la distancia entre dos coordenadas
	 */
	double calcularDistancia(double lat1,double lat2, double lon1, double lon2);
	/*
	 *post: busca las estaciones de la listas, mas proxima al punto de partida y el de destino
	 */
	void estacionMasCercana(Lista<Estaciones>* listaDeEstaciones);
	/*
	 * post:busca las dos estaciones mas cercanas entre las dos listas
	 */
	void estacionMasCercana(Lista<Estaciones>* lineaDeOrigen, Lista<Estaciones>* lineaDeDestino);
	/*
	 * pre:origen y destino deben de estar vacias
	 * post: llena las listas origen y destino con todas las estaciones que contiene la misma linea que las estaciones de origen y destino de la opcion1
	 */
	void buscarEstacionesDeMismaLinea(Lista<Estaciones>* estaciones,Lista<Estaciones>* origen,Lista<Estaciones>* destino);
	/*
	 *post: devuelve el camino que necesita el pasajero para llegar de un destino al otro
	 */
	Camino buscadorDeLineas(Lista<Estaciones>* estacionesDeFerrocarril,Lista<Estaciones>*  paradasDeColectivo,Lista<Estaciones>* estacionesDeSubte);


};


#endif /* BUSCARCAMINO_H_ */
