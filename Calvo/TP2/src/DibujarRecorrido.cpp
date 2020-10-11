#include "EasyBMP.h"
#include "EasyBMP_Geometry.h"
#include "DibujarRecorrido.h"
#include "EasyBMP_Font.h"

using namespace std;

void GenerarBMP(int longOrigen, int latOrigen, int longTransporteOrig, int latTransporteOrig,
		int longTransporteDest, int latTransporteDest, int longDestino, int latDestino){

	// Generar una imagen BMP
	BMP AnImage;

	// Cambiar tamaño a 1260x1080
	AnImage.SetSize(1260,1080);

	// Cambiar la profundidad del color a 8-bits
	AnImage.SetBitDepth(8);

	char origen [10];
	strcpy( origen , "Origen");
	char inicioTransporte [20];
	strcpy( inicioTransporte , "InicioTransporte");
	char finTransporte [20];
	strcpy( finTransporte , "FinTransporte");
	char destino [10];
	strcpy( destino , "Destino");

	// Generar el color negro
	RGBApixel Black;
	Black.Red = 0;
	Black.Green = 0;
	Black.Blue = 0;

	// Generar el color rojo
	RGBApixel Red;
	Red.Red = 255;
	Red.Green = 0;
	Red.Blue = 0;

	// Dibujar recorrido
	DrawFastLine( AnImage, longOrigen, latOrigen, longTransporteOrig, latTransporteOrig, Black);
	DrawLine( AnImage, longTransporteOrig, latTransporteOrig, longTransporteDest, latTransporteDest, Red);
	DrawFastLine( AnImage, longTransporteDest, latTransporteDest, longDestino, latDestino, Black);

	PrintString( AnImage, origen, longOrigen, latOrigen, 15, Black);
	PrintString( AnImage, inicioTransporte, longTransporteOrig, latTransporteOrig, 15, Black);
	PrintString( AnImage, finTransporte, longTransporteDest, latTransporteDest, 15, Black);
	PrintString( AnImage, destino, longDestino, latDestino, 15, Black);

	// Guardar Imagen
	AnImage.WriteToFile("Recorrido.bmp");

}

void GenerarBMP(int longOrigen, int latOrigen, int longPrimerTransporteOrig, int latPrimerTransporteOrig,
		int longPrimerTransporteDest, int latPrimerTransporteDest, int longSegundoTransporteOrig, int latSegundoTransporteOrig,
		int longSegundoTransporteDest, int latSegundoTransporteDest, int longDestino, int latDestino){

	// Generar una imagen BMP
	BMP AnImage;

	// Cambiar tamaño a 1260x1080
	AnImage.SetSize(1260,1080);

	// Cambiar la profundidad del color a 8-bits
	AnImage.SetBitDepth(8);

	char origen [10];
	strcpy( origen , "Origen");
	char inicioTransporte [20];
	strcpy( inicioTransporte , "InicioTransporte");
	char finTransporte [20];
	strcpy( finTransporte , "FinTransporte");
	char destino [10];
	strcpy( destino , "Destino");

	// Generar el color negro
	RGBApixel Black;
	Black.Red = 0;
	Black.Green = 0;
	Black.Blue = 0;

	// Generar el color rojo
	RGBApixel Red;
	Red.Red = 255;
	Red.Green = 0;
	Red.Blue = 0;

	// Dibujar recorrido
	DrawFastLine( AnImage, longOrigen, latOrigen, longPrimerTransporteOrig, latPrimerTransporteOrig, Black);
	DrawLine( AnImage, longPrimerTransporteOrig, latPrimerTransporteOrig, longPrimerTransporteDest, latPrimerTransporteDest, Red);
	DrawFastLine( AnImage, longPrimerTransporteDest, latPrimerTransporteDest, longSegundoTransporteOrig, latSegundoTransporteOrig, Black);
	DrawLine( AnImage, longSegundoTransporteOrig, latSegundoTransporteOrig, longSegundoTransporteDest, latSegundoTransporteDest, Red);
	DrawFastLine( AnImage, longSegundoTransporteDest, latSegundoTransporteDest, longDestino, latDestino, Black);

	PrintString( AnImage, origen, longOrigen, latOrigen, 15, Black);
	PrintString( AnImage, inicioTransporte, longPrimerTransporteOrig, latPrimerTransporteOrig, 15, Black);
	PrintString( AnImage, finTransporte, longPrimerTransporteDest, latPrimerTransporteDest, 15, Black);
	PrintString( AnImage, inicioTransporte, longSegundoTransporteOrig, latSegundoTransporteOrig, 15, Black);
	PrintString( AnImage, finTransporte, longSegundoTransporteDest, latSegundoTransporteDest, 15, Black);
	PrintString( AnImage, destino, longDestino, latDestino, 15, Black);

	// Guardar Imagen
	AnImage.WriteToFile("Recorrido.bmp");

}


