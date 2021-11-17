/*
Escribir un programa que cargue 2 (dos) matrices y sus dimensiones, las
multiplique en caso de ser posible o devuelva una señal si la operación no
puede realizarse.
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

int verificar(int filas_1, int columnas_2) {
	int posible = 1;
	if(filas_1 != columnas_2) {
		posible = 0;
	}
	return posible;
}
void multiplicarMatrices(int filas_1, int columnas_1, int columnas_2, int dim_salida, int matriz_1[][columnas_1], int matriz_2[][columnas_2], int matriz_salida[][dim_salida]) {
	int valor_salida;
	for(int i = 0; i < filas_1; i++) {
		for(int j = 0; j < columnas_2; j++) {
			valor_salida = 0;
			for(int k = 0; k < dim_salida; k++) {
				valor_salida += matriz_1[i][k] * matriz_2[k][j];
			}
			matriz_salida[i][j] = valor_salida;
		}
	}
}

void mostrarMatriz(int filas_salida, int columnas_salida, int matriz_salida[][columnas_salida]) {
	for(int i = 0; i < filas_salida; i++) {
		for(int j = 0; j < columnas_salida; j++) {
			printf("%i ", matriz_salida[i][j]);
		}
		printf("\n\n");
	}
}

void main() {
	int filas_1, filas_2, columnas_1, columnas_2, posible;
    cargarDimensiones(&filas_1, &columnas_1);
    int matriz_1[filas_1][columnas_1];
    cargarMatriz(filas_1, columnas_1, matriz_1);
    cargarDimensiones(&filas_2, &columnas_2);
    int matriz_2[filas_2][columnas_2];
    cargarMatriz(filas_2, columnas_2, matriz_2);
    int matriz_salida[columnas_1][filas_2];
    posible = verificar(filas_1, columnas_2);
    if(posible){
		multiplicarMatrices(filas_1, columnas_1, columnas_2, filas_2, matriz_1, matriz_2, matriz_salida);
		printf("Producto de las matrices 1 y 2:\n");
		mostrarMatriz(columnas_1, filas_2, matriz_salida);
	} else {
		printf("No es posible multiplicar las matrices.");
	}
    getchar();
}
