// 4) Ingresar tres números y hallar el mayor.

#include <stdio.h>

void cargar_num(int *num) {
	printf("Ingrese un numero: ");
	scanf("%d", &num);
}

void comparar_nums(int *max) {
	int num1, num2, num3;
	
	cargar_num(&num1);
	cargar_num(&num2);
	cargar_num(&num3);
	
	max = num1;
	if (num2 > *max) *max = num2;
	if (num3 > *max) *max = num3;
	
}

int main (){
	int max;
	
	comparar_nums(&max);
	printf("El numero mas grande fue: %d", max);

	return 0;
}