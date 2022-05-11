/*
(evaluar_n)
Escribir una funcion en C q reciba com parametro un numero entero
n y que imprima por pantalla los n primeros terminos de la sucesion geometrica de razon 3 (1, 3, 9, 27, etc)

(evaluar_n_razon)
Escribir una funcion en C q reciba comop parametro un numero entero n
y otro entero razon y que devuelva al modulo invocante el max termino de la sucesion geometrica de razon
*/

#include <stdio.h>

int evaluar_n_razon(int n, int razon) {
	int res = 1, i;
	
	for (i = 1; i <= n; i++)
		res = res*razon;
		
	return res;
}

void evaluar_n(int n) {
	int res = 1, i;
	
	for (i = 1; i <= n; i++){
		printf("\n %d", res);
		res = res*3;
	}
}

//int main() {
//	int num = 9;
//	
//	evaluar_n(num);
//}