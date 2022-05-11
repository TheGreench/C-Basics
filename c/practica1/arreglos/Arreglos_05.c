/*
Cargar un conjunto de números de documento en un vector. No se conoce la
cantidad de datos válidos. Informar el número de documento más alto del
conjunto y la posición que ocupa. Puede haber repetición, en este caso
informar todas las posiciones que ocupa.
*/

#include <stdio.h>
#define MAX 100

typedef unsigned long tvec[MAX];

int cargarDatos(tvec vector) {
	int i = 0;
	unsigned long entrada;
	char continuar = 's';
    while(continuar == 's') {
        printf("Ingrese un número de documento: ");
        scanf("%lu", &entrada);
        while ((getchar()) != '\n');
        vector[i] = entrada;
        i++;
        printf("Contiunar ingresando? (s/n): ");
        continuar = getchar();
    }
    return i - 1;
}

unsigned long buscarMostrarMayor(tvec vector, int ml) {
	unsigned long mayor = 0;
	int posicion = 0;
	for(int i = 0; i <= ml; i++) {
		if(vector[i] > mayor) {
			mayor = vector[i];
			posicion = i;
		}
	}
	printf("\nNúmero de documento más alto: %lu\n", mayor);
	printf("Posición: %i\n", posicion);
	return mayor;
}

void buscarRepeticion(tvec vector, int ml, unsigned long buscado) {
	int encontrado = 0;
	for(int i = 0; i <= ml; i++) {
		if(vector[i] == buscado){
			if(encontrado > 0) {
				printf("El número se repite en la posición %i\n", i);
			}
			encontrado++;
		}
	}
}

void main() {
	int ml;
	unsigned long mayor_documento;
    tvec vector;
    ml = cargarDatos(vector);
    mayor_documento = buscarMostrarMayor(vector, ml);
    buscarRepeticion(vector, ml, mayor_documento);
    getchar();
}
