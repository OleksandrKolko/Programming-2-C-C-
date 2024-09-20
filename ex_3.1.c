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
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    res = a + b + c;
    printf("a + b + c = %d\n", res);
    rev_num = 100*a + b*10 + c;
    printf("rev_num = %d\n", rev_num);
}