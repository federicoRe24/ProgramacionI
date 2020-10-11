/*
 * EstacionesDeMetrobus.h
 *
 *  Created on: 13 oct. 2019
 *      Author: brian
 */

#ifndef ESTACIONDEMETROBUS_H_
#define ESTACIONDEMETROBUS_H_

#include<string>

/*UNA ESTACION DE METROBUS ES UNA CLASE QUE ALMACENA DATOS SOBRE LA UBICACION E IDENTIFICACION DE LAS ESTACIONES
 * DE METRIBUS EN LA CIUDAD DE BUENOS AIRES*/

class EstacionDeMetrobus{

private:

	double longitud;
	double latitud;
	unsigned int id;
	std::string nombre;
	std::string calle1;
	std::string calle2;
	std::string interseccion;
	std::string lineaSentidoNorte;
	std::string lineaSentidoSur;
	std::string metrobus;
	std::string nombreSentido;
	std::string observaciones;

public:

	//Pre:
	//Post: Constructor. Instancia la clase y la deja lista para ser utilizada
	EstacionDeMetrobus();

	//Pre:
	//Post: asigna los datos pasados por parametro a cada atributo correspondiente de la clase
	void asignarDatos(double longitud, double latitud, unsigned int id, std::string nombre, std::string calle1,
					  std::string calle2, std::string interseccion, std::string lineaSentidoNorte,
					  std::string lineaSentidoSur, std::string metrobus, std::string nombreSentido,
					  std::string observaciones);

	//Pre:
	//Post: devuelve la longitud de la estación
	double obtenerLongitud();

	//Pre:
	//Post: devuelve la latitud de la estación
	double obtenerLatitud();

	//Pre:
	//Post: devuelve la id de la estación
	unsigned int obtenerId();

	//Pre:
	//Post: devuelve el nombre de la estación
	std::string obtenerNombre();

	//Pre:
	//Post: devuelve la primera calle donde se encuentra la estación
	std::string obtenerCalle1();

	//Pre:
	//Post: devuelve la segunda calle donde se encuentra la estación
	std::string obtenerCalle2();

	//Pre:
	//Post: devuelve entre que calles se encuentra la estación
	std::string obtenerInterseccion();

	//Pre:
	//Post: devuelve las lineas de colectivo que van hacia el norte
	std::string obtenerLineaSentidoNorte();

	//Pre:
	//Post: devuelve las lineas de colectivo que van hacia el sur
	std::string obtenerLineaSentidoSur();

	//Pre:
	//Post: devuelve el metrobus al que pertenece la estación
	std::string obtenerMetrobus();

	//Pre:
	//Post: devuelve el nombre del sentido de la estación
	std::string obtenerNombreSentido();

	//Pre:
	//Post: devuelve las observaciones de la estación
	std::string obtenerObservaciones();
};




#endif /* ESTACIONDEMETROBUS_H_ */
