#include <stdio.h>
#include <stdlib.h>

void output_matr(const double **matr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%lf ", matr[i][j]);
        }
        printf("\n");
    }
}

double** input_matrix(int n) {
    double** matr = (double**) calloc(n, sizeof(double*));
    for (int i = 0; i < n; i++) {
        matr[i] = (double*) calloc(n, sizeof(double));
        for (int j = 0; j < n; j++) {
            printf("a[%d, %d] = ", i, j);
            scanf("%lf", &matr[i][j]);
        }
    }
    return matr;
}

void delete_matr(double **matr, int n) {
    if (matr == NULL) return;
    for (int i = 0; i < n; i++) {
        free(matr[i]);
    }
    free(matr);
}

double** mult_matrix(const double **matr1, const double **matr2, int n) {
    double** matr3 = (double**) calloc(n, sizeof(double*));
    for (int i = 0; i < n; i++) {
        matr3[i] = (double*) calloc(n, sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matr3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matr3[i][j] += matr1[i][k] * matr2[k][j];
            }
        }
    }
    return matr3;
}

int main() {
    size_t n;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%zu", &n);

    double** matr1 = input_matrix(n);
    double** matr2 = input_matrix(n);

    double** matr3 = mult_matrix((const double**)matr1, (const double**)matr2, n);

    printf("Result of multiplication:\n");
    output_matr((const double**)matr3, n);

    delete_matr(matr1, n);
    delete_matr(matr2, n);
    delete_matr(matr3, n);
}
