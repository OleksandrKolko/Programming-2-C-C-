#include <stdio.h>
#include <math.h>

int Fibonacci(int n) {
    int F, F0=0, F1=1;
    if (n == 0){
        return F0;
    }
    else if (n == 1) {
        return F1;
    }
    else if (n >= 2) {
        for (int i = 2; i <= n; i++) {
            F = F0 + F1;
            F0 = F1;
            F1 = F;
        }
        return F;
    }
}

int main() {
    int i, F, a;
    printf("Enter number a: \n");
    scanf("%d", &a);
    F = Fibonacci(i);
    for (i = 0; i < a; i++) {
        F = Fibonacci(i);
        if (F >= a) {
            i--;
            F = Fibonacci(i);
            break;
        }
    }
    printf("F(%d) = %d < %d", i, F, a);
}