//
//
#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int main() {
    char myChar[101];
    printf("Introduzca una cadena de como mucho 100 caracteres:");
    fgets(myChar,100,stdin);
    int spaces=0;
    for (int i=0;i<strlen(myChar);i++) {
        if(isspace(myChar[i])) {   // if(myChar[i]==' '){spaces++;}
            spaces++;
        }
        if(myChar[i]=='a'||myChar[i]=='A'){myChar[i]='1';}
        else if(myChar[i]=='e'||myChar[i]=='E'){myChar[i]='2';}
        else if(myChar[i]=='i'||myChar[i]=='I'){myChar[i]='3';}
        else if(myChar[i]=='o'||myChar[i]=='O'){myChar[i]='4';}
        else if(myChar[i]=='u'||myChar[i]=='U'){myChar[i]='5';}
    }
    printf("\nLa cadena de texto tiene %d espacios: %s .",spaces-1,myChar); //Ojo porque isspace considera el salto de linea y el tabulador un espacio
    return 0;
}
