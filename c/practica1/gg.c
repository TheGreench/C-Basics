//ej1
// Ingresar una serie de de numeros positivos (validar) en un vector. 
// Invertir el vector y mostrar la serie invertida.

// ej2
//Ingresar una serie de numeros, entre 0 y 99,  
// finalizada con un numero negativo y mostrar la cantidad de veces que aparece cada numero en la serie

#include <stdio.h>

#define MAX 100
typedef int tv_numeros [MAX];

void cargar_nums(tv_numeros nums, int* ml) {
	int numero;
    *ml = 0;
    
    printf(" Ingrese una serie de numeros positivos, para finalizar ingrese un numero negativo o mayor a 99!\n(MAX 100 y del 0 al 99)\n");
    
    printf("\n Ingrese el primer numero: ");
    scanf("%d", &numero);
    
    while ((numero >= 0) && (*ml < MAX) && (numero >= 0) && (numero <= 99)) {        
		nums[*ml] = numero;
        (*ml)++;
        
        printf(" Ingrese el siguiente numero: ");
        scanf("%d", &numero);
    }
}

void mostrar_serie(tv_numeros nums, int ml) {
    int i;
    
    printf("\n Mostrando la serie ingresada:\n");
    for (i = 0; i < ml; i++) 
		printf(" %d ", nums[i]);
}

void invertir_serie(tv_numeros nums, int ml) {
    int i;
    
    printf("\n Mostrando la serie invertida:\n");
    for (i = ml-1; i >= 0; i--) 
		printf(" %d ", nums[i]);
}

void mostrar_repetidos(tv_numeros nums, int ml) {
	int i, j, contador = 0;
	
	printf("\n\n Mostrando cantidad de veces que cada numero se repitio: ");
	printf("\n[ Numero\t|\tCantidad en la Serie ]");
	
	for (i = 0; i < ml; i++) {
		for (j = 0; j < ml; j++)
			if (nums[j] == nums[i]) contador++;

		printf("\n  %d \t\t|\t %d", nums[i], contador);
		printf("\n----------------------------------------------");
			
		contador = 0;
	}
}

int main()
{
    int ml;
    tv_numeros nums;
    
    printf("--- INICIANDO PROGRAMA - TAREA 28/04/22 ---\n\n");
    
    cargar_nums(nums, &ml);
    
    if (ml < 1) printf("\n [ No se ingresaron numeros ]");
    else {
	    mostrar_serie(nums, ml);
	    invertir_serie(nums, ml);
	    mostrar_repetidos(nums, ml);    	
	}
    
    printf("\n\n------ FIN PROGRAMA - TAREA 28/04/22 ------");
    

    return 0;
}
