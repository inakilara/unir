//
// Created by ilara on 9/23/24.
// Tema 1 Fundamentos de programación 2024. Ejemplo 3.
// Ejemplo de código que lee registros de un archivo .csv
// y los muestra por pantalla devidamente formateados.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 10 //Longitud máxima de la base de datos

void readRegister(FILE *dataBase,char *names[n][20],int id[n]){
  //Función que lee los contenidos del archivo y los escribe en los arrays contenedores
    int i=0;
    char myString[100];
    char *output;
    for(int j=0;j<n;j++) { //Vacía los contenedores antes de llenar su contenido.
        strcpy(names[j],"");
        id[j]=0;
    }
    while(fgets(myString,100, dataBase)) { //Se detiene si llega al final el archivo
        if(i<n) { //Si el archivo tiene má entradas que las que permite el programa, se detiene la lectura
            strcpy(names[i], strtok(myString,";"));
            id[i]=strtol(strtok(NULL,";"), &output, 10);
            i++;
                }
        else {
            fclose(dataBase);
            break;
        }
    }
    fclose(dataBase);
}
void printRegisters(char *names[n][20],int id[n]) {
  //Escribe los registros por pantalla con un formato agradable de leer
    printf("  id\t\tnombre\n");
    printf("------------------\n");
    for(int i=0;i<n;i++) {
        if(id[i]>0){printf("%4d\t\t%s\n",id[i], names[i]);}
    }
}

int main() {
    FILE *dataBase;
    dataBase=fopen("/home/ilara/UNIR-codes/FUNPRO2025/Tema 1/database.csv","r"); //Abre el archivo
    char *names[n][10];
    int id[n];
    if(dataBase) { //Comprueba que el archivo existe antes de intentar usarlo.
        readRegister(dataBase,names,id);
        printRegisters(names,id);
    } else {printf("%s","Failed to open the database file.");}
    return 0;
}