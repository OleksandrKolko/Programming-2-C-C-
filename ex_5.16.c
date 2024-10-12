#include <stdio.h>
#include <math.h>
#define EPS 0.0000001

// Пункт е)
int main() {
    double x;
    printf("Enter x (|x| < 1): \n");
    scanf("%lf", &x);
    if (fabs(x) > 1) {
        printf("Wrong input!");
        return 0;
    }
    double log_e = log(1 + x);
    double res = 0 , a = x, i = 2;
    while (fabs(a) >  EPS) {
        res += a;
        a *= (x/i) * (-1);
        i++;
    }
    printf("Res = %lf\nLn(1 + %.2lf) = %lf", res, x, log_e);
}