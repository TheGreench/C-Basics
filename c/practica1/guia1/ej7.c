/*
Ingresar un número que representa un mes, escribir el nombre del mes
correspondiente. Puede haber error en el número dado. 
*/


#include <stdio.h>

int main() {
	int mes;
	
	printf("Ingrese el numero de mes: ");
	scanf("%d",&mes);
	
	while (mes > 12 || mes < 12) {
		printf("Meses 1 al 12!\nIngrese el numero de mes: ");
		scanf("%d",&mes);	
	}
	
	switch (mes) {
		case 1: printf("El mes es Enero!");
			break;
		case 2: printf("El mes es Febrero!");
			break;
		case 3: printf("El mes es Marzo!");
			break;
		case 4: printf("El mes es Abril!");
			break;
		case 5: printf("El mes es Mayo!");
			break;
		case 6: printf("El mes es Junio!");
			break;
		case 7: printf("El mes es Julio!");
			break;
		case 8: printf("El mes es Agosto!");
			break;
		case 9: printf("El mes es Septiembre!");
			break;
		case 10: printf("El mes es Octubre!");
			break;
		case 11: printf("El mes es Noviembre!");
			break;
		case 12: printf("El mes es Diciembre!");
			break;
		default: printf("Mes incorrecto!");
	}
	
	return 0;
	
}