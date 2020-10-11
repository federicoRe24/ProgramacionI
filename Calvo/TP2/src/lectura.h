#ifndef LECTURA_H_
#define LECTURA_H_

#include "Estaciones.h"
#include "Garaje.h"
#include "Lista.h"
#include <string>

void leerArchivoDeEstacionesDeFerrocarril(std::string rutaEntrada, Lista<Estaciones>* estacionesDeFerrocarril);
void leerArchivoDeEstacionDeMetrobus(std::string rutaEntrada, Lista<Estaciones>* estacionesDeMetrobus);
void leerArchivoDeEstacionDeSubte(std::string rutaEntrada, Lista<Estaciones>* estacionesDeSubte);
void leerArchivoDeGaraje(std::string rutaEntrada, Lista<Garaje>* listaDeGarajes);
void leerArchivoDeParadaDeColectivo(std::string rutaEntrada, Lista<Estaciones>* paradasDeColectivo);



#endif /* LECTURA_H_ */
