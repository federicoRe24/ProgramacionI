/*
 * estaciones.h
 *
 *  Created on: 3 sep. 2019
 *      Author: brian
 */

#ifndef ESTACIONES_H_
#define ESTACIONES_H_

#include<string>

const int MAXIMO_FILAS = 229;

struct EstacionesDeMetrobus{
	double longitud;
	double latitud;
	int id;
	std::string nombre;
	std::string calle1;
	std::string calle2;
	std::string interseccion;
	std::string lineaSentidoNorte;
	std::string lineaSentidoSur;
	std::string metrobus;
	std::string nombreSentido;
	std::string observaciones;


};

//asigna los valores pasados a los campos de un struct
void asignarValores( EstacionesDeMetrobus &estacion,double longitud,double latitud,int id,
					 std::string nombre,std::string calle1,std::string calle2,std::string interseccion,
					 std::string norte, std::string sur, std::string metrobus, std::string nombreSentido,
					 std::string observaciones);

//muestra una estacion pasada por parametro
void mostrarEstacion( EstacionesDeMetrobus estacion);


#endif /* ESTACIONES_H_ */
