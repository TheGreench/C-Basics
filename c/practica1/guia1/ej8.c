/*
Dado un mes escribir la cantidad de días de dicho mes. 
*/


#include <stdio.h>

int main() {
	int mes, dias;
	
	printf("Ingrese el numero de mes a calcular los dias: ");
	scanf("%d", &mes);
	
	if (mes == 4 || mes == 6 || mes == 9 || mes ==  11)
		printf("El ms tiene 30 dias!");
	else if (mes == 2)
		printf("El mes puede tener 28 o 29 dias, dependiendo si es bisiento o no!");
	else
		printf("El ms tiene 31 dias!");
	
	return 0;
	
}