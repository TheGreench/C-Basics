/*
Escribir un programa modular que solicite el ingreso de la cantidad de mililitros llovidos
 en la semana, de lunes a domingo, de 0 a 23hs.
El ingreso de datos es por dia comenzando el lunes, y para cada dia, por hora de 0 a 23.
Informar el promedio de mililitros llovidos para cada dia de la semana.
informar por cada dia y cada hora cuanto llovio
*/

#include <stdio.h>


#define DIAS 7
#define HORAS 24

typedef float tv_mililitros [DIAS][HORAS];

void ingresar_datos(tv_mililitros mili) {
  int i, j;
  float num;
  for (i=0 ; i<DIAS; i++){
    for (j=0; j<HORAS; j++) {
    	scanf("%f", &num); 
    	mili[i][j] = num;
    }
  }
}

float promedio(tv_mililitros mili, int num) {
  int i;
  float prom = 0;
  
  for (i = 0; i<HORAS; i++) {
    prom += mili[num][i];
  }
  
  prom = prom/HORAS;
  
  return prom;
}

void calcular_promedio(tv_mililitros mili) {
    int i;
  
    for (i=0 ; i<DIAS; i++){
      printf("Promedio del dia %d = %f", i+1, promedio(mili, i));
    }
}


void mostrar_datos(tv_mililitros mili){
  int i, j;
  
  for (i=0 ; i<DIAS; i++){
    for (j=0; j<HORAS; j++)
      printf("%f",mili[i][j]);
  
    }
}

int main(){
	
	tv_mililitros mili;
  
  ingresar_datos(mili); 
  calcular_promedio(mili);
  
  return 0;
	
}