
#include "lectura.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

void leerArchivoDeEstacionDeMetrobus(std::string rutaEntrada, Lista<Estaciones>* estacionesDeMetrobus) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* lee la primera línea completa */
	std::string titulo;
	std::getline(entrada, titulo);

	Estaciones estacion;

	/* lee el resto del archivo */
	while (! entrada.eof()) {
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
		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {
			longitudConvertida = strtod(longitud.c_str(),NULL);//funcion que convierte una representacion en string de un numero flotante a un dato de
														   //tipo double
			latitudConvertida = strtod(latitud.c_str(),NULL);
			idConvertida = atoi(id.c_str());
			estacion.asignarDatos("Metrobus",longitudConvertida, latitudConvertida, idConvertida,nombre, lineaSentidoNorte, lineaSentidoSur, nombreSentido);
			estacionesDeMetrobus->agregar(estacion);
		}
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
}


void leerArchivoDeEstacionesDeFerrocarril(std::string rutaEntrada,Lista<Estaciones>* estacionesDeFerrocarril) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* lee la primera línea completa */
	std::string titulo;
	std::getline(entrada, titulo);

	Estaciones estacion;

	/* lee el resto del archivo */
	while (! entrada.eof()) {
		std::string longitud;
		double longitudConvertida;
		std::string latitud;
		double latitudConvertida;
		std::string id;
		int idConvertida;
		std::string nombre;
		std::string linea;
		std::string linea2;
		std::string ramal;
		std::string barrio;
		std::string comuna;
		std::string localidad;
		std::string partido;

		/* intenta leer un número de longitud y detiene la lectura cuando hay una coma */
		std::getline(entrada,longitud,',');
		/* lee los demas elementos del archivo */
		std::getline(entrada,latitud,',');
		std::getline(entrada,id,',');
		std::getline(entrada,nombre,',');
		std::getline(entrada,linea,',');
		std::getline(entrada,linea2,',');
		std::getline(entrada,ramal,',');
		std::getline(entrada,barrio,',');
		std::getline(entrada,comuna,',');
		std::getline(entrada,localidad,',');
		std::getline(entrada,partido);
		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {
			longitudConvertida = strtod(longitud.c_str(),NULL);//funcion que convierte una representacion en string de un numero flotante a un dato de
														   //tipo double
			latitudConvertida = strtod(latitud.c_str(),NULL);
			idConvertida = atoi(id.c_str());
			estacion.asignarDatos("Tren",longitudConvertida, latitudConvertida, idConvertida,
					   	   	  	  nombre, linea, linea2,ramal);
			estacionesDeFerrocarril->agregar(estacion);
		}
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();

}

void leerArchivoDeEstacionDeSubte(std::string rutaEntrada, Lista<Estaciones>* estacionesDeSubte) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* lee la primera línea completa */
	std::string titulo;
	std::getline(entrada, titulo);

	Estaciones subte;

	/* lee el resto del archivo */
	while (! entrada.eof()) {
		std::string longitud;
		double longitudConvertida;
		std::string latitud;
		double latitudConvertida;
		std::string id;
		int idConvertida;
		std::string linea;
		std::string estacion;
		std::string numeroDeBoca;
		std::string numeroDeBocaConvertida ;
		std::string destino;
		std::string combinacion;
		std::string cerradoElFinDeSemana;
		std::string escaleraFija;
		std::string escaleraMecanica;
		std::string ascensor;
		std::string rampa;
		std::string salvaescalera;
		std::string calle;
		std::string altura;
		std::string alturaConvertida;
		std::string calle2;
		std::string barrio;
		std::string comuna;
		std::string observaciones;
		std::string objeto;
		std::string domicilioNormalizado;
		std::string domicilioOriginal;

		/* intenta leer un número de longitud y detiene la lectura cuando hay una coma */
		std::getline(entrada,longitud,',');
		/* lee los demas elementos del archivo */
		std::getline(entrada,latitud,',');
		std::getline(entrada,id,',');
		std::getline(entrada,linea,',');
		std::getline(entrada,estacion,',');
		std::getline(entrada,numeroDeBoca,',');
		std::getline(entrada,destino,',');
		std::getline(entrada,combinacion,',');
		std::getline(entrada,cerradoElFinDeSemana,',');
		std::getline(entrada,escaleraFija,',');
		std::getline(entrada,escaleraMecanica,',');
		std::getline(entrada,ascensor,',');
		std::getline(entrada,rampa,',');
		std::getline(entrada,salvaescalera,',');
		std::getline(entrada,calle,',');
		std::getline(entrada,altura,',');
		std::getline(entrada,calle2,',');
		std::getline(entrada,barrio,',');
		std::getline(entrada,comuna,',');
		std::getline(entrada,observaciones,',');
		std::getline(entrada,objeto,',');
		std::getline(entrada,domicilioNormalizado,',');
		std::getline(entrada,domicilioOriginal);
		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {

			longitudConvertida = strtod(longitud.c_str(),NULL);//funcion que convierte una representacion en string de un numero flotante a un dato de
															   //tipo double
			latitudConvertida = strtod(latitud.c_str(),NULL);
			idConvertida = atoi(id.c_str());
			subte.asignarDatos("Subte",longitudConvertida,latitudConvertida, idConvertida,estacion, linea, combinacion,destino);

			estacionesDeSubte->agregar(subte);
		}
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
}

void leerArchivoDeGaraje(std::string rutaEntrada, Lista<Garaje>* listaDeGarajes) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* lee la primera línea completa */
	std::string titulo;
	std::getline(entrada, titulo);

	Garaje garaje;

	/* lee el resto del archivo */
	while (! entrada.eof()) {
		std::string longitud;
		double longitudConvertida;
		std::string latitud;
		double latitudConvertida;
		std::string smp;
		std::string calle;
		std::string altura;
		unsigned int alturaConvertida;
		std::string tipo1;
		std::string tipo2;
		std::string pisos;
		unsigned int pisosConvertido;
		std::string nombre;
		std::string barrio;
		std::string comuna;
		std::string codigoPostal;
		unsigned int codigoPostalConvertido;
		std::string codigoPostalArgentino;

		/* intenta leer un número de longitud y detiene la lectura cuando hay una coma */
		std::getline(entrada,longitud,',');
		/* lee los demas elementos del archivo */
		std::getline(entrada,latitud,',');
		std::getline(entrada,smp,',');
		std::getline(entrada,calle,',');
		std::getline(entrada,altura,',');
		std::getline(entrada,tipo1,',');
		std::getline(entrada,tipo2,',');
		std::getline(entrada,pisos,',');
		std::getline(entrada,nombre,',');
		std::getline(entrada,barrio,',');
		std::getline(entrada,comuna,',');
		std::getline(entrada,codigoPostal,',');
		std::getline(entrada,codigoPostalArgentino);
		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {
			longitudConvertida = strtod(longitud.c_str(),NULL);//funcion que convierte una representacion en string de un numero flotante a un dato de
															   //tipo double
			latitudConvertida = strtod(latitud.c_str(),NULL);
			alturaConvertida = atoi(altura.c_str());
			pisosConvertido = atoi(pisos.c_str());
			codigoPostalConvertido= atoi(codigoPostal.c_str());
			garaje.agregarDatos(longitudConvertida, latitudConvertida, smp, calle, alturaConvertida, tipo1, tipo2,
								pisosConvertido, nombre, barrio, comuna, codigoPostalConvertido, codigoPostalArgentino);

			listaDeGarajes->agregar(garaje);
		}
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
}

void leerArchivoDeParadaDeColectivo(std::string rutaEntrada, Lista<Estaciones>* paradasDeColectivo) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	/* lee la primera línea completa */
	std::string titulo;
	std::getline(entrada, titulo);
	Estaciones paradaDeColectivo;

	/* lee el resto del archivo */
	while (! entrada.eof()) {
		std::string id;
		double idConvertido;
		std::string codigo;
		std::string nombre;
		std::string latitud;
		double latitudConvertida;
		std::string longitud;
		double longitudConvertida;
		std::string direccion;
		std::string ruta;
		std::string agencia;
		std::string linea;
		std::string nombreDeRuta;
		std::string descripcionDeRuta;
		std::string tipoDeRuta;

		/* intenta leer un número de longitud y detiene la lectura cuando hay una coma */
		std::getline(entrada,id,',');
		/* lee los demas elementos del archivo */
		std::getline(entrada,codigo,',');
		std::getline(entrada,nombre,',');
		std::getline(entrada,latitud,',');
		std::getline(entrada,longitud,',');
		std::getline(entrada,direccion,',');
		std::getline(entrada,ruta,',');
		std::getline(entrada,agencia,',');
		std::getline(entrada,linea,',');
		std::getline(entrada,nombreDeRuta,',');
		std::getline(entrada,descripcionDeRuta,',');
		std::getline(entrada,tipoDeRuta);
		/* verifica que no haya llegado al fin del archivo */
		if (! entrada.eof()) {
			longitudConvertida = strtod(longitud.c_str(),NULL);//funcion que convierte una representacion en string de un numero flotante a un dato de
															   //tipo double
			latitudConvertida = strtod(latitud.c_str(),NULL);
			idConvertido = strtod(id.c_str(),NULL);
			paradaDeColectivo.asignarDatos("Colectivo",longitudConvertida, latitudConvertida,idConvertido,
											nombre, linea,ruta, descripcionDeRuta);
			paradasDeColectivo->agregar(paradaDeColectivo);
		}
	}

	/* cierra el archivo, liberando el recurso */
	entrada.close();
}

