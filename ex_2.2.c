#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter a  -\n");
    scanf("%d", &a);
    printf("Enter b  -\n");
    scanf("%d", &b);
    if (a > 0 && b > 0) {
        c = sqrt(a*a + b*b);
        printf("c = %d", c);
    }
    else {
        printf("Incorrect input");
    }
}