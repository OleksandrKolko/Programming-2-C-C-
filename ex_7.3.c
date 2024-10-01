#include <stdio.h>
#include <math.h>
#define N 10
double func(double mas[N]) {
    double sum = 0;
    for(int i = 0; i < N; i++) {
        if (mas[i] > M_E) {
            sum += mas[i];
        }
    }
    return sum;
}

int main() {
    double p;
    double mas[N] = {};
    for(int i = 0; i < N; i++) {
        scanf("%lf", &p);
        mas[i] = p;
    }
    double res = func(mas);
    printf("Summ = %.2lf", res);
}