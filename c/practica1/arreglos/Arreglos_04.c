/*
Cargar una serie de números reales en un vector. No se conoce la cantidad
exacta de datos, pero se sabe que no superan los 100. No se conocen cotas
para los datos. Informar el valor máximo, la cantidad de veces que aparece y
la/s posición/es que ocupa.
*/

#include <stdio.h>
#define MAX 100

typedef float tvec[MAX];

int cargarDatos(tvec vector) {
	int i = 0;
	float entrada;
	char continuar = 's';
    while(continuar == 's') {
        printf("Ingrese un número a guardar: ");
        scanf("%f", &entrada);
        while ((getchar()) != '\n');
        vector[i] = entrada;
        i++;
        printf("Contiunar ingresando? (s/n): ");
        continuar = getchar();
    }
    return i - 1;
}

void mostrarContenido(float vector[], int n) {
    printf("Vector de %i posiciones\n", n);
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
