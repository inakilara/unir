//
//
//
#include <stdio.h>
#include <math.h>
//#define PI 3.1415986

double const PI = 2*acos(0);

int main () {
    double r=0;
    char c;
    printf("Introduce el valor del radio:");
    scanf("%lf",&r);
    printf("Introduce L para calcular la longitud y A para calcular el area:");
    scanf(" %c",&c);
    if(c=='L') {
        printf("La longitud de la circunferencia es: %.20lf\n",2*PI*r);
    }
    else if(c=='A') {
        printf("El area de la circunferencia es: %lf",PI*pow(r,2));
    }
    else {
        printf("La opcion introducida no es valida.");
    }
    return 0;
}