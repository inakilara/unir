//
//// Tema 2 Fundamentos de programación 2024. Ejemplo 1.
//   Resuelve el ejercicio 2.3 de Joyanes, L. 2008
//
//Escribir un programa para determinar el máximo común divisor de dos números enteros (MCD)
//por el algoritmo de Euclides:
//
//1.Dividir el mayor de los enteros por el menor.
//2.Dividir el divisor por el resto
//3.Continuar el proceso de dividir el último divisor por
// el último resto hasta que la división sea exacta.
//4. El último divisor es el mcd

//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numA=0,numB=0, resultado=0;
    printf("Introduce el valor del primer numero.\n");
    scanf("%d",&numA);
    printf("Introduce el valor del segundo numero.\n");
    scanf("%d",&numB);
    if(numA<=0||numB<=0) { //comprueba que ambos son positivos
        printf("Los numeros no son validos\n");
        return -1;
    }
    //Bloque que calcula el MCD según el metodo de Euclides
    // Toma dos numeros de entrada y devuelve el resultado
    	int bigNum=0,smallNum=0;
   		int dividendo=0,divisor=0,resto=-1;
    	if(numA>numB) {  //Esta ramificacion ordena a y b según cual sea mayor
        	bigNum=numA;
        	smallNum=numB;
    	}
    	else if(numB>numA) {
        	bigNum=numB;
        	smallNum=numA;
    	}
    	else { //si son iguales MCD es igual a ambos numeros.
        	resultado=numA;
    	}
        if (resultado==0){ //Empieza el cálculo si los numeros no son iguales
    		dividendo=bigNum;
    		divisor=smallNum;
    		resto=dividendo%divisor;
            if (resto==0){resultado=divisor;}//Si un numero es dibisible entre el otro, se termina el proceso
    		while(resto!=0) {   //repite la division hasta encontrar que divisor de resto cero
        		                    resultado=resto;   //el resultado es el último divisor antes de salir del bucle, es decir, el penúltimo resto.
			dividendo=divisor;
			divisor=resto;
			resto=dividendo%divisor;
    		}
        }
    printf("El resultado es: %d\n",resultado); //Devuelve el resultado por pantalla
    return 0;
}