/*
Se pide un programa permita publicar productos a la venta por los alumnos de algoritmos 1. Se debe ingresar Código de producto nombre del producto, Descripcion, grupo y precio.
1)Realizar una función que permita la carga de Productos.
2)Informar un listado de productos ordenados por Nombre del producto
3)Ingresar una palabra y realizar una búsqueda de productos que tengan dicha palabra en el nombre o descripción. 
4)Realizar un listado de los 10 productos  mas caros
5)Mostrar un listado ordenado por Código de producto
6) Ingresar un código y mostrar todos los datos del producto.
NOTA: - Los listados se deben mostrar: Nombre 		Descripción	 Grupo 	Código
XXXXXXXXXXXX    YYYYYYYYYYYYYY          1       1231
- Los string tienen un máximo de 30 caracteres */            



#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CAD  30
#define MAX_PRODUCTOS 50
#define MAX_GRUPOS 9
 
typedef char TString [MAX_CAD];

typedef struct{
int Codigo;
TString Nombre;
TString  Descripcion;
float Precio;
int Grupo;
} TProducto;


typedef TProducto TTablaProdutos[MAX_PRODUCTOS];
