#include <stdio.h>
#include <math.h>

int main() {
    unsigned int n, i;
    double res = 0;
    printf("n = \n");
    scanf("%u", &n);

    for (i = 1; i <= n; i++) {
        res += sqrt(2 + res);
    }
    printf("%lf", res);
}