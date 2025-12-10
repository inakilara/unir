#include <stdio.h>

int main(){
// Tema 1 Fundamentos de programación 2024. Ejemplo 1.
// Código para mostrar un error de compilación
// 
printf("Esta es la primera línea \n");
printf("Esta es la segunda línea \n");
printf("La siguiente línea contiene un error \n");
//a=b  //Esta linea da lugar a un error en el compilador
int *a=NULL;    //
printf("%d",*a);// Estas dos lineas producen un error en tiempo de ejecución.
printf("La línea anterior contenía un error");



return 0;
}
