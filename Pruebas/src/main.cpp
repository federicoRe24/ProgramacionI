#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "PruebaBMP.h"
//#include "PruebaBMP.cpp"

#include "EasyBMP.h"
#include "PruebaBMP.h"

using namespace std;

int main()
{
    // Declare a new bitmap object
    BMP AnImage;
    //AnImage.ReadFromFile("EasyBMPbackground.bmp");

    AnImage.SetSize(640,480);
    // Set its color depth to 8-bits
    AnImage.SetBitDepth(8);
    // Declare another BMP image
    BMP AnotherImage;
    // Read from a file
    //AnotherImage.ReadFromFile("EasyBMPbackground.bmp");

    //BMP AnImage;
    //AnImage.ReadFromFile("sample.bmp");
    cout << "File info:" << endl;
    cout << AnImage.TellWidth() << " x " << AnImage.TellHeight()
    << " at " << AnImage.TellBitDepth() << " bpp" << endl;
    cout << "colors: " << AnImage.TellNumberOfColors() << endl;

    // show the color of pixel (14,18)
    cout << "(" << (int) AnImage(14,18)->Red;
    cout << (int) AnImage(14,18)->Green;
    cout << (int) AnImage(14,18)->Blue;
    cout << (int) AnImage(14,18)->Alpha;
    // Change this pixel to a blue-grayish color
    AnImage(14,18)->Red
    = 50;
    AnImage(14,18)->Green = 50;
    AnImage(14,18)->Blue = 192;
    AnImage(14,18)->Alpha = 0;
    //To save the image
    AnImage.WriteToFile("copied.bmp");

    return 0;
}
