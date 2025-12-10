#include <stdio.h>
#include <math.h>

int main() {
    int operacion;
    double var1, var2,resultado;
    printf("Introduce el codigo de la la operacion a realizar suma(1), resta(2), producto(3), division(4), raiz cuadrada(5):\n");
    scanf("%d", &operacion);
    printf("Introduce el primer operando:");
    scanf("%lf", &var1);
    if (operacion<5) {
        printf("Introduce el segundo operando:");
        scanf("%lf", &var2);
    }
    switch (operacion) {
        case 1: {
            resultado = var1 + var2;
            printf("%lf + %lf = %lf\n", var1, var2, resultado);
            break;
        }
        case 2: {
            resultado = var1 - var2;
            printf("%lf - %lf = %lf\n", var1, var2, resultado);
            break;
        }
        case 3: {
            resultado = var1 * var2;
            printf("%lf * %lf = %lf\n", var1, var2, resultado);
            break;
        }
        case 4: {
            resultado =var1 / var2;
            printf("%lf / %lf = %lf\n", var1, var2, resultado);
            break;
        }
        case 5: {
            resultado=sqrt(var1);
            printf("sqrt(%lf) = %lf\n", var1, resultado);
            break;
        }
        default:
            printf("La opcion introducida no es valida.");
    }
    return 0;
}