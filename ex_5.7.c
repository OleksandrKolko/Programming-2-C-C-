#include <stdio.h>
#include <math.h>

int main() {
    double n, k, i, a1 = 0, a2 = 1, b1 = 1, b2 = 0, ak, bk, S = 6;
    scanf("%lf", &n);
    if (n == 1) {
        printf("2");
    }
    else if (n == 2) {
        printf("6");
    }
    else {
        double pow_2 = 2;
        for (i = 3; i <= n; i++) {
            bk = a2 + b2;
            b1 = b2;
            b2 = bk;
            ak = (a2 / i) + (a1 * bk);
            a1 = a2;
            a2 = ak;
            pow_2 *= 2;
            S += pow_2 / (ak + bk);
        }
    }
    printf("S = %lf", S);
}