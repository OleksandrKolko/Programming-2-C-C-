#include <stdio.h>
#include <math.h>

Пункт б)
double func_b(double x) {
    double x_2 = x * x;
    double op1 = x_2 + x;
    double op2 = x_2 * (x_2 + x);
    double y = op1 + op2 + 1;
    return y;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf'\n", func_b(x));
}
