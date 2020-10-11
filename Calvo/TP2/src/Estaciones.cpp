/*
 * Estaciones.cpp
 *
 *  Created on: 26 oct. 2019
 *      Author: martin
 */


#include "Estaciones.h"
using namespace std;

Estaciones::Estaciones(){
	this->transporte="";
	this->longitud=0;
	this->latitud=0;
	this->id=0;
	this->nombre="";
	this->linea="";
	this->linea2="";
	this->ramal="";
}


void Estaciones::asignarDatos(std::string transporte, double longitud, double latitud, unsigned int id,std::string nombre,
								std::string linea,std::string linea2, std::string ramal){
	this->transporte=transporte;
	this->longitud=longitud;
	this->latitud=latitud;
	this->id=id;
	this->nombre=nombre;
	this->linea=linea;
	this->linea2=linea2;
	this->ramal=ramal;
}
void Estaciones::asignarDatos(Estaciones estacionCopia){
	this->transporte=estacionCopia.obtenerTransporte();
	this->longitud=estacionCopia.obtenerLongitud();
	this->latitud=estacionCopia.obtenerLatitud();
	this->id=estacionCopia.obtenerId();
	this->nombre=estacionCopia.obtenerNombre();
	this->linea=estacionCopia.obtenerLinea();
	this->linea2=estacionCopia.obtenerLinea2();
	this->ramal=estacionCopia.obtenerRamal();
}

std::string Estaciones::obtenerTransporte(){
	return this->transporte;
}

double Estaciones::obtenerLongitud(){
	return this->longitud;
}

double Estaciones::obtenerLatitud(){
	return this->latitud;
}

unsigned int Estaciones::obtenerId(){
	return this->id;
}
std::string Estaciones::obtenerNombre(){
	return this->nombre;
}

string Estaciones::obtenerLinea(){
	return this->linea;
}

string Estaciones::obtenerLinea2(){
	return this->linea2;
}

string Estaciones::obtenerRamal(){
	return this->ramal;
}




