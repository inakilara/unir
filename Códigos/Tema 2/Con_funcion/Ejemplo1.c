//
// Created by ilara on 9/25/24.
//// Tema 2 Fundamentos de programación 2024. Ejemplo 1.
//   Resuelve el ejercicio 2.3 de Joyanes, L. 2008
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNumbers(int* a,int* b)
{ //Función que lee los valores de dos enteros desde la terminal.
//toma dos punteros a int y graba los valores sobre dicha direccion de memoria.
    printf("Introduce el valor del primer número.\n");
    scanf("%d",a);
    printf("Introduce el valor del psegundo número.\n");
    scanf("%d",b);
}

int calcMCD(int a,int b) {
    //Función que calcula el MCD según el método de Euclides
    // Toma dos numeros de entrada y devuelve el resultado
    int result=0;
    int bigNum=0,smallNum=0;
    int dividendo=0,divisor=0,resto=-1;
    if(a>b) {  //Esta ramificacion ordena a y b según cual sea mayor
        bigNum=a;
        smallNum=b;
    }
    else if(b>a) {
        bigNum=b;
        smallNum=a;
    }
    else { //si son iguales MCD es igual a ambos numeros.
        return a;
    }
    dividendo=bigNum;
    divisor=smallNum;
    resto=dividendo%divisor;
    while(resto!=0) {   //repite la division hasta encontrar que divisro da resto cero
        result=resto;   //el resultado es el último divisor antes de salir del bucle, es decir, el penúltimo resto.
        resto=divisor%resto;
    }
    return result;
}

int main() {
    //Función principal
    int numA=0,numB=0, result=0;
    getNumbers(&numA,&numB); //lee los números
    if(numA<=0||numB<=0) { //comprueba que ambos son positivos
        printf("Los numeros no son validos\n");
        return -1;
    }
    result=calcMCD(numA,numB); //calcula MCD
    printf("El resultado es: %d\n",result); //Devuelve el resultado por pantalla
    return 0;
}