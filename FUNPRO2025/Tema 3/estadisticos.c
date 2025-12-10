//
// Programa que calcula el promedio y la desviación típica de 5 valores enteros introducidos por teclado.
//

#include <stdio.h>
#include <math.h>

int main (){

    int num1=0,num2=0,num3=0,num4=0,num5=0;
    double media=0,std=0;
    printf("Introduce el primer valor:");
    scanf(" %d",&num1);
    printf("Introduce el segundo valor:");
    scanf(" %d",&num2);
    printf("Introduce el tercer valor:");
    scanf(" %d",&num3);
    printf("Introduce el cuarto valor:");
    scanf(" %d",&num4);
    printf("Introduce el quinto valor:");
    scanf(" %d",&num5);
    media=1.0/5.0*(num1+num2+num3+num4+num5);
    std=sqrt((pow(num1-media,2)+pow(num2-media,2)+pow(num3-media,2)+pow(num4-media,2)+pow(num5-media,2))/4);
    printf("La media vale:%lf. Y la desviacion tipica vale: %lf",media,std);
    return 0;
 }