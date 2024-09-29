#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    double result = 0;
    scanf("%lf %lf", &x, &y);
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        result = result + (pow(x, pow(2, n - i)) * pow(y, n - i));
    }
   printf("result = %lf", result);
}