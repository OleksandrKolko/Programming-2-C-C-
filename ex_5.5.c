#include <stdio.h>
#include <math.h>

int main() {
    int x1 = -99, x2 = -99, x3 = -99, x;
    int i = 3;
    while (x < 0) {
        x = x3 + x1 + 100;
        x1 = x2;
        x2 = x3;
        x3 = x;
        i++;
    }
    printf("x(%d) = %d", i, x);
}