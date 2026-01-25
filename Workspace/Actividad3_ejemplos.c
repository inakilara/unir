//
//   Crea un programa que calcule el factorial de u numero n de forma recursiva
//
#include <stdio.h>

int fact(int);


int main() {
    int n;
    printf("Introduce el valor de n: ");
    fflush(stdout);
    scanf(" %d",&n);
    printf("\nEl factorial de %d es: %d",n,fact(n));
    fflush(stdout);
    return 0;
}


int fact(int n) {
    int result = 0;
    if(n==1||n==0) {
        return 1;
    }
    result = n*fact(n-1);
    return result;
}