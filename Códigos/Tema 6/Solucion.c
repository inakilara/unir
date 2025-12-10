//
// Created by Iñaki Lara
//
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    int ejercicio,resultadoLectura=1;
    char caracterFinal;
    do{
      printf("\nIntroduce el numero del ejercicio que quieres resolver y 0 para terminar:\n");
      resultadoLectura*=scanf("%d%c", &ejercicio,&caracterFinal); //Descarta el salto de linea al final
      if(resultadoLectura==0||caracterFinal!='\n'){printf("Opcion invalida.");scanf("%*[^\n]%*c");continue;}
    	switch (ejercicio) {
        case 1:
        {
          char myString[51];
          int longitud,esNumerico=0,nEspacios=0;
          printf("Ejercicio 1: Introduzca una cadena de caracteres de longitud maxima 50:\n");
          fgets(myString, 50, stdin);
          longitud=strlen(myString);
            for (int i=0;i<longitud; i++)
                if (isdigit(myString[i]))
                {
                    esNumerico=1;
                }
                else {
                    if (myString[i]==' '){nEspacios++;}
                }
          if(esNumerico) {
              printf("La cadena tiene %d caracteres, contiene caracteres numericos y contiene %d palabras.",longitud-1,nEspacios+1) ;
          }
          else {printf("La cadena tiene %d caracteres, no contiene caracteres numericos y contiene %d palabras.",longitud-1,nEspacios+1) ;}
         }
        break;
        case 2:
        {
            int numA,numB,menor,mayor,suma=0;
            printf("Introduzca el valor del primero de los dos numeros:");
            scanf("%d",&numA);
            printf("\nIntroduzca el valor del segundo:");
            scanf("%d",&numB);
            if (numA<numB){menor=numA;mayor=numB;}
            else if(numA>numB){menor=numB;mayor=numA;}
            else{printf("Los numeros son iguales");break;}
            printf("Los cuadrados perfectos comprendidos entre los dos valores son:\n");
            for (int i=menor+1;i<mayor;i++) {
                int esCuadradoPerfecto=0;
                for (int j=2;j<i;j++) {
                    if(i==j*j){esCuadradoPerfecto=1;break;}
                }
                if(esCuadradoPerfecto){printf(" %d",i);suma+=i;}
            }
            printf("\n La suma de los cuadrados perfectos comprendidos entre %d y %d es: %d.",menor,mayor,suma);
        }
        break;
        case 3: {
            ;
            int numA;
            do{
                printf("Introduzca el valor a comprobar. Termine la ejecucion introduciendo 0:");
                scanf("%d",&numA);
                if (numA==0){break;}
                else if (numA%2==0){printf("El numero es divisible entre dos con cociente: %d.\n",numA/2);}
                else{printf("El numero no es divisible entre dos. Tiene por cociente: %d y por resto: %d.\n",numA/2,numA%2);}
            }while(numA!=0);
        }
        break;
        case 4: {
            char myString[50];
            int isPalindromo=1;
            printf("Introduce la palabra a comprobar:\n");
            scanf("%s",myString);
            for (int i=0;i<=strlen(myString);i++) {
                if(isupper(myString[i])){myString[i]=tolower(myString[i]);}
            }
            for (int i=0;i<=strlen(myString);i++){
                if(myString[strlen(myString)-1-i]!=myString[i]){
                    isPalindromo=0;
                    break;
                }
            }
            if(isPalindromo){printf("La palabra es un palindromo.");}
            else{printf("La palabra no es un palindromo.");}
        }
        break;
        case 0: {
            printf("Programa terminado.");
        }
            break;
        default:
          printf("Opcion invalida.");
        }
    }while(ejercicio!=0);
    return 0;
}