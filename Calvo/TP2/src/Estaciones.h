/*
 * Estaciones.h
 *
 *  Created on: 26 oct. 2019
 *      Author: martin
 */

#ifndef ESTACIONES_H_
#define ESTACIONES_H_

#include<string>

/* UNA ESTACION DE FERROCARRIL ES UNA CLASE QUE ALMACENA DATOS CORRESPONDIENTES A LA UBICACION E IDENTIFICACION
 * DE LAS ESTACIONES DE FERROCARRIL DE LA CIUDAD DE BUENOS AIRES*/

class Estaciones{

private:

	std::string transporte;
	double longitud;
	double latitud;
	unsigned int id;
	std::string nombre;
	std::string linea;
	std::string linea2;
	std::string ramal;

public:
	//Pre:
	//Post: instancia la clase y la deja lista para ser utilizada
	Estaciones();

	//Pre:
	//Post: asigna los datos pasados por parametro a cada atributo correspondinete de la clase
	void asignarDatos(std::string transporte, double longitud, double latitud, unsigned int id,std::string nombre, std::string linea,
					  std::string linea2, std::string ramal);
	/*
	 * post:
	 */
	void asignarDatos(Estaciones estacioncopia);

	//Pre:
	//Post: devuelve el transporte de la estación
	std::string obtenerTransporte();

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
	//Post: devuelve la linea de la estación
	std::string obtenerLinea();

	//Pre:
	//Post: devuelve la segunda linea de la estación
	std::string obtenerLinea2();

	//Pre:
	//Post: devuelve el ramal de la estación
	std::string obtenerRamal();


};




#endif /* ESTACIONES_H_ */
