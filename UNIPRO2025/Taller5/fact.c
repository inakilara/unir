//
// Created by Iñaki Lara on 20/01/2026.
//
#include <stdio.h>

int fact(int);

int main(){
  int n;
  printf("Introduce n:");
  scanf("%d",&n);
  int m = fact(n);
  printf("\nEl factorial de %d es %d",n,m);
}

int fact(int n){
  if (n==0){
    return 1;
  }
  else{
    return n*fact(n-1);
  }

}