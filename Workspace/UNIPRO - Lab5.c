//
//
# include <stdio.h>
#include <stdlib.h>

int fileLength(FILE*);

int main(int argc,char *argv[]) {
    FILE *archivo = fopen(argv[1],"rb");
    const int len = fileLength(archivo);
    fclose(archivo);
    archivo = fopen(argv[1],"r");
    char *texto = (char*)malloc(sizeof(char)*len);
    char format[20];
    sprintf(format,"%%%dc",len);
    fscanf(archivo,format,texto);
    printf("%s",texto);
    free(texto);
    fclose(archivo);
    return 0;
}

int fileLength(FILE *file){
    fseek(file,0,SEEK_END);
    const int len = ftell(file)/sizeof(char);
    return len;
}