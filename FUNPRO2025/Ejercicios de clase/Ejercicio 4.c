//

//

#include <stdio.h>
#include<stdlib.h>

int main(){
  int n;
  printf("Cuantos valores quieres introducir?:");
  scanf(" %d%*c",&n);
  double *vals=(double *)calloc(n,sizeof(double)),suma=0;
  for (int i=0;i<n;i++){
    printf("\nIntroduce el siguiente valor: ");
    scanf(" %lf%*c",vals+i);
    suma+=*(vals+i);
  }
  printf("\nLos valores introducidos son:");
  for (int i=0;i<n;i++){
    printf("%lf ",*(vals+i));
  }
  printf("\n Y el promedio es %lf.",suma/n);
  free(vals);
  return 0;
}