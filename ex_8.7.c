#include <stdio.h>
#include <math.h>

void row_sum(int m, double row1[m], double row2[m], double a) {
    for(int i = 0; i < m; i++) {
        row2[i] += row1[i] * a;
    }
}

void Gauss_method(int m, double matrix[m][m]) {
    for(int i = 1; i < m; i++) {
        for(int j = i; j < m; j++) {
            row_sum(m, matrix[i - 1], matrix[j], (-1) * matrix[j][i-1]/matrix[i-1][i-1]);
        }
    }
}

double Determinant(int m, double matrix[m][m]) {
    double det = 1;
    Gauss_method(m, matrix);
    for(int i = 0; i < m; i++) {
        det *= matrix[i][i];
    }
    return det;
}


int main() {
    unsigned m;
    printf("Enter m: \n");
    scanf("%u", &m);
    double matrix[m][m];
    for(int i = 0; i < m; i++) {
        printf("matrix[%d]: \n", i);
        for(int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    double det = Determinant(m, matrix);
    printf("Determinant = %.2lf", det);
}