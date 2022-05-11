/*
Se tienen los siguientes datos de un empleado: numero de legajo,
categoría a la que pertenece, fecha de ingreso a la empresa, cantidad
de horas trabajadas en el mes y cantidad de horas extras trabajadas.
	• La categoría puede ser: administrativo, técnico, profesional u
	operario.
	• El valor de la hora trabajada por categoría es: $5, $7, $12 y $3
	respectivamente.
	• Las horas extras tienen un valor superior en un 50%.
	• El sueldo a cobrar se compone de: sueldo base (cantidad de
	horas * valor hora) + monto por horas extras + porcentaje por
	años de antigüedad -un descuento del 3% por obra social -un
	descuento del 10% por jubilación.
	• Los porcentajes se calculan sobre el sueldo base.
	• La antigüedad se calcula según: 5% entre 1 y 3 años, 10% entre 4
	y 6 años, 20% entre 7 y 10 años, 50% entre 11 y 15 años, 100%
	más de 16 años (años cumplidos). La fecha de procesamiento se0
	ingresa una única vez.
		i. Informar el legajo, el sueldo base, el monto por horas
		extras si existe, el monto por antigüedad, el monto de cada
		descuento y el sueldo a cobrar. 
*/


#include <stdio.h>


void ingreso_datos(int *legajo, int *dia_ingreso, int *mes_ingreso, int *anio_ingreso, int *horas_mes, int *horas_extras, int *categoria)
{
    printf("==============Calcular Sueldo a Cobrar============= \n");
    printf("Ingrese numero de legajo: ");
    scanf("\n   %d", legajo);

    printf("Ingrese a que CATEGORIA pertenece: 1 => (administrativo) || 2 => (Tecnico) || 3 => (Profesional) || 4 => (Opererio) \n");
    scanf("\n    %d", categoria);
	//    printf("\n  %d", *categoria);

    printf("Ingrese DIA de ingreso a la empresa: ");
    scanf("\n  %d",dia_ingreso);

    printf("Ingrese MES de ingreso a la empresa: ");
    scanf("\n  %d", mes_ingreso);

    printf("Ingrese ANIO de ingreso a la empresa: ");
    scanf("\n   %d", anio_ingreso);

    printf("Ingrese cantidad de HORAS trabajadas en el mes: ");
    scanf("\n  %d", horas_mes);

    printf("Ingrese cantidad de HORAS EXTRAS trabajadas en el mes: ");
    scanf("%d", horas_extras);

}

void validacion_datos(int *categoria, int *dia_ingreso, int *mes_ingreso, int *anio_ingreso)
{
    printf("VALIDANDO DATOS......ESPERE UN MOMENTO..... \n");
    //VALIDACION CATEGORIA//
    while (*categoria < 1 || *categoria > 4)
    {
        printf("\n CATEGORIA INCORRECTA...Ingrese nuevamente la categoria => ");
        scanf("%d", categoria);
    }
        
    //VALIDANDO FECHA//
    while (*dia_ingreso < 1 || *dia_ingreso >31)
    {
        printf("DIA INGRESADO INCORRECTO...INGRESE NUEVAMENTE => ");
        scanf("%d", dia_ingreso);
    }

    while (*mes_ingreso <1 || *mes_ingreso > 12)
    {
        printf("MES INGRESADO INCORRECTO...INGRESE NUEVAMENTE => ");
        scanf("%d", mes_ingreso);
    }

    while (*anio_ingreso < 1990 || *anio_ingreso > 2022)
    {
        printf("ANIO INGRESADO INCORRECTO...INGRESE NUEVAMENTE => ");
        scanf("%d", anio_ingreso);
    }


}



void calculo_horas_extras(int *categoria_valor_hora, int horas_extras, int horas_mes, int categoria, float *sueldo_base, float *monto_horas_extras, float *porcentaje_antiguedad, int anio_ingreso, float *descuento_obra_social, float *descuento_jubilacion)
{
    int anios_antiguedad=0;
    float categoria_valor_extra = (*categoria_valor_hora) + (*categoria_valor_hora / 2);
    
    //ASIGNACION VALOR CATEGORIA
    if(categoria == 1){
        *categoria_valor_hora = 5;
        categoria_valor_extra = 7.5;
    }    
    else
        if(categoria == 2){
            *categoria_valor_hora = 7;
            categoria_valor_extra = 10.5;
        }    
        else
            if(categoria == 3){
                *categoria_valor_hora = 12;
                categoria_valor_extra = 18;
            }    
            else{
                *categoria_valor_hora = 3;
                categoria_valor_extra = 4.5;
            }    

		//     printf("%d", *categoria_valor_hora);

    // SUELDO BASE
    *sueldo_base = (*categoria_valor_hora) * (horas_mes);

    //MONTO HORAS EXTRAS
    *monto_horas_extras = (horas_extras) * (categoria_valor_extra);


    //ANIOS ANTIGUEDAD
    anios_antiguedad = 2022 - anio_ingreso;

    //PORCENTAJE ANTIGUEDAD
    if(anios_antiguedad >= 1 && anios_antiguedad <= 3)
        *porcentaje_antiguedad = (5*100)/(*sueldo_base) ;  // 5%
    else
        if(anios_antiguedad >=4 && anios_antiguedad <= 6)
            *porcentaje_antiguedad = (10*100)/(*sueldo_base); //10%
        else
            if (anios_antiguedad >= 7 && anios_antiguedad <= 10)
                *porcentaje_antiguedad = (20*100)/(*sueldo_base); //20%
            else
                if(anios_antiguedad >= 11 && anios_antiguedad <= 15)
                    *porcentaje_antiguedad = (50*100)/(*sueldo_base); //50%
                else
                    if(anios_antiguedad >= 16)
                        *porcentaje_antiguedad = *sueldo_base; //100%
                    else
                        *porcentaje_antiguedad = 0;
        
 	//DESCUENTOS JUBILACION Y OBRA SOCIAL
    *descuento_obra_social = 300/(*sueldo_base);       //3%
    printf("%f \n", *descuento_obra_social);

    *descuento_jubilacion = 1000/(*sueldo_base);       //10%
        printf("%f", *descuento_jubilacion);    
}


int main(){
    int legajo=0, dia_ingreso=0, mes_ingreso=0, anio_ingreso=0, horas_mes=0, horas_extras=0, categoria=0;
    int categoria_valor_hora=0;
    float monto_horas_extras=0, porcentaje_antiguedad=0, sueldo_base=0;
    float sueldo_total_cobrar, descuento_jubilacion=0, descuento_obra_social=0;


    ingreso_datos(&legajo, &dia_ingreso, &mes_ingreso, &anio_ingreso, &horas_mes, &horas_extras, &categoria);
    validacion_datos(&categoria, &dia_ingreso, &mes_ingreso, &anio_ingreso);
    calculo_horas_extras(&categoria_valor_hora, horas_extras, horas_mes, categoria, &sueldo_base, &monto_horas_extras, &porcentaje_antiguedad, anio_ingreso, &descuento_jubilacion, &descuento_obra_social);

	/*  El sueldo a cobrar se compone de: sueldo base (cantidad de
    horas * valor hora) + monto por horas extras + porcentaje por
    años de antigüedad -un descuento del 3% por obra social -un
    descuento del 10% por jubilación.
	*/

    sueldo_total_cobrar = sueldo_base + monto_horas_extras + porcentaje_antiguedad - descuento_obra_social - descuento_obra_social;

    /*
    i. Informar el legajo, el sueldo base, el monto por horas
    extras si existe, el monto por antigüedad, el monto de cada
    descuento y el sueldo a cobrar. 
    */

    printf("=======================LEGAJO=============================== \n");
    printf("%d \n", legajo);

    printf("=======================SUELDO BASE=============================== \n");
    printf("+ %.2f \n", sueldo_base );

    printf("=======================MONTO HORAS EXTRAS=============================== \n");
    printf("+ %.2f \n", monto_horas_extras);

    printf("=======================MONTO POR ANTIGUEDAD=============================== \n");
    printf("+ %.2f \n", porcentaje_antiguedad);

    printf("=======================DESCUENTOS=============================== \n");
    printf("- %.2f   \n", descuento_obra_social);
    printf("- %.2f  \n", descuento_jubilacion);


    printf("=======================SUELDO A COBRAR=============================== \n");
    printf("%.2f", sueldo_total_cobrar);




    return 0;
}