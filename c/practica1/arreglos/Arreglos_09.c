/*
Dado un vector a de longitud n ordenado ascendente y un elemento p del
mismo tipo que los elementos del vector, intercalar p en el vector a de modo
que siga ordenado.
*/

#include <stdio.h>

int buscarPosicion(int vector[], int ml, int elemento) {
	int posicion;
	int i = 0;
	int terminar = 1;
	if(elemento < vector[i])
		posicion = 0;
	else if(elemento > vector[ml - 1])
		posicion = ml - 1;
	else {
		terminar = 0;
		while(!terminar) {
			if((elemento > vector[i]) && elemento < vector[i + 1]) {
				posicion = i + 1;
				terminar = 1;
			} else {
				i++;
			}
		}
	}
	printf("Intercalando en posición %i...\n", posicion);
	return posicion;
}

void intercalar(int v_entrada[], int v_salida[], int ml, int posicion, int elemento) {
	for(int i = 0; i <= ml; i++) {
		if(i == posicion) {
			v_salida[i] = elemento;
			printf("INT %i\n", elemento);
		} else {
			if(i < posicion) {
				v_salida[i] = v_entrada[i];
				printf("MEN %i --> POS %i\n", v_salida[i], i);
			} else {
				v_salida[i] = v_entrada[i - 1];
				printf("MAY %i --> POS %i\n", v_salida[i], i);
			}
		}
	}
}

void mostrarVector(int vector[], int ml) {
	for(int i = 0; i <= ml; i++) {
		printf("%i, ", vector[i]);
	}
}

void main() {
    int v_entrada[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int ml = sizeof v_entrada / sizeof v_entrada[0];
    int v_salida[ml + 1];
    int p = -1;
    int posicion = buscarPosicion(v_entrada, ml, p);
	intercalar(v_entrada, v_salida, ml, posicion, p);
	printf("Cantidad de elementos en el vector: %i\n", ml);
	printf("Elemento \"%i\" intercalado en el vector.\n", p);
	printf("Elementos del vector: ");
	mostrarVector(v_salida, ml);
    getchar();
}
