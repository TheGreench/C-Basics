#include <stdio.h>

int main() {
    int maximo, minimo, suma = 0, cant = 0, casos = 0;

    printf("Ingrese los casos de un pais: ");
    scanf("%d", &casos);

    maximo = casos;
    minimo = casos;

    while (casos >= 0) {
        suma += casos;
        cant++;

        if (maximo < casos) maximo = casos;
        if (casos < minimo) minimo = casos;

        printf("Ingrese los casos de otro pais: ");
        scanf("%d", &casos);
    }

    if (cant > 0) {
        printf("El promedio de los %d paises es: %d", cant, suma/cant);
        printf("\nEl total de los %d paises es: %d", cant, suma);
        printf("\nLa cantidad maxima de los %d paises es: %d", cant, maximo);
        printf("\nLa cantidad minima de los %d paises es: %d", cant, minimo);
    }
}
