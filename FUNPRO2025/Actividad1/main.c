//
// Created by Iñaki Lara on 10/11/2025.
//
#include <ctype.h>
#include<stdio.h>
#include <string.h>

int main() {
    /*char nombre[11],caracter;
    float x[10];
    int error = 0,opcion;
    printf("Como te llamas?: ");
    //scanf("%10[^\n]%*c",&nombre);
    fgets(nombre,11,stdin);
    printf("\nHola %s\n",nombre);
    do {
        printf("Escriba 1) para la opcion a , 2) para la opcion b y 0) para salir:\n");
        error = scanf("%d%*c",&opcion);
        if (opcion == 1) {
            printf("Ha escogido la opcion a para comprobar si un caracter es alfabetico.\n Introduzca el caracter");
            caracter = getchar();
            if (isalpha(caracter)) {
                printf("%c es un caracter alfabetico.",caracter);
            }
            else {
                printf("%c no es un caracter alfabetico");
            }
        }
        else if (opcion == 2) {
            printf("Ha escogido la opcion b.\n");
        }
        else if (opcion == 0){
            return 0;
        }
        else {
            printf("Opcion invalida");
        }
    }while(opcion!=0);*/
    // Construye un programa que calcule la suma de los numeros pares entre dos numeros
    /*int a,b,suma_parcial=0;
    // Interfaz con el usuario
    printf("Introduce el valor del numero menor: ");
    scanf("%d",&a);
    printf("\nIntroduce el valor del numero mayor: ");
    scanf("%d",&b);
    for (int i = a; i<b;i++){
        if(i%2==0) {
            printf("%d\n",i);
            suma_parcial+=i;
        }
    }
    printf("La suma es: %d",suma_parcial);*/
    char myString[101];
    printf("Introduzca la cadena ha anlizar: ");
    scanf("%100[^\n]%*c",&myString);
    printf("La cadena mide: %d \n",strlen(myString));
    for (int i=0;i<strlen(myString);i++) {
        if (islower(myString[i])) {
            printf("%c esta en minuscula.\n",myString[i]);
        }
        else if(isupper(myString[i])) {
            printf("%c esta en mayuscula.\n",myString[i]);
        }
        else if(isdigit(myString[i])) {
            printf("%c es un digito.\n",myString[i]);
        }
    }
    return 0;
}
