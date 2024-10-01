#include <stdio.h>
#include <math.h>

int main() {
    double F0 = 2, F1 = 1, F2 = 2, F;
    int n;
    scanf("%d", &n);
    if (n % 2 != 0) {
        printf("%d is not an even number\n", n);
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        F = F1 + 1.0 / F0;
        F0 = F;
        F1 = F2;
    }
    printf("Result x(%d) = %.2lf", n, F);
}