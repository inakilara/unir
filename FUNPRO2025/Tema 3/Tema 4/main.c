//
// Created by Iñaki Lara on 11/11/2024.
//
#include <stdio.h>
#include <ctype.h>

int main(){
  char c;
  printf("Introduzca una cifra o una letra\n");
  scanf(" %c",&c);
  while(isdigit(c)){
    printf("Es una cifra\n");
    printf("Introduzca una cifra o una letra\n");
    scanf(" %c",&c);
  }
  printf("Es una letra.");
  return 0;
}
