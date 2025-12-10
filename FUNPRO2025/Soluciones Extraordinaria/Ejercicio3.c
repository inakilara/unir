//Solución al siguiente problema:
/*Desarrolle un programa que defina una estructura (struct) para definir puntos en 3 dimensiones (x, y, z).
A continuación, declare y lea los valores de 2 puntos A y B. Muestre por pantalla la distancia de Manhattan
que hay entre el punto A y B.

Ejemplo:
-A = (4, 6, 5)--> A.x=4; A.y=6; A.z=5;
-B = (2, 4, 4)--> B.x=2; B.y=4; B.z=4;
-La distancia de Manhattan es 5.

d(p,q)=sum(|pi-qi|)

Se trata de una solución extensa que se asegura que el usuario no introduzca valores inválidos,
en la práctica basta con con que el programa reproduzca el resultado del ejemplo para estar bien.
Al final hay una versión alternativa simplificada.
*/

#include "stdio.h"
#include "math.h"


struct point{
  float x;
  float y;
  float z;
};

float checkedfloatInput(){ //Empaqueta la lectura de un float en una función a parte
  int error=-1;
  float x=0;
  char mystring[100];
  while(error!=1){        // Crea una interfaz que repregunta al usuario hasta que obtiene una entrada válida.
    error *= scanf("%f",&x);    //
    if(error!=-1){//estas linea sse aseguran de que haya leido un entero (el resultado devuelto por scanf es 1 si está correctamente usado).
      printf("Introduzca un valor válido.\n");
      scanf("%s",mystring);
      continue; //corta esta ejecucion del loop
    }
    error=1;
  }
 return x;
}

float manhattanDistance(struct point a,struct point b){ //calcula la distancia de Manhattan para dos puntos
  float result=-1;
  return fabs(a.x-b.x)+fabs(a.y-b.y)+fabs(a.z-b.z);
  return result;
}


//Función principal
int main() {
  float x,y,z;
  struct point A;
  struct point B;
  printf("Introduzca el valor de A.x: ");
  A.x=checkedfloatInput();
  printf("Introduzca el valor de A.y: ");
  A.y=checkedfloatInput();
  printf("Introduzca el valor de A.z: ");
  A.z=checkedfloatInput();
  printf("Introduzca el valor de B.x: ");
  B.x=checkedfloatInput();
  printf("Introduzca el valor de B.y: ");
  B.y=checkedfloatInput();
  printf("Introduzca el valor de B.z: ");
  B.z=checkedfloatInput();
  ////

  printf("Valor de la distancia de Manhattan para los puntos A y B: %f",manhattanDistance(A,B));
  return 0;
}

/*Simplificada
#include "stdio.h"
#include "math.h"


struct point{
  float x;
  float y;
  float z;
};

float checkedfloatInput(){ //Empaqueta la lectura de un float en una función a parte
 float x=0;
 scanf("%f",&x);
 return x;
}

float manhattanDistance(struct point a,struct point b){ //calcula la distancia de Manhattan para dos puntos
  float result=-1;
  return fabs(a.x-b.x)+fabs(a.y-b.y)+fabs(a.z-b.z);
  return result;
}


//Función principal
int main() {
  float x,y,z;
  struct point A;
  struct point B;
  printf("Introduzca el valor de A.x: ");
  A.x=checkedfloatInput();
  printf("Introduzca el valor de A.y: ");
  A.y=checkedfloatInput();
  printf("Introduzca el valor de A.z: ");
  A.z=checkedfloatInput();
  printf("Introduzca el valor de B.x: ");
  B.x=checkedfloatInput();
  printf("Introduzca el valor de B.y: ");
  B.y=checkedfloatInput();
  printf("Introduzca el valor de B.z: ");
  B.z=checkedfloatInput();
  ////

  printf("Valor de la distancia de Manhattan para los puntos A y B: %f",manhattanDistance(A,B));
  return 0;
}
 * */