//

//
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char mystring[51],inverted_string[51];
    printf("Introduzca una cadena de como mucho 50 caracteres:");
    fgets(mystring,50,stdin);
    for (int i=0;i<strlen(mystring);i++) {
        inverted_string[i]= mystring[strlen(mystring)-i-2];
    }
    mystring[strlen(mystring)-1]='\0';
    inverted_string[strlen(inverted_string)]='\0';// hasta aqui inverted_string solo contiene los caracteres de mystring
    FILE *archivo=fopen("../cadenas.txt","w");
    fprintf(archivo,"%s\n%s",mystring,inverted_string);
    fclose(archivo);
    return 0;
}