/*
Escribir una función que reciba un mes y un año; y devuelva la cantidad de días
del mes, considerando los años bisiestos.
Tenga en cuenta que un año bisiesto es aquel divisible por 4, salvo que sea
divisible por 100, en cuyo caso también debe ser divisible por 400. 
*/

#include <stdio.h>
#include <stdbool.h>

void ingresar_datos(int *mes, int *anio) {
    printf("Ingrese el mes y el año cuando lo pide! (Meses 1 al 12) (Año desde 1900 hasta 2100)");

    printf("\nIngrese el mes: ");
    scanf("%d", mes);

    while (*mes < 1 || *mes > 12) {
        printf("El mes ingresado es incorrecto!");
        printf("\nIngrese el mes: ");
        scanf("%d", mes);
    }

    printf("\nIngrese el año: ");
    scanf("%d", anio);

    while (*anio < 1900 || *anio > 2100) {
        printf("El año ingresado es incorrecto!");
        printf("\nIngrese el año: ");
        scanf("%d", anio);
    }
}

bool es_bisiesto(int anio) {
    bool es;

    if (anio % 4 == 0 || anio % 100 != 0)
        es = true;
    else if (anio % 400 != 0)
        es = false;
    else
        es = false;

    return es;
}

int obtener_dias(int mes, int anio) {
    int valor;

    if (mes == 2) {
        if (es_bisiesto(anio))
            valor = 29;
        else 
            valor = 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        valor = 30;
    else
        valor = 31;

    return valor;
}

int main() {
    int mes, anio;

    ingresar_datos(&mes, &anio);

    printf("Los dias del mes %d del año %d son: ", mes, anio, obtener_dias(mes, anio));

    return 0;
}