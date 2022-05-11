/*
Calcular la suma de los n primeros números naturales
*/


#include <stdio.h>

int main() {
	int num, suma = 0, i;
	
	num = 8;
	
	for (i = 0; i < num; i++) {
		suma += i;
	}
	
	printf("La suma de los %d naturales es: %d", num, suma);
	
	return 0;
	
}