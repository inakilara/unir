#include <stdio.h>
#include <stdlib.h>
#define N_ELEM 3

void muestra_parte(char *mensaje, char *ptr, int n){
         printf(“%s en %p\n”, mensaje, ptr);
         for (int i = 0; i < n; i++){
               printf(“%d (%c), ”, ptr[i], ptr[i]);}
         printf(“\n\n”);}

int main(){
   char *parte1 = (char *) malloc(N_ELEM * sizeof(char));
  (*parte1) = ‘a’;
  char *parte2 = (char *) malloc(N_ELEM * sizeof(char));
  (*parte2) = ‘A’;
  muestra_parte(“Primera parte”,parte1, N_ELEM);
  muestra_parte(“Segunda parte”,parte2, N_ELEM);

  char *todo = (char *) realloc(parte1,N_ELEM *2);
  for (int i = 0; i < N_ELEM ; i++){
         todo[N_ELEM +i]=parte2[i];}
  muestra_parte(“Todo”,todo, N_ELEM *2);
  free(parte2);
  free(todo);
   return 0;
}
