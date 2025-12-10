#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"
#define n 10 //Tamaño ajustable

void createMatrix(int matriz[n][n]){  //Recorre la matriz con dos bucles anidados leyendo el contenido
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
    matriz[i][j]=(float)rand()/(float)(RAND_MAX/1.55);
    }
  }
}

void createIdentity(int matriz[n][n]){  //Recorre la matriz co dos bucles anidados leyendo el contenido
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
    if(i==j){matriz[i][j]=1;}
    else{matriz[i][j]=0;}
    }
  }
}

void printMatrix(int matriz[n][n],FILE *File){ //Recorre la matriz con dos bucles anidados escribiendo el contenido
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (File == NULL){printf("%d\t", matriz[i][j]);}  //Si no se proporciona archivo se escribe en pantalla
      else{fprintf(File,"%d\t", matriz[i][j]);}
    }
    if (File == NULL){printf("\n");}
    else{fprintf(File,"\n");}
  }
  if (File == NULL){printf("\n");}
  else{fprintf(File,"\n");}
}

void mutiplyMatrix(int matriz1[n][n], int matriz2[n][n], int matriz3[n][n]){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      matriz3[i][j]=0;
      for (int k = 0; k < n; k++){
        matriz3[i][j] += matriz1[i][k] * matriz2[k][j]; //Tres buvles anidados para implementar la difinicion de multiplciacion de matrices
      }
    }
  }
}

//Función principal
int main() {
  int A[n][n],B[n][n], C[n][n],Id[n][n];
  srand(time(NULL));
  createMatrix(A);
  createIdentity(Id);
  for (int i=0;i<20000;i++){
                     createMatrix(B);
                     mutiplyMatrix(Id, C, A);
  	mutiplyMatrix(A, B, C);
  }
  printf("\nMatriz resultante:\n");
  printMatrix(C,NULL); //Imprime en pantalla
  return 0;
}