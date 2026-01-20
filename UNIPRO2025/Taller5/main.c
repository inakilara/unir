//
// Crear programa que muestre contenido de un fichero por pantalla indicado en la llamada del programa
// Caracter a caracter
//

#include<stdio.h>


int main(int argc,char *argv[]){
  FILE *archivo = fopen(argv[1],"r");
  /*char c;
  do{
  c=fgetc(archivo);
  putc(c,stdout);
  }while(c!=EOF);
  char c[70];
  do{
    fgets(c,70,archivo);
    printf("%s",c);
  }while(!feof(archivo));
  return 0;*/
  char c[10000];
  fscanf(archivo,"%10000c",c);
  printf("%s",c);
  return 0;
}
