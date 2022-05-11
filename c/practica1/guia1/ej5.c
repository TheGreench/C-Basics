/*
Ingresar el radio de una esfera y calcular el volumen. 
*/


#include <stdio.h>

int main() {
	float radio, volumen, potencia = 3;
	
	printf("Ingrese el radio de la esfera: ");
	scanf("%f", &radio);
	
	while (potencia > 1) {
		radio *= radio;
		potencia--;
	}
	
	volumen = (4 / 3) * 3,14 * radio;
	
	printf("El volumen es: %f", volumen);
	
	return 0;
	
}