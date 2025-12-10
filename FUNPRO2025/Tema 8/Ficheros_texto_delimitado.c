//
// Created by Iñaki Lara
//
// Crea un programa que te permita interactuar con un fichero de texto con campos delimitados
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 20 //Lonitud máxima de la base de datos


void readRegister(FILE *dataBase,char names[n][20],int id[n]);
void saveRegisters(char names[n][20],int id[n]);
void printRegisters(char names[n][20],int id[n]);
void addRegister(char names[n][20],int id[n]);
void eraseRegister(char names[n][20],int id[n]);
// Utilidades
char* leerCadena();
int leerEntero(int*);  //El resultado indica si ha error de lectura o no

int main() {
    //Función principal
    char key=' ';
    char names[n][20];
    int id[n];
    FILE *dataBase =fopen("../database.csv","r"); //CLion ejecuta desde dentro de cmake-build-debug, tenemos que decirle que busque los archivos en la carpeta principal
    if(dataBase!= NULL) { //Comprueba que el archivo existe antes de intentar usarlo.
        readRegister(dataBase,names,id);
    } else {printf("%s","No ha sido posible leer el fichero.");}
    while (key!='q') { //Selector de operaciones
        printf("Presione d para mostrar los registros almacenados.\n");
        printf("Presione i para introducir un nuevo registro.\n");
        printf("Presione e para borrar un registro.\n");
        printf("Presione s para guardar los registros.\n");;
        printf("Presione q para terminar el programa.\n");
        scanf(" %c%*[^\n]%*c",&key);
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
    }
    return 0;
}

void readRegister(FILE *dataBase,char names[n][20],int id[n]){
    //Función que lee los contenidos del archivo y los escribe en los arrays contenedores
    int i=0;
    char myString[100];
    for(int j=0;j<n;j++) { //Vacía los contenedores antes de llenar su contenido.
        strcpy(names[j],"");
        id[j]=0;
    }
    // Solución basada en strtok, que fracciona la cadena en base a un delimitador
    while(fgets(myString,100, dataBase)) { //Se detiene si llega al final el archivo
        if(myString[0]=='#'){continue;}//Saltarse la primera linea, solo almacena el nombre de cada campo
        if(i<n) { //Si el archivo tiene más entradas que las que permite el programa, se detiene la lectura
            strcpy(names[i], strtok(myString,","));    // Apunto strtok a la cadena e indico el delimitador (el resultado es la parte que va antes del primer delimitador)
            id[i]=atoi(strtok(NULL, ",")); //Sucesivas llamadas a strtok retoman el fraccionamiento donde lo dejó la llamada anterior
            i++;
        }
        else {
            fclose(dataBase);
            break;
        }
    }
    /*  //Alternativa con scanf
    erro=2;
    while(error==2){error=fscanf(dataBase,"%d,%19[^\n]%*\n",&id[i],names[i]);i++;}
    fclose(dataBase);
  */
}

void saveRegisters(char names[n][20],int id[n]) {
    //Almacena los datos en un fichero
    FILE *dataBase=fopen("../database_new.csv","w");
    if(dataBase!=NULL) {
        for(int i=0;i<n;i++){
            if(id[i]>0){fprintf(dataBase, "%d,%s\n",id[i],names[i]);}
            }
        fclose(dataBase);
    } else {printf("%s","No ha sido posible abrir el archivo.");}
}

void printRegisters(char names[n][20],int id[n]) {
    //Escribe los registros por pantalla con un formato agradable de leer
    printf("  id\t\tnombre\n");
    printf("------------------\n");
    for(int i=0;i<n;i++) {
        if(id[i]>0){printf("%4d\t\t%s\n",id[i], names[i]);}
    }
}

void addRegister(char names[n][20],int id[n]) {
    //Añade un registro a los contenedores de datos
    int error=-1;
    int idVal=0;
    char nameString[20];
    while(error<0) { //Mantiene la interfaz activa hasta que la acción se termina correctamente.
        printf("Introduce la Id del registro\n");
        error=leerEntero(&idVal);
        if(error!=1){printf("Entrada invalida;");continue;}
        error=-1;
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
                        strcpy(names[i], leerCadena());
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

void eraseRegister(char names[n][20],int id[n]) {
    //Borra un registro
    int idVal=0;
    int error=-1;
    while(error<0) { //Mantiene la interfaz activa hasta que la acción se termina correctamente.
        printf("Introduce la Id del registro a borrar\n");
        error=leerEntero(&idVal);
        if(error==0){printf("Opción invalida introdúcela de nuevo.\n");}
        if(idVal>0) {
            for (int i=0;i<n;i++) {
                if(id[i]==idVal) {
                    for (int j=i+1;j<n;j++) { //Elimina las entradas vacias en medio de los contenedores
                        id[j-1]=id[j];
                        strcpy(names[j-1], names[j]);
                    }
                    error=0;
                    id[n-1]=0; //Colocas una entrada vacía al final
                    break;
                }
            }
            if(error<0){printf("La id no existe en el registro\n");} // Se incluyen diferentes ramificaciones
        }                                                                  // para identificar errores
        else{printf("Id invalida, introdúcela de nuevo.\n");}        // en la entrada de datos
    }
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
