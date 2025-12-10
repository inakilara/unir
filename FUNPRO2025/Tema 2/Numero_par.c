//
// Created by Iñaki Lara on 25/10/2024.
//
#include <stdio.h>

int main(){
    int Num=0;
    printf("Introduce un numero:");
    scanf(" %d",&Num);
    if(Num%2==0){printf("El numero es par.");}
    else{printf("El numero es impar");}
    return 0;
}