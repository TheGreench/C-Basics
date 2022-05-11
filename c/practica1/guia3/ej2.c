/*
Escribir una función que reciba un valor y calcule el factorial del mismo. Si no se
puede calcular el factorial del valor recibido, la función deberá devolver 0, de lo
contrario deberá devolver el valor calculado. 
*/

void calcular_factorial(int num) {
    int resultado, i;

    resultado = 1;

    for (i = 1; i <= num; i++) {
        resultado *= i;
    }

    printf("El factorial de %d es: %d", num, resultado);
}

void ingreso() {
    int num;

    printf("Ingrese el numero a calcular el factorial, (num +): ");
    scanf("%d", &num);

    if (num > 1)
        calcular_factorial(num);   
    else
        printf("0");
}

int main() {
    ingreso();

    return 0;
}