//
//
#include <stdio.h>
#include <math.h>
// En este código se asume que todas las matrices son cuadradas.
void mostrarMatriz(int *,int);
void crearIdentidad(int *,int);
void leerMatriz(int *,int);
void multiplicacionMatrices(int* ,int* ,int* ,int); //Asume que la forma de las matrices es igual para las 3.

int main() {
    int matriz33[3][3]={{10,1,-3},{4,2,0},{3,1,4}};
    int matriz22[2][2]={{3,-2},{4,7}},matriz22B[2][2],matriz22C[2][2];
    int identidad44[4][4];
    printf("Matriz 3x3:\n");
    mostrarMatriz(&matriz33[0][0],3);//longitud = (int)sqrt(sizeof(matriz33)/sizeof(int))
    printf("Matriz 2x2:\n");
    mostrarMatriz(&matriz22[0][0],2);
    printf("Matriz Identidad 4x4:\n");
    crearIdentidad(&identidad44[0][0],4);
    mostrarMatriz(&identidad44[0][0],4);
    leerMatriz(&matriz22B[0][0],2);
    multiplicacionMatrices(&matriz22[0][0],&matriz22B[0][0],&matriz22C[0][0],2);
    mostrarMatriz(&matriz22C[0][0],2);
    return 0;
}

void mostrarMatriz(int* matriz,int longitud) {
    for(int i=0;i<longitud;i++) {
        for(int j=0;j<longitud;j++) {
            printf("%d\t",*(matriz+i*longitud+j));
        }
        printf("\n");
    }
}

void crearIdentidad(int* matriz,int longitud) {
    for(int i=0;i<longitud;i++) {
        for(int j=0;j<longitud;j++) {
            if(i==j){*(matriz+i*longitud+j)=1;}
            else{ *(matriz+i*longitud+j)=0;}
        }
    }
}

void leerMatriz(int *matriz,int longitud){
    for (int i=0;i<longitud;i++){
        for (int j=0;j<longitud;j++){
            printf("Introduce el elemento %d %d: ",i+1,j+1);
            scanf("%d",matriz+i*longitud+j);
        }
    }
}

void multiplicacionMatrices(int *matriz1,int *matriz2,int *matriz3,int longitud){
    for (int i=0;i<longitud;i++){
        for (int j=0;j<longitud;j++){
            *(matriz3+i*longitud+j)=0;
            for (int k=0;k<longitud;k++){
                *(matriz3+i*longitud+j)+= (*(matriz1+i*longitud+k))* (*(matriz2+k*longitud+j));
            }
        }
    }
}