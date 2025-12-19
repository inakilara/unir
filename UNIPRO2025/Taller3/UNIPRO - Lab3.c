//
// Created by Iñaki Lara on 12/12/2025.
//

/*Enunciado 1: Escribir un programa que defina un struct para almacenar un vector en 3D y haga operaciones con él.
#include<stdio.h>
#include<math.h>

struct vector3D {
    double x;
    double y;
    double z;
};


typedef struct vector3D vector3D;

void inicializarVector(vector3D*,double,double,double);
void leerVector(vector3D*);
void mostrarVector(vector3D);
double calcularDistancia(vector3D,vector3D);

int main() {
    vector3D v1,v2;
    inicializarVector(&v1,1,2,0);
    leerVector(&v2);
    printf("La distancia entre v1:\n");
    fflush(stdout);
    mostrarVector(v1);
    printf("\n y v2:");
    fflush(stdout);
    mostrarVector(v1);
    printf("es : %lf",calcularDistancia(v1,v2));
    fflush(stdout);
    return 0;
}


void inicializarVector(vector3D* v,double x,double y,double z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void leerVector(vector3D* v) {
    printf("Introduce la componente x: ");
    fflush(stdout);
    scanf("%lf",&(v->x));
    printf("\nIntroduce la componente y: ");
    fflush(stdout);
    scanf("%lf",&(v->y));
    printf("\nIntroduce la componente z: ");
    fflush(stdout);
    scanf("%lf",&(v->z));
    printf("\n");
    fflush(stdout);
}

void mostrarVector(vector3D v) {
    printf("x: %lf;y: %lf;z: %lf\n",v.x,v.y,v.z);
    fflush(stdout);
}


double calcularDistancia(vector3D v1,vector3D v2) {
    return sqrt(pow(v1.x-v2.x,2)+pow(v1.y-v2.y,2)+pow(v1.z-v2.z,2));
}*/

//Enunciado2 Crear un programa que defina funciones para la lectura por teclado de forma ilimitada, usando gestión dinámica de memoria.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char *leerCadena();
int leerEntero(int*);

int main() {
    printf("Introduce una frase:\n");
    char *miCadena = leerCadena();
    printf("\nLa cadena introducida es: %s",miCadena);
    free(miCadena);
    printf("Introduce un numero: ");
    fflush(stdout);
    int valor,error;
    error = leerEntero(&valor);
    if(error==1) {
        printf("\n El numero introducido es: %d",valor);
        fflush(stdout);
    }
    else {
        printf("\n Error de lectura");
        fflush(stdout);
    }
    return 0;
}


char *leerCadena() {
    char *cadena = (char *)calloc(1,sizeof(char)),c;
    int len=0;
    do {
        len++;
        c=getchar();
        char *temp_p = (char *)realloc(cadena,len*sizeof(char));
        if (temp_p != NULL) {cadena = temp_p;}
        else{free(cadena);return NULL;}
        if(c!='\n') {
                *(cadena+len-1)=c;
        }
    }while(c!='\n');
    *(cadena+len-1)='\0';
    return cadena;
}

int leerEntero(int *valor) {
    errno = 0;
    char *miCadena = leerCadena(),*ptr;
    if (miCadena == NULL) {
        return -1;
    }
    *valor = strtol(miCadena,&ptr,10);
    free(miCadena);
    if((errno!=0)||(miCadena==ptr)) {
        return -1;
    }
    return 1;
}