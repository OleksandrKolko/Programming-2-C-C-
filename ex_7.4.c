#include <stdio.h>
#include <math.h>
#define N 5

int main() {
    int p;
    int mas[N] = {};
    for(int i = 0; i < N; i++) {
        scanf("%d", &p);
        mas[i] = p;
    }
    int max = 0;

    for(int i = 0; i < N; i++) {
        if (i == 0) {
            max = mas[i];
        }
        else {
            if(mas[i] > max) {
                max = mas[i];
            }
        }
    }
    printf("max = %.0d", max);
}