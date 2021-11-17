/*
Dado n entero positivo y un listado de n números reales, almacenar los
números en un vector en el orden de entrada. Informar el contenido del vector
indicando la posición ocupada por cada número a partir de la primera posición.
*/

#include <stdio.h>

void cargarDatos(int vector[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Ingrese el siguiente numero (quedan %i): ", n - i);
        scanf("%d", &vector[i]);
        while ((getchar()) != '\n');
    }
}

void mostrarContenido(int vector[], int n) {
    printf("Vector de %i posiciones\n", n);
    for(int i = 0; i < n; i++) {
        printf("Posición %i: %i\n", i, vector[i]);
    }
}

void main() {
    int max;
    printf("Ingrese la cantidad de elementos a guardar: ");
    scanf("%d", &max);
    int vector[max];
    cargarDatos(vector, max);
    mostrarContenido(vector, max);
    getchar();
}
