/*
 * BocasDeSubte.h
 *
 *  Created on: 14 oct. 2019
 *      Author: brian
 */

#ifndef ESTACIONDESUBTE_H_
#define ESTACIONDESUBTE_H_

#include<string>

/*UNA ESTACION DE SUBTE ES UNA CLASE QUE ALMACENA DATOS SOBRE LA UBICACION, IDENTIFICACION Y LAS HERRAMIENTAS QUE
 * POSEE UNA ESTACION DE SUBTE DE LA CIUDAD DE BUENOS AIRES, COMO POR EJEMEPLO LA EXISTENCIA DE ASCENSOR*/

class EstacionDeSubte{

private:

	double longitud;
	double latitud;
	unsigned int id;
	std::string linea;
	std::string estacion;
	unsigned int numeroDeBoca;
	std::string destino;
	std::string combinacion;
	std::string cerradoElFinDeSemana;
	std::string escaleraFija;
	std::string escaleraMecanica;
	std::string ascensor;
	std::string rampa;
	std::string salvaescalera;
	std::string calle;
	unsigned int altura;
	std::string calle2;
	std::string barrio;
	std::string comuna;
	std::string observaciones;
	std::string objeto;
	std::string domicilioNormalizado;
	std::string domicilioOriginal;

public:

	//Pre:
	//Post: Constructor. Instancia la clase y la deja lista para ser utilizada
	EstacionDeSubte();

	//Pre:
	//Post: agrega los datos pasados por parametro a cada atributo correspondiente de la clase
	void asignarDatos(double longitud, double latitud, unsigned int id, std::string linea, std::string estacion,
					  unsigned int numeroDeBoca, std::string destino, std::string combinacion,
					  std::string cerradoElFinDeSemana, std::string escaleraFija, std::string escaleraMecanica,
					  std::string ascensor, std::string rampa, std::string salvaescalera, std::string calle, unsigned int altura,
					  std::string calle2, std::string barrio, std::string comuna, std::string observaciones,
					  std::string objeto, std::string domicilioNormalizado, std::string domicilioOriginal);

	//Pre:
	//Post: devuelve la longitud donde se encuetra la boca de subte
	double obtenerLongitud();

	//Pre:
	//Post: devuelve la latitud donde se encuentra la boca de subte
	double obtenerLatitud();

	//Pre:
	//Post: devuelva la id de la boca de subte
	unsigned int obtenerId();

	//Pre:
	//Post: devuelve la linea de subte
	std::string obtenerLinea();

	//Pre:
	//Post: devuelve la estacion de subte
	std::string obtenerEstacion();

	//Pre:
	//Post: devuelve el numero de bocas de la estacion de subte
	unsigned int obtenerNumeroDeBoca();

	//Pre:
	//Post: devuelve los destinos del la estacion de subte
	std::string obtenerDestino();

	//Pre:
	//Post: deveulve las combinaciones de la estacion
	std::string obtenerCombinacion();

	//Pre:
	//Post: devuelve si la boca de la estacion esta cerrada el fin de semana
	std::string obtenerCerradoElFinDeSemana();

	//Pre:
	//Post: devuelve si la estacion de subte tiene escalera fija
	std::string obtenerEscaleraFija();

	//Pre:
	//Post: devuelve si la estacion de subte cuenta con escalera mecanica
	std::string obtenerEscaleraMecanica();

	//Pre:
	//Post: devuelve si la estacion de subte posee ascensor
	std::string obtenerAscensor();

	//Pre:
	//Post: devuelve si la estacion de subte tiene rampa
	std::string obtenerRampa();

	//Pre:
	//Post: devuelve si la estacion de subte posee salvaescalera
	std::string obtenerSalvaescalera();

	//Pre:
	//Post: devuelve la calle en la que se encuentra la boca de la estacion
	std::string obtenerCalle();

	//Pre:
	//Post: devuelve la altura a la que se encuentra la boca de la estacion
	unsigned int obtenerAltura();

	//Pre:
	//Post: devueve la calle que cruza a la calle principal
	std::string obtenerCalle2();

	//Pre:
	//Post: devuelve el barrio en el que se encuentra la boca de subte
	std::string obtenerBarrio();

	//Pre:
	//Post: devuelve la comuna en la que se encuentra la boca de subte
	std::string obtenerComuna();

	//Pe:
	//Post: devuelve las observaciones que hay sobre la boca de subte
	std::string obtenerObservaciones();

	//Pre:
	//Post: devuelve el elemento mapeado
	std::string obtenerObjeto();

	//Pre:
	//Post: devuelve el domicilio normalizado
	std::string obtenerDomicilioNormalizado();

	//Pre:
	//Post: devuelve el domicilio original de la base
	std::string obtenerDomicilioOriginal();

};



#endif /* ESTACIONDESUBTE_H_ */
