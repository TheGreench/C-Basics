#include <stdio.h>

int main() 
{
	/* Ej:
	Leer dos letras e indicar las letras que hay entre ellas
	*/
	
	char letra1,letra2,i;
	
	printf("Ingrese la primera letra en la que inicia el programa: ");
	scanf("%c", &letra1);
	fflush(stdin);
	printf("\nIngrese la letra en la que finaliza el programa: ");
	scanf("%c", &letra2);

	
	for (i=letra1; i<letra2; i++) {
		printf("%c", i+1);
	}
	
	return 0;
}
