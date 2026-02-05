/*
 * Escribe un programa que lea un archivo csv con coordenadas y las transforme escribiéndolas en un nuevo csv.
 * Permitiendo escoger entre cartesianas y polares.
 *
 */
/*
#include <stdio.h>


int main(int argc,char* argv[]) {
 if (argc<2) {
  fprintf(stderr,"Llamada incorrecta, no se ha incluido el nombre.\n La forma correcta es:\n UNIR.exe Nombre ");
  return -1;
 }
 printf("Hello %s",argv[1]);
 return 0;
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 100


typedef struct {
 double x;
 double y;
}cCartesiana;
struct cPolar {
 double r;
 double theta;
};

typedef  struct cPolar cPolar;

cPolar cCartesianaAcPolar(cCartesiana);

int main(int argc,char* argv[]) {
 if (argc!=3) {
  fprintf(stderr,"LLamada incorrecta. La sintaxis correcta es:\n >>UNIR.exe archivo.csv OPCION\n donde OPCION:\n c para convertir coordenada cartesianas y p para polares.");
  return -1;
 }
 char linea[N];
 FILE *archivo_de_entrada = fopen(argv[1],"r");
 FILE *archivo_de_salida = fopen("../Workspace/Coordenadas_polares.csv","w");
 fprintf(archivo_de_salida,"#r,theta\n");
 while(fgets(linea,sizeof(linea),archivo_de_entrada)){
  if(linea[0]=='#'){continue;}
  cCartesiana cc={.x=0,.y=0};
  cc.x = atof(strtok(linea,","));
  cc.y = atof(strtok(NULL,","));
  cPolar cp = cCartesianaAcPolar(cc);
  fprintf(archivo_de_salida,"%lf,%lf\n",cp.r,cp.theta);
  fflush(archivo_de_salida);
 }
 fclose(archivo_de_entrada);
 fclose(archivo_de_salida);
 return 0;
}

cPolar cCartesianaAcPolar(cCartesiana cc) {
 cPolar cp = {.r=0,.theta=0};
 cp.r=sqrt(cc.x*cc.x+cc.y*cc.y);
 cp.theta = atan2(cc.y,cc.x);
 return cp;
}








