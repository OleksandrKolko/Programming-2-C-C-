#include <stdio.h>
#include <math.h>

int main() {
    double a = 1;
    while ((1 + a) != 1) {
        a /= 2;
    }
    printf("Machine zero = %.20lf", a);
}