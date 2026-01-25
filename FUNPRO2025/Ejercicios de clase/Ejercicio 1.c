//
//
#include<stdio.h>
#include<stdlib.h>

int main() {
    char myChar[20],*pEnd,opcion;
    errno=0;
    long n,suma=0;
    printf("Introduzca un numero natural:");
    fgets(myChar,19,stdin);
    n=strtol(myChar,&pEnd,10);
    if (errno!=0||pEnd==&myChar[0]||n<=0){printf("\nValor introducido no válido.");return -1;}
    printf("\nIntroduzca s para calcular la suma de los valores menores que %d o m para su promedio:",n);
    scanf(" %c%*c",&opcion);
    for (int i=1;i<n;i++) {
        suma+=i;
    }
    if(opcion=='m') {
        printf("\nEl promedio es %d.",suma/(n-1));
    }
    else if(opcion=='s') {
        printf("\nLa suma es %d.",suma);
    }
    else{printf("Opción escogida inválida");}
    return 0;
}