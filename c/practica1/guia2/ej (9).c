/*
Se tiene un listado de alumnos que consiste en número de padrón y 4
notas por alumno. Informar el mayor y el menor promedio registrado
junto con el numero de padrón del alumno, suponiendo que ambos son
únicos. 
*/

#include <stdio.h>

int promedio(int nota1, int nota2, int nota3, int nota4) {
	int prom;

	prom = (nota1 + nota2 + nota3 + nota4) / 4;

	return prom;
}

void ingresar(float *menorP, float *mayorP, int *menorPR, int *mayorPR) {
	float aux, nota1, nota2, nota3, nota4;
	*menorP = 100;
	*mayorP = -1;
	int padron = 1;

	while (padron != 0) {
		printf("Ingrese el padron del alumno: ");
		scanf("%d", &padron);

		if (padron != 0) {
			printf("Ingrese la nota 1: ");
			scanf("%f", &nota1);

			printf("Ingrese la nota 1: ");
			scanf("%f", &nota2);

			printf("Ingrese la nota 1: ");
			scanf("%f", &nota3);

			printf("Ingrese la nota 1: ");
			scanf("%f", &nota4);

			aux = promedio(nota1, nota2, nota3, nota4);
			if (aux < *menorP) {
				*menorP = aux;
				*menorPR = padron;
			}
			if (aux > *mayorP) {
				*mayorP = aux;
				*mayorPR = padron;
			}
		}
	}
}

void datos(float *menorP, float *mayorP, int *menorPR, int *mayorPR) {
	printf("Ingrese los datos de los alumnos, para finalizar padron = 0!");
	ingresar(&menorP, &mayorP, &menorPR, &mayorPR);
}

void mostrar_datos(float menorP, float mayorP, int menorPR, int mayorPR) {
	printf("\nDatos menor Promedio:");
	printf("\nPadron: %d \nPromedio: %.2f", menorPR, menorP);

	printf("\nDatos mayor Promedio:");
	printf("\nPadron: %d \nPromedio: %.2f", mayorPR, mayorP);
}

int main() {
	float menorProd, mayorProd;
	int menorPadron, mayorPadron;

	datos(&menorProd, &mayorProd, &menorPadron, &mayorPadron);

	mostrar_datos(menorProd, mayorProd, menorPadron, mayorPadron);

	return 0;
}