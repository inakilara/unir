#include <stdio.h>

int main(){
    int i=2,n;
    int esPrimo = 1;
    scanf(" %d",&n);
    while(i<=n-1){
	if(n%i==0){
		esPrimo=0;
		}
	i++;
	}
    if(esPrimo){printf("El numero es primo.");}
    else{printf("El numero no es primo");}
    return 0;
}
