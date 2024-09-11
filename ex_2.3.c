#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, p, S;
    printf("Enter a  -\n");
    scanf("%f", &a);
    printf("Enter b  -\n");
    scanf("%f", &b);
    printf("Enter c  -\n");
    scanf("%f", &c);
    p = (a + b + c) / 2;
    S = sqrt(p * (p  - a) * (p - b)  * (p - c));
    printf("S = %f", S);
}
