#include <stdio.h>
#include <math.h>

int main() {
    long  a, b, c;
    scanf("%ld, %ld", &a, &b);
    if (abs(a) < 2e10 && abs(b) < 2e10) {
        c = a * b;
        printf("%ld", c);
    }
    else {
        printf("False");
    }
}