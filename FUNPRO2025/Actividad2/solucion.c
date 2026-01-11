//
// Created by Iñaki Lara
//
/* Este programa soluciona los enunciados de la actividad 2
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI (2.0 * asin(1.0))

//Definiciones de tipos y constantes globales
typedef struct {
    char nombre[21];
    char estudios[21];
    double sueldo;
}puesto;
typedef struct {
    char nombre[21];
    char apellidos[21];
    puesto puestoEmpleado;
    int codigoEmpleado;
}empleado;

typedef struct {
    double x;
    double y;
}cCartesiana;
typedef struct {
    double r;
    double theta;
}cPolar;


//Funciones con utilidades varias
char* leerCadena();
int leerEntero(int*);  //El resultado indica si ha error de lectura o no
int leerReal(double *);
int leer2Reales(double *,double *);
int leerCaracter(char*);
//Cuerpo de los ejercicios
int ejercicio1(); //Tipo int para indicar al programa principal si la ejecución fue correcta o no (1 o 0)
int ejercicio2();
int ejercicio3();
int ejercicio4();

//Operaciones con matrices para el ejercicio 1
void leerMatriz(double[2][2]);
void mostrarMatriz(double[2][2]);
void sumarMatrices(double[2][2],double[2][2],double[2][2]);
void transponerMatrices(double[2][2],double[2][2]);

//Operaciones para ejercicio 2
empleado leerEmplado();
puesto leerPuesto();
void mostrarEmpleado(empleado);
void mostrarPuesto(puesto);

//Operaciones para ejercicio 4
cCartesiana polarAcartesiana(cPolar);
cPolar cartesianaApolar(cCartesiana);

int main() {
    //La función principal escoge opción y ejecuta la función correspondiente a cada solución
    int opcion=-1;
    while(opcion!=0) { //Bucle que mantiene el menu funcionando hasta que se escoja finalizar el programa.
        printf("Introduce el numero de ejercicio a ejecutar o 0 para terminar.\n");
        int error=leerEntero(&opcion);
        if(opcion>4||opcion<0||error==0){opcion=-1;printf("La opcion introducida no es valida\n");continue;} //Si la lectura no es correcta, vuelve a reiniciar el menu.
        switch (opcion) {
            case 0: {
                printf("\n\n Programa finalizado.");
                return 0;
            }
            case 1: {
                error=ejercicio1();
                break;
            }
            case 2: {
                error=ejercicio2();
                break;
            }
            case 3: {
                error=ejercicio3();
                break;
            }
            case 4: {
                error=ejercicio4();
                break;
            }
            default:
                error=0;
        }
        if(error==0){printf("Ha habido un error en la ejecucion del ejercicio.");}
        }
    return 1;
    }


char *leerCadena() {
    char c;
    char *cadena = NULL;
    int len=1;
    do{
        c=getchar();
        if(c!='\n') {
            len++;
            char *ptr =(char *)realloc(cadena,len*sizeof(char));
            if (ptr==NULL) {
                free(cadena);
                free(ptr);
                return NULL;
            }
            else {
                cadena =ptr;
            }
            *(cadena+len-2)=c;
        }
        else if(len==1){c=' ';continue;}//Descartar un salto de línea si es lo primero que se encuentra
    }while(c!='\n');
    if (cadena!=NULL) {
        *(cadena+len-1)='\0';
    }
    return cadena;
}

int leerEntero(int* valor) {
    int error=1;
    errno=0;
    char *miCadena=leerCadena(),*pEnd;
    *valor=strtol(miCadena,&pEnd,10);
    if(errno!=0||miCadena==pEnd){error=0;}
    free(miCadena);
    return error;
}
int leerReal(double *valor){
    int error=1;
    errno=0;
    char *miCadena=leerCadena(),*pEnd;
    *valor=strtod(miCadena,&pEnd);
    if(errno!=0||miCadena==pEnd){error=0;}
    free(miCadena);
    return error;
}

int leer2Reales(double *valor1,double *valor2){
    int error=1;
    errno=0;
    char *miCadena=leerCadena(),*pEnd,*pEnd2;
    *valor1=strtod(miCadena,&pEnd);
    if(errno!=0||miCadena==pEnd){error=0;}
    *valor2=strtod(pEnd,&pEnd2);
    if(errno!=0||pEnd==pEnd2){error=0;}
    free(miCadena);
    return error;
}

int leerCaracter(char* c) {
    int error=1;
    char *miCadena=leerCadena();
    int cursor=0;
    for (int i=0;i<strlen(miCadena);i++) {
        cursor++;
        if(isspace(*(miCadena+i))){continue;}
        *c=*(miCadena+i);
        break;
    }
    for (int i=cursor;i<strlen(miCadena);i++) {
        if(isspace(*(miCadena+i))){continue;}
        if(*(miCadena+i)=='\n'){break;}
        error=0;
        break;
    }
    if(!isalpha(*c)){error=0;}
    free(miCadena);
    return error;
}

void leerMatriz(double M[2][2]) {
    for(int i=0;i<2;i++) {
            printf("Introduce los elementos de la fila %d separados por espacios:",i+1);
            while(leer2Reales(&M[i][0],&M[i][1])!=1){printf("Valor invalido\n");printf("Introduce los elementos de la fila %d separados por espacios:",i+1);}
    }
}
void mostrarMatriz(double M[2][2]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            printf("%lf\t",M[i][j]);
        }
        printf("\n");
    }
}
void sumarMatrices(double A[2][2],double B[2][2],double M[2][2]){
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            M[i][j]=A[i][j]+B[i][j];
        }
    }
}
void transponerMatrices(double A[2][2],double M[2][2]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            M[i][j]=A[j][i];
        }
    }
}

int ejercicio1() {
    int error,opcion;
    double M1[2][2],M2[2][2],M3[2][2];
    printf("1)----- Calculadora de matrices ------\n\n");
    do {
        printf("Selecciona la operacion a realizar\n\t 1) Suma\n\t 2) Transposicion.");
        error=leerEntero(&opcion);
        if(opcion>2||opcion<1||error==0){printf("La opcion introducida no es valida");} //Si la lectura no es correcta, vuelve a reiniciar el menu.
    }while(error==0);
    printf("Leyendo matriz A\n");
    leerMatriz(M1);
    printf("\nLeyendo matriz B\n");
    leerMatriz(M2);
    switch (opcion) {
        case 1: {
            printf("Matriz A:\n");
            mostrarMatriz(M1);
            printf("Matriz B:\n");
            mostrarMatriz(M2);
            printf("Resultado de la suma.\n");
            sumarMatrices(M1,M2,M3);
            mostrarMatriz(M3);
            break;
        }
        case 2: {
            printf("Matriz A:\n");
            mostrarMatriz(M1);
            printf("Matriz B:\n");
            mostrarMatriz(M2);
            printf("Transpuesta de A.\n");
            transponerMatrices(M1,M3);
            mostrarMatriz(M3);
            printf("Transpuesta de B.\n");
            transponerMatrices(M2,M3);
            mostrarMatriz(M3);
            break;
        }
        default:
            return 0;
    }
    return 1;
}
int ejercicio2(){
    printf("\n\n2)----- Gestor de empleados ------\n\n");
    //Interfaz con el usuario
    empleado empleado1=leerEmplado();
    mostrarEmpleado(empleado1);
    return 1;
}
int ejercicio3(){
    printf("\n\n3)----- Ordenacion de palabras ------\n\n");
    char palabras[5][21],opcion;
    char palabrasMinusculas[5][21];
    int indices[5]={-1,-1,-1,-1,-1},auxI=0;
    for (int i=0;i<5;i++) {
        printf("Introduzca la siguiente palabra:");
        scanf("%20[^\n]%*c",palabras[i]);
        for (int j=0;j<strlen(palabras[i]);j++) {
            palabrasMinusculas[i][j]=tolower(palabras[i][j]);
        }
    }
    for (int i=0;i<5;i++) { //Llena el vector índices con los índices ordenados (por selección) de la lista de palabras
        for (int j=0;j<5;j++) {
            if(!(j==indices[0]||j==indices[1]||j==indices[2]||j==indices[3]||j==indices[4])){auxI=j;break;}  //Busco el siguiente índice sin colocar y lo guardo en auxI para comparar esa palabra
        }
        for (int j=0;j<5;j++) {
            if(j==indices[0]||j==indices[1]||j==indices[2]||j==indices[3]||j==indices[4]){continue;} //No comparo las palabras correspondientes a indices ya ordenados
            if(strcmp(palabrasMinusculas[j],palabrasMinusculas[auxI])<0) {  // Comparo la palabra de auxI con las demas que no estan colocadas
             auxI=j;  // si es menor lo guardo
            }
        }
        indices[i]=auxI; //coloco un nuevo índice en la posicion que le toca
    }
    printf("Quieres ordenar la lista en orden alfabetico ascendente(a) o descendente(d)?: ");
    while((leerCaracter(&opcion)!=1)||(opcion!='a'&&opcion!='d')) {
        printf("\nOpcion invalida.\nVuelve a introducir la opcion:");
    }
    printf("\nLa lista ordenada de palabras es:\n");
    if (opcion=='a') {
        for (int i=0;i<5;i++) {
            printf("%s ",palabras[indices[i]]);
        }
    }
    else if(opcion=='d'){
        for (int i=0;i<5;i++) {
        printf("%s ",palabras[indices[4-i]]);
        }
    }
    printf("\n");
    return 1;
}


int ejercicio4(){
    printf("\n\n3)----- Cambio de coordenadas ------\n\n");
    char opcion;
    printf("Escoge cambiar a (c)cartesianas o (p)polares:");
    while((leerCaracter(&opcion)!=1)||(opcion!='c'&&opcion!='p')) {
        printf("\nOpcion invalida.\nVuelve a introducir la opcion:");
    }
    if (opcion=='c') {
        cPolar coordenadasP;
        printf("Has escogido transformar coordenadas polares a cartesianas.Introduzca el valor de r:\n");
        while(leerReal(&coordenadasP.r)!=1||coordenadasP.r<0) {
            printf("\nOpcion invalida, recuerda que r tiene que ser positivo.\nIntroduzca el valor de r:");
        }
        printf("Introduzca el valor de theta:\n");
        while(leerReal(&coordenadasP.theta)!=1||coordenadasP.theta>2*PI||coordenadasP.theta<0) {
            printf("\nOpcion invalida, recuerda que theta tine que estar entre 0 y 2pi.\nIntroduzca el valor de theta:");
        }
        cCartesiana coordenadasC=polarAcartesiana(coordenadasP);
        printf("Las coordenadas polares: r=%lf theta=%lf \n son en cartesianas: x=%lf y=%lf\n",coordenadasP.r,coordenadasP.theta,coordenadasC.x,coordenadasC.y);
    }
    else if(opcion=='p'){
        cCartesiana coordenadasC;
        printf("Has escogido transformar coordenadas cartesianas a polares .Introduzca el valor de x:\n");
        while(leerReal(&coordenadasC.x)!=1) {
            printf("\nOpcion invalida.\nIntroduzca el valor de x:");
        }
        printf("Introduzca el valor de y:\n");
        while(leerReal(&coordenadasC.y)!=1) {
            printf("\nOpcion invalida\nIntroduzca el valor de y:");
        }
        cPolar  coordenadasP=cartesianaApolar(coordenadasC);
        printf("Las coordenadas cartesianas: x=%lf y=%lf \n son en polares: r=%lf theta=%lf\n",coordenadasC.x,coordenadasC.y,coordenadasP.r,coordenadasP.theta);

    }
    printf("\n");
    return 1;
}

empleado leerEmplado() {
    empleado resultado;
    printf("Introduzca el nombre del empleado:");
    scanf("%20[^\n]%*c",resultado.nombre);
    printf("Introduzca los apellidos del empleado:");
    scanf("%20[^\n]%*c",resultado.apellidos);
    printf("Introduzca el codigo de empleado:");
    while(leerEntero(&resultado.codigoEmpleado)!=1) {
        printf("Entrada erronea\n");
        printf("Introduzca el codigo de empleado:");
    };
    resultado.puestoEmpleado=leerPuesto();
    return resultado;
}
puesto leerPuesto() {
    puesto resultado;
    printf("Introduzca el nombre del puesto:");
    scanf("%20[^\n]%*c",resultado.nombre);;
    printf("Introduzca el nombre de los estudios requeridos para el puesto:");
    scanf("%20[^\n]%*c",resultado.estudios);
    printf("Introduzca el sueldo asociado:");
    while(leerReal(&resultado.sueldo)!=1) {
        printf("Entrada erronea\n");
        printf("Introduzca el sueldo asociado:");
    };
    return resultado;
}
void mostrarEmpleado(empleado empleado) {
    printf("El empleado se llama: %s %s con codigo de empleado: %d.\n",empleado.nombre,empleado.apellidos,empleado.codigoEmpleado);
    mostrarPuesto(empleado.puestoEmpleado);
}
void mostrarPuesto(puesto puesto) {
        printf("El puesto es: %s \n los estudios asociados son: %s\n y el sueldo es: %lf.\n",puesto.nombre,puesto.estudios,puesto.sueldo);
}

cCartesiana polarAcartesiana(cPolar coordenadasP) {
    cCartesiana coordenadasC;
    coordenadasC.x=coordenadasP.r*cos(coordenadasP.theta);
    coordenadasC.y=coordenadasP.r*sin(coordenadasP.theta);
    return coordenadasC;
}

cPolar cartesianaApolar(cCartesiana coordenadasC) {
    cPolar coordenadasP;
    coordenadasP.r=sqrt(coordenadasC.x*coordenadasC.x+coordenadasC.y*coordenadasC.y);
    if(coordenadasC.x>0&&coordenadasC.y>=0) {
        coordenadasP.theta=atan(coordenadasC.y/coordenadasC.x);
    }
    else if(coordenadasC.x<0) {
        coordenadasP.theta=atan(coordenadasC.y/coordenadasC.x)+PI;
    }
    else if(coordenadasC.x>0&&coordenadasC.y<0) {
        coordenadasP.theta=atan(coordenadasC.y/coordenadasC.x)+2*PI;
    }
    else if(coordenadasC.x==0) {
        coordenadasP.theta=PI/2.0;
    }
    else {
        coordenadasP.theta=3*PI/2.0;
    }
    return coordenadasP;
}