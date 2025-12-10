//
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define n_max 180

typedef struct {
    int ID;
    char Provincia[15];
    char Localidad[15];
    int cp;
    char Direccion[50];
    char Margen;
    char Rotulo[10];
    double gasolina95;
    double gasolina98;
    double gasoleoA;
}gasolinera;

void leerLista(FILE *,gasolinera[],int*);
void mostrar_resgistros(gasolinera[],int);
void mostrar_registro(gasolinera);
void modificar_registro(gasolinera*);
void mostrar_extremo(gasolinera[],int,int);
void mostrar_ordenados(gasolinera[],int);
void ordenarLista(gasolinera[],int);

int main(){
    FILE *archivo = fopen("../datos.csv","r");
    if (archivo==NULL){printf("No se ha podido abrir el archivo");return -1;}
    int len=0;
    gasolinera gasolineras[n_max];
    leerLista(archivo,gasolineras,&len);
    char opcion=' ';
    while(opcion!='q') {
        printf("Escoja la opci\xA2n del men\xA3:\n(a) Mostrar todos los registros \n(b) Mostrar un registro \n(c) Modificar un registro \n(d) Mostrar el registro con el precio m\xA1nimo de la la gasolina 95\n(e) Mostrar el registro con el precio m\xA0ximo de la la gasolina 95 \n(f) Mostrar registros ordenados.\n\n");
        scanf(" %c%*c",&opcion);
        switch (opcion) {
            case 'a': {
                mostrar_resgistros(gasolineras,len);
                break;
            }
            case 'b': {
                printf("Introduce la ID del registro a mostrar:");
                int ID=0;
                scanf("%d",&ID);
                for(int i=0;i<len;i++) {
                    if(gasolineras[i].ID==ID){mostrar_registro(gasolineras[i]);break;}
                }
                break;
            }
            case 'c': {
                printf("Introduce la ID del registro a modificar:");
                int ID=0;
                scanf("%d",&ID);
                for(int i=0;i<len;i++) {
                    if(gasolineras[i].ID==ID){modificar_registro(&gasolineras[i]);break;}
                }
                break;
            }
            case 'd': {
                mostrar_extremo(gasolineras,1,len);
                break;
            }
            case 'e':
                mostrar_extremo(gasolineras,0,len);
                break;
            case 'f':
                mostrar_ordenados(gasolineras,len);
                break;
            case 'q':
                break;
            default:
                printf("Opci\xA2n inv\xA0lida.");
                break;
        }
    }
    return 0;
}

void leerLista(FILE *archivo,gasolinera gasolineras[],int* len) {
    char linea[150];
    int ind=0;
    while(fgets(linea,150,archivo)) {
        if(linea[0]=='I'){continue;}
        gasolineras[ind].ID=atoi(strtok(linea,";"));
        strcpy(gasolineras[ind].Provincia,strtok(NULL,";"));
        strcpy(gasolineras[ind].Localidad,strtok(NULL,";"));
        gasolineras[ind].cp=atoi(strtok(NULL,";"));
        strcpy(gasolineras[ind].Direccion,strtok(NULL,";"));
        gasolineras[ind].Margen=strtok(NULL,";")[0];
        strcpy(gasolineras[ind].Rotulo,strtok(NULL,";"));
        gasolineras[ind].gasolina95=atof(strtok(NULL,";"));
        gasolineras[ind].gasolina98=atof(strtok(NULL,";"));
        gasolineras[ind].gasoleoA=atof(strtok(NULL,";"));
        ind++;
    }
    fclose(archivo);
    *len=ind;
}

void mostrar_resgistros(gasolinera gasolineras[],int len) {
    for(int i=0;i<len;i++) {
        mostrar_registro(gasolineras[i]);
    }
}

void mostrar_registro(gasolinera gasolinera) {
    printf("\n ID:%d %s\n",gasolinera.ID,gasolinera.Rotulo);
    printf("%s %s %s %d\n",gasolinera.Direccion,gasolinera.Localidad,gasolinera.Provincia,gasolinera.cp);
    printf("gasolina95: %lf\n",gasolinera.gasolina95);
    printf("gasolina98: %lf\n",gasolinera.gasolina98);
    printf("gasoleoA: %lf\n",gasolinera.gasoleoA);
}

void modificar_registro(gasolinera *gasolinera) {
    printf("Introduce el nuevo valor del precio de la gasolina 95:");
    scanf("%lf",&gasolinera->gasolina95);
    printf("Introduce el nuevo valor del precio de la gasolina 98:");
    scanf("%lf",&gasolinera->gasolina98);
    printf("Introduce el nuevo valor del precio del gasoleoA:");
    scanf("%lf",&gasolinera->gasoleoA);
}

void mostrar_extremo(gasolinera gasolinera[],int modo,int len) {
    double val=pow(-1,modo)*1000;
    int ind=0;
    for(int i=0;i<len;i++) {
        if(gasolinera[i].gasolina95==-1){continue;}
        if(modo==1) {
            if(gasolinera[i].gasolina95>val) {
                val=gasolinera[i].gasolina95;
                ind=i;
            }
        }
        else if(modo==0){
            if(gasolinera[i].gasolina95<val) {
                val=gasolinera[i].gasolina95;
                ind=i;
            }
        }
    }
    mostrar_registro(gasolinera[ind]);
}


void mostrar_ordenados(gasolinera gasolineras[],int len) {
    ordenarLista(gasolineras,len);
    for (int i = 1; i < len ; i++) {
        mostrar_registro(gasolineras[i]);
    }

}

void ordenarLista(gasolinera gasolineras[], int len) {
    if (len == 1) {
        return;
    }
    for (int i = 1; i < len ; i++) {
        if (gasolineras[i-1].gasolina95 > gasolineras[i].gasolina95) {
            gasolinera auxVal = gasolineras[i-1];
            gasolineras[i-1] = gasolineras[i];
            gasolineras[i] = auxVal;
        }
    }
    ordenarLista(gasolineras, len-1);
}