/*
 * EstacionesDeSubte.cpp
 *
 *  Created on: 14 oct. 2019
 *      Author: brian
 */

#include "EstacionDeSubte.h"
using namespace std;

EstacionDeSubte::EstacionDeSubte(){
	this->longitud=0;
	this->latitud=0;
	this->id=0;
	this->linea="";
	this->estacion="";
	this->numeroDeBoca=0;
	this->destino="";
	this->combinacion="";
	this->cerradoElFinDeSemana="";
	this->escaleraFija="";
	this->escaleraMecanica="";
	this->ascensor="";
	this->rampa="";
	this->salvaescalera="";
	this->calle="";
	this->altura=0;
	this->calle2="";
	this->barrio="";
	this->comuna="";
	this->observaciones="";
	this->objeto="";
	this->domicilioNormalizado="";
	this->domicilioOriginal="";
}

void EstacionDeSubte::asignarDatos(double longitud, double latitud, unsigned int id, std::string linea, std::string estacion,
					  unsigned int numeroDeBoca, std::string destino, std::string combinacion,
					  std::string cerradoElFinDeSemana, std::string escaleraFija, std::string escaleraMecanica,
					  std::string ascensor, std::string rampa, std::string salvaescalera, std::string calle,
					  unsigned int altura, std::string calle2, std::string barrio, std::string comuna,
					  std::string observaciones, std::string objeto, std::string domicilioNormalizado,
					  std::string domicilioOriginal){

	this->longitud=longitud;
	this->latitud=latitud;
	this->id=id;
	this->linea=linea;
	this->estacion=estacion;
	this->numeroDeBoca=numeroDeBoca;
	this->destino=destino;
	this->combinacion=combinacion;
	this->cerradoElFinDeSemana=cerradoElFinDeSemana;
	this->escaleraFija=escaleraFija;
	this->escaleraMecanica=escaleraMecanica;
	this->ascensor=ascensor;
	this->rampa=rampa;
	this->salvaescalera=salvaescalera;
	this->calle=calle;
	this->altura=altura;
	this->calle2=calle2;
	this->barrio=barrio;
	this->comuna=comuna;
	this->observaciones=observaciones;
	this->objeto=objeto;
	this->domicilioNormalizado=domicilioNormalizado;
	this->domicilioOriginal=domicilioOriginal;

}



	double EstacionDeSubte::obtenerLongitud(){
		return this->longitud;
	}

	double EstacionDeSubte::obtenerLatitud(){
		return this->latitud;
	}

	unsigned int EstacionDeSubte::obtenerId(){
		return this->id;
	}

	std::string EstacionDeSubte::obtenerLinea(){
		return this->linea;
	}

	std::string EstacionDeSubte::obtenerEstacion(){
		return this->estacion;
	}

	unsigned int EstacionDeSubte::obtenerNumeroDeBoca(){
		return this->numeroDeBoca;
	}

	std::string EstacionDeSubte::obtenerDestino(){
		return this->destino;
	}

	std::string EstacionDeSubte::obtenerCombinacion(){
		return this->combinacion;
	}

	std::string EstacionDeSubte::obtenerCerradoElFinDeSemana(){
		return this->cerradoElFinDeSemana;
	}

	std::string EstacionDeSubte::obtenerEscaleraFija(){
		return this->escaleraFija;
	}

	std::string EstacionDeSubte::obtenerEscaleraMecanica(){
		return this->escaleraMecanica;
	}

	std::string EstacionDeSubte::obtenerAscensor(){
		return this->ascensor;
	}

	std::string EstacionDeSubte::obtenerRampa(){
		return this->rampa;
	}

	std::string EstacionDeSubte::obtenerSalvaescalera(){
		return this->salvaescalera;
	}

	std::string EstacionDeSubte::obtenerCalle(){
		return this->calle;
	}

	unsigned int EstacionDeSubte::obtenerAltura(){
		return this->altura;
	}

	std::string EstacionDeSubte::obtenerCalle2(){
		return this->calle2;
	}

	std::string EstacionDeSubte::obtenerBarrio(){
		return this->barrio;
	}

	std::string EstacionDeSubte::obtenerComuna(){
		return this->comuna;
	}

	std::string EstacionDeSubte::obtenerObservaciones(){
		return this->observaciones;
	}

	std::string EstacionDeSubte::obtenerObjeto(){
		return this->objeto;
	}

	std::string EstacionDeSubte::obtenerDomicilioNormalizado(){
		return this->domicilioNormalizado;
	}

	std::string EstacionDeSubte::obtenerDomicilioOriginal(){
		return this->domicilioOriginal;
	}



