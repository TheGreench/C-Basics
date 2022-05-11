/*
 Se realiza una encuesta para estimar el grado de aceptación de los
productos x e y en el mercado. A cada encuestado se le pregunta si
consume el producto x y si consume el producto y. La respuesta puede
ser sí o no. Se pide calcular e informar el porcentaje de consumidores
de:
a) del producto x
b) del producto y
c) del producto x solamente
d) del producto y solamente
e) de ambos productos
f) de ninguno de los productos
*/

#include <stdio.h>

float porcentaje(int num, int max) {
	int porcentaje;
	
	porcentaje = (num * 100) / max;
	
	return porcentaje;
}

void informar_sobre_prods(int cantidadEncuestados, int cantidadSiX, int cantidadSiY) {
	int i, cantidadNinguno, cantidadSoloX, cantidadSoloY;
	
	if (cantidadSiX < cantidadSiY){
		cantidadSoloX = 0;
		cantidadSoloY = cantidadSiY - cantidadSiX;
		cantidadNinguno = cantidadEncuestados - cantidadSiX;
	}
	else if (cantidadSiX > cantidadSiY) {
		cantidadSoloY = 0; 
		cantidadSoloX = cantidadSiX - cantidadSiY;
		cantidadNinguno = cantidadEncuestados - cantidadSiY;
	}
	else {
		cantidadSoloX = 0;
		cantidadSoloY = 0;
		cantidadNinguno = cantidadEncuestados - cantidadSiY;
	}
	
	printf("Mostrando porcentaje de Si X:        %.0f", porcentaje(cantidadSiX, cantidadEncuestados));
	printf("\nMostrando porcentaje de solo Si X:   %.0f", porcentaje(cantidadSoloX, cantidadEncuestados));
	printf("\nMostrando porcentaje de Si Y:        %.0f", porcentaje(cantidadSiY, cantidadEncuestados));
	printf("\nMostrando porcentaje de solo Si Y:   %.0f", porcentaje(cantidadSoloY, cantidadEncuestados));
	printf("\nMostrando porcentaje de Si X e Y:    %.0f", porcentaje(cantidadSiY + cantidadSiX, cantidadEncuestados*2));
	printf("\nMostrando porcentaje de ninguno:     %.0f", porcentaje(cantidadNinguno, cantidadEncuestados));
}

int main() {
	informar_sobre_prods(40, 32, 32);
	return 0;
}