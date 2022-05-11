/*
4. Escribir un programa que solicite el ingreso de dos números, y luego informe los
números primos que hay entre esos dos números.
Se debe validar que los números ingresados sean enteros y además que el primer
número sea menor o igual que el segundo.

*/

#include <stdio.h>

/**
 * Le pide al usuario que ingrese dos números y luego verifica que los números sean positivos. Si ellos estan
 * no, le pide al usuario que los ingrese nuevamente
 */
void ingrese_numeros(int *num1, int *num2){
    printf("Ingrese numero 1 => ");
    scanf("\n  %d", num1);

    printf("Ingrese numero 2 => ");
    scanf("\n  %d", num2);

	while (*num1 < 0 || *num2 < 0) {
		if (*num1 < 0) {
			printf("VALOR INCORRECTO ,Ingrese numero 1 => ");
        	scanf("%d", num1);
		}
		if (*num2 < 0) {
			printf("VALOR INCORRECTO ,Ingrese numero 2 => ");
        	scanf("%d", num2);
		}
	}
}

/**
 * La función funcion_numero_mayor toma dos enteros como entrada y devuelve el mayor de los dos
 * números enteros
 */
void funcion_numero_mayor(int num1, int num2, int *mayor, int *menor){
    if(num1 >= num2){
        *mayor = num1;
        *menor = num2;
    }    
    else{
        *mayor = num2;
        *menor = num1;
    }    

}

/**
 * Devuelve 1 si el número es primo, 0 en caso contrario
 * num El número a revisar.
 */
int es_primo(int num) {
	// variable a retornar
	int val = 1;
	// 1= true || 0=false
	
	if (num == 0 || num == 1 || num == 4)
		val = 0; // No es primo

	for (int x = 2; x < num / 2; x++) {
		if (num % x == 0)
			val = 0; // No es primo
	}

	return val;
}

/**
 * Imprime todos los números primos entre dos números.
 */
void numeros_primos(int mayor, int menor){
    int i,j;

	printf("Mostrando numeros primos entre %d y %d\n", menor, mayor);
	for (i = menor + 1; i < mayor; i++) {
		/* Imprimiendo el número si es primo. */
		if (es_primo(i))
			printf(" %d ", i);
	}

}


/**
 * Toma dos números, encuentra el mayor y el menor de los dos, y luego imprime todos los números primos
 * entre los dos
 */
int main(){
    int num1, num2, mayor, menor;

    ingrese_numeros(&num1, &num2);
    funcion_numero_mayor(num1, num2, &mayor, &menor);
    numeros_primos(mayor, menor);

    return 0;
}