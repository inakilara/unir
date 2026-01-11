// Crea un programa que lea un fichero de texto y muestre su contenido en la terminal

#include <stdio.h>
#include <stdlib.h>

int main(){
  char *ruta = "../Workspace/Lore_ipsum.txt";
  FILE *stream = fopen(ruta,"r");
  if (stream==NULL){
    printf("El archivo no se ha podido abrir");
    return -1;
  }
  /*char c;
  do{
    c = fgetc(stream);
    putc(c,stdout);
  }while(c!=EOF);*/
  char *texto=NULL;
  int len = 1;
  char c;
  while((c=(char)fgetc(stream))!=EOF){
    len ++;
    char *temp =(char *)realloc(texto,len*sizeof(char));
    if (temp == NULL) {
      free(texto);
      fclose(stream);
      return -1;
    }
    texto = temp;
    texto[len-2]=c;
  }
  if(texto!=NULL){
    texto[len-1]='\0';
  }
  //Mete aqui las operaciones que quieras realizar sobre el texto
  printf("%s",texto);
  free(texto);
  fclose(stream);
  return 1;
}
