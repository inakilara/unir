/*
//    Escribe un programa hello world que salude al nombre que se le pase como argumento de entrada en la llamada al programa.
#include <stdio.h>

int main(const int argc,char *argv[]) {
    printf("Hello %s\n",argv[1]);
    printf("Argumentos de entrada\n");
    for (int i=0;i<argc;i++) {
        printf("%d: %s\n",i,argv[i]);
    }
    return 1;
}*/
/*
// Escribe un programa que muestre por la terminal el contenido de un archivo de texto cuya ruta se pase como argumento
// de entrada de la llamada del programa.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef unsigned long long int_;

int_ longitudFicheroTexto(FILE*);

int main(const int argc,char *argv[]) {
    assert(("La llamada al programa no es valida. La forma correcta es:\n\t ./main ruta/al/archivo")&&(argc==2));
    FILE *archivo = fopen(argv[1],"rb");
    const int_ len = longitudFicheroTexto(archivo);
    fclose(archivo);
    archivo = fopen(argv[1],"r") ;
    char *texto = (char *) malloc(sizeof(char)*len);
    char format[20];
    sprintf(format,"%%%lluc",len);
    fscanf(archivo,format,texto);
    printf("%s",texto);
    free(texto);
    fclose(archivo);
    return 0;
}


int_ longitudFicheroTexto(FILE* f) {
    fseek(f,0,SEEK_END);
    return ftell(f)/sizeof(char);
}
*/

/* Escribe un programa que implemente la función factorial de forma recursiva
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int_;
int_ fact(int_);

int main(const int argc,char *argv[]) {
    printf("El factorial de %d es: %llu.",atoi(argv[1]),fact(atoi(argv[1])));
    fflush(stdout);
}


int_ fact(int_ n) {
    if(n==0) {
        return 1;
    }
    return n*fact(n-1);
}*/
/*
// Solucion al ejercicio 8 del tema 9 (p33)
//
//       a_n = (sqrt(a_(n-1))+5)/a_(n-2)
//
// Crea un programa que calcule el término n-esimo de la sucesión y de la serie correspondiente (la suma de los primeros n términos).
// Añadido: pasar n y los valores a0 y a1 por los argumentos de entrada del programa.


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double sucesion(int,double,double);
double serie(int,double,double);


int main(const int argc,char *argv[]) {
    assert(("La llamada al programa no es valida. La forma correcta es:\n\t ./main n a0 a1")&&(argc==4));
    int n = atoi(argv[1]);
    double a0 = atof(argv[2]),a1 = atof(argv[3]);
    double an = sucesion(n,a0,a1);
    double Sn = serie(n,a0,a1);
    printf("El termino %d de la sucesion es:%f\n",n,an);
    printf("El termino %d de la serie es:%f",n,Sn);

}

double sucesion(int n ,double a0,double a1) {
    if (n==0) {
        return a0;
    }
    if (n==1) {
        return a1;
    }
    return (sqrt(sucesion(n-1,a0,a1))+5)/sucesion(n-2,a0,a1);
}

double serie(int n,double a0,double a1) {
    if(n==0) {
        return a0;
    }
    return sucesion(n,a0,a1)+serie(n-1,a0,a1);
}
*/
/*
//Crea un programa que implemente una solución recursiva para resolver una ecuacion diferencial de forma numérica:
// Ej: calcular la concentracion de una substancia radiactiva tras un tiempo typedef

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double euler(double,double,double,double);
double solucionExacta(double,double,double);
double ecuacionDiferencial(double,double);

int main(const int argc,char *argv[]) {
    double lambda=atof(argv[1]), t=atof(argv[2]), N0=atof(argv[3]);
    int n=atoi(argv[4]);
    assert(("La llamada al programa no es valida. La forma correcta es:\n\t ./main lambda t N0 n")&&(argc==5));
    double valorExacto = solucionExacta(lambda,N0,t);
    double valorAproximado = euler(lambda,N0,t,t/n);
    printf("EL resultado exacto es: %lf, el aproximado es: %lf y el error relativo: %lf",valorExacto,valorAproximado,(valorExacto-valorAproximado)/valorExacto*100);
    return 0;
}

double solucionExacta(double lambda,double N0,double t) {
    return N0*exp(-lambda*t);
}

double ecuacionDiferencial(double lambda,double N) {
    return -lambda*N;
}

double euler(double lambda,double N0,double t,double dt) {
    if(t<=0) {
        return N0;
    }
    double N=euler(lambda,N0,t-dt,dt);
    return N+dt*ecuacionDiferencial(lambda,N);
}
*/


//  Escribe un programa que calcule el determinante de una matriz de tamaño arbitrario mediante el metodo de Laplace
//
//       det M(nxn) = sum(j=0,n){(-1)^(i+j)*M_(i,j)*m(i,j)}   donde i es un indice cualquiera fijo de las filas de la matriz  (el programa usa i=0)
//                                                            M_(i,j) es el elemento i j de la matriz
//                                                            m(i,j) es el determinante de la submatriz resultante de quitar la fila i y la columna j a la matriz
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double det(double*,int);

int main() {
    double M[2][2] = {{1,1},{1,1}};
    double M2[3][3] = {{2,2,1},{2,-5,6},{7,5,-4}};
    printf("El determinante es: %lf",det(&M2[0][0],3));
    return 0;

}


double det(double* M,int n) {
    if (n==1) {
        return *M;
    }
    double res=0;
    for (int j=0;j<n;j++) {
        double *m = (double*)malloc((n-1)*(n-1)*sizeof(double));
        int ind = 0;
        for (int r=0;r<n*n;r++) {
            if(r%n==j||r<n){continue;}
            *(m+ind) = *(M+(r/n)*n+r%n);
            ind++;
        }
        res += pow(-1,j)*(*(M+j))*det(m,n-1) ;
        free(m);
    }
    return res;
}