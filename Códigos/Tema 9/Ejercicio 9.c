//
//Ejercicio 9 Tema 8
//Implementa un programa en lenguaje C que introduzca registros con información de
//coordenadas geográficas (longitud y latitud) en un fichero de texto (o binario). Cada registro
//contiene también el nombre de la ubicación como una cadena de texto de 30
//caracteres. Hazlo de tal manera que todos los registros queden almacenados con el
//mismo tamaño en el fichero.
//
//Extra: Indicar por la llamada al programa el nombre del archivo a crear y si es binario o texto con ancho fijo
//
//

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    double latitud;
    double longitud;
    char nombre[31];
}Tcoordenada;

int leer_coordenadas(Tcoordenada *);
void guardar_A_texto(Tcoordenada *,int,char[]);
void guardar_A_binario(Tcoordenada *,int,char[]);


int main(int argc,char *argv[]) {
    Tcoordenada *Lista=(Tcoordenada *)malloc(0*sizeof(Tcoordenada));
    int longitud=0;
    if (argc!=3) {
        printf("La llamada al programa es incorrecta. Tiene que ser de la forma:\n [ejecutable] nombre_de_archivo modo");
        free(Lista);
        return -1;
    }
    switch (atoi(argv[2])) {
        case 1: {
            longitud=leer_coordenadas(Lista);
            guardar_A_texto(Lista,longitud,argv[1]);
            break;
        }
        case 2: {
            longitud=leer_coordenadas(Lista);
            guardar_A_binario(Lista,longitud,argv[1]);
            break;
        }
        default: {
            printf("Opcion de escritura incorrecta.");
        }
    }
    free(Lista);
    return 0;
}

int leer_coordenadas(Tcoordenada *Lista) {
    char seguir=' ';
    int len=0;
    do {
        seguir=' ';
        while(seguir!='s'&&seguir!='n') {
            printf("Quiere introducir otra coordenada[s,n]?");
            scanf(" %c%*c",&seguir);
        }
        if (seguir=='n'){break;}
        len++;
        Lista=(Tcoordenada *)realloc(Lista,len*sizeof(Tcoordenada));
        printf("\nIntroduzca el nombre de la localizacion (hasta 30 caracteres):");
        scanf("%30[^\n]%*c",&(Lista+len-1)->nombre);
        printf("\nIntroduzca la longitud:");
        scanf(" %lf%*c",&(Lista+len-1)->longitud);
        printf("\nIntroduzca la latitud:");
        scanf(" %lf%*c",&(Lista+len-1)->latitud);
    }while(seguir!='n');
    return len;
}

void guardar_A_texto(Tcoordenada *Lista,int longitud,char nombreArchivo[]) {
    FILE *archivo=fopen(nombreArchivo,"w");
    for(int i=0;i<longitud;i++) {
        fprintf(archivo,"%30s %6lf %6lf\n",(Lista+i)->nombre,(Lista+i)->longitud,(Lista+i)->latitud);
    }
    fclose(archivo);
}


void guardar_A_binario(Tcoordenada *Lista,int longitud,char nombreArchivo[]) {
    FILE *archivo=fopen(nombreArchivo,"wb");
    fwrite(Lista,sizeof(Tcoordenada),longitud,archivo);
    fclose(archivo);
}