//
// Crear programa que muestre contenido de un fichero por pantalla indicado en la llamada del programa
// Caracter a caracter
//
#include<stdio.h>

int main(int argc,char *argv[]){
  if (argc!=2) {
    printf("La llamada al programa es incorrecta. Tiene que ser de la forma:\n [ejecutable] nombre_de_archivo");
    return -1;
  }
  FILE *archivo= fopen(argv[1],"r");
  if (archivo==NULL){
    printf("No ha sido posible abrir el archivo");
    return -1;
  }
  char c;
  do{
    c=fgetc(archivo);
    printf("%c",c);
  }while(c!=EOF);
  return 0;
}