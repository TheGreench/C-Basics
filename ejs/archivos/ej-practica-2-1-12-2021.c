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
  int i=0; // ?
  telRegistros = fopen("telRegistros.dat", "rb");

  if (telRegistros == NULL) 
    printf("ERROR: No hay archivo llamado 'telRegistros.dat' !");
  else {
    fread(&nRegistros, sizeof(nRegistros), 1, telRegistros);
    printf("Localidad Central Numero\n");
    
    while (!feof(telRegistros)) {
      if (nRegistros.localidad == localidad)
        printf("%i-%i-%i\n",nRegistros.localidad, nRegistros.central, nRegistros.numero);
      fread(&nRegistros, sizeof(nRegistros), 1, telRegistros);
    }
    fclose(telRegistros);
  }
}

int main(void) {
  FILE *telRegistros;
  int localidad;
  int num;


/*
telRegistros = fopen("telRegistros.dat", "w");
  do{
    printf("localidad:");
    scanf("%i", &reg.localidad);
    printf("central:");
    scanf("%i", &reg.central);
    printf("numero:");
    scanf("%i", &reg.numero);
    fwrite(&reg, sizeof(reg), 1, telRegistros);
    printf("continuar?");
    scanf("%i", &num);
    printf("\n%i  -  %i  -  %i\n\n", reg.localidad, reg.central, reg.numero);
  } while(num != 0);
  fclose(telRegistros);
*/
  printf("Ingrese una caracteristica de localidad (4 digitos): ");
  scanf("%i", &localidad);
  mostrar_datos(telRegistros, localidad);

  return 0;
}

// Gracias
