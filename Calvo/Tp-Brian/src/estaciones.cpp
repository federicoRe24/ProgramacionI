/*
 * estaciones.cpp
 *
 *  Created on: 5 sep. 2019
 *      Author: brian
 */

#include "estaciones.h"
#include <iostream>
#include <string>

void asignarValores(EstacionesDeMetrobus &estacion,double longitud,double latitud,int id,
					std::string nombre,std::string calle1, std::string calle2,std::string interseccion,
					std::string norte, std::string sur,std::string metrobus, std::string nombreSentido,
					std::string observaciones){
	estacion.longitud = longitud;
	estacion.latitud = latitud;
	estacion.id = id;
	estacion.nombre = nombre;
	estacion.calle1 = calle1;
	estacion.calle2 = calle2;
	estacion.interseccion = interseccion;
	estacion.lineaSentidoNorte = norte;
	estacion.lineaSentidoSur = sur;
	estacion.metrobus = metrobus;
	estacion.nombreSentido = nombreSentido;
	estacion.observaciones = observaciones;

}

void mostrarEstacion( EstacionesDeMetrobus estacion){
	std::cout<<"longitud: "<<estacion.longitud<<" | "<<"latitud: "<<estacion.latitud<<" | "<< "id: "<<estacion.id<<std::endl;
	std::cout<<"nombre: "<<estacion.nombre<<" | "<<"calle 1: "<<estacion.calle1<<" | "<< "calle 2: "<<estacion.calle2<<std::endl;
	std::cout<<"interseccion: "<<estacion.interseccion<<" | "<<"lineas hacia el norte: "<<estacion.lineaSentidoNorte<<std::endl;
	std::cout<<"lineas hacia el sur: "<<estacion.lineaSentidoSur<<" | "<<"metrobus: "<<estacion.metrobus<<std::endl;
	std::cout<<"nombre del sentido: "<<estacion.nombreSentido<<" | "<<"observaciones: "<<estacion.observaciones<<std::endl;
}



