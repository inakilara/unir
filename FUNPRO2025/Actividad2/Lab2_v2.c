/*#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define NMAX 21

int leerCadena(char *);
int leerEntero(int *);
int leerReal(float *);


int main() {
    char miCadena[NMAX];
    int error,valor;
    printf("Introduce una cadena de caracteres de hasta 20 caracteres:\n");
    fflush(stdout);
    error = leerCadena(miCadena);
    if (error!=1) {
        printf("Cadena erronea");
        return 0;
    }
    printf("La cadena es: %s",miCadena);
    fflush(stdout);
    printf("Introduce un numero entero:\n");
    fflush(stdout);
    error = leerEntero(&valor);
    if (error!=1) {
        printf("Entrada erronea");
        return 0;
    }
    printf("El numero es: %d",valor);
    fflush(stdout);
    return 1;
}

int leerCadena(char *miCadena) {
    fgets(miCadena,NMAX,stdin);
    // Chequear que la entrada es correcta
    if (miCadena[strlen(miCadena)-1]!='\n') {
        miCadena="";
        return 0;
    }
    else {
        miCadena[strlen(miCadena)-1]='\0';
        return 1;
    }
}

int leerEntero(int* resultado){
    char miCadena[NMAX],*ptr=NULL;
    int error=1;
    error = leerCadena(miCadena);
    //Comprobar si se ha propagado un error dede leerCadena
    errno=0;
    *resultado = strtol(miCadena,&ptr,10);
    //Comprobar lectura correcta
    if (errno!=0) {
        return 0;
    }
    return 1;
}

int leerReal(float* resultado){
    char miCadena[NMAX],*ptr=NULL;
    int error=1;
    error = leerCadena(miCadena);
    //Comprobar si se ha propagado un error dede leerCadena
    errno=0;
    *resultado = strtof(miCadena,&ptr);
    //Comprobar lectura correcta
    if (errno!=0) {
        return 0;
    }
    return 1;
}
*/

#include<stdio.h>
#include <math.h>

struct vector {
    float x;
    float y;
    float z;
};
typedef struct vector vector3D;

void leerVector(vector3D*);
void inicializarVector(vector3D*,float,float,float);
void mostrarVector(vector3D);
float distancia(vector3D,vector3D);


int main() {
    vector3D v1,v2;
    inicializarVector(&v2,1,3,-2);
    leerVector(&v1);
    printf("La distancia entre v1:\n");
    fflush(stdout);
    mostrarVector(v1);
    printf("\ny v2:\n");
    fflush(stdout);
    mostrarVector(v2);
    printf("\nes %f",distancia(v1,v2));
    fflush(stdout);

    return 1;
}

void leerVector(vector3D* v) {
    printf("Introduce el valor x:");
    fflush(stdout);
    scanf("%f",&(v->x));
    printf("\nIntroduce el valor y:");
    fflush(stdout);
    scanf("%f",&(v->y));
    printf("\nIntroduce el valor z:");
    fflush(stdout);
    scanf("%f",&(v->z));
}

void inicializarVector(vector3D* v,float x,float y,float z) {
    v->x=x;
    v->y=y;
    v->z=z;
}
void mostrarVector(vector3D v) {
    printf("vx: %f; vy: %f; vz: %f",v.x,v.y,v.z);
    fflush(stdout);
}
float distancia(vector3D v1,vector3D v2) {
    return sqrt(pow(v1.x-v2.x,2)+pow(v1.y-v2.y,2)+pow(v1.z-v2.z,2));
}




