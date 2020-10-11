/*
 * EstacionesDeFerrocarril.h
 *
 *  Created on: 13 oct. 2019
 *      Author: brian
 */

#ifndef ESTACIONDEFERROCARRIL_H_
#define ESTACIONDEFERROCARRIL_H_

#include<string>

/* UNA ESTACION DE FERROCARRIL ES UNA CLASE QUE ALMACENA DATOS CORRESPONDIENTES A LA UBICACION E IDENTIFICACION
 * DE LAS ESTACIONES DE FERROCARRIL DE LA CIUDAD DE BUENOS AIRES*/

class EstacionDeFerrocarril{

private:

	double longitud;
	double latitud;
	unsigned int id;
	std::string nombre;
	std::string linea;
	std::string linea2;
	std::string ramal;
	std::string barrio;
	std::string comuna;
	std::string localidad;
	std::string partido;

public:
	//Pre:
	//Post: instancia la clase y la deja lista para ser utilizada
	EstacionDeFerrocarril();

	//Pre:
	//Post: asigna los datos pasados por parametro a cada atributo correspondinete de la clase
	void asignarDatos(double longitud, double latitud, unsigned int id, std::string nombre, std::string linea,
					  std::string linea2, std::string ramal, std::string barrio, std::string comuna,
					  std::string localidad, std::string partido);

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

	//Pre:
	//Post: devuelve el barrio donde se encuentra la estación
	std::string obtenerBarrio();

	//Pre:
	//Post: devuelve la comuna donde se encuentra la estación
	std::string obtenerComuna();

	//Pre:
	//Post: devuelve la localidad donde se encuentra la estación
	std::string obtenerLocalidad();

	//Pre:
	//Post: devuelve el partido donde se encuentra la estación
	std::string obtenerPartido();

};



#endif /* ESTACIONDEFERROCARRIL_H_ */
