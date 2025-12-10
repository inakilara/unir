//
// Ejercicio 2: Escribe un programa que calcule propiedades de la circunferencia con funciones
//
#include <stdio.h>
#include <math.h>
#define PI 3.1415986

float pedirRadio();
void evaluar(float);
float area(float);
float longitud(float);

int main () {
  float r= pedirRadio();
  evaluar(r);
  return 0;
}

float pedirRadio(){
  float r;
  printf("Introduce el valor del radio: ");
  scanf("%f",&r);
  printf("\n");
  return r;
}

void evaluar(float r){
  char c;
  printf("Introduce L para calcular la longitud o A para calcular el area: ");
  scanf(" %c%*c",&c);
  switch (c){
      case 'L':
      {
        printf("La longitud es: %f",  longitud(r));
        break;
        }
      case 'A':
        {
        printf("El area es: %f",area(r));
        break;
        }
      default:
        printf("Opcion invalida");
        break;
  }
}

float area(float r) {
  return PI*r*r;
}
float longitud(float r) {
  return 2*PI*r;
}
