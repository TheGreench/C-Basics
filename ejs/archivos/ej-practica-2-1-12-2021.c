/*
Se tiene un archivo de números telefónicos cuyos registros son de la forma: 
Característica de localidad (4 dígitos) 
Característica central (4 dígitos) 
Número (4 dígitos) 

Dado un número que representa una característica de localidad, listar todos los números telefónicos con dicha característica. 

Suponer los siguientes casos: 
  a) El archivo no cabe en memoria y está desordenado. 
  b) El archivo no cabe en memoria y está ordenado según números telefónicos crecientes. 
*/

#include <stdio.h>

typedef struct{
  int localidad;
  int central;
  int numero;
} t_nRegistro;

void mostrar_datos(FILE *telRegistros, int localidad) {
  t_nRegistro nRegistros;
  int i=0;
  telRegistros = fopen("telRegistros.dat", "rb");

  if (telRegistros == NULL) 
    printf("ERROR: No hay archivo llamado 'telRegistros.dat' !");
  else {
    printf("localida-central-numero");
    while (!feof(telRegistros)) {
      fread(&nRegistros, sizeof(nRegistros), 1, telRegistros);
      if (nRegistros.localidad == localidad)
        printf("%i-%i-%i",nRegistros.localidad, nRegistros.central, nRegistros.numero);
      else
        printf("No hay numeros con esa localidad!");
    }
    fclose(telRegistros);
  }
}

int main(void) {
  FILE *telRegistros;
  int localidad;

  printf("Ingrese una caracteristica de localidad (4 digitos): ");
  scanf("%i", &localidad);
  mostrar_datos(telRegistros, localidad);

  return 0;
}
