#include <stdio.h>

int main() {
    float a, b;
    printf("Enter value of a and b: ");
    scanf("%f %f", &a, &b);

    float avg = (a + b) / 2;
    printf("avg exp = %.2e\n", avg);
    printf("avg = %.2f\n", avg);

    float harmonic = 2 / ((1 / a) + (1 / b));
    printf("harmonic exp = %.2e\n", harmonic);
    printf("harmonic = %.2f\n", harmonic);
}
