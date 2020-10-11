/*
 * ParadaDeColectivo.cpp
 *
 *  Created on: 17 oct. 2019
 *      Author: brian
 */

#include "ParadaDeColectivo.h"
using namespace std;

ParadaDeColectivo::ParadaDeColectivo(){

	this->id=0;
	this->codigo=0;
	this->nombre="";
	this->latitud=0;
	this->longitud=0;
	this->direccion=0;
	this->ruta=0;
	this->agencia=0;
	this->linea="";
	this->nombreDeRuta="";
	this->descripcionDeRuta="";
	this->tipoDeRuta=0;
}

void ParadaDeColectivo::agregarDatos(double id, double codigo, std::string nombre, double longitud, double latitud,
					  	  	  	  	 unsigned int direccion, unsigned int ruta, unsigned int agencia, std::string linea,
									 std::string nombreDeRuta, std::string descripcionDeRuta, unsigned int tipoDeRuta){

	this->id=id;
	this->codigo=codigo;
	this->nombre=nombre;
	this->latitud=latitud;
	this->longitud=longitud;
	this->direccion=direccion;
	this->ruta=ruta;
	this->agencia=agencia;
	this->linea=linea;
	this->nombreDeRuta=nombreDeRuta;
	this->descripcionDeRuta=descripcionDeRuta;
	this->tipoDeRuta=tipoDeRuta;

}

double ParadaDeColectivo::obtenerId(){
	return this->id;
}

double ParadaDeColectivo::obtenerCodigo(){
	return this->codigo;
}

string ParadaDeColectivo::obtenerNombre(){
	return this->nombre;
}

double ParadaDeColectivo::obtenerLatitud(){
	return this->latitud;
}

double ParadaDeColectivo::obtenerLongitud(){
	return this->longitud;
}

unsigned int ParadaDeColectivo::obtenerDireccion(){
	return this->direccion;
}

unsigned int ParadaDeColectivo::obtenerRuta(){
	return this->ruta;
}

unsigned int ParadaDeColectivo::obtenerAgencia(){
	return this->agencia;
}

string ParadaDeColectivo::obtenerLinea(){
	return this->linea;
}

string ParadaDeColectivo::obtenerNombreDeRuta(){
	return this->nombreDeRuta;
}

string ParadaDeColectivo::obtenerDescripcionDeRuta(){
	return this->descripcionDeRuta;
}

unsigned int ParadaDeColectivo::obtenerTipoDeRuta(){
	return this->tipoDeRuta;
}

