#include <stdio.h>
#include <math.h>
double task_a(unsigned int n) {
    double P = 1, P_k, a_k = 1;
    for(int i = 1; i<= n; i++) {
        a_k /= i;
        P_k = P * (1 + a_k);
        P = P_k;
    }
    return P_k;
}
double task_b(unsigned int n) {
    double P = 1, P_k, a_k = 1;
    for(int i = 1; i<= n; i++) {
        a_k = (pow(-1, i + 1) * pow(i, 2))/ pow(2, i);
        P_k = P * (1 + a_k);
        P = P_k;
    }
    return P_k;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    double res1, res2;
    res1 = task_a(n);
    res2 = task_b(n);
    printf("Result for a = %.2lf\n", res1);
    printf("Result for b = %.2lf\n", res2);
}