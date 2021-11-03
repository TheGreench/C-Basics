/* Inclusion de archivos */
#include <stdio.h>
#include <stdlib.h> // Lib para system("PAUSE");

/* Funcion principal*/
int main() 
{	
	/* Ej: 
	Ingrese la cantidad de alumnos de la cátedra, luego por cada uno indique si entregaron el TP1. 
    - Indicar qué porcentaje de alumnos entregó el TP
    - Indicar cuántos alumnos no lo entregaron
	*/
	
	// Declarar Variables
	int alumnos,porcentaje,i,entregaron,entrega;
	//char entrega;
	
	// Tomar input de alumnos
	printf("Ingrese la cantidad de alumnos de la catedra: ");
	scanf("%d", &alumnos);
	
	printf("[ Indique alumno x alumno si entrego o no con: (1 (si) /0 (no))    ]\n");
	printf("[ Ejemplo: Entrego? s                                              ]\n");

	// Tomar x de inputs
	for (i = 0; i != alumnos; i++) {
		// Chequear si el valor ingresado es si o no
		do {
			printf("Valor incorrecto!");
			printf("Indique si el alumno entrego (1 (si) /0 (no)): ");
			scanf("%c", &entrega);
		} while (entrega != 1 || entrega != 0);
		
		if (entrega == 1) 
			entregaron += 1;
	}
	
	if (entregaron > 0) {
		porcentaje = (entregaron * 100) / alumnos;
		printf("El porcentaje de alumnos que entregaron es: %d %\n", porcentaje);
		printf("\nLa cantidad que no entrego fue: %d \n", (alumnos - entregaron));
	}

	system("PAUSE");
	return 0;
}
