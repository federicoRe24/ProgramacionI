#include <string>

#ifndef SRC_EJERCICIOPARCIAL_H_
#define SRC_EJERCICIOPARCIAL_H_

/* Diseñar e implementar el TDA PartidoDeFutbol, el que deberá tener como atributos (además de los que consideres necesarios) los nombres de
 * los equipos (local y visitante), los goles de cada uno y un estado de juego, el que podrá ser no comenzado, jugando o finalizado.
 * Por otro lado, las operaciones mínimas a definir son:
 * - Creación
 * - Anotar un gol para cierto equipo
 * - Conocer el resultado parcial
 * - Conocer el resultado final
 * - Indicar equipo ganador o empate
 *
 * Observaciones:
 * - Escribir PRE y POST condiciones.
 */

enum EstadoDeJuego { NoComenzado, Jugando, Finalizado };

class PartidoDeFutbol {

private:

	std::string equipoLocal;
	std::string equipoVisitante;
	int golesEquipoLocal;
	int golesEquipoVisitante;
	EstadoDeJuego estado;

};


#endif /* SRC_EJERCICIOPARCIAL_H_ */
