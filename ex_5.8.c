#include <stdio.h>
#include <math.h>
void task_a() {
    double x, eps, y, t;
    int i;
    printf("x = \n");
    scanf("%lf", &x);
    do {
        printf("eps = \n");
        scanf("%lf", &eps);
    } while(eps <= 0);
    i = 1.0;
    t = 1.0;
    y = t;
    while(t > eps) {
        t *= (x / i);
        i++;
        y += t;
    }
    printf("y = %lf, %lf\n", y, exp(x));
}

void task_b() {
    double x, eps, y, t;
    int i;
    printf("x = \n");
    scanf("%lf", &x);
    do {
        printf("eps = \n");
        scanf("%lf", &eps);
    } while(eps <= 0);
    i = 2;
    t = 1 * pow(x, 3)/ 3;
    y = x + y;
    while(fabs(t) > eps) {
        t *= (-1 * pow(x, 2))/ ((2*i + 1)*(2*i - 2));
        i++;
        y += t;
    }
    printf("y = %lf\n", y);
}

int main() {
    task_a();
    task_b();
}