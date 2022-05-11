/* 
   Escribir un programa modular en C, que solicite el ingreso de hasta 10 valores enteros.
   El ingreso de datos puede terminar porque el usuario ingresó 0 o bien porque se alcanzó la cantidad
   máxima de elementos. Muestre los números ingresados por el usuario.
*/

#include <stdio.h>
#define MAX 10

typedef int arreglo_enteros[MAX];

void most_arr(int a[], int ultima_pos) {
	int i;
	for (i = 0; i <= ultima_pos; i++)
		printf("%i ", a[i]);
}

int main() {
	int num, cant;
	arreglo_enteros arr;
	
	cant = 1;
	
	printf("Ingrese hasta 10 valores enteros. (para salir antes ingrese 0)\n");
	printf("Un valor: ");
	scanf("%d", &num);
	
	while ((num != 0) && (cant < MAX)) {
		arr[cant] = num;
		cant++;
		printf("Ingrese otro valor: ");
		scanf("%d", &num);
	}
	
	most_arr(arr, MAX);
}
