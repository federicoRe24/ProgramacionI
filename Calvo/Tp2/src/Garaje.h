/*
 * Garaje.h
 *
 *  Created on: 14 oct. 2019
 *      Author: brian
 */

#ifndef GARAJE_H_
#define GARAJE_H_

#include<string>

class Garaje{

private:

	double longitud;
	double latitud;
	std::string smp;
	std::string calle;
	unsigned int altura;
	std::string tipo1;
	std::string tipo2;
	unsigned int pisos;
	std::string nombre;
	std::string barrio;
	std::string comuna;
	unsigned int codigoPostal;
	std::string codigoPostalArgentino;

public:

	//Pre:
	//Post: Constructor. Instancia la clase y la deja lista para ser utilizada
	Garaje();

	//Pre:
	//Post: agrega los datos pasados por parametro a los atributos correspondientes de la clase
	void agregarDatos(double longitud, double latitud, std::string smp, std::string calle, unsigned int altura,
					  std::string tipo1, std::string tipo2, unsigned int pisos, std::string nombre,
					  std::string barrio, std::string comuna, unsigned int codigoPostal,
					  std::string codigoPostalArgentino);

	//Pre_
	//Post: devuelve la longitud en la que se encuentra el garaje
	double obtenerLongitud();

	//Pre:
	//Post:devuelve la latitud en la que se encuentra el garaje
	double obtenerLatitud();

	//Pre:
	//Post: devuelve la seccion manzana parcela en la que esta ubicado el garaje
	std::string obtenerSmp();

	//Pre:
	//Post: devuelve la calle en la que se encuentra el garaje
	std::string obtenerCalle();

	//Pre:
	//Post: devuelve la altura de la calle en la que se encuentra el garaje
	unsigned int obtenerAltura();

	//Pre:
	//Post: devuelve la abreviacion del tipo de uso
	std::string obtenerTipo1();

	//Pre:
	//Post: devuelve el nombre completo del tipo de uso
	std::string obtenerTipo2();

	//Pre:
	//Post: devuelve la cantidad de pisos que posee el garaje
	unsigned int obtenerPisos();

	//Pre:
	//Post: devuelve el nombre del garaje
	std::string obtenerNombre();

	//Pre:
	//Post: devuelve el barrio en el que se encuentra el garaje
	std::string obtenerBarrio();

	//Pre:
	//Post: devuelve la comuna en la que se encuentra el garaje
	std::string obtenerComuna();

	//Pre:
	//Post: devuelve el codigo postal del garaje
	unsigned int obtenerCodigoPostal();

	//Pre:
	//Post: devuelve el codigo postal argentino del garaje
	std::string obtenerCodigoPostalArgentino();

	//Pre:
	//Post: muestra por pantalla los datos del garaje
	void mostrarGaraje();


};


#endif /* GARAJE_H_ */
