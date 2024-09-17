#include <stdio.h>
#include <math.h>
#include <stdint.h>

uint16_t mult(uint8_t x, uint8_t y) {
    uint16_t z = (x * y);
    return z;
}

int main() {
    uint8_t x, y;
    uint16_t z;
    printf("x y:\n");
    scanf("%hhu %hhu", &x, &y);
    z = mult(x, y);
    printf("z = %hu", z);
}