#include <stdio.h>
#include <string.h>

#define WORD "murcielago"   //La solución
#define N_FALLOS 10         // El programa está pensado para 10 intentos

const char ahorcado[11][50]={"      \n      \n      \n      \n      \n      \n",
                                 "      \n      \n      \n      \n      \n     |\n",
                                 "      \n      \n      \n     |\n     |\n     |\n",
                                 "      \n     |\n     |\n     |\n     |\n     |\n",
                                 " +---+\n |   |\n     |\n     |\n     |\n     |\n",
                                 " +---+\n |   |\n 0   |\n     |\n     |\n     |\n",
                                 " +---+\n |   |\n 0   |\n/    |\n     |\n     |\n",
                                 " +---+\n |   |\n 0   |\n/|   |\n     |\n     |\n",
                                 " +---+\n |   |\n 0   |\n/|\\  |\n     |\n     |\n",
                                 " +---+\n |   |\n 0   |\n/|\\  |\n/    |\n     |\n",
                                 " +---+\n |   |\n 0   |\n/|\\  |\n/ \\  |\n     |\n"}; //Array de cadenas que almacena el dibujo del ahorcado

void inicializarPalabra(char* palabra_actual,int len);
void mostrarEstado(char *palabra_actual,int fallos);
void nuevoIntento(const char* palabra,char* palabra_actual,int *fallos);
int solucionar(const char* palabra);

int main() {
    //Bloque de declaraciones
    const char palabra[] = WORD; //Guardo la solución en esta constante, no debería de cambiar a lo largo del programa
    char palabra_actual[] = WORD; // Incializo una array de caracteres con la solución para que tenga su mismo tamaño
    int fallos=0;
    const int len=strlen(palabra);


    inicializarPalabra(palabra_actual,len); //Esta función substituye los caracteres por _



    while(strcmp(palabra,palabra_actual)!=0) {   //Si acierta la solución el bucle termina
        if(fallos==N_FALLOS){printf("Se te agotaron los intentos, perdiste.\n\n%s",ahorcado[10]);return 0;}  //Si se agotaron los intentos el programa termina
        mostrarEstado(palabra_actual,fallos);  //Mostramos el progreso
        int opcion=0;
        printf("Introduce 1 para probar una letra y 2 para resolver:");
        if(scanf("%d",&opcion)==0){printf("Opcion invalida\n\n");scanf("%*[^\n]");continue;};  //comprobamos que la entrada es válida
        if((opcion!=1)&&(opcion!=2)){printf("Opcion invalida\n\n");scanf("%*[^\n]");continue;} //
        switch (opcion) {   //Podemos escoger si probar letra o resolver
            case 1: {
                if (N_FALLOS-fallos>0){nuevoIntento(palabra,palabra_actual,&fallos);} //Intentamos adivinar letras
                else{printf("Se te agotaron los intentos, perdiste.\n\n%s",ahorcado[10]);return 0;}
            }
            break;
            case 2: {
                if ((solucionar(palabra))==1){printf("\n\n\t\tAcertaste!");return 0;} //Intentamos solucionar
                else{printf("Perdiste.\n\n%s",ahorcado[10]);return 0;}
            }
            break;
        }
    }
    printf("\n\n\t\tAcertaste!");return 0; //Si adivinamos letra por letra, tambien ganamos.
}


void nuevoIntento(const char* palabra, char* palabra_actual,int *fallos) {
    char c;
    int acierto=0;
    printf("Escribe el nuevo intento:");
    scanf(" %c",&c);
    for (int i=0;i<strlen(palabra);i++) {
        if(palabra[i]==c){palabra_actual[i]=c;acierto++;}  //comprueba letra a letra su hemos acertado alguna y la substituye
    }
    if(acierto==0){printf("%c no esta en la palabra.\n",c);*fallos=*fallos+1;} //Si no acerte ningna letra, aumento el fallo
}

void inicializarPalabra(char* palabra_actual,int len) {
    for (int i = 0; i < len; i++) { //Substituyo la palabra actual por huecos
        palabra_actual[i] = '_';//
        // *(palabra_actual+i) = '_'; //Esta linea haría lo mismo
    }
}
void mostrarEstado(char *palabra_actual,int fallos) {
    printf("\nHasta ahora has adivinado:\n\n");
    printf("%s\t\t te quedan %d intentos.\n\n",palabra_actual,N_FALLOS-fallos);   //Enseñamos el progreso por pantalla en un formato cómo de leer
    printf("%s\n",ahorcado[fallos]);
}

int solucionar(const char* palabra) {
    char intento[] = WORD;
    printf("\n Introduce el intento de solucion:");
    scanf(" %[^\n]%*c",intento); //Se podría mejorar ¿Cómo?
    int test=1;
    for(int i=0;i<strlen(palabra);i++) { // se podría usar strcmp para hacerlo más sencillo, por ejemplo
        if (palabra[i]!=intento[i]) {
            test=0;
            break;
        }
    }
    if (test){return 1;}
    else{return 0;}
}


