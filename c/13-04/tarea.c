#include <stdio.h>

int main() 
{	
	/*
	Ingrese la cantidad de alumnos de la catedra, luego por cada uno indique si entregaron el Final. 
		Indicar que  porcentaje de alumnos entrego el Final
		Indicar cuantos alumnos no entrego
	*/
	
	int alumnos, i, entregaron = 0, entrega;
	float porcentaje;

	printf("Ingrese la cantidad de alumnos de la catedra: ");
	scanf("%d", &alumnos);

	while (alumnos < 1 ) {
		printf("Cantidad de alumnos invalida! Re Ingrese: ");
		scanf("%d", &alumnos);
	}
		
	printf("[ Indique alumno x alumno si entrego o no con: (1 (si) | 0 (no) ]\n");
	printf("[ Ejemplo: Entrego? 1                                           ]\n\n");
	
	for (i = 0; i < alumnos; i++) {
		printf("El alumnno %d entrego? (1 (si) | 0 (no)): ", i+1); 
		scanf("%d", &entrega);
			
		if (entrega == 1) entregaron++;
	}
		
	if (entregaron > 0) {
		porcentaje = (entregaron * 100) / alumnos;
		printf("\nEl porcentaje de alumnos que entregaron es :  %3.3f%%", porcentaje);
		printf("\nLa cantidad que entrego fue                :  %d/%d", entregaron, alumnos);
		printf("\nLa cantidad que no entrego fue             :  %d/%d \n", (alumnos - entregaron), alumnos);
	}	

	return 0;
}
