//
//

#include<stdio.h>

void leerMatriz(float* ,int);
void mostrarMatriz(float* ,int);
void funcionInsegura(float**);

int main() {
    float A[3][3];
    float *ptr=NULL;
    leerMatriz(&A[0][0],3);
    mostrarMatriz(&A[0][0],3);
    funcionInsegura(&ptr);
    return 1;
}

void leerMatriz(float* M,int N) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("Introduce el valor de %d %d: ",i,j);
            scanf("%f",M+j+i*N);
        }
    }
}

void mostrarMatriz(float* M,int N) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            printf("%f ",*(M+j+i*N));
        }
        printf("\n");
    }
}

void funcionInsegura(float **ptr) {
    float a=7.5;
    *ptr=&a;
}