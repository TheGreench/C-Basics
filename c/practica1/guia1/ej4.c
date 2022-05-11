/*
Ingresar tres números y hallar el mayor. 
*/


#include <stdio.h>

void ingreso(int *num) {
	printf("Ingrese un numero: ");
	scanf("%d", num);
}

void mayor(int num1, int num2, int num3) {
	int max;
	
	max = num1;
	
	if (num2 > max) max = num2;
	if (num3 > max) max = num3;
	
	printf("El mayor es el: %d", max);
}

int main() {
	int num1, num2, num3;
	
	ingreso(&num1);
	ingreso(&num2);
	ingreso(&num3);
	
	mayor(num1, num2, num3);
	
	return 0;
	
}