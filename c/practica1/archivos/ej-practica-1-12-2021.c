/*
Dada la siguiente estructura:

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

EJERCICIO 1 
Escriba un programa modular que permita dar de alta registros de tipo t_regAlumno.
El usuario debe poder continuar ingresando datos hasta que ingrese un padron igual a 0.
Asuma que el archivo es inexistente.

EJERCICIO 2 
Escriba un programa modular que permita listar el contenido de el archivo creado en el punto 1.

EJERCICIO 3 
Escribir un programa que permita almacenar y consultar datos en un archivo de alumnos.
El programa deberá tener 2 opciones:
1 - Cargar Datos Alumnos
2 - Listar Alumnos

Los datos que se guardan de los alumnos son los indicados en la estructura inicial.
La carga de datos, termina cuando el padron ingresado sea 0.
La carga de datos, puede reanudarse, y en este caso no se deben perder los datos existentes.
El listado debe ser de todos los datos, encolumnados, y en el orden que se encuentran almacenados.
*/


#include <stdio.h>

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;

// EJERCICIO 1
void cargarDatos(FILE *arAlumnos) { // El archivo debe estar abierto en modo escritura
	t_regAlumno rAlumno;

	printf("\nIngrese los datos del alumno:\n");
	printf(" · Padrón del alumno: ");
	scanf("%d", &rAlumno.padron);

	while ((getchar()) != '\n');

	while(rAlumno.padron != 0) {
		printf(" · Apellido y nombre del alumno: ");
		scanf("%30[^\n]s", rAlumno.ape_nom);

		while ((getchar()) != '\n');

		printf(" · Nota: ");
		scanf("%f", &rAlumno.nota);

		while ((getchar()) != '\n');

		fwrite(&rAlumno, sizeof(rAlumno), 1, arAlumnos);

		printf("\nIngrese los datos del alumno:\n");
		printf(" · Padrón del alumno: ");
		scanf("%d", &rAlumno.padron);

		while ((getchar()) != '\n');
	}
}
// FIN EJERCICIO 1

// EJERCICIO 2
void mostrarDatos(FILE *arAlumnos) {
	t_regAlumno rAlumno;

	fread(&rAlumno, sizeof(rAlumno), 1, arAlumnos);

	printf("\nPadrón \tApellido y Nombre \t\tNota");
	while(!feof(arAlumnos)) {
		printf("\n %d \t%-30s %6.2f", rAlumno.padron, rAlumno.ape_nom, rAlumno.nota);
		fread(&rAlumno, sizeof(rAlumno), 1, arAlumnos);
	}
}
// FIN EJERCICIO 2

// EJERCICIO 3
void menuOpciones(FILE *arAlumnos, int opcion) {
	if(opcion == 1){
		arAlumnos = fopen("alumnos.dat", "ab");
		if(arAlumnos == NULL)
			arAlumnos = fopen("alumnos.dat", "wb");
		cargarDatos(arAlumnos);
		fclose(arAlumnos);
	} else if(opcion == 2) {
		arAlumnos = fopen("alumnos.dat", "rb");
		if(arAlumnos == NULL)
			printf("\n/!\\ Error: no existe el archivo de alumnos.");
		else {
			mostrarDatos(arAlumnos);
			fclose(arAlumnos);
		}
	}
}

void mostrarMenu(FILE *arAlumnos) {
	int opcion;

	printf("\nElija una de las siguientes opciones:");
	printf("\n1 - Cargar datos de alumnos");
	printf("\n2 - Listar alumnos");
	printf("\nOpción elegida: ");
	scanf("%i", &opcion);
  
	while((opcion != 1) && (opcion != 2)) {
		printf("Opción no válida, por favor vuelva a ingresar una opción: ");
		scanf("%i", &opcion);
	}
	menuOpciones(arAlumnos, opcion);
}
// FIN EJERCICIO 3

int main(void){
	FILE *arAlumnos;
	mostrarMenu(arAlumnos);
	return 0;
}
