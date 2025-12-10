//
// Created by Iñaki Lara
//
// Crea un programa que te permita interactuar con un fichero de binario
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[20];
    int id;
}Templeado ;


void readDatabase(FILE *dataBase);
void readRegister(FILE *dataBase);
void addRegister(FILE *dataBase);
void eraseRegister(FILE *dataBase);
// Utilidades
void clearSTDIN();
char* leerCadena();
int leerEntero(int*);  //El resultado indica si ha error de lectura o no
int longitudFichero(FILE *dataBase);

int main() {
    //Función principal
    int key;
    FILE *dataBase =fopen("../databaseBinary.txt","r"); //CLion ejecuta desde dentro de cmake-build-debug, tenemos que decirle que busque los archivos en la carpeta principal
    if(dataBase!= NULL) { //Comprueba que el archivo existe antes de intentar usarlo.
    } else {printf("%s","No ha sido posible leer el fichero.");return -1;}
    while (key!=0) { //Selector de operaciones
        printf("Presione 1 para mostrar el registro completo.\n");
        printf("Presione 2 para mostrar un unico registro.\n");
        printf("Presione 3 para borrar un registro.\n");
        printf("Presione 4 para crear un registro.\n");
        printf("Presione 0 para terminar el programa.\n");
        scanf(" %d%*[^\n]%*c",&key);
        switch(key) {
            case 1: readDatabase(dataBase);
            break;
            case 2:readRegister(dataBase);
            break;
            case 3:eraseRegister(dataBase);
            break;
            case 4: addRegister(dataBase);
            break;
            case 0:
                break;
            default: puts("La opción no existe");
        }
        printf("\n\n\n");
    }
    return 0;
}

void readDatabase(FILE *dataBase){
    const int len = longitudFichero(dataBase);
    Templeado *lista=malloc(sizeof(Templeado)*len);
    rewind(dataBase);
    fread(lista,sizeof(Templeado),len,dataBase);
    //Escribe los registros por pantalla con un formato agradable de leer
    printf("  id\t\tnombre\n");
    printf("------------------\n");
    for(int i=0;i<len;i++) {
        if((lista+i)->id>0){printf("%4d\t\t%s\n",(lista+i)->id, (lista+i)->nombre);}
    }
    rewind(dataBase);
    free(lista);
}

void readRegister(FILE *dataBase){
    Templeado empleado;
    int error=0,id;
    printf("Que posicion del registro quieres leer: ?");
    do {
        error=leerEntero(&id);
        if(error!=1){printf("Valor introducido invalido.");}
    }while(error!=1);
    fseek(dataBase,sizeof(Templeado)*(id-1),SEEK_SET);
    if(fread(&empleado,sizeof(Templeado),1,dataBase)!=1){printf("Ha habido un problema con la lectura.");}
    //Escribe los registros por pantalla con un formato agradable de leer
    printf("  id\t\tnombre\n");
    printf("------------------\n");
    printf("%4d\t\t%s\n",empleado.id, empleado.nombre);
    rewind(dataBase);
}

void addRegister(FILE *dataBase) {
    const int len = longitudFichero(dataBase);
    Templeado lista[len];
    rewind(dataBase);
    int n=fread(lista,sizeof(Templeado),len,dataBase);
    if(n!=len){printf("Ha habido un error al leer el fichero\n");}
    fclose(dataBase);
    Templeado *ptr=(Templeado*)malloc((len+1)*sizeof(Templeado));
    for(int i=0;i<len;i++) {
        *(ptr+i)=lista[i];
    }
    printf("Introduce la id del nuevo registro:");
    leerEntero(&((ptr+len)->id));
    printf("Introduce el nombre\n");
    strcpy((ptr+len)->nombre, leerCadena());
    FILE *bFile=fopen("../databaseBinary.txt","w");
    if (bFile!=NULL) {
        if(fwrite(ptr,sizeof(Templeado),len+1,bFile)<len+1) {
            printf("Ha habido un error en el proceso de escritura");
        }
    }
    else{printf("No se ha podido abrir el archivo.");}
    free(ptr);
    fclose(bFile);
    dataBase =fopen("../databaseBinary.txt","r");
}

void eraseRegister(FILE *dataBase) {
    const int len = longitudFichero(dataBase);
    printf("->%d",len);
    Templeado lista[len];
    rewind(dataBase);
    int id,n=fread(lista,sizeof(Templeado),len,dataBase);
    if(n!=len){printf("Ha habido un error al leer el fichero\n");}
    fclose(dataBase);
    Templeado *ptr=(Templeado*)malloc((len-1)*sizeof(Templeado));
    printf("Introduce la id del registro a borrar:");
    leerEntero(&id);
    for(int i=0;i<len;i++) {
        if(lista[i].id!=id){*(ptr+i)=lista[i];}
        else{i--;}
    }
    FILE *bFile=fopen("../databaseBinary.txt","w");
    if (bFile!=NULL) {
        if(fwrite(ptr,sizeof(Templeado),len-1,bFile)<len-1) {
            printf("Ha habido un error en el proceso de escritura");
        }
    }
    else{printf("No se ha podido abrir el archivo.");}
    free(ptr);
    fclose(bFile);
    dataBase =fopen("../databaseBinary.txt","r");
}



char *leerCadena() {
    char *cadena=(char *)calloc(1,sizeof(char)),c;
    int len=0;
    do{
        len++;
        c=getchar();
        if(c!='\n') {
            cadena=(char *)realloc(cadena,len*sizeof(char));
            *(cadena+len-1)=c;
        }
        else if(len==1){c=' ';len--;continue;}//Descartar un salto de linea si es lo primero que se encuentra
    }while(c!='\n');
    return cadena;
}

int leerEntero(int* valor) {
    int error=1;
    char *miCadena=leerCadena(),*pEnd;
    *valor=strtol(miCadena,&pEnd,10);
    if(miCadena==pEnd){error=0;}
    free(miCadena);
    return error;
}

int longitudFichero(FILE *dataBase) {
    fseek(dataBase, 0L, SEEK_SET);
    int len=0;
    while(feof(dataBase)!=0) {
        fseek(dataBase, 1L, SEEK_CUR);
        len++;
    }
    rewind(dataBase);
    //return ftell(dataBase)/sizeof(Templeado);
    return len;
}
