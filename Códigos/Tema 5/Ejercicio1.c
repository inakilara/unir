//
// Created by Iñaki Lara on 02/04/2025.
//
//Implementa un programa que utilice una función que muestre un saludo por pantalla.
#include <stdio.h>

void saludar(char nombre[10]);
void preguntar_nombre(char nombre[10]);

int main() {
    char nombre[10];
    preguntar_nombre(nombre);
    saludar(nombre);
    return 1;
}


void saludar(char nombre[10]) {
    printf("\n Hola %s!",nombre);
}

void preguntar_nombre(char nombre[10]) {
    printf("Escribe tu nombre:");
    scanf("%s",nombre);
}

