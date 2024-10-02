#include <stdio.h>
#include <math.h>

int main() {
    unsigned m, n;
    printf("Enter m and n : \n");
    scanf("%u %u", &m, &n);
    double matrix[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: \n", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }
}