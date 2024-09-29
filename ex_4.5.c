#include <stdio.h>
#include <math.h>

int main() {
    int n, res = 1;
    scanf("%d", &n);
    if (n % 2 == 0) {
        for (int i = 2; i <=n; i+= 2) {
            res *= i;
        }
    }
    else {
        for (int i = 1; i <=n; i+= 2) {
            res *= i;
        }
    }
    printf("n! = %d", res);
}