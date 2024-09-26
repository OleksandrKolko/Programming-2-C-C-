#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x;
    printf("x = \n");
    scanf("%f", &x);
    printf("n = \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        x = sin(x);
        printf("%f\n", x);
    }
    printf("result = %f", x);
}