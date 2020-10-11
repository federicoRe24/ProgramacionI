/*
 * Garaje.cpp
 *
 *  Created on: 16 oct. 2019
 *      Author: brian
 */

#include "Garaje.h"
#include<iostream>
using namespace std;

Garaje::Garaje(){

	this->longitud=0;
	this->latitud=0;
	this->smp="";
	this->calle="";
	this->altura=0;
	this->tipo1="";
	this->tipo2="";
	this->pisos=0;
	this->nombre="";
	this->barrio="";
	this->comuna="";
	this->codigoPostal=0;
	this->codigoPostalArgentino="";
}

void Garaje::agregarDatos(double longitud, double latitud, std::string smp, std::string calle, unsigned int altura,
					  	  std::string tipo1, std::string tipo2, unsigned int pisos, std::string nombre,
						  std::string barrio, std::string comuna, unsigned int codigoPostal,
						  std::string codigoPostalArgentino){

	this->longitud=longitud;
	this->latitud=latitud;
	this->smp=smp;
	this->calle=calle;
	this->altura=altura;
	this->tipo1=tipo1;
	this->tipo2=tipo2;
	this->pisos=pisos;
	this->nombre=nombre;
	this->barrio=barrio;
	this->comuna=comuna;
	this->codigoPostal=codigoPostal;
	this->codigoPostalArgentino=codigoPostalArgentino;
}

double Garaje::obtenerLongitud(){
	return this->longitud;
}

double Garaje::obtenerLatitud(){
	return this->latitud;
}

string Garaje::obtenerSmp(){
	return this->smp;
}

string Garaje::obtenerCalle(){
	return this->calle;
}

unsigned int Garaje::obtenerAltura(){
	return this->altura;
}

string Garaje::obtenerTipo1(){
	return this->tipo1;
}

string Garaje::obtenerTipo2(){
	return this->tipo2;
}

unsigned int Garaje::obtenerPisos(){
	return this->pisos;
}

string Garaje::obtenerNombre(){
	return this->nombre;
}

string Garaje::obtenerBarrio(){
	return this->barrio;
}

string Garaje::obtenerComuna(){
	return this->comuna;
}

unsigned int Garaje::obtenerCodigoPostal(){
	return this->codigoPostal;
}

string Garaje::obtenerCodigoPostalArgentino(){
	return this->codigoPostalArgentino;
}

void Garaje::mostrarGaraje(){

	cout<<"Nombre: "<<this->obtenerNombre()<<endl;
	cout<<"Ubicacion: "<<this->obtenerCalle()<<" "<<this->obtenerAltura()<<", "<<this->obtenerBarrio()<<endl;
	cout<< "Comuna: "<<this->obtenerComuna()<< ", "<< "C.P.: "<<this->obtenerCodigoPostal()<<endl;
}


