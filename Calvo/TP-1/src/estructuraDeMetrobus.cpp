#include "estructuraDeMetrobus.h"
#include <iostream>

void asignarMetrobus(EstacionMetro &estacion, double longitud, double latitud, int id, std::string nombre, std::string calle1,
		std::string calle2, std::string interseccion, std::string lineaSentidoNorte, std::string lineaSentidoSur, std::string metrobus,
		std::string nombreSentido, std::string observaciones){

	estacion.longitud = longitud;
	estacion.latitud = latitud;
	estacion.id = id;
	estacion.nombre = nombre;
	estacion.calle1 = calle1;
	estacion.calle2 = calle2;
	estacion.interseccion = interseccion;
	estacion.lineaSentidoNorte = lineaSentidoNorte;
	estacion.lineaSentidoSur = lineaSentidoSur;
	estacion.metrobus = metrobus;
	estacion.nombreSentido = nombreSentido;
	estacion.observaciones = observaciones;

	}

void imprimirEstacion(EstacionMetro estacion){

	std::cout.precision(16);

	std::cout << "longitud: " << estacion.longitud << ", " << "latitud: " << estacion.latitud << ", " << "id: " << estacion.id << ", "
	<< "nombre: " << estacion.nombre << ", " << "calle1: " << estacion.calle1 << ", " << "calle2: " << estacion.calle2 << std::endl;
	std::cout << "interseccion: " << estacion.interseccion << ", " << "lineaSentidoNorte: " << estacion.lineaSentidoNorte << ", "
	<< "lineaSentidoSur: " << estacion.lineaSentidoSur << ", " << "metrobus: " << estacion.metrobus << std::endl;
	std::cout << "nombreSentido: " << estacion.nombreSentido << ", " << "observaciones: " << estacion.observaciones << std::endl;

}
