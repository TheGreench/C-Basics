
/*
Se dan como datos de entrada las fechas de nacimiento (día, mes, año)
y los números de DNI de cada integrante de un grupo. Se indica fin de
datos de entrada cuando día = 0. Muestre por pantalla el número de DNI
del integrante más joven del grupo. 
*/


#include <stdio.h>

#define ANIO_ACTUAL 2022
#define MES_ACTUAL 5
#define DIA_ACTUAL 9
#define INTEGRANTES 5

int dar_edad(int dia, int mes, int anio) {
	int edad = ANIO_ACTUAL - anio;

	if (mes > MES_ACTUAL)
		edad--;
	else {
		if (mes == MES_ACTUAL) {
			if (dia < DIA_ACTUAL)
				edad--;
		}
	}

	return edad;
}

void ingresar_datos(int *m_joven, int *m_dni) {
	int dia = 1, mes, anio, dni, i;

	printf("Ingresando participantes, para fnalizar el dia debe ser 0!");

	*m_joven = 200;
	*m_dni = 1;

	while (dia != 0) {
		printf("\nIngrese el dia de nacmiento del integrante: ");
		scanf("%d", &dia);
		while ((dia > 31 || dia < 1) && dia != 0) {
			printf("Dia incorrecto! Ingrese el dia de nacmiento del integrante: ");
			scanf("%d", &dia);
		}
		
		if (dia != 0) {
			printf("Ingrese el mes de nacimiento del integrante: ");
			scanf("%d", &mes);
			while (mes > 12 || mes < 1) {
				printf("Mes Incorrecto! Ingrese el mes de nacimiento del integrante: ");
				scanf("%d", &mes);
			}
					
			printf("Ingrese el año de nacimiento del integrante: ");
			scanf("%d", &anio);
			while (ANIO_ACTUAL > 2022 || anio < 1900) {
				printf("Año Incorrect! Ingrese el año de nacimiento del integrante: ");
				scanf("%d", &anio);
			}
		
			printf("Ingrese el DNI del integrante: ");
			scanf("%d", &dni);
	
			if (dar_edad(dia, mes, anio) < *m_joven) {
				*m_joven = dar_edad(dia, mes, anio);
				*m_dni = dni;
			}
		}		
	}
}

void mostrar_joven(int edad, int dni) {
	printf("\nIntegrante mas Joven: ");
	printf("\nDNI: %d\nEdad: %d años", dni, edad);
}

int main() {
	int m_joven, m_dni;
	ingresar_datos(&m_joven, &m_dni);
	mostrar_joven(m_joven, m_dni);

	return 0;
}