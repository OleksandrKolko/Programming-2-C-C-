#include <stdio.h>
#include <math.h>

float maximum(float a, float b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}
float minimum(float a, float b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {
    float a, b, c, max, min;
    printf("a = \n");
    scanf("%f", &a);
    printf("b = \n");
    scanf("%f", &b);
    printf("c = \n");
    scanf("%f", &c);

    a = abs(a);
    b = abs(b);
    c = abs(c);
    max = maximum(maximum(a, b), c);
    min = minimum(minimum(a, b), c);
    printf("max = %.2f\nmin = %.2f", max, min);
}