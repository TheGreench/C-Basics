/*
Escribir un subprograma que dada una matriz de números reales, de n x m,
devuelva un vector que en cada posición i almacene el elemento mínimo de
cada fila i de la matriz.
*/

#include <stdio.h>

void cargarDimensiones(int *filas, int *columnas) {
	printf("Ingrese las dimensiones de la matriz, separadas por un espacio\n");
    printf("Ejemplo: 2 3 (2 filas, 3 columnas) :");
    scanf("%i %i", filas, columnas);
    while ((getchar()) != '\n');
}

void cargarMatriz(int filas, int columnas, int matriz[][columnas]) {
	for(int i = 0; i < filas; i++) {
		printf("--- Valores de la fila %i ---\n", i + 1);
		for(int j = 0; j < columnas; j++) {
			printf("Valor %i: ", j + 1);
			scanf("%i", &matriz[i][j]);
		}
	}
}

void valorMinimoPorFila(int fil, int col, int matriz[][col], int vector[]) {
	int i, j, menor_fila;
	for (i = 0; i < fil; i++) {
		menor_fila = matriz[i][0];
		for(j = 0; j < col; j++) {
			if(matriz[i][j] < menor_fila)
				menor_fila = matriz[i][j];
		}
		vector[i] = menor_fila;
	}
}

void mostrarVector(int salida[], int ml) {
	printf("Valores mínimos de cada fila de la matríz: ");
	for(int i = 0; i < ml; i++) {
		printf("%i ", salida[i]);
	}
}

void main() {
	int fil, col;
    cargarDimensiones(&fil, &col);
    int matriz[fil][col];
    int salida[fil];
    cargarMatriz(fil, col, matriz);
    valorMinimoPorFila(fil, col, matriz, salida);
	mostrarVector(salida, fil);
    getchar();
}
