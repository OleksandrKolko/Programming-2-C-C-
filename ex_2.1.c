#include <stdio.h>
#include <math.h>

int main() {
    int a, res;
    printf("Enter the number: ");
    scanf("%d", &a);
    res = cos(a);
    printf("Cos(%d) = %d", a, res);
}
