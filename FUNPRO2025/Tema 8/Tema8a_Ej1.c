#include <stdio.h>
#include <stdlib.h>


int main(){
     char *ruta = "../Workspace/Lore_ipsum.txt";
     FILE *fichero = fopen(ruta,"r");
     /*char c;
     do{
         c = (char)fgetc(fichero);
         putc(c,stdout);
     }while(c!=EOF);*/
     char *texto = NULL;
     int len = 1;
     char c;
     while((c=(char)fgetc(fichero))!=EOF){
         len ++;
         char *temp =(char*)realloc(texto,len*sizeof(char));
         if (temp == NULL){
            free(texto);
            fclose(fichero);
            return -1;
         }
         texto = temp;
         texto[len-2]=c;
     }
     if(texto!=NULL){
          texto[len-1]='\0';
     }
     printf("%s",texto);
     free(texto);
     fclose(fichero);
     return 0;
}
