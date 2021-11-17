/*
Dado un vector a de longitud n y un elemento p del mismo tipo que los
elementos del vector, buscar p en el vector a y devolver la posición que ocupa
en caso de encontrarlo o una señal en caso contrario. Suponer que vector está
ordenado ascendente.
*/

#include <stdio.h>

int buscarOrdenado(int vector[], int ml, int elemento) {
	int mayor = ml - 1;
	int menor = 0;
	int medio;
	int posicion = -1;
	int terminar = 0;
	while(!terminar) {
		if((elemento > vector[mayor]) || elemento < vector[menor]) {
			terminar = 1;
		} else {
			medio = (mayor + menor) / 2;
			if(elemento == vector[medio]) {
				terminar = 1;
				posicion = medio;
			} else {
				if(elemento > vector[medio]) {
					menor = medio + 1;
				} else {
					mayor = medio - 1;
				}
			}
		}
	}
	return posicion;
}

void main() {
    int vector[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int ml = (sizeof vector / sizeof vector[0]) - 1;
    int p = 16;
    int encontrado = buscarOrdenado(vector, ml, p);
    if(encontrado >= 0) {
		printf("Elemento \"%i\" encontrado en la posición %i.\n", p, encontrado);
	} else {
		printf("Elemento no encontrado.\n");
	}
    getchar();
}
