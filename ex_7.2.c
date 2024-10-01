#include <stdio.h>
#include <math.h>

int main() {
    int mas[] = {5, 112, 4, 3};
    int n = sizeof(mas) / sizeof(mas[0]);
    for (int i = n - 1; i >= 0 ; i--) {
        printf("mas[%d] = %d\n", i, mas[i]);
    }
}
