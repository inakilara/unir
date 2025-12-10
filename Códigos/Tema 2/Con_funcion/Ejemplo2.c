//
// Created by ilara on 9/25/24.
//// Tema 2 Fundamentos de programación 2024. Ejemplo 2.
//   Resuelve el ejercicio 2.9 de Joyanes, L. 2008
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void getNumber(int* a)
{ //Función que lee el valor de un entero desde la terminal.
//toma un punteros a int y graba el valore sobre dicha direccion de memoria.
    printf("Introduce el valor del número.\n");
    scanf("%d",a);
}

void printPrimes(int a) {
    //Función que calcula los números primos menores que a 
    // y los imprime por pantalla
   for(int i=2;i<=a;i++){ // Bucle sobre los numeros desde 2->a (EL 1 es primo¿?)
	bool isPrime=true;
	for(int j=2;j<i;j++){ //Comprueba todos los numeros de 2->a-1 (todos los números son divisibles entre 1 y si mismos)
		if(i%j==0){
			isPrime=false; //La primera vez que encuentra un divisor exacto para el bucle y lo marca como no primo.
			break;}
		}
	if (a==i){if(isPrime){printf("%d ",i);}} 
	else{if(isPrime){printf("%d, ",i);}}
	}
printf("\n");
}

int main() {
    //Función principal
    int num=0;
    getNumber(&num); //leeel número
    if(num<=0) { //comprueba que es positivo
        printf("El número no es válido\n");
        return -1;
    }
    printf("Los números primos menores que %d son:\n",num);
    printPrimes(num); //Imprime por pantalla los primos menores que num;
    return 0;
}