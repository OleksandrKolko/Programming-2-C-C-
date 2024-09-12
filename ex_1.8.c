#include <stdio.h>

int main() {
    float num1, num2;
    printf("Enter number1: ");
    scanf("%f", &num1);
    printf("Enter number2: ");
    scanf("%f", &num2);

    float sub = num1 - num2;
    float mul = num1 * num2;

    printf("Subtraction = %.2f\n", sub);
    printf("Multiplication = %.2f", mul);
}
