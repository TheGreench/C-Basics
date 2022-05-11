/* Ingresar num y ver si esprimo o no*/
#include <stdio.h>

int main() {
  	int num, i;
  	int divisores = 0;
  
  	printf("Ingrese el numero: ");
  	scanf("%d", &num);
  
  	for (i = 2; i < num; i++) {
		if (num%i==0) divisores++;
  	}
  
  	if (divisores == 0) printf("EL numero %d es primo!", num);
	else printf("El numero %d no es primo!", num);
	
	return 0;
}
