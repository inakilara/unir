//
// Solución al ejercicio 8 del tema 9 (p33) del cuaderno de ejercicios
//
//      a_n = (sqrt(a_(n-1))+5)/a_(n-2)
//
//     Crea un programa que calcule el término n y la suma de los primeros n términos
//
#include <stdio.h>
#include <math.h>
#include <assert.h>

float sucesion(int,float,float);
float serie(int,float,float);

int main() {
    int n=0;
    float an=0,Sn=0,a0,a1;
    printf("Introduce el valor de n:");
    scanf(" %d",&n);
    printf("\nIntroduce el valor de a0:");
    scanf(" %f",&a0);
    printf("\nIntroduce el valor de a1:");
    scanf(" %f",&a1);
    an = sucesion(n,a0,a1);
   // Sn = serie(n,a0,a1);
    printf("\nEl termino n de la sucesion es %f y el termino n de la serie es %f",an,Sn);
}


float sucesion(int n,float a0,float a1) {
    if (n==0) {
        return a0;
    }
    if (n==1) {
        return a1;
    }
    return (sqrt(sucesion(n-1,a0,a1))+5.0)/sucesion(n-2,a0,a1);

}
float serie(int n,float a0 ,float a1) {
    if(n==0) {
        return a0;
    }
    return serie(n-1,a0,a1)+sucesion(n,a0,a1);
}
