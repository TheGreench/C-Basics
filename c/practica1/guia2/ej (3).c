/*
Dado un número n, informar los n primeros términos de la sucesión
geométrica de razón 3 (1, 3, 9, 27, etc.). 
*/

#include <stdio.h>

void evaluar_n(int n) {
	int res = 1, i;
	
	for (i = 1; i <= n; i++){
		printf("\n %d", res);
		res = res*3;
	}
}

int main() {
	evaluar_n(8);

	return 0;
}