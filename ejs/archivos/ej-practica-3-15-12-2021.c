;/*  CORTE DE CONTROL

Argentina
CABA
	Almagro + 1 – 0
	Belgrano + 1 – 1
	Caballito + 2 – 0
Total CABA+ 4 – 1
Buenos Aires
	Avellaneda + 1 – 0
 	Morón  + 1 – 0
Total Buenos Aires   + 2 – 0
La Pampa
	Santa Rosa+ 0 – 1
Total Córdoba  + 0 – 1
Mendoza
	Santa Rosa  + 0 – 1
Total Mendoza  + 0 –1
Total País  + 6 – 2


Abrir Archivo
Leer Registro
Mostrar Total Final
Cerrar Archivo
CICLO NO EOF
Inicializar variables PAIS
CICLO NO EOF Y ANTPAIS=PAIS
Inicializar variables CIUDAD
CICLO NO EOF Y ANTPAIS=PAIS Y ANTCIU=CIU
Incrementar variables (Nucleo)
Leer Registro
Mostrar Totales CIUDAD 
Mostrar Totales PAIS
Mostrar Total Final
Cerrar Archivo 
*/

#include <stdio.h>
#include <string.h>
#define MAX_NOM 100
typedef char String[MAX_NOM];
typedef struct  {
  
  String Provincia;
  String Ciudad; 
  int dni;
  char test;
} TRegistro;


void corte(FILE *Arch) {
  int totalPosProvincias, totalNegProvincias, totalPosCiudades, totalNegCiudades;
  String ProvinciaAnterior, CiudadAnterior;
	TRegistro registro;
  
  Arch = fopen("Arch.dat", "ab");
  fread(&registro, sizeof(TRegistro), 1, Arch);
  
  while (!feof(Arch)){
    totalPosProvincias = 0;
    totalNegProvincias = 0;
    strcpy(ProvinciaAnterior,registro.Provincia);
    
    while(!feof(Arch) && strcmp(ProvinciaAnterior, registro.Provincia)) {
    totalPosCiudades = 0;
    totalNegCiudades = 0;
    strcpy(CiudadAnterior, registro.Ciudad);

      while(!feof(Arch) && strcmp(ProvinciaAnterior, registro.Provincia) && strcmp(CiudadAnterior, registro.Ciudad)) {
        if (registro.test=='+') totalPosCiudades++;
        else totalNegCiudades++;
        fread(&registro, sizeof(TRegistro), 1, Arch); 
      }
    printf("Total ciudad: +  %d - %d", totalPosCiudades, totalNegCiudades);
    
    totalPosProvincias=totalPosProvincias + totalNegCiudades;
 
  }

  printf("Total Provincia: + %d - %d", totalPosProvincias, totalNegProvincias);
  
  fclose(Arch);
}


int main() {
  FILE *Arch;
  corte(Arch);
}
