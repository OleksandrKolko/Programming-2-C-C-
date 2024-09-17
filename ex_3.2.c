#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main() {
    int a, b, c, res, rev_num;
    unsigned number;
    printf("n = \n");
    scanf("%u", &number);
    if (number >= 100 && number <= 999) {
        a = number % 10;
        b = (number / 10) % 10;
        c = number / 100;
    }
    if (a != b && a != c && a != b) {

        printf("%d%d%d\n", a, b, c);
        printf("%d%d%d\n", a, c, b);
        printf("%d%d%d\n", b, a, c);
        printf("%d%d%d\n", b, c, a);
        printf("%d%d%d\n", c, b, a);
        printf("%d%d%d\n", c, a, b);
    }
}