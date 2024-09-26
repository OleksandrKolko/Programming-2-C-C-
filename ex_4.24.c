#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long n;
    unsigned long long p;
    unsigned long long res = 0;
    unsigned long long i = 0;
    printf("Enter n: \n");
    scanf("%llu", &n);

    while (n) {
        p = n % 10;
        if (p == 0 || p == 5) {
            n /= 10;
        }
        else {
            res += p * pow(10, i);
            i++;
            n /= 10;
        }
    }
    printf("Result: %llu",res);
}