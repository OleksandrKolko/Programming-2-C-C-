#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x;
    scanf("%d %lf", &n, &x);
    if (n == 0) {
        printf("Result = 1");
        return 0;
    }
    double res = 1;
    double app = 1;
    for (int i = 1; i <= n; i++) {
        app *= (x / i);
        res += app;
    }
    printf("Result = %.3lf", res);
}