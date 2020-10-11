
#ifndef SRC_ENTERO_H_
#define SRC_ENTERO_H_

class Entero{

private:

	int entero;

public:


	//Pre:
	//Post: agrega los datos pasados por parametro a los atributos correspondientes de la clase
	void agregarDatos();

	//Pre_
	//Post: devuelve la longitud en la que se encuentra el garaje
	double obtenerLongitud();

	//Pre:
	//Post:devuelve la latitud en la que se encuentra el garaje
	double obtenerLatitud();

	//Pre:
	//Post: devuelve la seccion manzana parcela en la que esta ubicado el garaje
	std::string obtenerSmp();

	//Pre:
	//Post: devuelve la calle en la que se encuentra el garaje
	std::string obtenerCalle();

	//Pre:
	//Post: devuelve la altura de la calle en la que se encuentra el garaje
	unsigned int obtenerAltura();

	//Pre:
	//Post: devuelve la abreviacion del tipo de uso
	std::string obtenerTipo1();

	//Pre:
	//Post: devuelve el nombre completo del tipo de uso
	std::string obtenerTipo2();

	//Pre:
	//Post: devuelve la cantidad de pisos que posee el garaje
	unsigned int obtenerPisos();

	//Pre:
	//Post: devuelve el nombre del garaje
	std::string obtenerNombre();

	//Pre:
	//Post: devuelve el barrio en el que se encuentra el garaje
	std::string obtenerBarrio();

	//Pre:
	//Post: devuelve la comuna en la que se encuentra el garaje
	std::string obtenerComuna();

	//Pre:
	//Post: devuelve el codigo postal del garaje
	unsigned int obtenerCodigoPostal();

	//Pre:
	//Post: devuelve el codigo postal argentino del garaje
	std::string obtenerCodigoPostalArgentino();

	//Pre:
	//Post: muestra por pantalla los datos del garaje
	void mostrarGaraje();


};




#endif /* SRC_ENTERO_H_ */
