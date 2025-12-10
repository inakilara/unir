#include <stdio.h>

int EsPrimo(int num){
	int i=2,resultado=1;
	while(i<=num-1){
	if(num%i==0){
		resultado=0;
		}
	i++;
	}
	return resultado;}

int main(){
    int n;    
   printf("Introduce un número para comprobar si es primo:");
    scanf(" %d",&n);
    if(EsPrimo(n)){printf("El número es primo.");}
    else{printf("El número no es primo");}
    return 0;
}