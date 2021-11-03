/*
Leer un numero N positivo y luego leer una serie de N numeros
positivos. Para los numeros que sean primos mostarr el numero
invertido y los que no lo sean mostar divisores
*/

#include <stdio.h>
#include <stdbool.h>

void leer_valido(int *num) {
	printf("\nIngrese un numero positivo: ");
	scanf("%d", num);
	
	while (*num < 0) {
		printf("\n[INGRESO UN NUMERO NEGATIVO] - Ingrese un numero positivo: ");
		scanf("%d", num);
	}
}

bool es_primo(int b) {
	int i = 2;
	bool primo = true;
	
	while((i <= (b / 2)) && primo) {
		if((b % i) == 0)
			primo = false;
		i++;
	}
	return primo;
}

int invertir_numero(int aux) {
	int inv;
 	
	inv = aux % 10;
	
	while (aux > 9) {
		aux = (aux / 10);
		inv = (inv * 10) + (aux % 10);
	}
	
 	return inv;
}

void cal_divisores(int f) {
	int divisor_actual, i;

    printf("Los divisores de %d son: ", f);

	for (i = 1; i <= f ; i++){
		if (f % i == 0){
			printf("%d, ",i);
		}
	}
}

void main() {
	int n, i, a;
	
	leer_valido(&n);
	
	for (i = 1; i <= n; i++) {
		leer_valido(&a);
		
		if (es_primo(a)){
			printf("%d \n", invertir_numero(a));
		}
		else {
			cal_divisores(a);
		}
	}	

	return 0;
}
