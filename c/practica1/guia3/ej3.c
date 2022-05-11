/*
Escribir una función que reciba un valor n, entero, y devuelva la suma de los
valores entre 0 y n. 
*/

void ingreso(int *num) {
    printf("Ingrese un numero entero: ");
    scanf("%d", num);
}

void valores(int num) {
    int i, resultado;

    for (i = 0; i <= num; i++)
        resultado += i;

    printf("La suma es: %d", resultado);
}

int main() {
    int num;

    ingreso(&num);
    valores(num);

    return 0;
}