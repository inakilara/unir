//Solución al siguiente problema:
/*Escriba un programa que lea los valores introducidos por teclado de 2 matrices de
tamaño 3x3 y las guarde en 2 arrays bidimensionales. Calcule la multiplicación de
las dos matrices. Muestre la matriz resultado de la multiplicación por pantalla y
escríbala en un fichero llamado “mul.txt”. Haga uso de ‘\n’ y ‘\t’ para una
visualización cómoda de la matriz.


*/

#include "stdio.h"
#include "string.h"
#define n 3 //Tamaño ajustable

void readMatrix(int matriz[n][n]){  //Recorre la matriz co dos bucles anidados leyendo el contenido
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("Ingrese la matriz [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
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
  int A[n][n],B[n][n], C[n][n];
  FILE *File=fopen("mul.txt", "w"); //La opción "w" crea un archivo si no existe
  if (File==NULL){printf("Error al abrir el archivo");
    return 0;
  }
  readMatrix(A);
  readMatrix(B);
  mutiplyMatrix(A, B, C);
  fprintf(File,"Matriz A:\n");
  printMatrix(A,File);
  fprintf(File,"Matriz B:\n");
  printMatrix(B,File);
  fprintf(File,"Matriz AxB:\n");
  printMatrix(C,File);
  printf("\nMatriz AxB:\n");
  printMatrix(C,NULL); //Imprime en pantalla
  fclose(File);
  return 0;
}
