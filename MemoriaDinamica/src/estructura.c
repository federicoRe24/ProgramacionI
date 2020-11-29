
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG_NOMBRE 50

struct
{
	int id;
	char name[LONG_NOMBRE];
	char lastName[LONG_NOMBRE];
	int isEmpty;

}typedef Estructura;


int Estructura_setter_lastname(Estructura* struc, char* lastName)
{
	int returnFunction = -1;
	if(struc!=NULL && lastName!=NULL)
	{											//struct->lastName
		strncpy(struc->lastName,lastName,sizeof(LONG_NOMBRE));
		//UpperFirstChar(struct->lastName);
		returnFunction = 0;
	}
	return returnFunction;
}
