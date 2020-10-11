#ifndef ESTRUCTURADEMETROBUS_H_
#define ESTRUCTURADEMETROBUS_H_
#include <iostream>

	const int CANTIDAD_ESTACIONES = 230; //Cantidad máxima de registros del archivo.

	struct EstacionMetro{
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

void asignarMetrobus(EstacionMetro &estacion, double longitud, double latitud, int id, std::string nombre, std::string calle1,
			std::string calle2, std::string interseccion, std::string lineaSentidoNorte, std::string lineaSentidoSur, std::string metrobus,
			std::string nombreSentido, std::string observaciones);

void imprimirEstacion(EstacionMetro estacion);

#endif /* ESTRUCTURADEMETROBUS_H_ */
