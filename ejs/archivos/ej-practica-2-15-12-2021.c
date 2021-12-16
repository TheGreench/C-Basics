/* Realizar dos programas.
- Uno que permita Guardar todos los alumnos que se encuentran en las carreras de Informática de FIUBA (DNI, Nombre Email),
- otro que permita mostrar los alumnos.
*/




#include <stdio.h>
#include <string.h>
#define MAX_NOM 100
typedef char String[MAX_NOM];
typedef struct {
   int DNI;
   String Nombre;
   String Email; 
 } TRegistro;


void Merge (FILE *FIUBA, FILE *EXUBA, FILE *FINAL) {
	TRegistro Reg_FIUBA, Reg_EXUBA;
  FIUBA = fopen("FIUBA.dat", "r");
  EXUBA = fopen("EXUBA.dat", "rb");
  FINAL = fopen("FINAL.dat", "wb");

  fread(&Reg_FIUBA,sizeof(TRegistro),1,FIUBA);
  fread(&Reg_EXUBA, sizeof(TRegistro), 1, EXUBA);

  while (!feof(FIUBA) && (!feof(EXUBA))) {
    if (Reg_FIUBA.DNI < Reg_EXUBA.DNI ) {
      fwrite(&Reg_FIUBA,sizeof(TRegistro),1,FINAL);
      fread(&Reg_FIUBA,sizeof(TRegistro),1,FIUBA);
    } else {
      fwrite(&Reg_EXUBA,sizeof(TRegistro),1,FINAL);
      fread(&Reg_EXUBA,sizeof(TRegistro),1,EXUBA);
    }
  }
  
  while (!feof(FIUBA)) {
    fwrite(&Reg_FIUBA,sizeof(TRegistro),1,FINAL);
    fread(&Reg_FIUBA,sizeof(TRegistro),1,FIUBA);
  } 
  while (!feof(EXUBA)) {
    fwrite(&Reg_EXUBA,sizeof(TRegistro),1,FINAL);
    fread(&Reg_EXUBA,sizeof(TRegistro),1,EXUBA);
  }

  fclose(FIUBA);
  fclose(EXUBA);

}


int main() {
  FILE *FIUBA;
  FILE *EXUBA;
  FILE *FINAL;
  Merge(FIUBA, EXUBA, FINAL);
  return 0;
}


