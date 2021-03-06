
#include "lectura.h"
#include "estructuraDeMetrobus.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

void leerNotas(std::string rutaEntrada, EstacionMetro estaciones[]) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* Crea el array de structs donde se almacenarán los datos */
	int i = 0;

	/* lee la primera línea completa */
	std::string titulo;
	std::getline(entrada, titulo);
	std::cout << "*** " << titulo << " ***" << std::endl;


	/* lee el resto del archivo */
	while (! entrada.eof()) {
		std::string longitud;
		double longitudDouble;
		std::string latitud;
		double latitudDouble;
		std::string id;
		int idEntero;
		std::string nombre;
		std::string calle1;
		std::string calle2;
		std::string interseccion;
		std::string lineaSentidoNorte;
		std::string lineaSentidoSur;
		std::string metrobus;
		std::string nombreSentido;
		std::string observaciones;


		/* intenta leer un número de padrón */
		std::getline(entrada,longitud,',');


		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {

			/* lee el nombre y la nota */

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

			//Parseo un numero flotante representado como string a un dato de tipo double
			longitudDouble = strtod(longitud.c_str(),NULL);
			latitudDouble = strtod(latitud.c_str(),NULL);
			//Parseo un numero entero representado como string a un dato de tipo entero
			idEntero = atoi(id.c_str());

			asignarMetrobus(estaciones[i], longitudDouble, latitudDouble, idEntero, nombre, calle1, calle2, interseccion, lineaSentidoNorte, lineaSentidoSur,
					metrobus, nombreSentido, observaciones);

			i++;
		}
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
}


