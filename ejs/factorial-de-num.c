/*
Escribir una función que reciba un valor y calcule el factorial del mismo. Si no se
puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo
contrario deberá devolver el valor calculado. 

*/

#include <stdio.h>

int cal_factorial(int n) {
	int i;
	int producto = 1;
		
	for (i = n; i > 1; i--) {
		producto *= i;
	}	

	return (producto);
}

void main() {
	int num, fact;
	
	printf("Dar un entero entre para calcular el factorial (1 al 15): ");
	scanf("%d", &num);
	
	if (num > 0 && num < 16) {
		fact = cal_factorial(num);
		printf("El factorial de %d es %d\n", num, fact);
	} 
	else fact = 0;
	
	return (fact);
}
