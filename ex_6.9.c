#include <stdio.h>
#include <math.h>

int oldest_non_zero(unsigned int n) {
    int index = 0, i = 0;
    while (n > 0) {
        if (n & 1) {
            index = i;
        }
        i++;
        n >>= 1;
    }
    return index;
}

int oldest_zero(unsigned int n) {
    int index = -1;
    unsigned int m = n;
    int end = oldest_non_zero(m);
    for(int i = 0; i < end; i++) {
        if (!(n & 1)) {
            index = i;
        }
        n >>= 1;
    }
    return index;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    printf("Numder of oldest non-zero = %d\n", oldest_non_zero(n));
    printf("Number of oldest zero = %d\n", oldest_zero(n));
}