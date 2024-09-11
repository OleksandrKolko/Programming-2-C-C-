#include <stdio.h>
#include <math.h>

double Rosenbrock2d(double x, double y) {
    double t1 = pow(x, 2) - y;
    double t2 = x - 1;
    double z = 100 * pow(t1, 2) + pow(t2, 2);
    return z;
}

int main() {
    printf("%lf\n", Rosenbrock2d(0, 1));
    printf("%lf\n", Rosenbrock2d(2, 4));
    printf("%lf\n", Rosenbrock2d(1, 0));
}