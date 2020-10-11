/*
 * buscadorRuta.h
 *
 *  Created on: 26 oct. 2019
 *      Author: martin
 */

#ifndef CAMINO_H_
#define CAMINO_H_

#include "Estaciones.h"


class Camino{

	private:
		Estaciones* estacionDeOrigen;
		Estaciones* estacionDeDestino;
		Estaciones* estacionDeConexion1;
		Estaciones* estacionDeConexion2;

	public:

		/*
		 * post: Camino vacio.
		 */
		Camino();

		/*
		 * post: Guarda la estacion de origen
		 */
		void setEstacionOrigen(Estaciones estacionOrigen);
		/*
		 * post: Guarda estacion de destino
		 */
		void setEstacionDestino(Estaciones estacionDestino);
		/*
		 * Pre: estacionDeConexion1 debe estar en el recorrida de la linea que pasa por la estacion de origen y la
		 *  estacion de conexion 2 debe tener alguna linea que pase por la estacion de destino
		 *  Post: se guarda las estaciones donde el pasajero debera hacer un intercambio
		 */
		void setEstacionDeConexion(Estaciones estacionDeConexion1, Estaciones estacionDeConexion2);
		/*
		 * pre:debera tener al menos un una estacion de origen y una de destino
		 * Post: imprime por pantalla el recorrido que debera hacer el pasajero
		 */
		void explicarRecorrido();
		/*
		 * post:libera la memoria utilizada
		 */
		Estaciones* obtenerOrigen();
		Estaciones* ObtenerDestino();
		Estaciones* obtenerConexion1();
		Estaciones* obtenerConexion2();
};


#endif /* CAMINO_H_ */
