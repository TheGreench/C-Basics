/* ----------- Ejercicio 1 ----------- */

//
// Implementar la funcion Ejercio_1, 
// la cual recibe por parametro el vector vec de largo d
//
// La misma debe sumar los valores pares almacenados en vec
// Por ejemplo: 
// si en vec se recibe el vector {51,1,20,4,5,6,7};
// el valor devuelto debe ser 30, dado que se suman 20 + 4 + 6
//

// Nicolas Invernizzi - 108761

#include <stdio.h>

int Ejercio_1(int vec[], int d)
{
    /* INICIO: INGRESE SU CODIGO ACA */    
    int i, suma;
    suma = 0;
	for (i = 0; i < d; i++) {
		if (vec[i] % 2 == 0)
			suma += vec[i];
	}
	return suma;
    /* FIN: INGRESE SU CODIGO ACA */    
}

void main()
{

    const int largo = 7;
    
    //vectores de prueba
    int vector_1[] = {51,1,20,4,5,6,7};
    int vector_2[] = {8,2,3,4,45,6,10};

 
    // Verificacion con vector_1
    if ( Ejercio_1(vector_1,largo) == 30 )
       printf ("Correcto con vector_1\n\n");
    else
       printf ("Incorrecto con vector_1\n\n");
       
    // Verificacion con vector_2       
    if ( Ejercio_1(vector_2,largo) == 30 )
       printf ("Correcto con vector_2\n\n");
    else
       printf ("Incorrecto con vector_2\n\n");       

}
