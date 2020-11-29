
#ifndef SRC_UTN_H_
#define SRC_UTN_H_

int getInt(char* mensaje, char* mensajeError, int* resultado, int reintentos, int maximo, int minimo);
int getFloat(char *mensaje,char *mensajeError,int reintentos,float *pResultado);
int esUnNombreValido(char* cadena,int limite);
int esUnCuitValido(char* cadena,int limite);
int esUnaZonaValida(char* cadena,int limite);
int getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int getCuit(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int len);
int getZona(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getAlphaNum(char* pMensaje, char* pMensajeError, char* pResultado, int reintentos, int limite);
int utn_getChar(char* pMensaje, char* pMensajeError, char* pResultado, int reintentos, int limite);
int utn_sortArrayInt(int pArray[], int limite);
int GetMayorValorArray(int *array, int len);

#endif /* SRC_UTN_H_ */
