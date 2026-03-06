// Hello world con argumentos de entrada
/*#include <stdio.h>

int main(int argc,char* argv[]) {
    if (argc<2) {
        fprintf(stderr,"LLamada incorrecta, no se ha introducido el nombre. La sintaxis correcta es:\n >>UNIR.exe Nombre");
        return -1;
    }
    printf("Hola %s",argv[1]);
    printf("Has llamado al programa con %d argumentos",argc);
    return 0;
}*/

/*
 * Escribe unprograma que lea un archivo csv con coordenadas y las transforme escribiendolas a un nuevo archivo.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 100


struct cCartesiana {
    double x;
    double y;
};

struct cPolar {
    double r;
    double theta;
};

typedef struct cCartesiana cCartesiana;
typedef struct cPolar cPolar;

cPolar cCartesianaAcPolar(cCartesiana);

int main(int argc,char* argv[]) {
    if (argc!=2) {
        fprintf(stderr,"LLamada incorreta. La sintaxis adecuada es:\n >>UNIR.exe archivo.csv");
        return -1;
    }
    char linea[N];
    FILE* archivo_de_entrada=fopen(argv[1],"r");
    FILE* archivo_de_salida=fopen("../Workspace/Respuesta.csv","w");
    fprintf(archivo_de_salida,"#r,theta\n");
    while(fgets(linea,sizeof(linea),archivo_de_entrada)){
        if(linea[0]=='#'){continue;}
        cCartesiana cc={.x=0,.y=0};
        cc.x=atof(strtok(linea,","));
        cc.y=atof(strtok(NULL,","));
        cPolar cp = cCartesianaAcPolar(cc);
        fprintf(archivo_de_salida,"%lf,%lf\n",cp.r,cp.theta);
    }
    fclose(archivo_de_entrada);
    fclose(archivo_de_salida);
    return 0;
}

cPolar cCartesianaAcPolar(cCartesiana cc) {
    cPolar cp = {.r=0, .theta=0};
    cp.r = sqrt(cc.x*cc.x+cc.y*cc.y);
    cp.theta = atan2(cc.y,cc.x);
    return cp;
}
