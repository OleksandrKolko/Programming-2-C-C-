#include <stdio.h>
#include <math.h>

int main() {
    unsigned m, n;
    int k;
    double sum = 0.0;
    printf("Enter number (i - j) = k: \n");
    scanf("%d", &k);
    printf("Enter m and n : \n");
    scanf("%u %u", &m, &n);
    double matrix[m][n];
    for(int i = 0; i < m; i++) {
        printf("matrix[%d]: \n", i);
        for(int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if ((i - j) == k) {
                sum += matrix[i][j];
            }
        }
    }
    printf("The sum is: %.2lf\n", sum);
}