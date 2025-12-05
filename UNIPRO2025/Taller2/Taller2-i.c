//
// Ejercicio 3: Escribe un programa que calcule valores estadisticos
//
#include <stdio.h>
#include <math.h>

float actualizarMedia(float,float,int);
float actualizarVarianza(float,float,float,int);


int main () {
  float media=0,varianza=0,valor=0;
  int n=0;
  char c;
  do{
    n++;
    printf("Introduce el siguiente valor: ");
    scanf("%f",&valor);
    printf("\n");
    media =  actualizarMedia(media,valor,n);
    varianza = actualizarVarianza(varianza,media,valor,n);
    printf("Quieres seguir añadiendo valores? (s para sí, cualquier otra tecla para no)");
    scanf(" %c%*c",&c);
  }while(c=='s');
  printf("\n El valor de la media es: %f.\n EL valor de la varianza es: %f",media,varianza);
}


float actualizarMedia(float media,float valor ,int n){
  return media*((float)n-1)/(float)n+valor/(float)n;
}
float actualizarVarianza(float varianza,float media,float valor,int n){
  return varianza*((float)n-1)/(float)n+pow(valor-media,2)/(float)n;
}

