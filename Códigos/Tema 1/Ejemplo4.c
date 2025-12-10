//
// Created by ilara on 9/24/24.
// Tema 1 Fundamentos de programación 2024. Ejemplo 4.
// Ejemplo de código que manipula una base de datos con una interfaz interactiva.
//

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
            //id[i]=atoi(strtok(NULL, ";"));
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

void saveRegisters(char *names[n][20],int id[n]) {
    //Almacena los datos en un fichero
    FILE *dataBase;
    dataBase=fopen("/home/ilara/UNIR-codes/Códigos/Tema 1/database2.csv","r");
    if(dataBase) {
        for(int i=0;i<n;i++){
            if(id[i]!=0) {fprintf(dataBase, "%d;%s",id[i],names[i][20]);}
            }
        fclose(dataBase);
    } else {printf("%s","Failed to open the database file.");}
}

void printRegisters(char *names[n][20],int id[n]) {
    //Escribe los registros por pantalla con un formato agradable de leer
    printf("  id\t\tnombre\n");
    printf("------------------\n");
    for(int i=0;i<n;i++) {
        if(id[i]>0){printf("%4d\t\t%s\n",id[i], names[i]);}
    }
}

void addRegister(char *names[n][20],int id[n]) {
    //Añade un registro a los contenedores de datos
    int error=-1;
    int idVal=0;
    char *nameString[10];
    while(error<0) { //Mantiene la interfaz activa hasta que la acción se termina correctamente.
        printf("Introduce la Id del registro\n");
        scanf("%d",&idVal);
        if(idVal>0) {
            int isRepeated=0;
            for (int i=0;i<n;i++) {
                if(id[i]==idVal) {isRepeated=1;}
            }
            if(isRepeated!=1) {
                for (int i=0;i<n;i++) {
                    if(id[i]==0) {
                        id[i]=idVal;
                        printf("Introduce el nombre\n");
                        scanf("%s",nameString);
                        strcpy(names[i], nameString);
                        error=0;
                        break;
                    }
                }
                if(error!=0){printf("El registro está lleno\n");return;} // Se incluyen diferentes ramificaciones
            }else{printf("La Id ya existe en el registro.\n");}          // para identificar errores
        }                                                                      // en la entrada de datos
        else{printf("Id inválida, introdúcela de nuevo.\n");}
    }

    printf("  id\t\tnombre\n");  // Muestra el registro por pantalla para verificar la acción
    printf("------------------\n");
    for(int i=0;i<n;i++) {
        if(id[i]>0){printf("%4d\t\t%s\n",id[i], names[i]);}
    }
}

void eraseRegister(char *names[n][20],int id[n]) {
    //Borra un registro
    int idVal=0;
    int error=-1;
    while(error<0) { //Mantiene la interfaz activa hasta que la acción se termina correctamente.
        printf("Introduce la Id del registro a borrar\n");
        scanf("%d",&idVal);
        if(idVal>0) {
            for (int i=0;i<n;i++) {
                if(id[i]==idVal) {
                    for (int j=i+1;j<n;j++) { //Elimina las entradas vacias en medio de los contenedores
                        id[j-1]=id[j];
                        strcpy(names[j-1], names[j]);
                    }
                    error=0;
                    break;
                }
            }
            if(error<0){printf("La id no existe en el registro\n");} // Se incluyen diferentes ramificaciones
        }                                                                  // para identificar errores
        else{printf("Id inválida, introdúcela de nuevo.\n");}        // en la entrada de datos
    }
}


int main() {
    //Función principal
    char *stdinString[20];
    char key=' ';
    char *names[n][10];
    int id[n];
    FILE *dataBase;
    dataBase=fopen("/home/ilara/UNIR-codes/Códigos/Tema 1/database2.csv","r");
    if(dataBase) { //Comprueba que el archivo existe antes de intentar usarlo.
        readRegister(dataBase,names,id);
    } else {printf("%s","Failed to open the database file.");}
    while (key!='q') { //Selector de operaciones
        printf("Presione d para mostrar los registros almacenados.\n");
        printf("Presione i para introducir un nuevo registro.\n");
        printf("Presione e para borrar un registro.\n");
        printf("Presione s para guardar los registros.\n");;
        printf("Presione q para terminar el programa.\n");
        key=getchar();
        switch(key) {
            case 'd': printRegisters(names,id);
            break;
            case 'i':addRegister(names,id);
            break;
            case 'e':eraseRegister(names,id);
            break;
            case 's': saveRegisters(names,id);
            break;
            case 'q':
            break;
            default: puts("La opción no existe");
        }
        printf("\n\n\n");
        getchar();

    }
    return 0;
}