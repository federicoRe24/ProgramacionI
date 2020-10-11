
#include <iostream>

const int ULTIMO_DIGITO_DEL_PADRON = 3;

void ejercicio1(){

	int *A, *C, *F;
	int **B;
	char *D, *E;
	char G;
	int H;

	H = 65 + ULTIMO_DIGITO_DEL_PADRON;
	G = 'A' + ULTIMO_DIGITO_DEL_PADRON;
	A = &H;
	D = &G;
	B = &A;
	std::cout << (**B) << (*D) << (*A) << std::endl;

	C = new int[4];
	for (int i = 0; i < 4; i++) {
		C[i] = H + i;
	}

	F = C + 2;
	(*A) = 69;
	C[1] = H;
	(*F) = 67;
	(*C) = H;
	std::cout << C[0] << C[1] << C[2] << C[3] << std::endl;

	(**B) = C[0] + 2;
	A = C + 1;
	(**B) = H;
	C[0] = *A;
	(*F) = A[0] + 1;
	std::cout << C[2] << C[1] << C[0] << std::endl;

	E = (char*) A;
	//C[1] = (**B) - 6;
	std::cout << (*D) << (*E) << G << std::endl;

}
