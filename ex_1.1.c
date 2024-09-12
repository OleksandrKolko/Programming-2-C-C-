#include <stdio.h>

int main() {
    float res1, res2, res3, res4, res5, res6;
    res1 = 2 + 31;
    printf("2 + 31 = %.2f\n", res1);

    res2 = (45*54)-11;
    printf("(45*54)-11 = %.2f\n", res2);

    res3 = 15/4;
    printf("15/4 = %.2f\n", res3);

    res4 = 15/0.4;
    printf("15/0.4 = %f\n", res4);

    res5 = 67%5;
    printf("67%5 = %.2f\n", res5);

    res6 = (2 * 45.1 + 3.2)/2;
    printf("2 * 45.1 + 3.2 = %2.f\n", res6);
}