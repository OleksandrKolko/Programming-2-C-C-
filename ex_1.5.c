#include <stdio.h>

int main() {
    int x, x_2, x_4;
    scanf("%d", &x);
    x_2 = x*x;
    x_4 = x_2 * x_2;
    x_4 =  x_4 * x_2;
    printf("%d\n", x_4);
}