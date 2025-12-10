//
// Created by Iñaki Lara on 02/04/2025.
//
/*Implementa un programa que calcule el perímetro de un cuadrado (P), el área de ese
cuadrado (A), el perímetro del círculo circunscrito (PC) y el área de la circunferencia
circunscrita (AC). Debes definir funciones diferentes para calcular P, A, PC y AC. El
único parámetro proporcionado por el usuario es el lado del cuadrado.*/

#include <stdio.h>
#include <math.h>

double const PI = acos(-1) ;

void interfaz(double*);
void perimetro_cuadrado(double);
void circulos(double);

int main() {
    double L;
    interfaz(&L);
    perimetro_cuadrado(L);
    circulos(L);
}


void interfaz(double* L) {
    printf("Introduce el valor del lado:");
    scanf("%lf",L);
}

void perimetro_cuadrado(double L) {
    double perimetro = 4*L;
    printf("El perimetro es: %lf.",perimetro);
}

void circulos(double L) {
    printf("Perímetro de circunferencia inscrita: %lf",L*PI);
}