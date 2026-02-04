#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct coordenadaCartesiana {
    double x;
    double y;
};
struct coordenadaPolar {
    double r;
    double theta;
};
typedef struct coordenadaCartesiana coordenadaCartesiana;
typedef struct coordenadaPolar coordenadaPolar;

coordenadaPolar cartesianaApolar(coordenadaCartesiana);

int main(int argc,char* argv[]) {
    if (argc!=2) {
        fprintf(stderr,"Llamada incorrecta. La sintaxis es:\n \\.main archivo.csv");
        return 1;
    }
    char linea[100];
    FILE *archivo_origen = fopen(argv[1],"r");
    FILE *archivo_destino = fopen("../Workspace/out.csv","w");
    fprintf(archivo_destino,"#r,theta\n");
    while(fgets(linea,sizeof(linea),archivo_origen)) {
        coordenadaCartesiana cc={.x=0,.y=0};
        coordenadaPolar cp={.r=0,.theta=0};
        if (linea[0]=='#'){continue;}
        cc.x = atof(strtok(linea,","));
        cc.y = atof(strtok(NULL,","));
        cp = cartesianaApolar(cc);
        fprintf(archivo_destino,"%lf,%lf\n",cp.r,cp.theta);
        fflush(archivo_destino);
    }
    fclose(archivo_destino);
    fclose(archivo_origen);
    return 0;
}



coordenadaPolar cartesianaApolar(coordenadaCartesiana cc) {
    coordenadaPolar cp={.r=0,.theta=0};
    cp.r=sqrt(cc.x*cc.x+cc.y*cc.y);
    cp.theta = atan2(cc.x,cc.y);
    return cp;
}