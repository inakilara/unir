//

//

#include <stdio.h>
#include <math.h>

typedef struct {
    double Ax;
    double Ay;
    double Az;
}vector;

double modulo(vector v);

int main() {
    vector vector1;
    printf("Introduzca el valor de Ax:");
    scanf(" %lf%*c",&vector1.Ax);
    printf("\nIntroduzca el valor de Ay:");
    scanf(" %lf%*c",&vector1.Ay);
    printf("\nIntroduzca el valor de Az:");
    scanf(" %lf%*c",&vector1.Az);
    printf("El modulo de A es: %lf",modulo(vector1));


}

double modulo(vector v) {
    return sqrt(v.Ax*v.Ax+v.Ay*v.Ay+v.Az*v.Az);
}