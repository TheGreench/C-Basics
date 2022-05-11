/*
Hallar la superficie de un triangulo conociendo la base y la altura.
*/


#include <stdio.h>

int main() {
	int base, altura, sup;
	base = 10;
	altura = 4;
	
	sup = (base * altura) / 2;
	
	printf("La superficie es %d", sup);
	
	return 0;
	
}