/*
Dado un listado de valores numéricos i y x, donde i es un entero mayor que
0 y x un real, almacenar x en la posición i de un vector. El listado no se
ingresa ordenado por posición. Informar la cantidad de números y el contenido
del vector indicando la posición ocupada por cada número a partir de la primera
posición.
*/

#include <stdio.h>
#define MAX 100

typedef float tvec[MAX];

int cargarDatos(tvec vector) {
	int posicion;
	int max_posicion = 0;
	float entrada;
	printf("Ingrese la posición del número a guardar: ");
    scanf("%i", &posicion);
    while ((getchar()) != '\n');
    while(posicion >= 0) {
        printf("Ingrese el número correspondiente: ");
        scanf("%f", &entrada);
        while ((getchar()) != '\n');
        vector[posicion] = entrada;
        if(posicion > max_posicion)
			max_posicion = posicion;
		printf("Ingrese la posición del número a guardar: ");
		scanf("%i", &posicion);
		while ((getchar()) != '\n');
    }
    return max_posicion;
}

void mostrarContenido(float vector[], int n) {
    printf("Vector de %i posiciones\n", n + 1);
    for(int i = 0; i <= n; i++) {
        printf("Posición %i: %.2f\n", i, vector[i]);
    }
}

void main() {
	int ml;
    tvec vector;
    ml = cargarDatos(vector);
    mostrarContenido(vector, ml);
    getchar();
}
