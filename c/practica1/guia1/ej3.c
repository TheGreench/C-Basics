/*
Calcular el sueldo de un operario ingresando por teclado la cantidad de
horas que trabajó en el mes y el valor de la hora.

*/


#include <stdio.h>

int main() {
	int hrs;
	float valorHr, total;
	
	printf("Ingrese la cantidad de horas trabajas: ");
	scanf("%d", &hrs);
	
	printf("Ingrese el valor de la hr: ");
	scanf("%f", &valorHr);
	
	total = hrs * valorHr;
	
	printf("El sueldo del operario es: $ %.2f", total);
	
	return 0;
	
}