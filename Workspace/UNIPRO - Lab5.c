//
//
# include <stdio.h>
#include <stdlib.h>

typedef const unsigned long long int_;
int_ fileLength(FILE*);

int main(const int argc,char *argv[]) {
    if (argc!=2) {
        printf("Ej:\n main path/to/file");
        return -1;
    }
    FILE *archivo = fopen(argv[1],"rb");
    const int_ len = fileLength(archivo);
    fclose(archivo);
    archivo = fopen(argv[1],"r");
    char *texto = (char*)malloc(sizeof(char)*len);
    char format[20];
    sprintf(format,"%%%lluc",len);
    fscanf(archivo,format,texto);
    printf("%s",texto);
    free(texto);
    fclose(archivo);
    return 0;
}

int_ fileLength(FILE *file){
    fseek(file,0,SEEK_END);
    int_ len = ftell(file)/sizeof(char);
    return len;
}