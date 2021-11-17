/*
Se tiene un registro de la temperatura por hora (0 a 23) por día (1 a n) de
un mes, ordenada cronológicamente. Se pide:
a) Ingresar el número de mes para conocer la cantidad de días registrados.
b) Cargar el listado en una matriz e informarla en forma bidimensional.
c) Informar además la máxima y la mínima temperatura por día, la máxima y la
   mínima temperatura del mes.
*/

#include <stdio.h>
#define MAX_COLUMNAS 24

int cargarMes() {
	int dias_del_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int mes;
	printf("Ingrese el número correspondiente al mes");
	printf("(Enero = 1 ... Diciembre = 12): ");
	scanf("%i", &mes);
	return dias_del_mes[mes];
}

void cargarTabla(int filas, float matriz[][MAX_COLUMNAS]) {
	for(int i = 0; i < filas; i++) {
		printf("--- Valores del día %i ---\n", i + 1);
		for(int j = 0; j < MAX_COLUMNAS; j++) {
			printf("Temperatura a la hora %i: ", j);
			scanf("%f", &matriz[i][j]);
		}
	}
}

void mostrarTabla(int filas, float matriz[][MAX_COLUMNAS]) {
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < MAX_COLUMNAS; j++) {
			printf("%.2f ", matriz[i][j]);
		}
		printf("\n\n");
	}
}

void asignarExtremo(float actual, float * mayor, float * menor) {
	if(actual < *menor)
		*menor = actual;
	else if(actual > *mayor)
		*mayor = actual;
}

void mostrarExtremos(int filas, float matriz[][MAX_COLUMNAS]) {
	int i, j;
	float menor_temp_diaria, mayor_temp_diaria;
	float min_temp = matriz[0][0], max_temp = min_temp;
	printf("\n--- Temperaturas Máximas y Minimas por Día ---\n");
	for(i = 0; i < filas; i++){
		printf("------------------- Día %02i ------------------\n", i);
		mayor_temp_diaria = menor_temp_diaria = matriz[i][0];
		for(j = 0; j < MAX_COLUMNAS; j++) {
			asignarExtremo(matriz[i][j], &mayor_temp_diaria, &menor_temp_diaria);
		}
		if(menor_temp_diaria < min_temp)
			min_temp = menor_temp_diaria;
		else if(mayor_temp_diaria > max_temp)
			max_temp = mayor_temp_diaria;
		printf("Temperatura máxima: %.2f\n", mayor_temp_diaria);
		printf("Temperatura mínima: %.2f\n", menor_temp_diaria);
	}
	printf("\n--- Temperatura máxima del mes: %.2f\n", max_temp);
	printf("--- Temperatura mínima del mes: %.2f\n", min_temp);
}

void main() {
	const int MAX_FILAS = cargarMes();
	float tabla_temp_hora[MAX_FILAS][MAX_COLUMNAS];
	cargarTabla(MAX_FILAS, tabla_temp_hora);
	mostrarTabla(MAX_FILAS, tabla_temp_hora);
	mostrarExtremos(MAX_FILAS, tabla_temp_hora);
    getchar();
}
