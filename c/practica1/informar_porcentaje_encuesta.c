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

#define MAX 100
// 1 = si , 0 = no
typedef int VecEncuestadosX[MAX];
typedef int VecEncuestadosY[MAX];

void cargar_datos(VecEncuestadosX encX, VecEncuestadosY encY, int *ml) {
	int i, auxX, auxY;
	
	printf("Ingrese cantidad de encuestados: ");
	scanf("%d", ml);
	
	for (i = 0; i<*ml; i++) {
		printf("Ingrese si una el producto X (si  = 1 | no = 0): ");
		scanf("%d", auxX);
		encX[i] = auxX;
		
		printf("Ingrese si una el producto Y (si  = 1 | no = 0): ");
		scanf("%d", auxY);
		encY[i] = auxY;
	}
}

void informar_porcentage(int num, int ml) {
	float porcentaje;
	
	porcentaje = (num * 100) / ml;
	
	printf("El porcentaje es: %f", porcentaje);
}

void calcular_encuestas(VecEncuestadosX encX, VecEncuestadosY encY, int ml) {
	int i, j, contadorProdX = 0, contadorProdY = 0, contadorProdNull = 0;
	
	for (i=0; i<ml; i++) {
		if ((encX[i] == 0) && (encY[i] == 0)) contadorProdNull++;
		if (encX[i] == 1) contadorProdX++;
		if (encY[i] == 1) contadorProdY++;
	}
	
	printf("\nPorcentaje del producto X: ");
	informar_porcentage(contadorProdX, ml);
	
	printf("\nPorcentaje del producto Y: ");
	informar_porcentage(contadorProdY, ml);
	
	printf("\nPorcentaje del ninguno de los productos: ");
	informar_porcentage(contadorProdNull, ml);
}

int main() {
	VecEncuestadosX encX;
	VecEncuestadosY encY;
	int ml;
	
	cargar_datos(encX, encY, &ml);
	calcular_encuestas(encX, encY, ml);

	return 0;
}