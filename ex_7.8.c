#include <stdio.h>
#include <math.h>
#define N  10
#define EPS 0.000001

//Пункт в)
int is_integer(double num) {
    return fabs(num - round(num)) < 1e-9;
}

double nth_root(double x, int n) {
    return pow(x, 1.0 / n);
}

int main() {
    unsigned mas[N];
    int n, count = 0;
    for(int i = 0; i < N; i++) {
        scanf("%u", &mas[i]);
    }

    printf("Enter n: \n");
    scanf("%d", &n);

    for(int i = 0; i < N; i++) {
        if (is_integer(nth_root(mas[i], n))) {
            count++;
        }
    }
    printf("Count = %d\n", count);
}