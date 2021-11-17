/*
Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que no hay
repeticiones.
*/

#include <stdio.h>

int buscarElemento(int vector[], int ml, int elemento) {
	int posicion;
	int i = 0;
	int encontrado = 0;
	while(!encontrado) {
		if(vector[i] == elemento) {
			posicion = i;
			encontrado = 1;
		} else {
			i++;
		}
	}
	return posicion;
}

void main() {
    int vector[] = {4, 16, 5, 7, 2, 11, 6, 14, 3, 1, 9, 13, 8, 15, 12};
    int ml = (sizeof vector / sizeof vector[0]) - 1;
    int p = 14;
    int encontrado = buscarElemento(vector, ml, p);
    if(encontrado >= 0) {
		printf("Elemento \"%i\" encontrado en la posición %i.\n", p, encontrado);
	} else {
		printf("Elemento no encontrado.\n");
	}
    getchar();
}
