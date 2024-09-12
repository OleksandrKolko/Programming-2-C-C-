#include <stdio.h>
#include <math.h>

int main() {
    int c, f, r, z, d;
    double x;
    printf("x = \n");
    scanf("%fl", &x);
    c = ceil(x);
    f = floor(x);
    r = round(x);
    z = (int)x;
    d = fabs(x-z);
    printf("c = %d, f = %d, r = %d, z = %d, d = %d", c ,f, r, z, d);
}