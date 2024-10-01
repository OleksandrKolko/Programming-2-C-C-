#include <stdio.h>
#include <math.h>
#define EPS 0.000001

unsigned int sequence(int n) {
    unsigned int a_n = n;
    unsigned int i = 0;
    while (a_n - 1 > EPS) {
        if (a_n % 2 == 0) {
            a_n = a_n / 2;
        }
        else {
            a_n = (a_n * 3) + 1;
        }
        i++;
    }
    printf("Count of iterations for %u = %u, a(%u)= %u\n", n, i, i, a_n);
    return i;
}

int main() {
    for(int i = 1; i < 1000; i++) {
        sequence(i);
    }
}