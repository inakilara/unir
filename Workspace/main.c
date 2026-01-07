#include<stdio.h>
#include <stdlib.h>

int main(){
  FILE *fichero = fopen("../Workspace/Lore_ipsum.txt","r");
  if (fichero==NULL){
    printf("Error abriendo el archivo");
    return -1;
  }
  /*char c;
  do{
    c = fgetc(fichero);
    putc(c,stdout);
  }while(c!=EOF);*/
  char *texto = NULL;
  int len=1;
  int c;
  while((c = fgetc(fichero)) != EOF){
    if (c!=EOF) {
      len++;
      char *temp = (char*) realloc(texto,len*sizeof(char));
      if (temp==NULL) {
        free(texto);
        fclose(fichero);
        return -1;
      }
        texto = temp;
        texto[len-2]=(char)c;
    }
  }
  if (texto!=NULL){
     texto[len-1] = '\0';
  }
  printf("%s",texto);
  free(texto);
  fclose(fichero);
  return 0;
}
