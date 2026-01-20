//
//
//
//  Solucion al ejercicio 8 del tema 9 (p33) del cuaderno de ejercios

 //      a_n= (sqrt(a_(n-1))+5)/a_(n-2)
//
// Calcular el término n y la suma de los n primeros
// Añadido: pedir n por la llamada al programa y los valores de a0 y a1

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

double sucesion(double,double,int);
double serie(double,double,int);

int main(int argc, char *argv[]) {
    double an=sucesion(atof(argv[1]),atof(argv[2]),atoi(argv[3])); // Los argumentos de main() son cadenas
    double Sn=serie(atof(argv[1]),atof(argv[2]),atoi(argv[3]));    // Es necesario convertirlos a entero
    printf("El termino %d de la sucesion es:%f.\n",atoi(argv[3]),an);
    printf("El termino %d de la serie es: %f.",atoi(argv[3]),Sn);
}

double sucesion(double a1,double a0,int n) {
    if(n==2) {
        return (sqrt(a1)+5)/(a0);   // En este caso la formula ya da el resultado sin necesidad de recursión
    }
    if(n==1){
        return a1; // Si vale 1 es el valor inicial fijado por la llamada al programa
    }
    if(n==0){
        return a0;   // Si vale 0 es el valor inicial fijado por la llamada al programa
    }
    return (sqrt(sucesion(a1,a0,n-1))+5)/(sucesion(a1,a0,n-2));   //Implementamos la fórmula recursiva
}
double serie(double a1,double a0,int n) {
    if(n==0){
        return a0;   // La serie comienza con el término 0
    }
    return serie(a1,a0,n-1)+sucesion(a1,a0,n);  //Cada elemento de la serie es igual al anterior más el término n de la sucesion
}