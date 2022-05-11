/*
6. Informar un listado de números entre el 000 y el 999, escritos separando
cada dígito de cada número con un guión, 0-0-0, 0-0-1, 0-0-2, ......... ,9-
9-9.
*/


#include <stdio.h>

int main() {
    int i, j, k, unidad = 0, decena = 0, centena = 0;
    
	/* Printing all the numbers from 000 to 999. */
	// i = centna | j = decena | k = unidad
	for (i = 0; i <= 9; i++) {

		for (j = 0; j <= 9; j++) {

			for (k = 0; k <= 9; k++) {

				printf("\n %d - %d - %d", centena, decena, unidad);
				unidad += 1;

			}

			decena += 1;
			unidad = 0;

		}

		centena += 1;
		decena = 0;

	}
    

    
    return 0;
}