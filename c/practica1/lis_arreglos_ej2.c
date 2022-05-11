/*
Dado un listado de números reales del cual no se conoce la cantidad, 
almacenar los números en un vector en el orden de entrada. Informar la 
cantidad de números y el contenido del vector indicando la posición 
ocupada por cada número a partir de la primera posición.
*/

#include <stdio.h>

#define MF 500
typedef float vec_nums[MF];

void mostrar(vec_nums vec, int num) {
	int i;
	
	printf("\nLa cantidad de elementos es de %d \n", num);
	
	for (i = 0; i < num; i++)
		printf("Posicion %d: %.1f \n", i, vec[i]);
}

void ingreso(vec_nums vec, int *ml) {
	int i;
	float num = 1;
	*ml = 0;
	
	printf("Ingrese de numeros, para finalizar 0!\n");
	
	while (num != 0) {
		printf("Ingrese un numero: ");
		scanf("%f", &num);
		
		if (num != 0) {
			vec[*ml] = num;
			(*ml)++;	
		}
	}
}		

int main() {
	int num;
	vec_nums vec;
	
	ingreso(vec, &num);
	mostrar(vec, num);
	
	return 0;
}