//
// Created by Iñaki Lara on 28/10/2024.
//
#include <stdio.h>
#include <math.h>

int main() {
  double a0,a1,a2,a3,a4,a5,a6;
  double tolerancia=0.001,error=0.0,resultado=0.0;
  int maxIter=0;

    //Interfaz de entrada
    printf("Este programa busca, usando el metodo de Newton, una raiz real de la ecuacion polinómica de forma general :\n\n");
    printf("\ta6x^6 + a5x^5 + a4x^4 + a3x^3 + a2x^2 + a1x + a0 = 0 \n\n");
    printf("Introduzca el valor de a6:");
    scanf(" %lf",&a6);
    printf("Introduzca el valor de a5:");
    scanf(" %lf",&a5);
    printf("Introduzca el valor de a4:");
    scanf(" %lf",&a4);
    printf("Introduzca el valor de a3:");
    scanf(" %lf",&a3);
    printf("Introduzca el valor de a2:");
    scanf(" %lf",&a2);
    printf("Introduzca el valor de a1:");
    scanf(" %lf",&a1);
    printf("Introduzca el valor de a0:");
    scanf(" %lf",&a0);
    printf("Introduzca el punto inicial de la busqueda:");
    scanf(" %lf",&resultado);
    //Bucle de cálculo
    do{
    double resultado0=resultado;
    resultado = resultado-(a6*pow(resultado,6)+a5*pow(resultado,5)+a4*pow(resultado,4)+a3*pow(resultado,3)
                               +a2*pow(resultado,2)+a1*pow(resultado,1)+a0)/(6*a6*pow(resultado,5)+
                                   5*a5*pow(resultado,4)+4*a4*pow(resultado,3)+3*a3*pow(resultado,2)+
                                   2*a2*pow(resultado,1)+a1*pow(resultado,0));
    error=fabs(resultado0-resultado);
    maxIter++;
    if(maxIter>1000){printf("No se observa convergencia tras alcanzar el numero maximo de iteraciones."); return -1;}
    }while(error>tolerancia);
  printf("La ecuaci0n introducida es:\n\n");
  printf("\t %lfx^6 + %lfx^5 + %lfx^4 + %lfx^3 + %lfx^2 + %lfx + %lf = 0 \n\n",a6,a5,a4,a3,a2,a1,a0);
  printf("El valor de la raiz encontrada es %lf, con un error de %lf.",resultado,error);


  return 0;}