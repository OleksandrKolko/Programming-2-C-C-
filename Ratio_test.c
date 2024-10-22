#include "Ratio.h"
#include <stdio.h>

int main() {
    Ratio a, b, c;
    printf("Enter first fraction:\n");
    if (!input(&a)) {
        printf("Invalid input for the first fraction.\n");
        return 1;
    }
    printf("Enter second fraction:\n");
    if (!input(&b)) {
        printf("Invalid input for the second fraction.\n");
        return 1;
    }
    c = mull(a, b);
    reduce(&c);
    printf("Result of multiplication: ");
    output(c);
    printf("\n");
    return 0;
}