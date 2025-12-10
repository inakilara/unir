//
// Created by Iñaki Lara on 28/10/2024.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//#define NDEBUG
#include <assert.h>
//#define TRACES

/**
 Documentación en formato Doxygen
Solución de ecuación 2º grado

Este programa calcula las raíces de un polinomio general de segundo grado.
En caso de que se trate de un polinomio de primer grado, calcula su raíz única.
El programa toma tres parámetros por línea de comandos: a, b y c correspondientes a
los coeficientes del término cuadrático, lineal y constante respectivamente.

@param  a : Coeficiente del término cuadrático. Se lee desde argv[1]
@param  b : Coeficiente del término lineal. Se lee desde argv[2]
@param  c : Coeficiente del término constante Se lee desde argv[3]
@return  La ejecución correcta retorna 0. El resultado se muestra por pantalla.
*/

int main(int argc,char *argv[]) {
  // Conversión de parámetros de entrada
  char *pEnd;
  errno=0;
  double a=strtod(argv[1],&pEnd);                   //Convierte a double, si falla pEnd apunta al mismo sitio que argv[1]
  assert(("a invalido")&&errno==0&&pEnd!=argv[1]);  // errno es distinto de 0 si hay problemas numéricos en la conversión, pEnd apunta a argv[1] si la entrada es inválida
  double b=strtod(argv[2],&pEnd);
  assert(("b invalido")&&errno==0&&pEnd!=argv[2]);
  double c=strtod(argv[3],&pEnd);
  assert(("c invalido")&&errno==0&&pEnd!=argv[3]);

  //Mensaje informativo
  printf("Este programa calcula las raices de la ecuacion de segundo grado de forma general:\n\n");
  printf("\tax^2+bx+c=0 \n\n");
  printf("Ejecutando para paramtros de entrada: a=%lf, b=%lf, c=%lf \n\n",a,b,c);

  //Comprueba que la entrada es válida
  assert(("Parametros nulos")&&(a!=0)||(b!=0));
  //Cálculo para grado 1
  if(a==0) {
    printf("la raiz de la ecuacion es: %lf\n",-c/b);
    printf("(La ecuacion es de 1er grado, no de segundo grado.)\n");
  }
  //Cálculo para grado 2
  else{
    double discriminante=b*b-4*a*c;
#ifdef TRACES
    printf("Valor del discriminante: %lf\n",discriminante);
#endif
    if (discriminante<0){
      printf("La ecuacion no tiene raices reales, las raices complejas son:\n");
      printf("raiz 1: %lf+i*%lf\n",-b/(2*a),sqrt(-discriminante)/(2*a));
      printf("raiz 2: %lf-i*%lf\n",-b/(2*a),sqrt(-discriminante)/(2*a));
      return 0;
    }
   if (discriminante==0) {
      printf("La ecuacion tiene raiz doble:\n");
      printf("raiz doble: %lf\n",-b/(2*a));
      return 0;
    }
      printf("La ecuacion tiene dos raices reales:\n");
      printf("raiz 1: %lf\n",-b/(2*a)+sqrt(discriminante)/(2*a));
      printf("raiz 2: %lf\n",-b/(2*a)-sqrt(discriminante)/(2*a));
      return 0;
  }

  return 0;
}
