//
// Crear programa que muestre contenido de un fichero por pantalla indicado en la llamada del programa
// linea a linea
//
#include<stdio.h>

int main(int argc,char *argv[]){
  if (argc!=2) {
    printf("La llamada al programa es incorrecta. Tiene que ser de la forma:\n [ejecutable] nombre_de_archivo");
    return -1;
  }
  FILE *archivo= fopen(argv[1],"r");
  char c[70];
  do{
    fgets(c,70,archivo);
    printf("%s",c);
  }while(!feof(archivo));
  return 0;
}