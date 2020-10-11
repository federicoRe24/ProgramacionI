/*
 *
 * Camino.cpp
 *
 *  Created on: 26 oct. 2019
 *      Author: martin
 */

#include "Camino.h"
#include "Estaciones.h"
#include <iostream>


Camino::Camino(){
	this->estacionDeOrigen=NULL;
	this->estacionDeDestino=NULL;
	this->estacionDeConexion1=NULL;
	this->estacionDeConexion2=NULL;
}

void Camino::setEstacionOrigen(Estaciones estacionOrigen){
	this->estacionDeOrigen=new Estaciones;
	this->estacionDeOrigen->asignarDatos(estacionOrigen);
}
void Camino::setEstacionDestino(Estaciones estacionDestino){
	this->estacionDeDestino=new Estaciones;
	this->estacionDeDestino->asignarDatos(estacionDestino);
}
void Camino::setEstacionDeConexion(Estaciones estacionDeConexion1, Estaciones estacionDeConexion2)
{
	if (this->estacionDeConexion1){
		this->estacionDeConexion1->asignarDatos(estacionDeConexion1);
		this->estacionDeConexion2->asignarDatos(estacionDeConexion2);
	}
	else {
		this->estacionDeConexion1=new Estaciones;
		this->estacionDeConexion2=new Estaciones;
		this->estacionDeConexion1->asignarDatos(estacionDeConexion1);
		this->estacionDeConexion2->asignarDatos(estacionDeConexion2);
	}
}
void Camino::explicarRecorrido(){
//Aca iria el bitmap
	if (this->estacionDeConexion1){
		std::cout<<"Ir hasta la estacion "<<this->estacionDeOrigen->obtenerNombre()<<", tomate el "<<estacionDeOrigen->obtenerTransporte()<<" "<<this->estacionDeOrigen->obtenerLinea()
				<<" y bajate en "<<this->estacionDeConexion1->obtenerNombre()<<". Anda hasta "<<this->estacionDeConexion2->obtenerNombre()<<" subite al "<<
				estacionDeOrigen->obtenerTransporte()<<" "<<this->estacionDeConexion2->obtenerLinea()<<", y bajate en "<<this->estacionDeDestino->obtenerNombre()<<std::endl;
	}
	else {
		std::cout<<"Ir hasta la estacion "<<this->estacionDeOrigen->obtenerNombre()<<", tomate el "<<estacionDeOrigen->obtenerTransporte()<<" "<<this->estacionDeDestino->obtenerLinea()
				<<" y bajate en "<<this->estacionDeDestino->obtenerNombre()<< std::endl;
	}

}
Estaciones* Camino::obtenerOrigen(){
	return this->estacionDeOrigen;
}
Estaciones* Camino::ObtenerDestino(){
	return this->estacionDeDestino;
}
Estaciones* Camino::obtenerConexion1(){
	return this->estacionDeConexion1;
}
Estaciones* Camino::obtenerConexion2(){
	return this->estacionDeConexion2;
}
