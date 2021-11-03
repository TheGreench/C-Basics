/* Inclusion de archivos */
#include <stdio.h>
/* #include <stdlib.h> // Lib para system("PAUSE");*/

/* Funcion principal*/
int main() 
{	
	/* Ej: 
	leer n y dibujar por la pantalla un triangulo de n filas
	*
	**
	***
	****
	*****
	etc
	*/
	
	int num,i,f;
	
	printf("Ingrese un numero para hacer el triangulo: ");
	scanf("%d", &num);
			
	for (i = 0; i < num; i++) {
		for (f = 0; f < i; f++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;
}
