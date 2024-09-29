#include <stdio.h>
#include <math.h>
#include <float.h>
#define EPSILON 0.000001


int main() {
    int i = 0;
    double sum = 0, x;
    double eps = 2 * DBL_EPSILON;
    do {
        printf("a[%d] =", i);
        scanf("%lf", &x);
        sum += x;
    }while (fabs(x) > eps);
}