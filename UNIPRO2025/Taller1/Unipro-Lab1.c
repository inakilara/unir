#include<stdio.h>
#include <string.h>
#include<math.h>

int main() {
   /*char nombre[21];
   int edad;
   printf("Introduce tu nombre: ");
   //fgets(nombre,20,stdin);
   scanf("%20[^\n]%*[^\n]%*c",nombre);
   //nombre[strlen(nombre)-1]='\0';
   printf("\nHola %s!",nombre);
   printf("Introduce tu edad: ");
   scanf("%d",&edad);
   printf("\nTienes %d años",edad);
   return 0;*/
   //Enunciado 1: Crea un programa que te permita sumar los valores pares entre dos numeros intorducidos por teclado
   /*int valor1,valor2,suma=0;
   printf("Introduzca el primer valor: ");
   scanf("%d",&valor1);
   printf("\nIntroduzca el segundo valor: ");
   scanf("%d",&valor2);
   for(int i=valor1;i<=valor2;i++) {
      if(i%2==0) {
         suma += i;
      }
   }
   int i=valor1;
   while(i<=valor2){
      if(i%2==0) {
         suma += i;
      }
      i++;
   }
   printf("\n El resultado de la suma es: %d",suma);
   */
   // Crea un programa que compruebe si un numero es primo
   int esPrimo=1;
   long long n;
   printf("Introduzca el numero a comprobar: ");
   scanf(" %llu",&n);
   for (int i=2;i<(int)sqrt(n);i++) {
   //for (int i=2;i<n;i++) {
      if(n%i==0) {
         esPrimo=0;
      }
   }
   if (esPrimo) {
      printf("El numero es primo");
   }
   else {
      printf("El numero no es primo");
   }



}



