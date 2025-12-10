

/*

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Nmax 21
int leerCadena(char *);
int leerEntero(int *); //El valor de retorno es un código de error, la variable se modifica pasandola por referencia.



int main(){
  char miCadena[Nmax];
  int error = 0;
  int valor;
  printf("Introduce una cadena (de maximo 20 caracteres):\n");
  fflush(stdout);
  error = leerCadena(miCadena);
  printf("%s",miCadena);
  fflush(stdout);
  printf("\nIntroduce numero entero:\n");
  fflush(stdout);
  error = leerEntero(&valor);
  printf("%d",valor);
  fflush(stdout);
  return 0;
}

int leerCadena(char *miCadena){
  fgets(miCadena,Nmax,stdin);
  //implementar chequeo de lectura correcta para hacer la salida 0.
  miCadena[strlen(miCadena)-1]='\0';
  return 1;
}

int leerEntero(int* valor){
  char miCadena[Nmax];
  char *ptr;
  int error =1;
  error = leerCadena(miCadena);
  if (error != 1){return error;}
  else{
    errno=0;
     *valor = strtol(miCadena,&ptr,10);
   //Implementar chequeos
     if(errno!=0||miCadena==ptr){return -1;}
  }

}
*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 2

void leerMatriz(float [N][N]);
void mostrarMatriz(float [N][N]);

int main(){
  float A[N][N];
  leerMatriz(A);
  mostrarMatriz(A);
  return 0;
}

void leerMatriz(float M[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("Introduce el elemento %d %d",i,j);
      scanf(" %f",&M[i][j]);
    }
  }

}

void mostrarMatriz(float M[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf(" %f\t",M[i][j]);
    }
    printf("\n");
  }
}*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 2

void leerMatriz(float *const ,int);
void mostrarMatriz(float *const,int);


int main(){
  float A[N][N];
  leerMatriz(&A[0][0],N);
  mostrarMatriz(&A[0][0],N);
  return 0;
}

void leerMatriz(float *const M,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("Introduce el elemento %d %d: ",i,j);
      scanf(" %f%*c",M+j+i*n);
    }
  }

}

void mostrarMatriz(float *const M, int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf(" %f  ",*(M+j+i*n));
    }
    printf("\n");
  }
}

/*
#include <stdio.h>
#include<math.h>

struct vector{
  float x;
  float y;
  float z;
};

typedef struct vector Tvector;

void leerVector(Tvector*);
void mostrarVector(Tvector);
float distancia(Tvector,Tvector);

int main(){
  Tvector v1,v2;
  v2.x=0;
  v2.y=1;
  v2.z=1;

  leerVector(&v1);
  mostrarVector(v1);

  printf("la distancia con v2 es: %f",distancia(v1,v2));
  return 0;
}

void leerVector(Tvector* v){
  printf("Introduce el valor x: \n");
  scanf(" %f",&(v->x));
  printf("Introduce el valor y: \n");
  scanf(" %f",&(v->y));
  printf("Introduce el valor z: \n");
  scanf(" %f",&(v->z));
}
void mostrarVector(Tvector v){
  printf("vx: %f, vy: %f, vz: %f",v.x,v.y,v.z);
}

float distancia(Tvector v1,Tvector v2){
  return sqrt(v1.x*v2.x+v1.y*v2.y+v1.z*v2.z);
}


void leerMatriz(float *M,int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("Introduce el elemento %d %d: ",i,j);
      scanf(" %f%*c",M+j+i*n);
    }
  }

}*/