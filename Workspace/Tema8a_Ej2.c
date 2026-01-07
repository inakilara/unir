//
// Crea un programa que te permita interactuar con una base de datos alojada en un fichero de texto con campos delimitados por comas.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

int leerRegistros(char*,char[N][100],int[N]);
void menu(char[N][100],int[N]);
void mostrarRegistros(char[N][100],int[N]);
void insertarRegistro(char[N][100],int[N]);
void eliminarRegistro(char[N][100],int[N]);
void guardarRegistros(char[N][100],int[N]);


int main(){
      char nombres[N][100],*ruta="../Workspace/database.csv";
      int ids[N];
      if (leerRegistros(ruta,nombres,ids)==-1){
            return -1;
      }
      menu(nombres,ids);
      return 0;
}

int leerRegistros(char* ruta,char nombres[N][100],int ids[N]){
    FILE *fichero = fopen(ruta,"r");
    if (fichero==NULL){
        printf("El fichero no ha podido ser abierto");
        fclose(fichero);
        return -1;
    }
    for (int i=0;i<N;i++){
        strcpy(nombres[i],"");
        ids[i]=0;
    }
    char mystring[110];
    int ind = 0;
    while(fgets(mystring,110,fichero)){
         if(mystring[0]=='#'){
             continue;
         }
         if(ind<N){
            strcpy(nombres[ind],strtok(mystring,","));
            ids[ind] = atoi(strtok(NULL,",")) ;
            ind++;
         }
         else{
         break;
         }
    }
    return 1;
}

void menu(char nombres[N][100],int ids[N]){
    char key = ' ';
    while(key!='q'){
       printf("Presiona m para mostrar los registros por pantalla\n");
       printf("Presiona i para introducir un registro\n");
       printf("Presiona e para eliminar un registro\n");
       printf("Presiona g para guardar la base de datos\n");
       printf("Presiona q para cerrar el programa\n");
       scanf(" %c%[^\n]%*c",&key);
       switch(key){
             case 'm':
                    mostrarRegistros(nombres,ids);
                    break;
             case 'i':
                    insertarRegistro(nombres,ids);
                    break;
             case 'e':
                    eliminarRegistro(nombres,ids);
                    break;
             case 'g':
                    guardarRegistros(nombres,ids);
                    break;
             case 'q':
                    break;
             default: puts("la opción elegida no es valida");
       }

    }
}

void mostrarRegistros(char nombres[N][100],int ids[N]){
    printf("  id\t\t nombre \n");
    printf("-------------------------------\n");
    for (int i=0;i<N;i++){
        if(ids[i]>0){
            printf("%d\t\t%s\n",ids[i],nombres[i]);
        }
    }
}



void insertarRegistro(char nombres[N][100],int ids[N]){
      int id;
      char nombre[100];
      printf("Introduce la id: ");
      scanf(" %d",&id);
      printf("\nIntroduce el nombre:");
      scanf(" %99[^\n]%*c",nombre);
      int is_repeated=0,is_full=1;
      for(int i=0;i<N;i++){
           if(ids[i]==id){
               is_repeated=1;
               break;
           }
      }
      if(is_repeated){
          printf("La id ya existe");
      }
      else{
          for(int i=0;i<N;i++){
           if(ids[i]==0){
              ids[i]=id;
              strcpy(nombres[i],nombre);
              is_full=0;
              break;
           }
      }
      if(is_full==1){
          printf("la base datos esta llena");
      }

      }
}

void eliminarRegistro(char nombres[N][100],int ids[N]){
      int id,exists=0;
      printf("Introduce la id: ");
      scanf(" %d",&id);
      for(int i=0;i<N;i++){
           if(ids[i]==id){
              for (int j=i;j<N-1;j++){
                 ids[j]=ids[j+1];
                 strcpy(nombres[j],nombres[j+1]);
              }
              ids[N-1]=0;
              exists=1;
              break;
           }
      }
      if(exists==0){printf("La id no existe");}
}

void guardarRegistros(char nombres[N][100],int ids[N]){
      FILE *fichero = fopen("../Workspace/database_new.csv","w");
      if (fichero==NULL){
            printf("Error al crear el archivo");
      }
      else{
         fprintf(fichero,"#name,id\n");
         for(int i=0;i<N;i++){
            if (ids[i]>0){
               fprintf(fichero,"%s,%d\n",nombres[i],ids[i]);
            }
         }
      }
      fclose(fichero);
}
