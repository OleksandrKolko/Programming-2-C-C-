#include <stdio.h>
#include <math.h>

int main() {
    double x, y, power = 1;
    unsigned n, i;
    scanf("%lf %u", &x, &n);
    y = 0;
    for (i = 1; i <= n; i++) {
        power *= x;
        y += power * i;
    }
    printf("y = %lf", y);
}