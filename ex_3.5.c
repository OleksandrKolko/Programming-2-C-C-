#include <stdio.h>
#include <math.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) {
        printf("max = %d\n", x);
        printf("min = %d\n", y);
    }
    else if ( x < y) {
        printf("max = %d\n", y);
        printf("min = %d\n", x);
    }
}