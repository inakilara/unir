//
// Created by Iñaki Lara on 30/12/2024.
//
// Escriba un programa que implemente el metodo de euler de forma recursiva para calcular
// la concentración de una substancia radiactiva tras un tiempo t .

#include <math.h>
#include<stdio.h>

double solucionExacta(double,double,double); //La solución exacta es N=N0*exp(-t*lambda)
double ecuacionDiferencial(double,double);   // La ecuación diferencial del problema es dN/dt=-N*lambda
double euler(double,double,double,double);


int main(){
    double lambda,t,N0,valorExacto,valorAproximado;
    int n;
    //Interfaz con el usuario
    printf("Introduce el valor de la constante lambda:");
    scanf("%lf",&lambda);
    printf("Introduce el tiempo final:");
    scanf("%lf",&t);
    printf("Introduce la masa inicial:");
    scanf("%lf",&N0);
    printf("Introduce el numero de pasos en la integracion:");
    scanf("%d",&n);
    //Calculo del valor de T
    valorExacto=solucionExacta(lambda,N0,t);
    valorAproximado=euler(lambda,N0,t,t/n);
    //Devolvemos los resultados
    printf("La masa final exacta es: %lf\n la masa final aproximada es: %lf\n y el error relativo: %lf.",valorExacto,valorAproximado,fabs(valorExacto-valorAproximado)/valorExacto*100.0);
    return 0;
}

double solucionExacta(double lambda,double N0,double t) {
    return N0*exp(-lambda*t);
}
double ecuacionDiferencial(double lambda,double N) {
    return -lambda*N;
}
double euler(double lambda,double N0,double t ,double dt) {
    if(t<=0) {
        return N0;
    }
    double N=euler(lambda,N0,t-dt,dt);
    return N+dt*ecuacionDiferencial(lambda,N);
}


