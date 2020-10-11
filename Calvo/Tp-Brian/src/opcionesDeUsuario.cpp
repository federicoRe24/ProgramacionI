/*
 * opcionesDeUsuario.cpp
 *
 *  Created on: 21 sep. 2019
 *      Author: brian
 */

#include "opcionesDeUsuario.h"
#include <iostream>
using namespace std;

void menuDeUsuario(EstacionesDeMetrobus array[]){
	int opcion;
	mostrarMensaje(MENSAJE1);
	cin>>opcion;
	switch(opcion){
	case 1: filtrarPorLongitud(array);
			menuDeUsuario(array);
			break;
	case 2: filtrarPorLatitud(array);
			menuDeUsuario(array);
			break;
	case 3: filtrarPorId(array);
			menuDeUsuario(array);
			break;
	case 4: mostrarMensaje(MENSAJE_DE_DESPEDIDA);
			break;
	default: mostrarMensaje(MENSAJE2);
			 menuDeUsuario(array);
	}
}

void mostrarMensaje(string mensaje){
	cout<<mensaje<<endl;
}

void filtrarPorLongitud(EstacionesDeMetrobus array[]){
	EstacionesDeMetrobus filtrado[MAXIMO_FILAS];
	int contador = 0;
	double inicioDeRango;
	double finalDeRango;
	mostrarMensaje(MENSAJE3);
	cin>> inicioDeRango;
	mostrarMensaje(MENSAJE4);
	cin>> finalDeRango;
	for(int i=0;i<MAXIMO_FILAS;i++){
		if((array[i].longitud>=inicioDeRango)&&(array[i].longitud<=finalDeRango)){
			filtrado[contador] = array[i];
			contador++;
		}
	}
	cout<< "Se encontraron "<<contador<< " casos"<<endl;
	if(contador>0){
		impresionDeDatosFiltrados(filtrado, contador);
	}
}

void mostrarCasosEncontrados(EstacionesDeMetrobus array[], int contador){
	for(int i=0;i<contador;i++){
		mostrarEstacion(array[i]);
	}
}

void impresionDeDatosFiltrados(EstacionesDeMetrobus array[],int contador){
	int opcion;
	mostrarMensaje(MENSAJE5);
	mostrarMensaje(MENSAJE6);
	cin>> opcion;
	switch(opcion){
	case 1: mostrarCasosEncontrados(array, contador);
			break;
	case 2: break;
	default: mostrarMensaje(MENSAJE2);
			 impresionDeDatosFiltrados(array,contador);
	}
}

void filtrarPorLatitud(EstacionesDeMetrobus array[]){
	EstacionesDeMetrobus filtrado[MAXIMO_FILAS];
	int contador = 0;
	double inicioDeRango;
	double finalDeRango;
	mostrarMensaje(MENSAJE3);
	cin>> inicioDeRango;
	mostrarMensaje(MENSAJE4);
	cin>> finalDeRango;
	for(int i=0;i<MAXIMO_FILAS;i++){
		if((array[i].latitud>=inicioDeRango)&&(array[i].latitud<=finalDeRango)){
			filtrado[contador] = array[i];
			contador++;
		}
	}
	cout<< "Se encontraron "<<contador<< " casos"<<endl;
	if(contador>0){
		impresionDeDatosFiltrados(filtrado, contador);
	}
}

void filtrarPorId(EstacionesDeMetrobus array[]){
	EstacionesDeMetrobus estacion;
	int contador=0;
	int id;
	mostrarMensaje(MENSAJE7);
	cin>>id;
	for(int i=0;i<MAXIMO_FILAS;i++){
		if(array[i].id==id){
			estacion=array[i];
			contador++;
		}
	}
	cout<< "Se encontraron "<<contador<<" casos"<<endl;
	if(contador>0){
		mostrarEstacion(estacion);
	}
}




