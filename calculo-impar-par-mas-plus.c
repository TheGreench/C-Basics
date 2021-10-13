/*
Leer un numero N positivo y luego leer una serie de N numeros
positivos. Para los numeros que sean primos mostarr el numero
invertido y los que no lo sean mostar divisores

SIN las funciones
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Lib para system("PAUSE");

void main() {
	int n, i, a;
	
	leer_valido(&n);
	
	// fflush(stdin);
	
	for (i = 1; i <= n; i++) {
		leer_valido(&a);
		
		if (a % 2 == 0) {
			printf("%d", invertir_numero(a));
		}
		else {
			cal_divisores(a);
		}
	}	
	
	system("PAUSE");
	return 0;
}
