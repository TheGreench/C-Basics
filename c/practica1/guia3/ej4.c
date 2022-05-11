/*
Escribir una función que reciba un número y devuelva un valor booleano
indicando si el número recibido es ó no primo. Si desconoce como devolver un
valor booleano, puede devolver 0, en caso de No ser primo; y 1, si lo es.
*/

void ingreso(int *num) {
    printf("Ingrese un valor para ver si es primo: ");
    scanf("%d", num);
}

void es_primo(int num) {
    int i, es = 1;

    if (num == 0 || num == 1 || num == 4)
        es = 0;
    else {
        for (i = 2; i < num / 2; i++)
            if (num % i == 0)
                es = 0;
    }

    if (es == 0)
        printf("No es primo!");
    else
        printf("El numero es primo!");
}

int main() {
    int num;

    ingreso(&num);
    es_primo(num);

    return 0;
}