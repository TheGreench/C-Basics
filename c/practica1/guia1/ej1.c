/*
Ingresar un número entero y decir si:
a) es par o impar.
b) es mayor, menor o igual a cero.
*/


#include <stdio.h>

int main() {
	int num;
	
	printf("Ingrse un numero pra ver si es par o no: ");
	scanf("%d", &num);
	
	if (num % 2 == 0) 
		printf("El numero es par!");
		
	if (num == 0) 
		printf("\nEl numero es = a 0!");
	else {
		if (num > 0)
			printf("El numero es mayor a 0!");
		else
			printf("El numero es menor a 0!");
	}
	
	return 0;
	
}