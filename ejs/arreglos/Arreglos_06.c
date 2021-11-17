/*
Dados 2 vectores a y b de longitudes n y m, el primero ordenado ascendente
y el segundo ordenado descendente, crear un nuevo vector c de n + m
elementos intercalando los elementos de a y b de modo que c quede ordenado
ascendente.
*/

#include <stdio.h>

void vectoresParejos(int val_ascen, int val_descen, int ordenado[], int i_ord) {
	if(val_ascen < val_descen) {
		ordenado[i_ord] = val_ascen;
		ordenado[i_ord + 1] = val_descen;
	} else {
		ordenado[i_ord] = val_descen;
		ordenado[i_ord + 1] = val_ascen;
	}
}

void ordenarVectores(int ascendente[], int descendente[], int ordenado[], int ml_asc, int ml_dec) {
	int ml_max;
	int i_ord = 0;
	if(ml_asc < ml_dec) {
		ml_max = ml_dec;
	} else {
		ml_max = ml_asc;
	}
	for(int i = 0; i <= ml_max; i++) {
		if((ml_asc - i >= 0) && (ml_dec - i >= 0)) {
			vectoresParejos(ascendente[i], descendente[ml_dec - i], ordenado, i_ord);
			i_ord += 2;
		} else if(ml_asc - i < 0) {
			ordenado[i_ord] = descendente[ml_dec - i];
			i_ord++;
		} else {
			ordenado[i_ord] = ascendente[i];
			i_ord++;
		}
	}
}

void mostrarVector(int vector[], int ml) {
	printf("Vector ordenado: ");
	for(int i = 0; i < ml; i++) {
		printf("%i, ", vector[i]);
	}
}

void main() {
    int ascendente[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int descendente[] = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0};
    //int ascendente[] = {0, 2, 4, 6, 8};
    //int descendente[] = {15, 14, 13, 12, 11, 10, 9, 7, 5, 3, 1};
    //int ascendente[] = {1, 3, 5, 7, 9, 10, 11, 12, 13, 14, 15};
    //int descendente[] = {8, 6, 4, 2, 0};
    int ml_asc = (sizeof ascendente / sizeof ascendente[0]) - 1;
    int ml_dec = (sizeof descendente / sizeof descendente[0]) - 1;
    int ml_ord = ml_asc + ml_dec + 2;
    int ordenado[ml_ord];
    ordenarVectores(ascendente, descendente, ordenado, ml_asc, ml_dec);
    mostrarVector(ordenado, ml_ord);
    getchar();
}
