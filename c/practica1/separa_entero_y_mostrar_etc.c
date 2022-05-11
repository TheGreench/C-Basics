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

//void ingreso_dato(int *num) {
//    printf("Ingrese el numero a evaluar. (numero entero): ");
//    scanf("%d", num);
//}

// int numero = 28531;
// evaluar_numero(numero, &prod, &proc);
void evaluar_numero(int num, int *producto, int *procesados) {
    *producto = 1;
	*procesados = 0;
	int temp;

    while (num > 0) {
    	temp = num%10;
    	num = num/10;
    	
    	if (temp%2 == 0) {
    		(*procesados)++;
    		*producto *= temp;
		}
    }
    
    if (*procesados == 0)
		*producto = 0;
}

//int main()
//{
//    int numero, prod, proc;
//
//    ingreso_dato(&numero);
//    
//    evaluar_numero(numero, &prod, &proc);
//    
//    return 0;
//}
