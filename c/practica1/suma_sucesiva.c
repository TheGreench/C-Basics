/*
escribir un programa que solicite el ingreso de 2 valores enteros y luego informe
el resultado de multiplicarlos, pero mediante sumas sucesivas. 
*/

#include <stdio.h>

void cargar_datos(int *num1, int *num2) {
	printf("Ingrese el primer valor entero: ");
	scanf("%d", num1);
	printf("Ingrese el segundo valor entero: ");
	scanf("%d", num2);
}

void mostrar_ej(int num1, int num2) {
	int aux=num1, i;

	for(i=1; i< num2; i++){
		aux += num1;
		printf("\n %d", aux);
	}
}

int main() {
	int num1, num2;
	cargar_datos(&num1, &num2);
	mostrar_ej(num1, num2);
	return 0;
}