//
// Created by Iñaki Lara
//
// Escribe un programa que permita definir un polígono de n lados fijados en tiempo de ejecución,
// que permita introducir sus coordenadas y las muestre por pantalla

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct{
  double x;
  double y;
}Coordenada;

Coordenada* crearPoligono(int*);
void leerVertices(Coordenada*,int);
void mostrarVertices(Coordenada*,int);
void rotarPoligono(Coordenada*,int,double);

int main(){
  int n;
  Coordenada *poligono=crearPoligono(&n);
  leerVertices(poligono,n);
  mostrarVertices(poligono,n);
  rotarPoligono(poligono,n,asin(1));
  mostrarVertices(poligono,n);
  free(poligono);
  return 0;
}

Coordenada* crearPoligono(int* n){
  //Coordenada *poligono=NULL;
  printf("Introduce el numero de lados del poligono: ");
  scanf("%d",n);
  Coordenada *poligono = (Coordenada* ) malloc(*n * sizeof(Coordenada)); //Asignamos a poligono un espacio en memoria igual al contenido de n por el
  return poligono;                            // tamaño en la memoria de las variables tipo Coordenada.
}

void leerVertices(Coordenada* poligono,int n){
  for (int i=0;i<n;i++){
   printf("Introduce el valor de la coordenada x del vertice numero %d: ",i);
   scanf("%lf",&(poligono+i)->x);
    printf("Introduce el valor de la coordenada y del vertice numero %d: ",i);
    scanf("%lf",&(poligono+i)->y);
  }
}

void mostrarVertices(Coordenada* poligono,int n){
  printf("\nLas coordenadas del poligono son:\n");
  for (int i=0;i<n;i++){
    printf("%d) x:%lf y:%lf\n",i,(poligono+i)->x,(poligono+i)->y);
  }
}

void rotarPoligono(Coordenada* poligono,int n,double angulo){
    double xr,yr;
    for (int i=0;i<n;i++){
      xr=cos(angulo)*((poligono+i)->x)-sin(angulo)*((poligono+i)->y);
      yr=sin(angulo)*((poligono+i)->x)+cos(angulo)*((poligono+i)->y);
      (poligono+i)->x=xr;
      (poligono+i)->y=yr;
    }
}