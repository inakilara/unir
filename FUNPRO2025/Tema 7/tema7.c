#include<stdio.h>

void buscarMaximo(int[],int,int**);

int main(){
  int vec[10]={1,2,3,4,5,6,7,8,9,0};
  int * ptr=NULL;
  buscarMaximo(vec,10,&ptr);
  return 0;
}

void buscarMaximo(int v[],int n,int**p){
  int max=v[0],ind=0;
  for(int i=1;i<n;i++){
    if(v[i]>max){
      max=v[i];
      ind=i;
    }
  }
  *p=&v[ind];
}
