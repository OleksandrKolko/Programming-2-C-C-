#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    int r = 0;
    while (pow(2, r) <= n) {
        r += 1;
    }
    printf("2^%d(%.0f) > %d", r, pow(2, r), n);
}