#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "PruebaBMP.h"
//#include "PruebaBMP.cpp"

#include "EasyBMP.h"
#include "PruebaBMP.h"

using namespace std;

int prueba( int argc, char* argv[] )
{
	if( argc != 3 )
	{
		cout << "Usage: ColorBMPtoGrayscale <input_filename> <output_filename>"
				<< endl << endl;
		return 1;
	}

	// declare and read the bitmap
	BMP Input;
	Input.ReadFromFile( argv[1] );

	// convert each pixel to grayscale using RGB->YUV
	for( int j=0 ; j < Input.TellHeight() ; j++)
	{
	for( int i=0 ; i < Input.TellWidth() ; i++)
	{
	int Temp = (int) floor( 0.299*Input(i,j)->Red +
	0.587*Input(i,j)->Green +
	0.114*Input(i,j)->Blue );
	ebmpBYTE TempBYTE = (ebmpBYTE) Temp;
	Input(i,j)->Red
	= TempBYTE;
	Input(i,j)->Green = TempBYTE;
	Input(i,j)->Blue = TempBYTE;
	}
	}
	// Create a grayscale color table if necessary
	if( Input.TellBitDepth() < 16 )
	{ CreateGrayscaleColorTable( Input ); }
	// write the output file
	Input.WriteToFile( argv[2] );
	return 0;

	/*char szOrbits[] = "365.24 29.53";
	char* pEnd;
	double d1, d2;
	d1 = strtod (szOrbits, &pEnd);
	d2 = strtod (pEnd, NULL);
	printf ("The moon completes %.2f orbits per Earth year.\n", d1/d2);

	std::cout.precision(20);

    std::string data="20.965464565465464";
    float value = strtod(data.c_str(), &pEnd);
    std::cout<<value<<'\n';
    double numero = 20.965464565465464;
    std::cout << numero << std::endl;
    long double numero2 = 20.965464565465464;
    std::cout << numero2 << std::endl;
    float numero3 = 20.965464565465464;
    std::cout << numero3 << std::endl;
    signed int numero4 = 132213;
    std::cout << numero4 << std::endl;*/

}
