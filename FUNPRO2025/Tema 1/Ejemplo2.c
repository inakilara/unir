//
// Created by ilara on 9/23/24.
// Tema 1 Fundamentos de programación 2024. Ejemplo 2.
// El código implementa el cálculo numérico de la derivada de la función seno
// mediante el método de las diferencias finitas.
#include <stdio.h>
#include <math.h>

double f(double x){ //función a derivar
  return sin(x);
}


int main(){
  double h=0.01; //double en lugar de float para más precision.
  double x=0;
  printf("Introduce el valor de x.\n");
  scanf("%lf",&x);
  double df=(f(x+h)-f(x-h))/(2*h);
  printf("El valor aproximado de la derivada de f en %f es %f\n",x,df);
  printf("El valor exacto de Cos(x) en %f es %f\n",x,cos(x));
  return 0;
}



