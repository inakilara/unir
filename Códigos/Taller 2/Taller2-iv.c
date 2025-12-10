//
// Ejercicio 4: Escribe un programa que muestre la tabla de multiplicar escogida
//
#include <stdio.h>
#include <math.h>


void mostrarTabla(int);


int main () {
  int i;
  printf("Escoge el numero del que quieres mostrar la tabla de multiplicar: ");
  scanf(" %d",&i);
  mostrarTabla(i);
}


void mostrarTabla(int n){
  printf("\n La tabla del %d es:\n",n);
  for(int i=0;i<10;i++){
    printf("%d x %d = %d \n",i,n,i*n);
  }
}

