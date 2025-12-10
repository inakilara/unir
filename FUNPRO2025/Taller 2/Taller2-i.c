#include<stdio.h>
#include <string.h>

/*Enunciado 1*/
void mostrarMensaje(char*);
int leerEntero(char*);
void leerCadena(char*,char*,int);

int main(){
  /*
* Ejercicio 1: Crea una interfaz de usuario usando funciones que permita mandar mensajes, leer cadenas de texto y numeros enteros*/
  int num;
  char myString[51];
  leerCadena("Introduce tu nombre",myString,50);
  num = leerEntero("Introduce tu curso");
  mostrarMensaje("Hola ");
  mostrarMensaje(myString);
  if (num ==1) {
    mostrarMensaje("\n Bienvenido al 1er curso");
  }
  return 0;
}

void mostrarMensaje(char* c){
  printf("%s",c);
}
int leerEntero(char* c){
  int n;
  printf("%s:\n",c);
  scanf(" %d",&n);
  return n;
}
void leerCadena(char* c1,char* c2,int lenMax) {
  printf("%s: \n",c1);
  fgets(c2,lenMax,stdin);
  c2[strlen(c2)-1]='\0';
}