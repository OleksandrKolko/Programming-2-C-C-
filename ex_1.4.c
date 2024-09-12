#include <stdio.h>

int main() {
    double m1, m2, r, F;
    double l = 6.673e-11;
    scanf("%lf %lf %lf", &m1, &m2, &r);

    F = l*((m1*m2)/(r*r));
    printf("%e", F);
}