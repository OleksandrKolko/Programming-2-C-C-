#include <stdio.h>
#include <math.h>

int main() {
    float   v, u, r, a ,b ,c, d;
    printf("Enter values for v, u and r:\n");
    scanf("%f %f %f", &v, &u, &r);
    printf("Enter values for a, b and c:\n");
    scanf("%f %f %f", &a, &b, &c);

    d = abs(a*v + b*u + c) / sqrt(a*a + b*b);

    if (d < r) {
        printf("Two points of intersection");
    }
    else if (d == r) {
        printf("One point of intersection");
    }
    else if (d > r) {
        printf("Zero points of intersection");
    }
}