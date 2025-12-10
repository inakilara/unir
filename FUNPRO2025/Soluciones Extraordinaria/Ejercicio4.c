//Solución al siguiente problema:
/*Escriba un programa que lea por teclado una cadena de como máximo 100 caracteres.
Indique la palabra más corta de la frase y su longitud (si hay varias con la misma longitud es suficiente indicar solo una).

Ejemplo:
-Array de Entrada = “Llega el fin del primer cuatrimestre del curso”
-La palabra más corta es “el” con 2 caracteres.


*/

#include "stdio.h"
#include "string.h"
#define n 100




//Función principal
int main() {
  char mystring[n];
  printf("Introduzca la frase:");
  fgets(mystring, n, stdin); //A diferencia de printf , no deja de leer al encontrar un espacio en blanco
  if (mystring[0] == '\n') { //Si la cadena está vacía detiene el programa
    printf("La entrada está vacía");
    return 0;
  }
  char *result =strtok(mystring," ");  //Parte la cadena en trozos separados por " ", cada llamada devuelve un puntero al siguiente trozo.
  int length=0;
  if(result!=NULL) {length=strlen(result);} // Guarda la longitud del primertrozo
  char *word=strtok(NULL," ");
  while (word != NULL) { //Mientras la particion no termine, compara cada trozo con el previo
    if(strlen(word)<=length){length=strlen(word);result=word;} //Si el trozo es más pequeño, guárdalo a él y su longitud
    word=strtok(NULL," ");
  }
  printf("La palabra más corta es: %s. Con una longitud de %d.",result,length);
  return 0;
}
