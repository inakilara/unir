//
// Created by Iñaki Lara on 22/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONGITUD_MINIMA 20

int main(){
  int ind=0,longitud=LONGITUD_MINIMA;
  char c,*miCadena=(char*) malloc(longitud*sizeof(char));
  printf("Introduce una cadena por teclado:");
  do{
    c=getchar();
    if(ind==longitud){longitud++;miCadena=(char*)realloc(miCadena,longitud*sizeof(char));}
    *(miCadena+ind)=c;
    ind++;
  }while(c!='\n');
  ind--;
  *(miCadena+ind)='\0';
  longitud=(ind);
  miCadena=(char*)realloc(miCadena,longitud*sizeof(char));
  printf("La cadena es:\n%s\tTiene longitud: %d\ty ocupa %d direcciones de memoria",miCadena,strlen(miCadena),longitud);
  free(miCadena);
  return 0;
}

