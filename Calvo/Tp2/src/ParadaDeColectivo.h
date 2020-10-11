/*
 * ParadaDeColectivo.h
 *
 *  Created on: 16 oct. 2019
 *      Author: brian
 */

#ifndef PARADADECOLECTIVO_H_
#define PARADADECOLECTIVO_H_

/* UNA PARADA DE COLECTIVO ES UNA CLASE QUE GUARDA INFORMACION ACERCA DE LA IDENTIFICACION, UBICACION Y LA RUTA QUE
 * TOMA UNA LINEA DE COLECTIVO*/

#include<string>

class ParadaDeColectivo{

private:

	double id;
	double codigo;
	std::string nombre;
	double latitud;
	double longitud;
	unsigned int direccion;
	unsigned int ruta;
	unsigned int agencia;
	std::string linea;
	std::string nombreDeRuta;
	std::string descripcionDeRuta;
	unsigned int tipoDeRuta;

public:

	//Pre:
	//Post: Constructor. Instancia la clase y la deja lista para ser utilizada
	ParadaDeColectivo();

	//Pre:
	//Post: agrega todos los datos pasados por parametro al atriburto correspondiente de la clase
	void agregarDatos(double id, double codigo, std::string nombre, double longitud, double latitud,
					  unsigned int direccion, unsigned int ruta, unsigned int agencia, std::string linea,
					  std::string nombreDeRuta, std::string descripcionDeRuta, unsigned int tipoDeRuta);

	//Pre:
	//Post: devuelve el id de la parada
	double obtenerId();

	//Pre:
	//Post: devuelve el codigo de la parada
	double obtenerCodigo();

	//Pre:
	//Post: devuelve el nombre de la parada
	std::string obtenerNombre();

	//Pre:
	//Post: devuelve la latitud a la que se enuentra la parada
	double obtenerLatitud();

	//Pre:
	//Post: devuelve la longitud a la que se encuentra la parada
	double obtenerLongitud();

	//Pre:
	//Post: devuelve la direccion de la parada
	unsigned int obtenerDireccion();

	//Pe:
	//Post: devuelve la ruta de la linea de la parada
	unsigned int obtenerRuta();

	//Pre:
	//Post: devuelve la agencia de la linea de la parada
	unsigned int obtenerAgencia();

	//Pre:
	//Post: devuelve la linea de colectivo que utiliza la parada
	std::string obtenerLinea();

	//Pre:
	//Post: el nombre de la ruta del colectivo
	std::string obtenerNombreDeRuta();

	//Pre:
	//Post: devuelve la descripcion de la ruta
	std::string obtenerDescripcionDeRuta();

	//Pre:
	//Pots: devuelve el tipo de ruta
	unsigned int obtenerTipoDeRuta();


};




#endif /* PARADADECOLECTIVO_H_ */
