/*
 * EstacionesDeFerrocarril.cpp
 *
 *  Created on: 13 oct. 2019
 *      Author: brian
 */

#include "EstacionDeFerrocarril.h"
using namespace std;

EstacionDeFerrocarril::EstacionDeFerrocarril(){
	this->longitud=0;
	this->latitud=0;
	this->id=0;
	this->nombre="";
	this->linea="";
	this->linea2="";
	this->ramal="";
	this->barrio="";
	this->comuna="";
	this->localidad="";
	this->partido="";
}

void EstacionDeFerrocarril::asignarDatos(double longitud, double latitud, unsigned int id, std::string nombre,
										 std::string linea, std::string linea2, std::string ramal,
										 std::string barrio, std::string comuna, std::string localidad,
										 std::string partido){
	this->longitud=longitud;
	this->latitud=latitud;
	this->id=id;
	this->nombre=nombre;
	this->linea=linea;
	this->linea2=linea2;
	this->ramal=ramal;
	this->barrio=barrio;
	this->comuna=comuna;
	this->localidad=localidad;
	this->partido=partido;
}

double EstacionDeFerrocarril::obtenerLongitud(){
	return this->longitud;
}

double EstacionDeFerrocarril::obtenerLatitud(){
	return this->latitud;
}

unsigned int EstacionDeFerrocarril::obtenerId(){
	return this->id;
}

string EstacionDeFerrocarril::obtenerNombre(){
	return this->nombre;
}

string EstacionDeFerrocarril::obtenerLinea(){
	return this->linea;
}

string EstacionDeFerrocarril::obtenerLinea2(){
	return this->linea2;
}

string EstacionDeFerrocarril::obtenerRamal(){
	return this->ramal;
}

string EstacionDeFerrocarril::obtenerBarrio(){
	return this->barrio;
}

string EstacionDeFerrocarril::obtenerComuna(){
	return this->comuna;
}

string EstacionDeFerrocarril::obtenerLocalidad(){
	return this->localidad;
}

string EstacionDeFerrocarril::obtenerPartido(){
	return this->partido;
}


