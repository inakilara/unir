//
// Created by Iñaki Lara on 05/12/2024.
//
#include <stdio.h>
#include <math.h>
#define FILAS 3
#define COLUMNAS 3

void mostrarMatriz(int m[FILAS][COLUMNAS]);
void crearIdentidad(int m[FILAS][COLUMNAS]);

int main() {
    int matriz33[3][3]={{10,1,-3},{4,2,0},{3,1,4}};
    //int matriz22[2][2]={{3,-2},{4,7}};
    int identidad33[3][3];
    printf("Matriz 3x3:\n");
    mostrarMatriz(matriz33);
    //printf("Matriz 2x2:\n");
    //mostrarMatriz(matriz22);
    printf("Matriz Identidad 3x3:\n");
    crearIdentidad(identidad33);
    mostrarMatriz(identidad33);
    return 0;
}

void mostrarMatriz(int m[FILAS][COLUMNAS]) {
    for(int i=0;i<FILAS;i++) {
        for(int j=0;j<COLUMNAS;j++) {
            //printf("%d\t",*(matriz+i*longitud+j));
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }

}

void crearIdentidad(int m[FILAS][COLUMNAS]) {
    for(int i=0;i<FILAS;i++) {
        for(int j=0;j<COLUMNAS;j++) {
            if(i==j){m[i][j]=1;}
            else{ m[i][j]=0;}
        }
        printf("\n");
    }
}