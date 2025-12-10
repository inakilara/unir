//
// Created by ilara on 9/25/24.
//// Tema 2 Fundamentos de programación 2024. Ejemplo 4.
//   Resuelve el ejercicio 2.15 de Joyanes, L. 2008
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void readData(double *interes,double *semanas,double *capitalInicial) {
    //Funcion que lee los datos desde el terminal
    printf("Introduce el capital inicial (en euros):\n");
    scanf("%lf",capitalInicial);

    printf("Introduce el interes (en porcentaje):\n");
    scanf("%lf",interes);

    printf("Introduce las semanas:\n");
    scanf("%lf",semanas);
}


int main() {
    double capitalInicial=0,capitalFinal=0,interes=0,semanas=0;
    readData(&interes,&semanas,&capitalInicial);
    capitalFinal=capitalInicial;
    for (int i=0;i<semanas*7;i++) {
        capitalFinal+=capitalInicial*interes/(365*100); //si interes es entero en lugar de real
    }                                                   // el cociente es entero en lugar de exacto
    printf("El capital final es: %f",capitalFinal);
}