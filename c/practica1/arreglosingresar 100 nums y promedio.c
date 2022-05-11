//Ingresar 100 numeros y luego mostrar el promedio y todos los numeros superiores al promedio calculado

#include <stdio.h>

#define MAX 100

typedef int tv_numeros[MAX];

void cargar_datos(tv_numeros num, int maximo) {
    int i;
    
    for (i = 0; i < maximo; i++) {
        printf("Ingrese el un numero %d: ", i+1);
        scanf("%d", &num[i]);
    }
}

void mostrar_mayor(tv_numeros num, int maximo, float promedio) {
    int i;
    
    for (i = 0; i < maximo; i++) 
        if (num[i]> promedio) printf("\nEl numero %d es mayor al promedio %f", num[i], promedio);
}

float cal_promedio(tv_numeros num, int maximo) {
    int i, temp = 0;
    float promedio = 0;
    
    for (i = 0; i < maximo; i++) temp += num[i];
    
    promedio = temp / maximo;
    
    return promedio;
}

int main()
{
    tv_numeros num;
    
    printf("Ingresar 100 numeros y luego mostrar el promedio y todos los numeros superiores al promedio calculado\n");
    cargar_datos(num, MAX);
    printf("\n Calculando promedio y mostrando numeros mayores a este!");
    mostrar_mayor(num, MAX, cal_promedio(num, MAX));
    

    return 0;
}
