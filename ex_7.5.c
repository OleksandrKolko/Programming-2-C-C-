#include <stdio.h>
#include <math.h>

int main() {
    int p, n;
    scanf("%d", &n);
    int mas[n] = {};
    for(int i = 0; i < n; i++) {
        scanf("%d", &p);
        mas[i] = p;
    }
    int odd = 0, coup = 0;
    for(int i = 0; i < n; i++) {
        if (mas[i] % 2 == 0) {
            coup++;
        }
        else {
            odd++;
        }
    }
    printf("Coup = %d\nOdd = %d", coup, odd);
}