//
//    Solucion al ejercicio 8 del tema 9 (p33) del cuaderno de ejercicios
//
//       a_n = (sqrt(a_(n-1))+5)/a_(n-2)
//
//   Calcular el termino n y al suma de los n primeros terminos usando una solucion recursiva
//
//


#include <stdio.h>
#include <math.h>
#include <assert.h>


double sucesion(double,double,int);
double serie(double,double,int);

int main() {
    int n;
    double a0,a1,an,Sn;
    printf("Introduce el valor de a0:");
    fflush(stdout);
    scanf(" %lf",&a0);
    printf("\nIntroduce el valor de a1:");
    fflush(stdout);
    scanf(" %lf",&a1);
    printf("\nIntroduce el valor de n:");
    fflush(stdout);
    scanf(" %d",&n);
    an = sucesion(a0,a1,n);
    Sn = serie(a0,a1,n);
    printf("\n\n El termino %d de la sucesion es: %f y el termino n de la serie es: %f",n,an,Sn);
}

double sucesion(double a0,double a1,int n) {
    if(n==0) {
        return a0;
    }
    if(n==1) {
        return a1;
    }
    return (sqrt(sucesion(a0,a1,n-1))+5)/sucesion(a0,a1,n-2);


}
double serie(double a0,double a1 ,int n) {
   if(n==0) {
       return a0;
   }
    return sucesion(a0,a1,n-1) + serie(a0,a1,n-1);
}





