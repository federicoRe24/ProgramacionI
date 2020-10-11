#include "EasyBMP.h"
#include "EasyBMP_Geometry.h"
#include "EasyBMP_Font.h"
#include "AdditionalSource.h"

using namespace std;


void DibujarRecorrido(BMP& InputImage, int longOrigen, int latOrigen, int longTransporteOrig, int latTransporteOrig,
		int longTransporteDest, int latTransporteDest, int longDestino, int latDestino){

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

	DrawFastLine( InputImage, longOrigen, latOrigen, longTransporteOrig, latTransporteOrig, Black);
	DrawLine( InputImage, longTransporteOrig, latTransporteOrig, longTransporteDest, latTransporteDest, Red);
	DrawFastLine( InputImage, longTransporteDest, latTransporteDest, longDestino, latDestino, Black);

	PrintString( InputImage, origen, longOrigen, latOrigen, 15, Black);
	PrintString( InputImage, inicioTransporte, longTransporteOrig, latTransporteOrig, 15, Black);
	PrintString( InputImage, finTransporte, longTransporteDest, latTransporteDest, 15, Black);
	PrintString( InputImage, destino, longDestino, latDestino, 15, Black);

}

void DibujarRecorrido(BMP& InputImage, int longOrigen, int latOrigen, int longPrimerTransporteOrig, int latPrimerTransporteOrig,
		int longPrimerTransporteDest, int latPrimerTransporteDest, int longSegundoTransporteOrig, int latSegundoTransporteOrig,
		int longSegundoTransporteDest, int latSegundoTransporteDest, int longDestino, int latDestino){

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

	DrawFastLine( InputImage, longOrigen, latOrigen, longPrimerTransporteOrig, latPrimerTransporteOrig, Black);
	DrawLine( InputImage, longPrimerTransporteOrig, latPrimerTransporteOrig, longPrimerTransporteDest, latPrimerTransporteDest, Red);
	DrawFastLine( InputImage, longPrimerTransporteDest, latPrimerTransporteDest, longSegundoTransporteOrig, latSegundoTransporteOrig, Black);
	DrawLine( InputImage, longSegundoTransporteOrig, latSegundoTransporteOrig, longSegundoTransporteDest, latSegundoTransporteDest, Red);
	DrawFastLine( InputImage, longSegundoTransporteDest, latSegundoTransporteDest, longDestino, latDestino, Black);

	PrintString( InputImage, origen, longOrigen, latOrigen, 15, Black);
	PrintString( InputImage, inicioTransporte, longPrimerTransporteOrig, latPrimerTransporteOrig, 15, Black);
	PrintString( InputImage, finTransporte, longPrimerTransporteDest, latPrimerTransporteDest, 15, Black);
	PrintString( InputImage, inicioTransporte, longSegundoTransporteOrig, latSegundoTransporteOrig, 15, Black);
	PrintString( InputImage, finTransporte, longSegundoTransporteDest, latSegundoTransporteDest, 15, Black);
	PrintString( InputImage, destino, longDestino, latDestino, 15, Black);

}


int main(){

	// Generar una imagen BMP
	BMP AnImage;

	// Cambiar tamaño a 1260x1080
	AnImage.SetSize(1260,1080);

	// Cambiar la profundidad del color a 8-bits
	AnImage.SetBitDepth(8);

	// Dibujar el recorrido
	DibujarRecorrido(AnImage, 8, 88, 19, 69, 33, 31, 888, 818, 868, 866, 629, 450);

	// Guardar Imagen
	AnImage.WriteToFile("Recorrido.bmp");

	return 0;
}


