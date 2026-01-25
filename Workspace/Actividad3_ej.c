/*#include <stdio.h>


int fact(int);

int main() {
    int n;
    printf("Introduczca n: ");
    fflush(stdout);
    scanf(" %d",&n);
    printf("%d! es: %d",n,fact(n));
    fflush(stdout);
    return 0;
}



int fact(int n) {
    int solucion=0;
    if (n==0) {
        return 1;
    }
    solucion = n*fact(n-1) ;
    return solucion;
}
*/

#include  <stdio.h>

int fibonacci(int);

int main() {
    int n;
    printf("Introduczca n: ");
    fflush(stdout);
    scanf(" %d",&n);
    printf("El término %d de la sucesión de fibonacci es: %d",n,fibonacci(n));
    fflush(stdout);
    return 0;
}


int fibonacci(int n) {
    if (n==0) {
        return 0;
    }
    if(n==1) {
        return 1;
    }
    int result = fibonacci(n-1)+fibonacci(n-2);
    return result;
}