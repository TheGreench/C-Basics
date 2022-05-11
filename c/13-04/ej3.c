// Grupo 2

#include <stdio.h>

int main() 
{
	/* Leer dos letras e indicar las letras que hay entre ellas */
	
	char letra1, letra2, i, aux;
	
	printf("Ingrese la primera letra en la que inicia el programa: ");
	scanf("%c", &letra1);
    
    fflush(stdin);

	printf("\nIngrese la letra en la que finaliza el programa: ");
	scanf("%c", &letra2);

    if (letr2 < letra1) {
        aux = letra1;
        letra1 = letra2;
        letra2 = letra1;
    }

	for (i=letra1; i<=letra2; i++)
		printf("%c", i);
	
	return 0;
}
