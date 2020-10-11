#include <stdio_ext.h>
#include <stdio.h>
#include "clase9.h"
#include <string.h>
#define LONG_NOMBRE 50
#define LIMITE_BUFFER_STRING 4096
#define CANTIDAD_ALUMNOS 5

/*struct sFecha
{
	int dia;
	int mes;
	int anio;
};
typedef struct sFecha Fecha;*/

typedef struct
{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct
{
	char nombre[50];
	char apellido [50];
	long dni;
	Fecha fechaNac;
	Fecha fechaAltaSistema;
}Alumno;

int cargarAlumno(Alumno alumnos[], int limite, int indice);
int imprimirAlumno(Alumno alumno);
int utn_esUnNombreValido(char * cadena, int limite);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado, int reintentos, int limite);
int getInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo);

void clase9(void)
{
	int op;
	//int indice;
	Alumno arrayAlumnos[CANTIDAD_ALUMNOS];

	do
	{
		getInt("\n1-Alta\n2-Mostrar\n3-Salir","\nError", &op,2,3,1);
		switch(op)
		{
			case 1:
				if(1)//(getInt("\Indice?","\nError", &indice,2,CANTIDAD_ALUMNOS,1) == 0)
				{
					//cargarAlumno();
					printf("Terminar");
				}
				break;
			case 2:
				imprimirAlumno(arrayAlumnos[0]);
				break;
		}
	}while(op != 3);
}

//int ordenarNombre(struct sAlumno array[])

int cargarAlumno(Alumno alumnos[], int limite, int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;
	if(alumnos != NULL && limite > 0 && indice >=0 && indice < limite)
	{
		// & al pasarle el buffer para pedir un int?
		if(utn_getNombre("Ingrese el nombre del alumno: ", "Debe ingresar un nombre válido", bufferAlumno.nombre, 5, LONG_NOMBRE) == 0 &&
		   utn_getNombre("Ingrese el apellido del alumno: ", "Debe ingresar un apellido válido", bufferAlumno.apellido, 5, LONG_NOMBRE) == 0)
		{
			//alumnos[indice] =
		}

	}


	//alumno[0].dni = 12345678;

	return retorno;
}

int imprimirAlumno(Alumno alumno)
{
	printf("El nombre del alumno es %s\n",alumno.nombre);
	printf("El apellido del alumno es %s\n",alumno.apellido);
	printf("El dni del alumno es %ld\n",alumno.dni);

	return 0;
}

int utn_esUnNombreValido(char * cadena, int limite)
{
	int respuesta = 1; //todo ok
	for(int i=0;i<=limite && cadena[i] != '\0';i++)
	{
		if((cadena[i] > 'Z' ||cadena[i] < 'A')&&(cadena[i] > 'z' ||cadena[i] < 'a') && cadena[i] != ' ')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}

//static --> Funcion privada, su ambito de visibilidad es este atchivo. La firma de la funcion no la llevamos al .h
static int myGets(char *cadena, int longitud) // myGets resuelve varios problemas del scanf, usarla de ahora en más
{
	__fpurge(stdin);
	fgets(cadena, longitud, stdin);
	cadena[strlen (cadena) -1] = '\0'; //Con el \0 pisamos el enter que ingresamos al final

	return 0;
}

int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				utn_esUnNombreValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;
}

int getInt(char* mensaje, char* mensajeError, int* pResultado, int reintentos, int maximo, int minimo)
{
	int retorno = -1;
	int bufferInt; // Variable descartable
	int resultadoScanf;
	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			maximo >= minimo) // Como mínimo, que máx sea mayor que mín para que tenga sentido

	do
	{
		printf("%s", mensaje);
		__fpurge(stdin); // stdin --> standard input
		resultadoScanf = scanf("%d", &bufferInt);
		if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		else
		{
			//Error
			printf("%s",mensajeError);
			reintentos --;
		}
	}while(reintentos >= 0);

	return retorno;
}



