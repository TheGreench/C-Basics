/* 
Realizar dos programas. 
 - Uno que permita Guardar todos los alumnos que se encuentran en las carreras de Informática de FIUBA (DNI, Nombre Email)
 - Otro que permita mostrar los alumnos.
*/

#include <stdio.h>
#include <string.h>
#define MAX_NOM 100
typedef char String[MAX_NOM];
typedef struct  {
  int DNI;
  String Nombre;
  String Email; 
} TRegistro;

// EJ 1
void cargar(FILE * Archivo) {
	TRegistro registro;
	char cargar = 's';
	while(cargar == 's'){
		printf("Ingrese el DNI del alumno: ");
		scanf("%i", &registro.DNI);
		printf("Ingrese el nombre del alumno:");
		scanf("%30[^\n]s", registro.Nombre);

		while ((getchar()) != '\n'); // = fflush

		printf("Ingrese el email del alumno:");
		scanf("%30[^\n]s", registro.Email);

		while ((getchar()) != '\n'); // = fflush

		fwrite(registro, sizeof(registro), 1, Archivo);
		printf("Seguir cargando alumnos? (s/n): ");
		scanf("%c", &cargar);
	}
}

int main( ) {
  FILE *Archivo;
  cargar( Archivo);
  return 0;
}
