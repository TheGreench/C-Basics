#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO 3

/* definimos una estructura alumno */
typedef struct  
{
     char nombre[30];
     int padron;
     char email[50];
     int notas[2] ;
     float promedio;
} alumno;

void cargar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        printf("\nIngrese el Nombre:\n");
        scanf("%s",vec[i].nombre);

        printf("Ingrese el padron:\n");
        scanf("%d",&vec[i].padron);

        printf("Ingrese el email:\n");
        scanf("%s",vec[i].email);

        printf("Ingrese la nota del Parcial 1:\n");
        scanf("%d",&vec[i].notas[0]);

        printf("Ingrese la nota del Parcial 2:\n");
        scanf("%d",&vec[i].notas[1]);

	vec[i].promedio = (float)(vec[i].notas[0] + vec[i].notas[1])/2;
    }
}

void mostrar(alumno vec[TAMANIO])
{
    int i;
    for(i=0;i<TAMANIO;i++)
    {
 	printf("\n\n Alumnos[%d]",i);
	printf("\n nombre: %s ", vec[i].nombre);
	printf("\n padron: %d ", vec[i].padron);	
	printf("\n email: %s ", vec[i].email);
	printf("\n Nota Parcial 1: %d Nota Parcial 2: %d", vec[i].notas[0],vec[i].notas[1]);
	printf("\n promedio Cd: %.2f ", vec[i].promedio);
    }
}

int main(void)
{
    alumno Alumnos[TAMANIO];

    // cargo los elementos con funcion cargar
    cargar(Alumnos);

 	/* Muestro datos del primer elemento de la tabla*/
    mostrar(Alumnos);

	printf("\n\n");
	system("PAUSE");
	return 0;
}
