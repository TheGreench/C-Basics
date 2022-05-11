/*
Escribir un programa modular que solicite el ingreso de la cantidad de mililitros llovidos
 en la semana, de lunes a domingo, de 0 a 23hs.
El ingreso de datos es por dia comenzando el lunes, y para cada dia, por hora de 0 a 23.
Informar el promedio de mililitros llovidos para cada dia de la semana.
informar por cada dia y cada hora cuanto llovio
Informar por cada días la cantidad de horas que llovio mas que el promedio del día
Informar cual fue el día de la semana que mas llovió
*/

#include <stdio.h>

#define DIAS 7
#define HORAS 24

typedef float tv_mililitros [DIAS][HORAS];

void show_Dia(int dia) {
  	switch ( dia ) {
    	case 1 : printf( "\nEl dia Lunes" );
            break;
    	case 2 : printf( "\nEl dia Martes" );
            break;
    	case 3 : printf( "\nEl dia Miercoles" );
            break;
    	case 4 : printf( "\nEl dia Jueves" );
            break;
    	case 5 : printf( "\nEl dia Viernes" );
            break;
    	case 6 : printf( "\nEl dia Sabado" );
            break;
    	case 7 : printf( "\nEl dia Domingo" );
            break;
        default : printf( "\n   ERROR: Dia incorrecto." );
    }
}

void ingresar_datos(tv_mililitros mili) {
	int i, j;
	float num;
	for (i=0 ; i<DIAS; i++){
    	show_Dia(i+1);
    	for (j=0; j<HORAS; j++) {
      		printf("\n Ingrese los mililitros de lluvia a la hr %d: \n", j+1);
    		scanf("%f", &num); 
    		mili[i][j] = num;
    	}
  	}
}

float suma(tv_mililitros mili, int num) {
	int i;
	float sum = 0;
  
	for (i = 0; i<HORAS; i++)
    	sum += mili[num][i];
  
  	return sum;
}

void calcular_promedio(tv_mililitros mili) {
    int i ;
 
    for (i=0 ; i<DIAS; i++){
    	show_Dia(i+1);
      	printf("Promedio = %f", i+1, suma(mili, i)/HORAS);
    }
}


void mostrar_datos(tv_mililitros mili){
  	int i, j;
  
  	for (i=0 ; i<DIAS; i++){
    	show_Dia(i+1);
    	for (j=0; j<HORAS; j++)
      		printf("Hora %d: llovió %f mm", j, mili[i][j]);
    }
}

void informar_ej3(tv_mililitros mili) {
	int i , j, contador;
	float prom;
  
   	for (i=0 ; i<DIAS; i++){
    	contador = 0;
    	prom = suma(mili, i)/HORAS;
     	show_Dia(i+1);
     	
     	for (j = 0; j < HORAS; j++) {
       		if (mili[i][j] > prom) 
        		contador += j;
       	
       		printf("\nSe paso el promedio %d hrs - promedio: ", contador, prom);
     	}
    }
}

int MaxDiaLLuvia(tv_mililitros mili) {
  	int i, j;
  	float max = 0, sum;
  
  	for (i=0 ; i<DIAS; i++){
    	sum = suma(mili, i);
      	if (sum > max) max = i+1;
    }
 
}

int main(){
	
	tv_mililitros mili;
  
  	ingresar_datos(mili); 
  	calcular_promedio(mili);
  	mostrar_datos(mili);
    printf("El dia que mas llovio es");
    show_Dia(MaxDiaLLuvia(mili));
    //mostrarhoraS(MaxDiaLLuvia(mili));
    
  	return 0;
	
}