//
// Created by Iñaki Lara on 05/12/2024.
//
#include <stdio.h>

void ordenarInsercion(int*);
void ordenarSeleccion(int*);
void ordenarBurbuja(int*);

int main(){
  int vector[10]={-4,12,4,0,-5,1,5,9,-6,5};
  printf("Vector sin ordenar:\n(");
  for(int i=0;i<9;i++){
    printf("%d,",vector[i]);
  }
  printf("%d)",vector[10]);// este fuera para que quede más bonito
  //ordenarInsercion(vector);
  //ordenarSeleccion(vector);
  ordenarBurbuja(vector);
  printf("\nVector ordenado:\n(");
  for(int i=0;i<9;i++){
    printf("%d,",vector[i]);
  }
  printf("%d)",vector[10]);



}

void ordenarInsercion(int vector[]){
  int vectorAux[10]; //vector auxiliar para modificarlo
  for(int i=0;i<10;i++){
    vectorAux[i]=vector[i];
  }
  int auxVal; //el numero que seleccionamos
  vectorAux[0]=vector[0]; //el primer elemento está ya ordenado
  for (int ind=1;ind<10;ind++){
  auxVal=vector[ind];
    for (int i=0;i<ind;i++){
      if(vectorAux[i]>auxVal){
        for (int j=ind;j>i;j--){
          vectorAux[j]=vectorAux[j-1];
        }
        vectorAux[i]=auxVal;
        break;
      }
    }
    }
  for(int i=0;i<10;i++){
    vector[i]=vectorAux[i];
  }
}

void ordenarSeleccion(int vector[]){
  int min,aux,ind;
  int vectorAux[10];
  for(int i=0;i<10;i++){
    vectorAux[i]=vector[i];
  }
  for(int i=0;i<10;i++){
    min=vectorAux[i];
    for(int j=i;j<10;j++){
      if(vectorAux[j]<min)
        {
        min=vectorAux[j];
        ind=j;
      }
    }
    aux=vectorAux[i];
    vectorAux[i]=min;
    vectorAux[ind]=aux;

  }
  for(int i=0;i<10;i++){
    vector[i]=vectorAux[i];
  }
}

void ordenarBurbuja(int vector[]){
  int vectorAux[10],flag=1,aux;
  for(int i=0;i<10;i++){
    vectorAux[i]=vector[i];
  }
  while(flag==1){
    flag=0;
    for(int i=0;i<10;i++){
      if(vectorAux[9-i]<vectorAux[9-i-1]){
        aux=vectorAux[9-i];
        vectorAux[9-i]=vectorAux[9-i-1];
        vectorAux[9-i-1]=aux;
        flag=1;
      }
    }
  }
  for(int i=0;i<10;i++){
    vector[i]=vectorAux[i];
  }
}