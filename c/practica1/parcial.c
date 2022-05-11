/* ENUNCIADO EJERCICIO 3: 

Implementar la función ejercicio_3 que reciba una matriz cargada con números enteros entre 0 y 100, y el máximo lógico de filas y 
el de columnas de ésta.
La función debe mostrar por pantalla los numeros que se encuentran presentes en la matriz y la cantidad de apariciones de cada uno de ellos.
Considerar que solo se puede recorrer una vez la matriz. Está permitida la utilización de un vector auxiliar.

Por ejemplo:
se tiene la siguiente matriz de 3x3 -> {{56, 89, 56}, {78, 23, 11}, {75, 56, 11}}

El resultado debe ser:
11 -> 2
23 -> 1
56 -> 3
75 -> 1
87 -> 1
89 -> 1

*/

#include <stdio.h>

typedef int matrix_t[25][25];

void ejercicio_3(matrix_t matrix, int mf, int mc) {
	 
	int vec_aux[100][2] = {{0}}, i, j, num;	
	
	
	for (i = 0 ; i < mf; i++) {
		for (j = 0; j < mc; j++) {
			num = matrix[i][j];
		    
		    if (vec_aux[num][0] == num) {
		    	vec_aux[num][0] = num;
		    	vec_aux[num][1] = vec_aux[num][1] + 1;
			}
			else {
				vec_aux[num][0] = num;
		    	vec_aux[num][1] = 1;
			}

		}
	}
	
	for (i = 0 ; i < mf; i++){
		if (vec_aux[i][0] > 0)
			printf(" %d\t--> %d\n", i, vec_aux[i][1]);
	}			    	
}


void main(){
matrix_t matriz1 = {{8,5,2},{7,4,1}};
matrix_t matriz2 = {{94,16,3,48,12},{15,66,20,92,93},{34,87,14,78,41},{2,67,15,66,64},{36,76,2,97,20},{81,48,91,20,56},{20,44,84,16,51},{69,43,78,30,11},{53,75,51,97,32},{89,24,89,87,56}};
matrix_t matriz3 = {{15,37,19,33,27,30},{0,24,19,39,24,27},{49,28,30,11,37,43},{30,23,36,21,2,14},{16,6,15,36,20,2},{0,11,6,19,39,40},{9,2,44,44,6,15},{5,31,20,16,17,7},{10,32,40,15,3,10},{29,4,46,28,22,31},{5,18,24,25,9,19},{19,13,5,50,14,18},{36,13,34,7,28,45},{2,4,17,39,30,19},{7,1,43,3,41,23},{29,34,6,35,6,1},{25,20,20,42,17,43},{36,46,31,24,29,3},{9,43,24,31,37,39},{44,48,9,13,40,6}};

    printf("CASO 1 -------------------------\n\n");

    ejercicio_3(matriz1, 2, 3);

    printf("CASO 2 -------------------------\n\n");

    //ejercicio_3(matriz2, 10, 5);

    printf("CASO 3 -------------------------\n\n");

    //ejercicio_3(matriz3, 20, 6);

}