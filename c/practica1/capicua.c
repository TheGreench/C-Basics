#include <stdio.h>

void ingresar_datos(int *num){
    printf("Ingrese un numero entero positivo para ver si es o no capicua: \n ");
    scanf("%d", num);

    while (*num < 0) {
        printf("Numero Invalido! Ingrese otro valor: ");
        scanf("%d", num);
    }
}

int mostrarEsCapicua(int num) {
    int valor = num;
    int ultimo_numero;
    int numero_invertido;
    int suma = 0;

    while (valor > 0){
        ultimo_numero = valor % 10;
        valor = valor / 10;
        numero_invertido = ultimo_numero + (suma * 10);
        suma = numero_invertido;
    }

    return suma;
}

void capicua(int num) {
    while (num != 0) {
        if (num == mostrarEsCapicua(num))
            printf("%d es Capicua\n", num);
        else
            printf("%d no es Capicua\n", num);
    }
}

int main () {
    int num;

    ingresar_datos(&num);
    capicua(num);

    return 0;
}