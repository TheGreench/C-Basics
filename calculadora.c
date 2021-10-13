#include <stdio.h>

int main() 
{
	/*
	Nicolas Invernizzi - 108761

	[ Tarea ]
	Calculadora. 
	- Ingresar 2 valores y un operador matematico (+,-,*,/,^) y 
	  devolver el resultado de la operacion. (^ representa la potencia) 
	*/
	
	// Declarar Variables
	/*
	valor1 = al primer valor
	valor2 = al sgundo valor
	ope = operacion
	i = while en potencia
	*/
	
	int valor1, valor2, i;
	float ope;
	char operador;
	
	// Tomar primer valor
	printf("Ingrese el primer valor: ");
	scanf("%d", &valor1);
	
	fflush(stdin);
	
	// Tomar segundo valor
	printf("Ingrese el segundo valor: ");
	scanf("%d", &valor2);
	
	fflush(stdin);
	
	// Tomar el operador
	printf("Ingrese el operador (+,-,*,/,^): ");
	scanf("%c", &operador);
	
	// Calculos
	switch (operador) {
		// Suma
		case '+':
			ope = valor1 + valor2;
			printf("La suma entre %d y %d es: %d", valor1, valor2, ope);
			break;
		//Resta
		case '-':
			ope = valor1 - valor2;
			printf("La resta entre %d y %d es: %d", valor1, valor2, ope);
			break;
		// Multiplicacion
		case '*':
			ope = valor1 * valor2;
			printf("La multiplicacion entre %d y %d es: %d", valor1, valor2, ope);
			break;
		// Division
		case '/':
			ope = valor1 / valor2;
			printf("La division entre %d y %d es: %d (resto %d)", valor1, valor2, valor1 / valor2, valor1 % valor2);
			break;
		// Potencia
		case '^':
			ope = valor1;
			while (i < valor2 - 1) {
				ope = ope * valor1;
				++i;
			}
			printf("La potencia de %d sobre %d es: %d", valor1, valor2, ope);
			break;
		default:
			printf("Valores ingresados no permitidos.");
	}
	
	
	return 0;
}
