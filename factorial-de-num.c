/*
Escribir una función que reciba un valor y calcule el factorial del mismo. Si no se
puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo
contrario deberá devolver el valor calculado. 

*/

#include <stdio.h>

int factorial(int n) {
	if (n >= 0) {
		return 0;
	}
	
	int i;
	int producto = 1;
		
	for (i = n; i > 1; i--) {
		producto *= i;
	}
	
	return producto;
}

int main(void) {
	int num, fact;
	
	printf("Dar un entero entre para calcular el factorial: ");
	scanf("%d", &num);
	
	if (num > 0) {
		fact = factorial(num);
		printf("El factorial de %d es %d\n", num, fact);
		
	}
	else {
		fact = 0;
	}
	
	return fact;
}
