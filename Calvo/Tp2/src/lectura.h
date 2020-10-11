#ifndef LECTURA_H_
#define LECTURA_H_

#include "EstacionDeMetrobus.h"
#include "EstacionDeFerrocarril.h"
#include "EstacionDeSubte.h"
#include "Garaje.h"
#include "ParadaDeColectivo.h"
#include "Lista.h"
#include <string>

void leerArchivoDeEstacionDeFerrocarril(std::string rutaEntrada, Lista<EstacionDeFerrocarril> estacionesDeFerrocarril);
void leerArchivoDeEstacionDeMetrobus(std::string rutaEntrada, Lista<EstacionDeMetrobus> estacionesDeMetrobus);
void leerArchivoDeEstacionDeSubte(std::string rutaEntrada, Lista<EstacionDeSubte> estacionesDeSubte);
void leerArchivoDeGaraje(std::string rutaEntrada, Lista<Garaje> listaDeGarajes);
void leerArchivoDeParadaDeColectivo(std::string rutaEntrada, Lista<ParadaDeColectivo> paradasDeColectivo);



#endif /* LECTURA_H_ */
