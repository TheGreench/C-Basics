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
#define MAX_ALUMNOS 500

typedef struct{
	int padron;
	char ape_nom[30];
	float nota;
}t_regAlumno;
typedef t_regAlumno Alumnos[MAX_ALUMNOS];

void cargar_datos(Alumnos alumno, int *ml) {
  int carga;
	int i =0;

	printf("Desea ingresar un alumno? con 0 sale: ");
	scanf("%i", &carga);

	while (carga!=0 && i<MAX_ALUMNOS) {
    printf("Nombre del alumno\n");
		scanf("%s", alumno[i].ape_nom);
    fflush(stdin);
		
    printf("Padron del alumno\n");
		scanf("%d",  &alumno[i].padron);
    fflush(stdin);
		
    printf("Nota del alumno\n"  );
		scanf("%f", &alumno[i].nota);
    fflush(stdin);
		
    printf("Desea ingresar un alumno? con 0 sale: ");
		scanf("%i", &carga);
		i++;
	}
	*ml = i;
}

int main(void) {
  Alumnos alumno;
  int ml;

  cargar_datos(alumno, &ml);

  

  return 0;
}
