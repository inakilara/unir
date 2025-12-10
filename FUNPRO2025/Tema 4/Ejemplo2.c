//
// Created by Iñaki Lara on 06/11/2024.
//

#include<stdio.h>
#define SECRETO 11
int main(){
    int intento;
    printf("Intenta adivinar el numero secreto.");
    do {
        printf("\nIntroduce el siguiente intento:");
        scanf("%d",&intento);
        if(intento==SECRETO){printf("\n Acertaste!");}
        else if(intento<SECRETO){printf("\nLo siento, el numero introducido es menor");}
        else{printf("\nLo siento, el numero introducido es mayor");}
    }while(intento!=SECRETO);
    return 0;
}