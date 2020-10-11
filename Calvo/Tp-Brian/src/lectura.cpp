
#include "lectura.h"
#include "estaciones.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

void leerArchivo(std::string rutaEntrada, EstacionesDeMetrobus array[]) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* lee la primera línea completa */
	std::string titulo;
	std::getline(entrada, titulo);

	int contador=0;
	EstacionesDeMetrobus estacion;

	/* lee el resto del archivo */
	while (! entrada.eof()&&contador<MAXIMO_FILAS) {
		std::string longitud;
		double longitudConvertida;
		std::string latitud;
		double latitudConvertida;
		std::string id;
		int idConvertida;
		std::string nombre;
		std::string calle1;
		std::string calle2;
		std::string interseccion;
		std::string lineaSentidoNorte;
		std::string lineaSentidoSur;
		std::string metrobus;
		std::string nombreSentido;
		std::string observaciones;

		/* intenta leer un número de longitud y detiene la lectura cuando hay una coma */
		std::getline(entrada,longitud,',');

		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {

			/* lee los demas elementos del archivo */
			std::getline(entrada,latitud,',');
			std::getline(entrada,id,',');
			std::getline(entrada,nombre,',');
			std::getline(entrada,calle1,',');
			std::getline(entrada,calle2,',');
			std::getline(entrada,interseccion,',');
			std::getline(entrada,lineaSentidoNorte,',');
			std::getline(entrada,lineaSentidoSur,',');
			std::getline(entrada,metrobus,',');
			std::getline(entrada,nombreSentido,',');
			std::getline(entrada,observaciones);
		}
		longitudConvertida = strtod(longitud.c_str(),NULL);//funcion que convierte una representacion en string de un numero flotante a un dato de
														   //tipo double
		latitudConvertida = strtod(latitud.c_str(),NULL);
		idConvertida = atoi(id.c_str());
		asignarValores(estacion,longitudConvertida, latitudConvertida, idConvertida,
					   nombre,calle1, calle2,interseccion,
					   lineaSentidoNorte, lineaSentidoSur,metrobus, nombreSentido,
					   observaciones);

		array[contador]= estacion;
		contador++;
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
}


