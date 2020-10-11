#include "interfaz.h"
#include <iostream>

void menu(EstacionMetro array[]){
	int opcion;
	std::cout << "Elija una opcion para filtrar: 1- Rango de Longitud, 2- Rango de latitud,"
			 " 3- ID exacto, 4- Finalizar: ";
	std::cin>>opcion;
	switch(opcion){
	case 1: filtrarPorLongitud(array);
			menu(array);
			break;
	case 2: filtrarPorLatitud(array);
			menu(array);
			break;
	case 3: filtrarPorId(array);
			menu(array);
			break;
	case 4: std::cout << "Saludos";
			break;
	default: std::cout << "Por favor ingrese una opción de filtro válida." << std::endl;
			 menu(array);
	}

}

void mostrarCasos(EstacionMetro array[],int contador){
	int opcion;
	std::cout << "Ingrese 1 si desea imprimir los datos hallados. De lo contrario ingrese 2.";
	std::cin >> opcion;
	switch(opcion){
	case 1: for(int i=0;i<contador;i++){
				imprimirEstacion(array[i]);
			}
			break;
	case 2: break;
	default: std::cout << "Por favor ingrese una opción válida.";
			mostrarCasos(array,contador);
	}
}


void filtrarPorLongitud(EstacionMetro array[]){
	EstacionMetro filtrado[CANTIDAD_ESTACIONES];
	int contador = 0;
	double minimo;
	double maximo;
	std::cout << "Ingrese el valor mínimo a buscar";
	std::cin >> minimo;
	std::cout << "Ingrese el valor máximo a buscar";
	std::cin >> maximo;
	for(int i=0;i<CANTIDAD_ESTACIONES;i++){
		if((array[i].longitud>=minimo)&&(array[i].longitud<=maximo)){
			filtrado[contador] = array[i];
			contador++;
		}
	}
	std::cout << "Se encontraron " << contador << " casos"<< std::endl;
	if(contador>0){
		mostrarCasos(filtrado, contador);
	}
}

void mostrarCasosEncontrados(EstacionMetro array[], int contador){
	for(int i=0;i<contador;i++){
		imprimirEstacion(array[i]);
	}
}


void filtrarPorLatitud(EstacionMetro array[]){
	EstacionMetro filtrado[CANTIDAD_ESTACIONES];
	int contador = 0;
	double minimo;
	double maximo;
	std::cout << "Ingrese el valor mínimo a buscar";
	std::cin >> minimo;
	std::cout << "Ingrese el valor máximo a buscar";
	std::cin >> maximo;
	for(int i=0;i<CANTIDAD_ESTACIONES;i++){
		if((array[i].latitud>=minimo)&&(array[i].latitud<=maximo)){
			filtrado[contador] = array[i];
			contador++;
		}
	}
	std::cout<< "Se encontraron " << contador << " casos" << std::endl;
	if(contador>0){
		mostrarCasos(filtrado, contador);
	}
}

void filtrarPorId(EstacionMetro array[]){
	EstacionMetro estacion;
	int contador=0;
	int id;
	std::cout << "Ingrese el ID a buscar" << std::endl;
	std::cin >> id;
	for(int i=0;i<CANTIDAD_ESTACIONES;i++){
		if(array[i].id==id){
			estacion=array[i];
			contador++;
		}
	}
	std::cout << "Se encontraron " << contador << " casos" << std::endl;
	if(contador>0){
		imprimirEstacion(estacion);
	}
}




