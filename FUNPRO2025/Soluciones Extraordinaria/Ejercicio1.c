//Solución al siguiente problema:
/*Dado un número entero y una letra, realizar un programa que muestre por pantalla todos los números pares o impares desde 0 hasta dicho número en función de si el usuario elige la opción ‘p’ (pares) o ‘i’ (impares).
Ejemplo:
-Si el usuario elige el número 7 y la opción ‘p’ la salida del programa será: 0, 2, 4, 6.
-Si el usuario elige el número 10 y la opción ‘i’ la salida del programa será: 1, 3, 5, 7, 9.

Se trata de una solución extensa que se asegura que el usuario no introduzca valores inválidos,
en la práctica basta con con que el programa reproduzca el resultado del ejemplo para estar bien.
Al final hay una versión alternativa simplificada.
*/


#include "stdio.h"

//Función principal
int main() {
  int num=0;              //Declaración de variables
  char option;
  int error=-1;
  char mystring[10];
  while(error!=1){        // Crea una interfaz que repregunta al usuario hasta que obtiene una entrada válida.
    printf("Ingrese un número natural:\n");
    error *= scanf("%d",&num);    // la opción d convierte la entrada de forma automática a un entero, si introduces otra cosa el programa falla
    if(error!=-1){//estas linea sse aseguran de que haya leido un entero (el resultado devuelto por scanf es 1 si está correctamente usado).
      printf("Introduzca un valor válido.\n");
      scanf("%s",mystring);
      continue; //corta esta ejecucion del loop
    }
    if (num<=0) {        // Si el número no es positivo, pide que se ingrese de nuevo.
       printf("El número ingresado es 0 o negativo.\n");
       continue;
    }
    error=1;
  }
  error=-1;
  while(error<0){  // Crea una interfaz que repregunta al usuario hasta que obtiene una entrada válida.
    printf("Ingrese p para mostrar los números pares e ingrese i para mostrar los impares:\n");
    scanf(" %c",&option); //El espacio antes de %c indica a scanf que descarte cualquier espacio en blanco, tabulador o salto de linea hasta el primer caracter
    //en caso contrario podría almacenar en c el salto de línea del scanf anterior.
    if (!(option=='p'||option=='i')) {  ///Comprobamos que la opción es válida
        printf("Opción no válida.\n");
        continue;
    }
    error=0;
  }
  if (option=='p') {  //Ramificación que controla el modo de ejecución.
    printf("Numeros pares de 1 a %d:\n",num);
    for (int i=1; i<=num; i++) {
      if (i%2==0) {printf("%d ",i);}
      }
  }
  else if (option=='i') {
    printf("Numeros impares de 1 a %d:\n",num);
    for (int i=1; i<=num; i++) {
      if (i%2!=0) {printf("%d ",i);}
    }
  }
  else {printf("Ha ocurrido un error inexperado");};  //Si por cualquier motivo la variable opcion no vale lo que debe
  return 0;                                           // indica al usuario que el programa no funcionó como debía.
}

/*Simplificado

#include "stdio.h"

//Función principal
int main() {
  int num=0;              //Declaración de variables
  char option;
  printf("Ingrese un número natural:\n");
  scanf("%d",&num);
  printf("Ingrese p para mostrar los números pares e ingrese i para mostrar los impares:\n");
  scanf(" %c",&option);
  if (option=='p') {  //Ramificación que controla el modo de ejecución.
    printf("Numeros pares de 1 a %d:\n",num);
    for (int i=1; i<=num; i++) {
      if (i%2==0) {printf("%d ",i);}
      }
  }
  else if (option=='i') {
    printf("Numeros impares de 1 a %d:\n",num);
    for (int i=1; i<=num; i++) {
      if (i%2!=0) {printf("%d ",i);}
    }
  }
  else {printf("Ha ocurrido un error inexperado");};  //Si por cualquier motivo la variable opcion no vale lo que debe
  return 0;                                           // indica al usuario que el programa no funcionó como debía.
}


 */
