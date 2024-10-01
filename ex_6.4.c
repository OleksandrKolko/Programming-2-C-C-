#include <stdio.h>
#include <math.h>

int main() {
    unsigned n, b1, b2, b3, b4, m;
    scanf("%u", &n);
    b1 = n&0xFF;
    b2 = (n>>8)&0xFF;
    b3 = (n>>16)&0xFF;
    b4 = n>>24;
    m = (b1 << 24) | (b3 << 16) | (b2 << 8) | b4;
    printf("%u", m);
}
