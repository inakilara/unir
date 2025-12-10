//
//  Construye un programa que permita convertir un archivo csv en un archivo binario y vice-versa, pasando la direccion
//  del archivo y el modo de operacion como argumentos en la llamada del programa.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{    // Estructura de los datos
  char nombre[51];
  int  codigoCLiente;
  float facturacionMedia;
}Tcliente;


int csvAbinario(char *);
int binarioAcsv(char *);
int longitudFichero(FILE *);

int main(int argc, char *argv[]){
  if (argc!=3){  //Si el numero de datos no coincide con lo esperado, cortamos la ejecución y mostramos un mensaje de ayuda.
    printf("Los parametros de entrada no son validos, el formato adecuado es:\n conversor [ruta_a_archivo] [1 o 2]");
    return 0;
  }
  switch (atoi(argv[2])){  //los argumentos se pasan a main() como cadenas, si son números hay que convertirlos.
    case 1:{
      return csvAbinario(argv[1]);}
    case 2: {
      return binarioAcsv(argv[1]);
    }
    default:
    printf("El modo de funcionamiento no es valido");
    return 0;
  }
}

int csvAbinario(char *path){
  Tcliente *lista=(Tcliente*) malloc(0*sizeof(Tcliente));  // Creamos una lista dinámica en la que ir leyendo los registros
  char myString[51];                                        //Aquí almacenaremos los registros de los clientes
  FILE *file=fopen(path,"r");
  int i=0;
  if (file!=NULL) {  // Comprueba que se ha abierto el archivo
    while(fgets(myString,50, file)) {        //Se detiene si llega al final el archivo
      if(myString[0]=='#'){continue;}        //Saltarse la primera linea, solo almacena el nombre de cada campo
      i++;                                   // i almacena el tamaño de la lista
      lista=(Tcliente*)realloc(lista,i*sizeof(Tcliente));   // Ampliamos la lista en 1 en cada vuelta del bucle
      strcpy((lista+i-1)->nombre, strtok(myString,","));    // Apunto strtok a la cadena e indico el delimitador (el resultado es la parte que va antes del primer delimitador)
      (lista+i-1)->codigoCLiente=atoi(strtok(NULL, ",")); //Sucesivas llamadas a strtok retoman el fraccionamiento donde lo dejó la llamada anterior
      (lista+i-1)->facturacionMedia=strtof(strtok(NULL, ","), NULL);
    }
    fclose(file);
    char *newNAME=(char*)malloc(sizeof(char)*strlen(path));   //Quiero abrir un archivo que se llame como el antiguo pero con cambio de extension
    strcpy(newNAME,path);
    for(int j=0;j<strlen(newNAME);j++){
      if(path[j]=='.'&&path[j+1]!='.'&&path[j+1]!='/'){
        *(newNAME+j)='.';
        *(newNAME+j+1)='b';
        *(newNAME+j+2)='i';
        *(newNAME+j+3)='n';
        *(newNAME+j+4)='\0';
        break;}
    }
    FILE *file_converted=fopen(newNAME,"wb");  //Abrir en modo binario
    if (file_converted!=NULL){
      if(fwrite(lista,sizeof(Tcliente),i,file_converted)<i) {                 //Escribo la lista en binario
        free(lista);free(newNAME);fclose(file);fclose(file_converted);return -3;  //Al terminar la funcion tengo que cerrar los archivos y liberar la memoria reservada
      }
      free(lista);free(newNAME);fclose(file);fclose(file_converted);return 1;
    }
    else{free(lista);free(newNAME);fclose(file);return -2;}
  }
  else{free(lista);return -1;}
}

int binarioAcsv(char *path){
  FILE *file=fopen(path,"rb");
  const int len = longitudFichero(file);
  Tcliente *lista=(Tcliente*) malloc(len*sizeof(Tcliente));   // Creo una lista dinámica para almacenar el contenido del binario
  if (file!=NULL) {
    const int n=fread(lista,sizeof(Tcliente),len,file);  //vuelco el binario en la lista
    if (n!=len){fclose(file);return -2;}                                 // compruebo que la lectura es adecuada
    char *newNAME=(char*)malloc(sizeof(char)*strlen(path));          // cambio la extensión del nombre
    strcpy(newNAME,path);
    for(int j=0;j<strlen(newNAME);j++){
      if(path[j]=='.'&&path[j+1]!='.'&&path[j+1]!='/'){
        *(newNAME+j)='.';
        *(newNAME+j+1)='c';
        *(newNAME+j+2)='s';
        *(newNAME+j+3)='v';
        *(newNAME+j+4)='\0';
        break;}
    }
    FILE *file_converted=fopen(newNAME,"w");                           // ahora el archivo es de texto
    if (file_converted!=NULL) {
      fprintf(file_converted,"#Nombre,codigo de cliente,facturacion media\n");
      for(int i=0;i<len;i++) {
        fprintf(file_converted,"%s,%d,%f\n",lista[i].nombre,lista[i].codigoCLiente,lista[i].facturacionMedia);   //escribo con el formato separado por comas
      }
      free(newNAME);free(lista);fclose(file);return 1;   // Hay que cerrar los archivos y liberar la memoria con cada return
    }
    else{free(newNAME);free(lista);fclose(file);return -3;}
  }
  else{free(lista);return -1;}
}

int longitudFichero(FILE *dataBase) {
  fseek(dataBase, 0L, SEEK_END);
  const int len=ftell(dataBase)/sizeof(Tcliente);
  rewind(dataBase);
  return len;
}