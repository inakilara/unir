//
// Created by Iñaki Lara on 28/10/2024.
//
#include <stdio.h>
#include <math.h>

int main() {
  double a,b,c;

  //Interfaz de entrada
  printf("Este programa calcula las raices de la ecuacion de segundo grado de forma general:\n\n");
  printf("\tax^2+bx+c=0 \n\n");
  printf("Introduzca el valor del a:");
  scanf(" %lf",&a);
  printf("Introduzca el valor del b:");
  scanf(" %lf",&b);
  printf("Introduzca el valor del c:");
  scanf(" %lf",&c);

  //Comprueba que la entrada es válida
  if((a==0)&&(b==0)) {
    printf("a y b no pueden ser ambos nulos. La ecuacion no tiene raices.\n");
    return -1;
  }
  //Cálculo de las raices
  else if(a==0) {
    printf("la raiz de la ecuacion es: %lf\n",-c/b);
    printf("(La ecuacion es de 1er grado, no de segundo grado.)\n");
  }
  else{
    double discriminante=b*b-4*a*c;
    if (discriminante<0){
      printf("La ecuacion no tiene raices reales, las raices complejas son:\n");
      printf("raiz 1: %lf+i*%lf\n",-b/(2*a),sqrt(-discriminante)/(2*a));
      printf("raiz 2: %lf-i*%lf\n",-b/(2*a),sqrt(-discriminante)/(2*a));
      return 0;
    }
    else if (discriminante==0) {
      printf("La ecuacion tiene raiz doble:\n");
      printf("raiz doble: %lf\n",-b/(2*a));
      return 0;
    }
    else {
      printf("La ecuacion tiene dos raices reales:\n");
      printf("raiz 1: %lf\n",-b/(2*a)+sqrt(discriminante)/(2*a));
      printf("raiz 2: %lf\n",-b/(2*a)-sqrt(discriminante)/(2*a));
      return 0;
    }
  }
  return 0;
}
