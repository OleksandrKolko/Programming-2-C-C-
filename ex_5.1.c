#include <stdio.h>
#include <math.h>

int main() {
    int n = 1;
    float a;
    scanf("%f", &a);
    float num = 1 / n;
    if (a < num) {
        printf("num = %.3f", num);
        return 0;
    }
    while (a > num) {
        n++;
        num += (1.0/n);
        printf("Number = %.3f\n", num);
    }
    printf("Number = %.3f", num);
}