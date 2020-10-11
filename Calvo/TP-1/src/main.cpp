
#include "estructuraDeMetrobus.h"
#include "interfaz.h"
#include <string>
#include "lectura.h"

int main() {

	std::string archivoConNotas = "datos/estaciones-de-metrobus.csv";
	//std::string archivoConSecuencia = "datos/salida.txt";

	EstacionMetro estaciones[CANTIDAD_ESTACIONES];
	leerNotas(archivoConNotas, estaciones);
	menu(estaciones);

	//escribirSecuencia(archivoConSecuencia);

	return 0;
}
