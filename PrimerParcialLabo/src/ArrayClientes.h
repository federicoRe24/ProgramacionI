/*
 * Cliente.h
 *
 *  Created on: 26 sept. 2020
 *      Author: totinho91
 */

#ifndef SRC_ARRAYCLIENTES_H_
#define SRC_ARRAYCLIENTES_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define LONG_CUIT 12
#define ELEMENTOS_ARRAY 10

struct
{
	int id;
	char name[LONG_NOMBRE];
	char lastName[LONG_NOMBRE];
	char cuit[LONG_CUIT];
	int isEmpty;

}typedef Cliente;

int initClientes(Cliente* list, int len);
int addCliente(Cliente* list, int len, int id, char name[],char lastName[],char cuit[]);
int findClienteById(Cliente* list, int len,int id);
int removeCliente(Cliente* list, int len, int id);
int sortClientes(Cliente* list, int len, int order);
int printClientes(Cliente* list, int length);
int printCliente(Cliente* list, int len, int id);
int BorrarCliente(Cliente* list, int len);
int CargarCliente(Cliente* list, int len);
int ModificarCliente(Cliente* list, int len);
int altaForzadaClientes(Cliente* list, int len);

#endif /* SRC_ARRAYCLIENTES_H_ */
