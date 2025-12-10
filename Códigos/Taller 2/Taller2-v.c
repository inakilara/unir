//
// Ejercicio 5: Crea un programa que pida dos matrices y muestre la multiplicación de estas
//
#include <stdio.h>
#include <math.h>
#define N 2


void pedirMatriz(float[N][N]);
void mutiplicarMatrices(float[N][N],float[N][N],float[N][N]);
void mostrarMatriz(float[N][N]);


int main () {
  float A[N][N],B[N][N],C[N][N];
  printf("Introduce la primera matriz:\n");
  pedirMatriz(A);
  printf("Introduce la segunda matriz:\n");
  pedirMatriz(B);
  mutiplicarMatrices(A,B,C);
  printf("El resultado es:\n");
  mostrarMatriz(C);
}

void pedirMatriz(float M[N][N]){
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      printf("\nIntroduce el valor %d %d:",i,j);
      scanf("%f",&M[i][j]);
    }
  }
}

void mutiplicarMatrices(float A[N][N],float B[N][N],float C[N][N]){
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      C[i][j]=0;
      for (int k=0;k<N;k++){
        C[i][j]+=A[i][k]*B[k][j];
      }
    }
  }
}

void mostrarMatriz(float M[N][N]){
  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      printf("%f\t",M[i][j]);
    }
    printf("\n");
  }
}


