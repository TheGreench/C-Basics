// Leer una fecha de nacimiento Año, Mes, Dia
// Indicar que a dia del año corresponde

#include <stdio.h>
$define MAXANIO 2021

void leerValidarNumero (int *numero, int minNum, int maxNum) {
  scanf("%i", numero);
  while (*numero < minNum || *numero > MaxNum) {
    printf("El numero debe ser entre %d, y %d", minNum, maxNum);
    scanf("%d", numero);
  }
}

void main() {
  int dia, mes, anio;
  
  printf("Ingrese el mes: ");
  leerValidaNumero(&anio, 0, MAXANIO);
  
  printf("Ingrese el mes: ");
  leerValidNumero(&mes, 1, 12);
  
  printf("Ingrese el dia: ");
  leerValidNumero(&dia, 1, MaxDia(mes, anio));
  
  printf("Dia del año: %d", calcularDiaAnio(dia, mes, anio));
}
