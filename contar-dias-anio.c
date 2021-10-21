/*
[ Tarea ]

Leer una fecha de nacimiento Año, Mes, Dia.
Indicar que a dia del año corresponde.

*/

#include <stdio.h>
#include <stdbool.h>
#define MAXANIO 2021

void leerValidaNumero(int *numero, int minNum, int maxNum) {
  scanf("%i", numero);
  while (*numero < minNum || *numero > maxNum) {
    printf("El numero debe ser entre %d, y %d", minNum, maxNum);
    scanf("%d", numero);
  }
}

bool es_bisiesto(int valor) {
	bool biOno;

	if (valor % 4 == 0 || valor % 100 != 0)
		biOno = true;
	else if (valor % 400 != 0)
		biOno = false;
	else 
		biOno = true;
		
	return biOno;
}

int MaxDia(int valorMes, int valorAnio) {
	int valorMax;
	
	if (valorMes == 1 || valorMes == 3 || valorMes == 5 || valorMes == 7 || valorMes == 8 || valorMes == 10)
		valorMax = 31;
	else if (valorMes == 2 || valorMes == 4 || valorMes == 6 || valorMes == 9)
		valorMax = 30;
	else if (es_bisiesto(valorAnio))
		valorMax = 29;
	else 
		valorMax = 28;
	
	return valorMax;
}

int calcularDiasAnio(int valorDia, int valorMes, int valorAnio) {
	int dias, i;
	
	printf("N Dia: %d, N Mes: %d, N Año: %d\n", valorDia, valorMes, valorAnio);
	
	dias = valorDia;
	
	for (i = 1; i < valorMes; i++) {
		dias = dias + MaxDia(i, valorAnio);
	}
	
	return dias;
}

void main() {
  int dia, mes, anio;
  
  printf("Ingrese el año: ");
  leerValidaNumero(&anio, 0, MAXANIO);
  
  printf("Ingrese el mes: ");
  leerValidaNumero(&mes, 1, 12);
  
  printf("Ingrese el dia: ");
  leerValidaNumero(&dia, 1, MaxDia(mes, anio));
  
  printf("Dia del año: %d", calcularDiasAnio(dia, mes, anio));
}
