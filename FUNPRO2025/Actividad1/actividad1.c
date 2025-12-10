//
// Created by Iñaki Lara
//

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>




int main() {
    int ejercicio,resultadoLectura=1;
    char caracterFinal;
    do{
      printf("\nIntroduce el numero del ejercicio (1-4) que quieres resolver y 0 para terminar:\n");
      resultadoLectura=scanf(" %d%c", &ejercicio,&caracterFinal); //Descarta el salto de linea al final
      if(resultadoLectura==0||caracterFinal!='\n'){printf("Opcion invalida.");scanf("%*[^\n]%*c");continue;}
    	switch (ejercicio) {
        case 1:
        {
          char c;
          printf("Introduce el caracter a analizar: ");
          scanf(" %c%*c",&c);
          if (!isalpha(c)){printf("El caracter introducido no es una letra");}
          else if(tolower(c)=='a'||tolower(c)=='e'||tolower(c)=='i'||tolower(c)=='o'||tolower(c)=='u'){
            printf("El caracter introducido es vocal");
          }
          else{
              printf("El caracter introducido es consonante");
          }
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
            else{
              printf("Los numeros son iguales");
              break;}
            printf("Los cuadrados perfectos comprendidos entre los dos valores son:\n");
            for (int i=menor;i<=mayor;i++) {
                int esCuadradoPerfecto=0;
                for (int j=1;j<=(int)sqrt(i);j++) {
                    if(i==j*j){esCuadradoPerfecto=1;break;}
                }
                if(esCuadradoPerfecto){printf(" %d",i);suma+=i;}
            }
            printf("\n La suma de los cuadrados perfectos comprendidos entre %d y %d es: %d.",menor,mayor,suma);
        }
        break;
        case 3: {
            int num,odds=0,evens=0;
            char numString[11];//Suficiente para un int
            printf("Introduce un numero positivo: ");
            if(scanf(" %d%*c",&num)!=1){printf("\nEntrada invalida");scanf("%*[^\n]%*c");break;}
            sprintf(numString,"%d",num);
            for (int i=0;i<strlen(numString);i++) {
                if((int)numString[i]%2==0) {
                    evens++;
                }
                else {
                    odds++;
                }
            }
            printf("EL numero: %d tiene %d cifras de las cuales %d son pares y %d impares",num,strlen(numString),evens,odds);
        }
        break;
        case 4: {
            char myString[51];
            int isPalindromo=1;
            printf("Introduce la palabra a comprobar:\n");
            scanf("%s",myString);   //Probar a cambiar para que admita frases como entrada
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
