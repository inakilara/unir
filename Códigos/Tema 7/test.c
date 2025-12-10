#include<stdio.h>

struct ficha {
    int balance;
    char nombre[80];
};

int main(){
    struct ficha *pficha,ficha;
    pficha=&ficha;
    printf("Introduce el valor:\n");
    printf("%d",pficha->balance);
    return 0;
}
