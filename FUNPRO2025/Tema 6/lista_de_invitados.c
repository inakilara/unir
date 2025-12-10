//
// Created by Iñaki Lara on 20/11/2024.
//
#include <stdio.h>
#include <string.h>
#define N_INVITADOS 10

typedef struct {
    char nombre[20];
    char apellidos[100];
    char relacion; //'F':familiar, 'A':amigo, 'T':trabajo, 'O':otros
    int  n;  //Indice unico
}Tinvitado;

void mostrarLista(Tinvitado lista[]);
void añadirInvitado(Tinvitado lista[]);
void eliminarInvitado(Tinvitado lista[]);


int main() {
    int opcion=0;
    int error=0;
    Tinvitado listaInvitados[N_INVITADOS];
    listaInvitados[0].n=0; //Señalo el final de la lista con un n=0.
    do {
        printf("Teclee:\n\t 1. Para mostrar la lista de invitados.\n\t 2. Para crear un invitado\n\t 3. Para eliminar un invitado\n\t 0. Para finalizar el programa.\n\n");
        error=scanf("%d",&opcion);
        if(opcion<0||opcion>3||error!=1){printf("Opcion invalida");scanf("%*[^\n]%*c");continue;}
        switch (opcion) {
            case 0:
                break;
            case 1: {
                mostrarLista(listaInvitados);
                break;
            }
            case 2: {
                añadirInvitado(listaInvitados);
                break;
            }
            case 3: {
                eliminarInvitado(listaInvitados);
                break;
            }
        }
    }while(opcion!=0);
    return 0;
}


void mostrarLista(Tinvitado lista[]) {
    int n,i=0;
    printf("  n\t\tNombre\t\tApellidos\t\t\tRelacion\n");
    printf("------------------------------------------------------------------------------------\n");
    do {
        n=lista[i].n;
        if(n>0){printf("  %d\t\t%s\t\t%s\t\t\t%c\n",lista[i].n,lista[i].nombre,lista[i].apellidos,lista[i].relacion);}
        i++;
    }while(n>0);
    printf("------------------------------------------------------------------------------------\n");
}

void añadirInvitado(Tinvitado lista[]) {
    int error,n,i_last;
    char nombre[20],apellidos[100],relacion;
    do{
        error=1;
        printf("Introduce el nombre:");
        error*=scanf(" %19[^\n]%*c",nombre);
        printf("Introduce los apellidos:");
        error*=scanf("%99[^\n]%*c",apellidos);
        printf("Introduce la relacion (F:familiar,A:amigo,T:trabajo,O:otros):");
        error*=scanf("%c%*c",&relacion);
        if (error<=0){printf("Los datos introducidos no son validos.\n");}
    }while(error<=0);
    for (int i=0;i<N_INVITADOS;i++) {
        if(lista[i].n==0) {
            i_last=i;
            if(i_last==0){lista[i].n=1;}
            else{lista[i].n=lista[i_last-1].n+1;}
            strcpy(lista[i].nombre,nombre);
            strcpy(lista[i].apellidos,apellidos);
            lista[i].relacion=relacion;
            lista[i+1].n=0;
            break;
        }
    }
}

void eliminarInvitado(Tinvitado lista[]) {
    int error,id,i_del;
    do {
        error=1;
        printf("Introduzca el numero del invitado a eliminar:");
        error*=scanf("%d",&id);
        if (error<=0){printf("Los datos introducidos no son validos.\n");}
    }while(error<=0);
    for (int i=0;i<N_INVITADOS;i++) {
        if(lista[i].n==id){i_del=i;break;}
    }
    for (int i=i_del;i<N_INVITADOS-1;i++) {
        strcpy(lista[i].nombre,lista[i+1].nombre);
        strcpy(lista[i].apellidos,lista[i+1].apellidos);
        lista[i].relacion=lista[i+1].relacion;
        lista[i].n=lista[i+1].n;
    }
}

