#include <stdio.h>
#include <math.h>

int main() {
    int m;
    printf("Enter m:\n");
    scanf("%d", &m);
    int k = 0;
    while (pow(4, k + 1) <= m) {
        k += 1;
    }
    printf("4^%d <= %d", k, m);
}