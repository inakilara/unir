//
// Created by ilara on 9/25/24.
//// Tema 2 Fundamentos de programación 2024. Ejemplo 2.
//   Resuelve el ejercicio 2.9 de Joyanes, L. 2008
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int num=0;
    printf("Introduce el valor del numero.\n");
    scanf("%d",&num);
    if(num<=0) { //comprueba que es positivo
        printf("El numero no es válido\n");
        return -1;
    }
    printf("Los numeros primos menores que %d son:\n",num);
    for(int i=2;i<=num;i++){ // Bucle sobre los numeros desde 2->a (EL 1 es primo¿?)
	bool isPrime=true;
	for(int j=2;j<i;j++){ //Comprueba todos los numeros de 2->a-1 (todos los números son divisibles entre 1 y si mismos)
		if(i%j==0){
			isPrime=false; //La primera vez que encuentra un divisor exacto para el bucle y lo marca como no primo.
			break;}
		}
	if (num==i){if(isPrime){printf("%d ",i);}}
	else{if(isPrime){printf("%d, ",i);}}
	}
    printf("\n");
    return 0;
}