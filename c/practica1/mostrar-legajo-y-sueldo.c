/*Se tiene el listado de numeros de legajo y sueldos de los empleados de una empresa.
Se pide mostrar el sueldo mas alto y el legajo correspondiente a ese sueldo 
Mostrar todos los legajos y sueldos que sean inferiores a la mitad (o menos) que el sueldo maximo
Ingresar un legajo y mostrar el legajo y sueldo
Mostrar listado ordenado por Legajo. Mostrar Legajo y Sueldo.
Se sabe que no son mas de 1000 empleados en la empresa y la carga finaliza con legajo=0
*/
#include <stdio.h>

#define MAX 1000
typedef int tvLegajos[MAX];
typedef float tvSueldos[MAX];

// Inicio Grupo 3
void cargar_datos(tvLegajos vLegajos, tvSueldos vSueldos, int ml) {
  int input;
  ml = 0;
  while (input != 0) {
    for(int i=0; i<ml; i++) {
      printf("\nIngrese el legajo: ");
      scanf("%d", &vLegajos[i]);

      input = vLegajos[i];

      printf("\nIngrese el sueldo del legajo: %d = ", vLegajos[i]);
      scanf("%f", &vSueldos[i]);

      ml++;
    }
  }
}

void mostrar_inferiores(tvLegajos vLegajos, tvSueldos vSueldos, int ml, float sueldo) {
  printf("[ Mostrando sueldos menores a la mitad del sueldo maximo ]");
  for (int i = 0; i < ml; i++) {
    if(vSueldos[i]<(sueldo)/2)
      printf("%d %f", vLegajos[i], vSueldos[i]);
  }
}
// Fin Grupo 3

void main() {
  tvLegajos vLegajos;
  tvSueldos vSueldos;
  
  int ml;
  int pos_sueldo_maximo;
  
  cargar_datos(vLegajos, vSueldos, ml);
  pos_sueldo_maximo = buscar_max_sueld(vSueldos, ml);
  
  printf("Sueldo mas alto (legajo): %d (%d)", vSueldos[pos_sueldo_maximo], vLegajos[pos_sueldo_maximo]);
  
  mostrar_inferiores(vLegajos, vSueldos, ml, vSueldos[pos_sueldo_maximo]);
  buscar_mostrar_empleado(vLegajos, vSueldos, ml);
  mostrar_listado_ordenado(vLegajos, vSueldos, ml);
}
