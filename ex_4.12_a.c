#include <stdio.h>
#include <math.h>

int main() {
    double x;
    int n;
    printf("Enter x: \n");
    scanf("%lf", &x);
    printf("Enter n: \n");
    scanf("%d", &n);

    double sum = 1;
    for (int i = 1; i <= n; i++) {
        sum += pow(x, pow(2, i));
    }
    printf("Result = %.2lf", sum);
}