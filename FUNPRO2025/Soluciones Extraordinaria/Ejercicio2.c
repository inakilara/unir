//Solución al siguiente problema:
/*Desarrolla un programa que solicite al usuario que introduzca un número a adivinar. Posteriormente, se le solicitará que introduzca otro número. En caso de que dicho número sea menor, se le informará que ha introducido un número menor y se le pedirá nuevamente. Si el número ingresado es mayor, se le indicará que se ha excedido y se le instará a intentarlo de nuevo. Este proceso continuará hasta que el usuario adivine el número, momento en el cual se mostrará un mensaje confirmando que ha acertado y el programa finalizará.
Ejemplo:
Número a adivinar 5.
En caso de introducir 3, se indicará que ha introducido un número menor.
En caso de introducir 7, se indicará que se ha excedido.
Cuando introduzca el número 5 se indicará que ha acertado y finalizará el programa.

Se trata de una solución extensa que se asegura que el usuario no introduzca valores inválidos,
en la práctica basta con con que el programa reproduzca el resultado del ejemplo para estar bien.
Al final hay una versión alternativa simplificada.
*/

#include "stdio.h"

//Función principal
int main() {
  int secretNum=0;             //Declaración de variables
  int triedNum=0;
  int error=-1;
  char mystring[10];
  while(error!=1){        // Crea una interfaz que repregunta al usuario hasta que obtiene una entrada válida.
    printf("Ingrese un número natural:\n");
    error=-1;
    error *= scanf("%d",&secretNum);    // la opción d convierte la entrada de forma automática a un entero, si introduces otra cosa el programa falla
    if(error!=-1){//estas linea sse aseguran de que haya leido un entero (el resultado devuelto por scanf es 1 si está correctamente usado).
      printf("Introduzca un valor válido.\n");
      scanf("%s",mystring);
      continue; //corta esta ejecucion del loop
    }
    error=1;
  }
  do{ //Usamos un do... while en lugar de un while para evitar que si el usuario escoje el 0 (al cuál hemos inicializado las variables), el programa no se se ejecute.
    error=-1;
    while(error<0){  // Crea una interfaz que repregunta al usuario hasta que obtiene una entrada válida.
      printf("Introduzca el siguiente intento:\n");
      error=-1;
      error *= scanf("%d",&triedNum);
      if(error!=-1){//estas linea sse aseguran de que haya leido un entero (el resultado devuelto por scanf es 1 si está correctamente usado).
        printf("Introduzca un valor válido.\n");
        scanf("%s",mystring);
        continue; //corta esta ejecucion del loop
      }
      error=1;
    }
    if(error!=1){continue;}
    if (triedNum>secretNum){
      printf("El número secreto es menor. Inténtelo de nuevo.\n");
    }
    else if (triedNum<secretNum){
      printf("El número secreto es mayor. Inténtelo de nuevo.\n");
    }
    else if (triedNum==secretNum){
      printf("Has adivinado el número secreto!. Su valor es:%d\n",secretNum);
    }
    else{printf("Un error inesperado ha ocurrido.\n");}
  }while(triedNum!=secretNum);
  return 0;
}

/* simplificado
* #include "stdio.h"

//Función principal
int main() {
  int secretNum=0;             //Declaración de variables
  int triedNum=0;
  printf("Ingrese un número natural:\n");
  scanf("%d",&secretNum);
  do{ //Usamos un do... while en lugar de un while para evitar que si el usuario escoje el 0 (al cuál hemos inicializado las variables), el programa no se se ejecute.
    printf("Introduzca el siguiente intento:\n");
    scanf("%d",&triedNum);
    if (triedNum>secretNum){
      printf("El número secreto es menor. Inténtelo de nuevo.\n");
    }
    else if (triedNum<secretNum){
      printf("El número secreto es mayor. Inténtelo de nuevo.\n");
    }
    else if (triedNum==secretNum){
      printf("Has adivinado el número secreto!. Su valor es:%d\n",secretNum);
    }
    else{printf("Un error inesperado ha ocurrido.\n");}
  }while(triedNum!=secretNum);
  return 0;
}
* */
