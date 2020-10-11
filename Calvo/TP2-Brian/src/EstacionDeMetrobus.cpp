/*
 * EstacionesDeMetrobus.cpp
 *
 *  Created on: 13 oct. 2019
 *      Author: brian
 */

#include "EstacionDeMetrobus.h"
using namespace std;

EstacionDeMetrobus::EstacionDeMetrobus(){
	this->longitud=0;
	this->latitud=0;
	this->id=0;
	this->nombre="";
	this->calle1="";
	this->calle2="";
	this->interseccion="";
	this->lineaSentidoNorte="";
	this->lineaSentidoSur="";
	this->metrobus="";
	this->nombreSentido="";
	this->observaciones="";
}

void EstacionDeMetrobus::asignarDatos(double longitud, double latitud, unsigned int id, std::string nombre,
									  std::string calle1, std::string calle2, std::string interseccion,
									  std::string lineaSentidoNorte, std::string lineaSentidoSur,
									  std::string metrobus, std::string nombreSentido, std::string observaciones){
	this->longitud=longitud;
	this->latitud=latitud;
	this->id=id;
	this->nombre=nombre;
	this->calle1=calle1;
	this->calle2=calle2;
	this->interseccion=interseccion;
	this->lineaSentidoNorte=lineaSentidoNorte;
	this->lineaSentidoSur=lineaSentidoSur;
	this->metrobus=metrobus;
	this->nombreSentido=nombreSentido;
	this->observaciones=observaciones;
}

double EstacionDeMetrobus::obtenerLongitud(){
	return this->longitud;
}

double EstacionDeMetrobus::obtenerLatitud(){
	return this->latitud;
}

unsigned int EstacionDeMetrobus::obtenerId(){
	return this->id;
}

string EstacionDeMetrobus::obtenerNombre(){
	return this->nombre;
}

string EstacionDeMetrobus::obtenerCalle1(){
	return this->calle1;
}

string EstacionDeMetrobus::obtenerCalle2(){
	return this->calle2;
}

string EstacionDeMetrobus::obtenerInterseccion(){
	return this->interseccion;
}

string EstacionDeMetrobus::obtenerLineaSentidoNorte(){
	return this->lineaSentidoNorte;
}

string EstacionDeMetrobus::obtenerLineaSentidoSur(){
	return this->lineaSentidoSur;
}

string EstacionDeMetrobus::obtenerMetrobus(){
	return this->metrobus;
}

string EstacionDeMetrobus::obtenerNombreSentido(){
	return this->nombreSentido;
}

string EstacionDeMetrobus::obtenerObservaciones(){
	return this->observaciones;
}
