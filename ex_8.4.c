#include <stdio.h>

int main() {
    unsigned m, n;
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
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }
}