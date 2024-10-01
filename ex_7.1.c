#include <stdio.h>
#include <math.h>
#define N 5

int main() {
    int mas[N] =  {1, 2, 3, 4, 5};
    double a;
    scanf("%lf", &a);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if(mas[i] < a) {
            cnt ++;
        }
    printf("k = %d", cnt);
    }
}
