#include <stdio.h>
#include <math.h>

int main() {
    unsigned char n;
    scanf("%llu", n);
    unsigned long long m = 1 << n;
    printf("%llu", m);
}
