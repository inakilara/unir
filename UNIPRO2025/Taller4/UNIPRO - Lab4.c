
//Escribe un programa que incluya una función para ordenar una lista de numeros enteros
/*
#include<stdio.h>
#include<stdlib.h>


void leerVector(int**,int*);
void mostrarVector(int*,int);
void ordenarVectorBurbuja(int*,int);
void ordenarVectorInsercion(int*,int);

int main() {
    //int vector[N]={-4,12,4,0,-5,1,5,9,-6,5};
    int *vector=NULL,nmax;
    leerVector(&vector,&nmax);
    printf("Vector sin ordenar:\n");
    mostrarVector(vector,nmax);
    //ordenarVectorBurbuja(vector);
    ordenarVectorInsercion(vector,nmax);
    printf("\nVector ordenado:\n");
    mostrarVector(vector,nmax);
    free(vector);
    return 0;
}


void mostrarVector(int* v,int nmax) {
    printf("(");
    for (int i=0;i<nmax-1;i++) {
        printf("%d,",*(v+i));
    }
    printf("%d)",*(v+nmax-1));
}

void ordenarVectorBurbuja(int* v,int nmax) {
    // Algoritmo de la burbuja
    int vectorAux[10],tieneInversion=1,aux;
    for (int i=0;i<nmax;i++) {
        vectorAux[i]=v[i];
    }
    while(tieneInversion==1) {
        tieneInversion=0;
        for(int i=0;i<nmax;i++) {
            if(vectorAux[nmax-i-1]<vectorAux[nmax-i-2]) { //Comprobar si el par está ordenado
                aux=vectorAux[nmax-i-1];
                vectorAux[nmax-i-1]=vectorAux[nmax-i-2];
                vectorAux[nmax-i-2]=aux;
                tieneInversion=1;
            }
        }
    }
    for (int i=0;i<nmax;i++) {
        v[i]=vectorAux[i];
    }
}


void ordenarVectorInsercion(int* v,int nmax) {
    // Algoritmo de Insercion
    int vectorAux[10],aux;
    for (int i=0;i<nmax;i++) {
        vectorAux[i]=v[i];
    }
    for (int ind=1;ind<nmax;ind++) {
        aux=vectorAux[ind];
        for(int i=0;i<ind;i++) {
            if(vectorAux[i]>aux) {
                for(int j=ind;j>i;j--) {
                    vectorAux[j]=vectorAux[j-1];
                }
                vectorAux[i]=aux;
                break;
            }
        }
    }
    for (int i=0;i<nmax;i++) {
        v[i]=vectorAux[i];
    }
}


void leerVector(int** v,int* nmax) {
    printf("Introduce el numero de elementos a leer:");
    scanf(" %d",nmax);
    *v = (int *)calloc(*nmax,sizeof(int));
    for(int i=0;i<*nmax;i++) {
        printf("\nIntroduce el valor %d:",i);
        scanf("%d",*(v)+i);
    }
}*/
/*Crea un programa que lea la primera linea de un archivo de texto y la muestre por pantalla

#include <stdio.h>



int main() {
    char miCadena[100];
    FILE *archivo = fopen("database.csv","r");
    fgets(miCadena,100,archivo);
    printf("%s",miCadena);

}
*/

//Crea un programa que te permita interactuar con un fichero de texto con campos delimitados por comas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

void menu(char[N][100],int[N]);
int leerRegistros(char*,char[N][100],int[N]);
void mostrarRegistros(char[N][100],int[N]);
void insertarRegistro(char[N][100],int[N]);
void eliminarRegistro(char[N][100],int[N]);
void guardarRegistros(char[N][100],int[N]);

int main() {
    char nombres[N][100],*path="../Workspace/database.csv";
    int ids[N];
    if (leerRegistros(path,nombres,ids)==-1) {
        return -1;
    }
    menu(nombres,ids);

    return 0;
}

int leerRegistros(char* path,char strings[N][100],int nums[N]) {
    FILE *dataBase = fopen(path,"r");
    if(dataBase==NULL) {
        printf("El fichero no se ha podido abrir");
        fclose(dataBase);
        return -1;
    }
    char myString[100];
    int ind=0;
    for (int i=0;i<N;i++) {
        strcpy(strings[i],"");
        nums[i]=0;
    }
    while(fgets(myString,100,dataBase)) {
        if (myString[0]=='#') {
            continue;
        }
        if(ind<N) {
            strcpy(strings[ind],strtok(myString,","));
            nums[ind]=atoi(strtok(NULL,","));
            ind++;
        }
        else {
            break;
        }
    }
    return 1;
}

void menu(char nombres[N][100],int ids[N]) {
    char key=' ';
    while(key!='q') {
        printf("Presiona d para mostrar los registros en la base de datos.\n");
        printf("Presiona i para introducir un nuevo registro.\n");
        printf("Presiona e para borrar un registro.\n");
        printf("Presiona s para guardar la base de datos.\n");
        printf("Presiona q para finalizar el programa.\n");
        scanf(" %c%*[^\n]%*c",&key);
        switch(key) {
            case 'd':
                mostrarRegistros(nombres,ids);
                break;
            case 'i':
                insertarRegistro(nombres,ids);
                break;
            case 'e':
                eliminarRegistro(nombres,ids);
                break;
            case 's':
                guardarRegistros(nombres,ids);
                break;
            case 'q':
                break;
            default: puts("Lo opcion introducida no es valida");
        }
    }

}


void mostrarRegistros(char strings[N][100],int nums[N]) {
    printf("  id\t\t nombre\n");
    printf("----------------------\n");
    for (int i=0;i<N;i++) {
        if(nums[i]>0){printf("%d\t\t%s\n",nums[i],strings[i]);}
    }


}


void insertarRegistro(char nombres[N][100],int ids[N]) {
    int id;
    char nombre[100];
    printf("Introduce el nombre:");
    scanf(" %99[^\n]%*c",nombre);
    printf("\nIntroduce la id:");
    scanf(" %d",&id);
    int is_repeated=0,is_full=1;
    for(int i=0;i<N;i++) {
        if(ids[i]==id) {
            is_repeated=1;
            break;
        }
    }
    if (is_repeated==1) {
        printf("La id ya existe");
    }
    else {
        for(int i=0;i<N;i++) {
            if(ids[i]==0) {
                ids[i]=id;
                strcpy(nombres[i],nombre);
                is_full=0;
                break;
            }
        }
    }
    if (is_full==1) {
        printf("La base de datos está llena");
    }

}

void eliminarRegistro(char nombres[N][100],int ids[N]) {
    int id;
    printf("\nIntroduce la id:");
    scanf(" %d",&id);
    int exists=0;
    for(int i=0;i<N;i++) {
        if(ids[i]==id) {
            exists=1;
            for (int j=i;j<N-1;j++) {
                ids[j]=ids[j+1];
                strcpy(nombres[j],nombres[j+1]);
            }
            ids[N-1]=0;
            break;
        }
    }
    if(exists==0){printf("La id no existe");}
}

void guardarRegistros(char nombres[N][100],int ids[N]) {
    FILE *archivo = fopen("database_new.csv","w");
    if (archivo==NULL) {
        printf("no se ha podido crear el archivo");
    }
    else {
        for (int i=0;i<N;i++) {
            if(ids[i]>0)(fprintf(archivo,"%d,%s\n",ids[i],nombres[i]));
        }
        fclose(archivo);

    }
}