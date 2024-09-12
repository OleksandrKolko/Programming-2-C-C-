#include <stdio.h>
#include <math.h>

int main() {
    float num1 = pow(10,-4);
    double num2 = 24.33e5;
    double num3 = M_PI;
    long double num4 = M_E;
    long double num5 = pow(5, 0.5);
    long double num6 = log(100);

    printf("%.4f\n", num1);
    printf("%.2f\n", num2);
    printf("%.2f\n", num3);
    printf("%.2f\n", num4);
    printf("%.2lf\n", num5);
    printf("%.2lf\n", num6);

}