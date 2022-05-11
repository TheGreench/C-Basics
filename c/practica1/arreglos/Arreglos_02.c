/*
Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada. Informar la
cantidad de números y el contenido del vector indicando la posición ocupada
por cada número a partir de la primera posición. 
*/

#include <stdio.h>
#define MAX 100

typedef int tvec[MAX];

int cargarDatos(int vector[]) {
	int entrada = -1;
	int i = 0;
    while(entrada != 0) {
        printf("Ingrese el siguiente numero (ingrese 0 para terminar): ");
        scanf("%d", &entrada);
        while ((getchar()) != '\n');
        vector[i] = entrada;
        i++;
    }
    return i - 1;
}

void mostrarContenido(int vector[], int n) {
    printf("Vector de %i posiciones\n", n);
    for(int i = 0; i < n; i++) {
        printf("Posicion %i: %i\n", i, vector[i]);
    }
}

void main() {
	int ml;
    tvec vector;
    ml = cargarDatos(vector);
    mostrarContenido(vector, ml);
    getchar();
}
