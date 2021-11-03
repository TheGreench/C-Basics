/* Inclusion de archivos */
#include <stdio.h>
/* #include <stdlib.h> // Lib para system("PAUSE");*/

/* Funcion principal*/
int main() 
{	
	/* Ej: 
	Escribir un programa que permita al usuario ingresar numeros enteros
	positivos y que al finalizar informe x pantalla cual fue el mayor
	de los n ingresados
	
	se desconoce cantidad de datos a ingresar
	
	se finaliza al cargar 0
	*/
	
	int num,ant,max;
	
	printf("Ingrese un numero entero y positivo para comparar: ");
	scanf("%d", &num);
			
	while (num != 0) {
		if (num < 0)
			printf("El numero ingresado debe ser positivo!\n");	

		ant = num;
		printf("Ingrese un numero para comparar: ");
		scanf("%d", &num);
		
		if (num > ant)
			max = num;
	}
	
	printf("El numero mas grande ingresado fue: %d", max);
	
	return 0;
}
