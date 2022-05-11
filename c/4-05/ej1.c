/*
Escriir una funcion en c q reciba como parametro un numero entero y devuelva al modulo invocante los siguientes valores:
- El res de multiplicar digitos pares
- cantidad de digitos que cumplieron con la condicion y fueron procesados

Ej:
- Numero con el q se invoca 25831
- Dig pares = 2, 8
Devuelve valores: 16 y 2. El 16 por el producto y el 2 por la cantidad de digitos

Nota: para la resolucioin de este ejercicio no se pueden usar arreglos
*/

#include <stdio.h>

/**
 * Esta función le pide al usuario que ingrese un número y lo almacena en la variable num
 */
void ingreso_dato(int *num) {
    printf("Ingrese el numero a evaluar. (numero entero): ");
    scanf("%d", num);
}

/**
 * Toma un número como entrada, y luego imprime los dígitos del número en orden inverso, y luego
 * imprime el producto de todos los dígitos pares del número, y luego imprime el número de pares
 * dígitos en el número
 */
void evaluar_numero(int num) {
    int producto = 1, procesados = 0, temp;
    
    printf("\nNumero ingresado: %d", num);

    while (num > 0) {
    	temp = num%10;
    	num = num/10;
    	
    	if (temp%2 == 0) {
    		/* Incrementando el valor de `procesados` en 1. */
            procesados++;
    		producto *= temp;
		}
    	
        printf("\n %d", temp);
    }

    printf("\nProducto = %d | Digitos Procesados %d", producto, procesados);
}

/**
 * La función ingreso_dato() toma un puntero a un número entero como argumento y pide al usuario que
 * Ingrese un numero
 */

int main()
{
    int numero;

    ingreso_dato(&numero);
    
    evaluar_numero(numero);
    
    return 0;
}
