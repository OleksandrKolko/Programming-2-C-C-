#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("!0 = 1");
        return 0;
    }
    else if (n == 1) {
        printf("!1 = 0");
        return 0;
    }

    unsigned long long perv1 = 1;
    unsigned long long perv2 = 0;
    unsigned long long result = 0;

    for (int i = 2; i <= n; i++) {
        result = (i - 1)*(perv2 + perv1);
        perv1 = perv2;
        perv2 = result;
    }
    printf("!%d = %llu", n, result);
}