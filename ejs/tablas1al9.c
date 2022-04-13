/* Mostrar tablas del 1 al 9. Nums del 1 al 100*/
#include <stdio.h>

int main() {
  int tabla, operacion;
  
  printf("Mostrando tablas...");
  for (tabla = 1; operacion < 101; operacion++) {
    printf("%d x %d = %d", operacion, tabla, operacion * tabla);
  }
  
  return 0;
}
