//
// Created by Iñaki Lara on 05/12/2025.
//
/*#include<stdio.h>


int main(){
  int vector[4];
  for (int i=0;i<4;i++){
    printf("Introduce el valor %d",i);
    fflush(stdout);
    scanf("%d",&vector[i]);
  }
  printf("El contenido del vector es");
  printf("%d %d %d %d",vector[0],vector[1],*(vector+2),*(vector+3));
  fflush(stdout);
  return 0;
}*/

/*Enunciado 1: Escribe un programa que pida al usuario rellenar un array de 5 posiciones y devuelva la media y la varianza de sus valores.

#include<stdio.h>
#include<math.h>


void leerValores(int*,int);
float calcularMedia(int*,int);
float calcularVarianza(int*,int);

int main(){
  int valores[]={0,0,0,0,0},length=5;
  leerValores(valores,length);
  float media = calcularMedia(valores,length);
  float varianza = calcularVarianza(valores,length);
  printf("La media del array es: %f  la varianza es: %f",media,varianza);
  return 0;
}


void leerValores(int* valores,int N){
  for(int i=0;i<N;i++){
    printf("\nIntroduzca el valor %d:",i);
    scanf(" %d",valores+i);
  }
}

float calcularMedia(int* valores,int length){
  float media=0;
  for (int i=0;i<length;i++){
    media += (float)*(valores+i)/(float)length;
  }
  return media;
}



float calcularVarianza(int* valores,int length){
  float media = calcularMedia(valores,length);
  float varianza = 0 ;
  for (int i=0;i<length;i++){
    varianza += pow(((float)*(valores+i)-media),2)/(float)length;
  }
  return varianza;
}*/


//Enunciado 2: Crea un programa que lea dos matrices por teclado y calcule la suma, la transpuesta
// y la multiplicacion de ellas y muestre el resultado por pantalla.


#include<stdio.h>

void leerMatriz(float*,int);
void mostrarMatriz(const float*,int);
void calcularTraspuesta(const float*,float*,int);
void calcularSuma(const float*,const float*,float*,int);
void calcularProducto(const float*,const float*,float*,int);


int main(){
  float A[2][2],B[2][2],T[2][2],S[2][2],P[2][2];
  leerMatriz(&A[0][0],2);
  leerMatriz(&B[0][0],2);
  calcularTraspuesta(&A[0][0],&T[0][0],2);
  calcularSuma(&A[0][0],&B[0][0],&S[0][0],2);
  calcularProducto(&A[0][0],&B[0][0],&P[0][0],2);
  printf("La traspuesta de A es:\n");
  mostrarMatriz(&T[0][0],2);
  printf("La suma de A+B es:\n");
  mostrarMatriz(&S[0][0],2);
  printf("El producto de A por B es:\n");
  mostrarMatriz(&P[0][0],2);
  return 0;
}

void leerMatriz(float*M,int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("\nIntroduzca el valor %d %d:",i,j);
      scanf(" %f",M+j+i*N);
    }
  }
}

void mostrarMatriz(const float*M,int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("%f\t",*(M+j+i*N));
    }
    printf("\n");
  }
}

void calcularTraspuesta(const float*M,float*T,int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        *(T+j+i*N)=*(M+i+j*N);
    }
  }
}

void calcularSuma(const float*A,const float*B,float*S,int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      *(S+j+i*N)=*(A+j+i*N)+*(B+j+i*N);
    }
  }
}

void calcularProducto(const float*A,const float*B,float*P,int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
     *(P+j+i*N)=0;
      for(int k=0;k<N;k++){
        *(P+j+i*N) += (  *(A+k+i*N)  )*(   *(B+j+k*N) );
      }
    }
  }
}


