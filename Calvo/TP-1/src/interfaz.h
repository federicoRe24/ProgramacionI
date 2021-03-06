#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "estructuraDeMetrobus.h"
#include <string>

void menu(EstacionMetro array[]);

void mostrarCasos(EstacionMetro array[],int contador);

void filtrarPorLongitud(EstacionMetro array[]);

void mostrarCasosEncontrados(EstacionMetro array[], int contador);

void filtrarPorLatitud(EstacionMetro array[]);

void filtrarPorId(EstacionMetro array[]);

#endif /* INTERFAZ_H_ */
