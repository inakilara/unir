//
// Crea un programa que te permita introducir un numero arbitrario de cordenadas y las guarde en un archivo de texto
//
/*
#include <stdio.h>
#include <stdlib.h>

struct coordenada{
  float x;
  float y;
  float z;
};

typedef struct coordenada coordenada3D;

void add_coordenada(coordenada3D *,int);

int main(){
  coordenada3D *lista_de_coordenadas = NULL;
  char c;
  int len=0;
  do {
    printf("Pulsa cualquier tecla para introducir el siguiente valor o 'N' para finalizar");
    scanf(" %c",&c);
    if(c!='N') {
      len++;
      coordenada3D* temp = (coordenada3D *)realloc(lista_de_coordenadas,sizeof(coordenada3D)*len);
      if (temp ==NULL) {
        free(temp);
        free(lista_de_coordenadas);
        temp=NULL;
        lista_de_coordenadas=NULL;
        return -1;
      }
      lista_de_coordenadas = temp;
      add_coordenada(lista_de_coordenadas,len);
    }
  }while(c!='N');
  FILE *archivo = fopen("../Workspace/coordenadas.txt","w");
  if (archivo==NULL) {
    fclose(archivo);
    free(lista_de_coordenadas);
  }
  else {
    fprintf(archivo,"#x,y,z\n");
    if (lista_de_coordenadas==NULL) {
      fclose(archivo);
    }
    else {
      for(int i=0;i<len;i++) {
        fprintf(archivo,"%f,%f,%f\n",(lista_de_coordenadas+i)->x,(lista_de_coordenadas+i)->y,(lista_de_coordenadas+i)->z);
      }
    }
    fclose(archivo);
    free(lista_de_coordenadas);
  }
  return 0;
}

void add_coordenada(coordenada3D *lista_de_coordenadas,int len){
  printf("\nIntroduce el valor de x: ");
  scanf("%f",&((lista_de_coordenadas+len-1)->x));
  printf("\nIntroduce el valor de y: ");
  scanf("%f",&((lista_de_coordenadas+len-1)->y));
  printf("\nIntroduce el valor de z: ");
  scanf("%f",&((lista_de_coordenadas+len-1)->z));
}*/

//Problema 5
/*
Escriba un programa que:
1.Permita introducir al usuario un introducir una cadena de caracteres de longitud máxima 50.
2.Invierta la cadena.
3.Grabe la cadena y la cadena invertida en un fichero externo llamado “cadenas.txt”
*/
#include <string.h>
#include <stdio.h>

int main() {
  char miCadena[51],cadena_invertida[51];
  printf("Introduce una cadena de caracteres de hasta 50 caracteres:\n");
  scanf("%50[^\n]",miCadena);
  //fgets(miCadena,50,stdin);  // Añadir un caracter más para hacer espacio para el salto de linea
  for (int i=0;i<strlen(miCadena);i++) {
        cadena_invertida[i] = miCadena[strlen(miCadena)-i-1];
  }
  cadena_invertida[strlen(miCadena)]='\0';
  FILE *archivo= fopen("../Workspace/cadenas.txt","w");
  if (archivo==NULL) {
    printf("El fichero no se ha podido abrir");
    return -1;
  }
  fprintf(archivo,"%s\n%s",miCadena,cadena_invertida);
  fclose(archivo);
  return 0;
}

