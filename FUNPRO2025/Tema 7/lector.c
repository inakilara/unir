//
// Created by Iñaki Lara on .
//
// Crea un programa capaz de leer una cantidad arbitraria de caracteres por teclado y que convierta la entrada a número real o entero, detectando errores de conversión.

#include<stdio.h>
#include<stdlib.h>  // Podeis revisar aqui la documentación de strtol y strtod
#include<string.h> //
#include<ctype.h>  //

char *leerCadena();
int leerEntero(int*);  //El resultado indica si ha error de lectura o no
int leerReal(double *);
int leerCaracter(char*);

int main() {
    printf("Introduce la frase a leer:\n");
    char *miCadena=leerCadena();
    printf("La frase leida es:\n %s.",miCadena);
    free(miCadena);
    printf("\n Introduce un numero real:\n");
    int n,error;
    double x;
    error=leerReal(&x);
    if (error==1){
    printf("El numero real es: %lf",x);
    }
    else{
        printf("Error de lectura");
    }
    printf("\n Introduce un numero entero:\n");
    error=leerEntero(&n);
    if (error==1){
    printf("El numero entero es: %d",n);
    }
    else{
        printf("Error de lectura");
    }
    printf("\n Introduce un caracter:\n");
    char c;
    error=leerCaracter(&c);
    if (error==1){
    printf("El caracter es: %c",c);
    }
    else{
        printf("Error de lectura");
    }
    return 0;
}

char *leerCadena() {
    char *cadena=(char *)calloc(1,sizeof(char)),c;
    int len=0;
    do{
        len++;
        c=getchar(); //Lee el siguiente caracter y avanza el cursor
        if(c!='\n') { //Si es un salto de linea, termina
            cadena=(char *)realloc(cadena,len*sizeof(char)); //Agranda la cadena
            *(cadena+len-1)=c;                                       //Coloca el nuevo caracter
        }
    }while(c!='\n');
    *(cadena+len)='\0'; //Coloca el caracter nulo al final
   return cadena;
}

int leerEntero(int* valor) {
    int error=1;
    errno=0;      //declared in <errno.h>  si hay problemas numericos cambia de valor
    char *miCadena=leerCadena(),*pEnd;
    *valor=strtol(miCadena,&pEnd,10);       // convierte miCadena, almacena el final de la conversion en &pEnd , hace la conversion en base 10
    if(errno!=0||miCadena==pEnd||!(isspace(*pEnd)||*pEnd=='\n'||*pEnd=='\0')){error=0;}   //si hay problemas numéricos, o no se ha convertido nada o tras la conversión lo que hay no es ni un espacio ni un salto de linea o el nulo, da error.
    free(miCadena);                               // Libera miCadena ¡Cuidado con los memory-leaks!
    return error;                                 // si no hay error vuelve 1
}
int leerReal(double *valor){
    int error=1;
    errno=0;
    char *miCadena=leerCadena(),*pEnd;
    *valor=strtod(miCadena,&pEnd);
    if(errno!=0||miCadena==pEnd||!(isspace(*pEnd)||*pEnd=='\n'||*pEnd=='\0')){error=0;}
    free(miCadena);
    return error;
}

int leerCaracter(char* c) {
    int error=1;
    char *miCadena=leerCadena();
    int cursor=0;
    for (int i=0;i<strlen(miCadena);i++) {     //Recorremos la cadena de entrada moviendo el cursor hasta encontrar el primer caracter que no sea un espacio
        cursor++;
        if(isspace(*(miCadena+i))){continue;}
        *c=*(miCadena+i);
        break;
    }
    for (int i=cursor;i<strlen(miCadena);i++) {   //Comprobamos lo que hay despues de leer el primer caracter, si entre dicho caracter y el salto de linea final hay algo que no sea un espacio, damos error.
        if(isspace(*(miCadena+i))){continue;}
        if(*(miCadena+i)=='\n'){break;}
        error=0;
        break;
    }
    if(!isalpha(*c)){error=0;}                 // Si no es un caracter alfabético devuelve error.
    free(miCadena);
    return error;
}