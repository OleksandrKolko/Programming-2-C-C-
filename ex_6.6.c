#include <stdio.h>
#include <math.h>
int divisor2(unsigned n) {
    int k = 1;
    while (n % k == 0) {
        k *= 2;
    }
    return k;
}


int main() {
    unsigned y_1, y_2, n;
    // for (unsigned i = 0; i < 1 << 32 - 1; ++i) {
    //     if (!((i & (i - 1)))) {
    //         // припускаємо, що індекси степенів 2 будуть false
    //         printf("%u\t", i);
    //     }
    // }
    // printf("\n");
    for (unsigned i = 0; i < 1 << 32 - 1; ++i) {
        if (divisor2(i) != (-i) & i) {
            printf("%u not work", i);
        }
    }
}
