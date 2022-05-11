/*
Dada una fecha año, mes y día, informar si es correcta o no. 
*/


#include <stdio.h>

int main() {
	int anio, mes, dia;
	
	printf("Ingrese el año: ");
	scanf("%d", &anio);
	
	printf("Ingrese el mes: ");
	scanf("%d", &mes);
	
	printf("Ingrese el dia: ");
	scanf("%d", &dia);
	
	if (mes > 12 || mes < 1) 
		printf("La fecha es incorrecta! Meses: 1 al 12");
	else if (dia > 31 || dia < 1) 
		printf("La fecha es incorrecta! Dias: 1 al 31");
	else 
		printf("La fecha es correcta: %d/%d/%d", dia, mes, anio);
		
	return 0;
	
}