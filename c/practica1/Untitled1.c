#include <stdio.h>
#include <stdlib.h>
#define Max 100

typedef int vector[Max];

void maximo_logico(vector numero, int *max)
{
    int i = 0;
    int entrada;
    while (entrada != -1)
    {
        printf("ingrese un numero y -1 para terminar\n");
        scanf("%d", &entrada);
        numero[i] = entrada;
        i++;
    }
    *max = i - 1;
}
void mostrar_datos(vector numero, int max, vector posiciones)
{
    int i = 0, pos;
    for (i = 0; i < max; i++) {
    	pos = i;
    	
    	if (posiciones[i] == numero[i])
    		pos = posiciones[i];
    		
        printf("posicion %d --> elementos guardados: %d\n", pos, numero[i]);
	}
}

void mayor(vector numero, int max, int *repeticion, vector posiciones, int *Mayor)
{
    int i, j = 0, mayor = 0, posicion = 0;
    for (i = 0; i < max; i++)
    {
        if (numero[i] > mayor)
        {
            mayor = numero[i];
            posicion = i;
            *repeticion = 0;
            j = 0;
        }
        if (mayor == numero[i])
        {
            posiciones[j] = i;
            *repeticion = *repeticion + 1;
            j++;
        }
    }
    *Mayor = posicion;
}

int main()
{
    vector numero;
    vector posiciones;
    
    int max, Mayor, repeticion;
    
    maximo_logico(numero, &max);
    mostrar_datos(numero, max, posiciones);
    mayor(numero, max, &repeticion, posiciones, &Mayor);
    
    printf("la posicion mayor es:%d y el mayor es: %d, y se repite:%d veces\n", Mayor, numero[Mayor], repeticion);
    
    mostrar_datos(numero, repeticion, posiciones);
    
    return 0;
}