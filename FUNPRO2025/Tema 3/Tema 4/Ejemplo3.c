//
// Created by ilara on 9/25/24.
//// Tema 2 Fundamentos de programación 2024. Ejemplo 3.
//   Resuelve el ejercicio 2.13 de Joyanes, L. 2008
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define n 100



int main() {
    //Función principal
    char myString[n];
   int isPalindromo=1;
    printf("Introduce la palabra a comprobar:\n");
    scanf("%s",myString);
	for (int i=0;i<=strlen(myString);i++) {
		if(isupper(myString[i])){myString[i]=tolower(myString[i]);}
	}
    for (int i=0;i<=strlen(myString);i++){
	if(myString[strlen(myString)-1-i]!=myString[i]){
		isPalindromo=0;
		break;
		}
	} 
    if(isPalindromo){printf("La palabra es un palíndromo.");}
	else{printf("La palabra no es un palíndromo.");}
    return 0;
}