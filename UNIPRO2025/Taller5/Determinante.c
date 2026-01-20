//
// Escribe un programa que calcule el determinante de una matríz de tamaño arbitrario por el metodo de Laplace:
/*
 *
 *              det M(nxn)=sum(j=0,n){ (-1)^(i+j)*M_(i,j)*m(i,j) }   donde i es cualquiera de las filas de la matriz (el programa usa i=0)
 *                                                                   M_(i,j) es el elemento i, j de la matriz M
 *                                                                   y m(i,j) es el determinante de la submatriz resultante de quitar en M la fila i y la columna j.
 *
*/
//
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double det(double *,int n);

int main() {
    double M[2][2]={{1,1},{1,1}};  //det = 0
    double M2[3][3]={{2,2,1},{2,-5,6},{7,5,-4}}; // det = 125
    printf("%lf",det(&M[0][0],2));
	return 0;
}


double det(double *M,int n) {
    if( n==1) {
        return *M;                                                          // El determinante de un número es el propio número
    }
        double res=0;
        for(int j = 0; j<n ;j++) {                                          // El metodo de Laplace con i=0 y recorriendo j
            double *m=(double*)malloc((n-1)*(n-1)*sizeof(double));          //Matriz para calcular el determinante de tamaño (n-1)x(n-1)
            int ind=0;                                                      //indice para recorrer la matriz m
            for(int r = 0; r<n*n ;r++) {                                    //Recorremos la matriz M
                if(r%n==j||r<n){continue;}                                  // Nos saltamos la primera fila y la columna j
                *(m+ind)=*(M+(r/n)*n+r%n);                                  //Rellenamos la matriz m. Recorremos m con un único indice a00->a01->a02 ...-> a0n-1->a10-> ... -> an-1n-1
                ind++;
            }
            res += pow(-1,j)*(*(M+j))*det(m,n-1);                           //Cada elemento de la suma incluye una llamada recursiva al determinante de un orden inferior.
            free(m);
        }
        return res;
}