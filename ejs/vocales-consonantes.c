#include <stdio.h>
/* #include <stdlib.h> // Lib para system("PAUSE");*/

int main() 
{
	/* Ej:
	Ingresar un texto terminado en '.' e indicar cantidad de vocales y consonantes
	*/
	char caracter;
	int cant_voc = 0,cant_cons = 0;
	
	printf("Ingrese el texto deseado para ver vocales y consonantes terminado en '.': \n");
	printf("Ingrese texto: ");
	scanf("%c", &caracter);

	while (caracter != '.') {
		if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
			if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u'
			|| caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U')
				cant_voc++;
			else
				cant_cons++;
		}
		scanf("%c", &caracter);
	}
	
	printf("Cantidad de Vocales: %d \n Cantidad Consonantes: %d", cant_voc, cant_cons);
	
	return 0;
}
