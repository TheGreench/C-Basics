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
- Los string tienen un máximo de 30 caracteres 
*/ 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CAD  30
#define MAX_PRODUCTOS 50
#define MAX_GRUPOS 9
 
typedef char TString [MAX_CAD];

typedef struct {
int Codigo;
TString Nombre;
TString  Descripcion;
float Precio;
int Grupo;
} TProducto;
typedef TProducto TTablaProductos[MAX_PRODUCTOS];

// EJ-1
void cargar_datos(TTablaProductos stock, int *ml) {
	int carga;
	int i =0;

	printf("Desea ingresar un producto? con 0 sale: ");
	scanf(" %i", &carga);

	while (carga!=0 && i<MAX_PRODUCTOS) {
		printf("Cual es el codigo del producto\n");
		scanf(" %i", &stock[i].Codigo);
		
    fflush(stdin);
		
    printf("Cual es el Nombre del producto\n");
		scanf(" %s", stock[i].Nombre);
		
    fflush(stdin);
		
    printf("Cual es la Descripcion del producto\n");
		scanf(" %s",  stock[i].Descripcion);
		
    fflush(stdin);
		
    printf("Cual es el precio del producto\n"  );
		scanf(" %f", &stock[i].Precio);
		
    fflush(stdin);

		printf("Cual es el grupo del producto\n");
		scanf(" %i", &stock[i].Grupo);
		
    fflush(stdin);
		
    printf("Desea ingresar un producto? con 0 sale: ");
		scanf(" %i", &carga);
		i++;
	}
	*ml = i;
}
// EJ-1

// EJ-2
void ordenar_por_nombre(TTablaProductos tabla, int ml) {
  int i,j;     
  TProducto aux;
  for(i=1;i<ml;i++){   
    for(j=0;j<ml-i;j++){  
      if(strcmp(tabla[j].Nombre, tabla[j+1].Nombre) > 0){
        aux=tabla[j];
        tabla[j]=tabla[j+1]; 
        tabla[j+1]=aux; 
      } 
    }
  }
}
void mostrar_datos(TProducto reg) {
  printf("%d",reg.Codigo);
  printf("%s",reg.Nombre);
  printf("%s",reg.Descripcion);
  printf("%.2f",reg.Precio);
  printf("%d",reg.Grupo);
  printf("\n");
}

void listar(TTablaProductos tabla, int ml) {
  for ( int i=0;i<ml;i++)
    mostrar_datos(tabla[i]);
}

void informar_Ordenados(TTablaProductos tabla, int ml) {
  ordenar_por_nombre(tabla, ml);
  listar(tabla, ml);  
}
// EJ-2

// EJ-3
void busqueda(TTablaProductos tabla,int ml) {
  TString palabra;
  int i=0;
  bool encontrado = false; 

  printf("\n\nIngrese una palabra para realizar una busqueda de un producto:");
  scanf("%s", palabra);

  while (i < ml) {
    if (strstr(tabla[i].Descripcion, palabra) > 0 || strstr(tabla[i].Nombre,palabra) > 0) {
      encontrado = true;
      mostrar_datos(tabla[i]);
    }
    i++; 
  }
  if (!encontrado)
    printf("\n\nNo se encontro resultados."); 
}
// EJ-3

// EJ-4
void listado_caros(TTablaProductos productos, int maximo) {
  int i,j;
  TProducto temp;

  for (i=1; i<=maximo; i++) {
    for(j=0; j<maximo-i; j++) {
      if (productos[j].Precio < productos[j+1].Precio) {
        temp = productos[j];
        productos[j] = productos[j + 1];  
        productos[j + 1] = temp;
      }
    }
  }

  printf("Mostrando los 10 productos mas caros: \n");
  listar(productos, 10);
} 
// EJ-4

// EJ-5
void ordenarPorCodigo(TTablaProductos vec, int ml) {
	int i, j;
	TProducto aux;

	for(i = 1; i < ml; i++) {
		for(j = 0; j < (ml - i); j++) {
			if(vec[j].Codigo > vec[j + 1].Codigo) {
				aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}
}
// EJ-5

// EJ-6
int buscarProducto(int codigoBuscado, TTablaProductos producto, int ml){
	int i=0, posicion =-1;
	bool encontrado;

	while (i<ml || !encontrado) {	
		if(codigoBuscado == producto[i].Codigo) {
		  posicion = i;
		  encontrado = true;
		}
		i = i + 1;
	}
	return posicion;
}

void mostrarBuscado(int codigoEncontrado, int codigoBuscado, TTablaProductos producto) {
	if(codigoEncontrado==-1)
		printf("\n PRODUCTO %d NO ENCONTRADO!", codigoBuscado);
	else
	  mostrar_datos(producto[codigoEncontrado]);
}
// EJ-6

void main() {
  TTablaProductos  tabla;
  int ml;
  int codigoBuscado, codigoEncontrado;

  cargar_datos(tabla, &ml);
  informar_Ordenados(tabla,ml);
  busqueda(tabla,ml);
  listado_caros(tabla, ml);
  ordenarPorCodigo(tabla, ml);
  listar(tabla, ml);
	printf("\n Ingrese el codigo del producto a buscar: ");
  scanf("%d", &codigoBuscado);
	codigoEncontrado = buscarProducto(codigoBuscado,tabla, ml);
	mostrarBuscado(codigoEncontrado, codigoBuscado, tabla);
}
