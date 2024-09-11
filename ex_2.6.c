#include <stdio.h>
#include <math.h>

double length(double x_1, double y_1, double x_2, double y_2) {
    return sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
}

double area(double A, double B, double C) {
    double p = (A + B + C) / 2;
    double S = sqrt(p * (p  - A) * (p - B)  * (p - C));
    return S;
}

int main() {
    double x_a, y_a, x_b, y_b, x_c, y_c;
    printf("Enter cordinates for A:\n");
    scanf("%lf %lf", &x_a, &y_a);
    printf("Enter cordinates for B:\n");
    scanf("%lf %lf", &x_b, &y_b);
    printf("Enter cordinates for C:\n");
    scanf("%lf %lf", &x_c, &y_c);

    double A = length(x_a, y_a, x_b, y_b);
    double B = length(x_b, y_b, x_c, y_c);
    double C = length(x_c, y_c, x_a, y_c);

    double S = area(A, B ,C);
    printf("Area = %lf", S);
}