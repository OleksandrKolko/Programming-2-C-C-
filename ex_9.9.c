#include <stdio.h>
#include <stdlib.h>
// Пункт m)

void delete_matrix(double **matr, int n) {
    if (matr == NULL) return;
    for (int i = 0; i < n; i++) {
        free(matr[i]);
    }
    free(matr);
}

double** input_matrix(int n, int m) {
    double** matr = (double**) calloc(n, sizeof(double*));
    for (int i = 0; i < n; i++) {
        matr[i] = (double*) calloc(m, sizeof(double));
        for (int j = 0; j < m; j++) {
            printf("a[%d, %d] = ", i, j);
            scanf("%lf", &matr[i][j]);
        }
    }
    return matr;
}

void output_matrix(double **matr, int n, int m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            printf("%.0lf ", matr[i][j]);
        }
        printf("\n");
    }
}

double** remove_columns(double **matrix, int n, int m, int k, int t) {
    int new_m = m - (t - k + 1);
    double** new_matrix = (double**) calloc(n, sizeof(double*));

    for (int i = 0; i < n; i++) {
        new_matrix[i] = (double*) calloc(new_m, sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        int new_col = 0;
        for (int j = 0; j < m; j++) {
            if (j < k || j > t) {
                new_matrix[i][new_col++] = matrix[i][j];
            }
        }
    }
    return new_matrix;
}

int main() {
    int n, m, k, t;
    printf("Enter the number of rows (n) and columns (m): \n");
    scanf("%d %d", &n, &m);
    printf("Enter the start (k) and end (t) columns to remove (0-indexed): \n");
    scanf("%d %d", &k, &t);

    if (k < 0 || t >= m || k > t) {
        printf("Invalid range for columns!\n");
        return 1;
    }

    double** matrix = input_matrix(n, m);
    printf("\nOriginal matrix:\n");
    output_matrix(matrix, n, m);


    double** new_matrix = remove_columns(matrix, n, m, k, t);
    int new_m = m - (t - k + 1);

    printf("\nMatrix after removing columns %d to %d:\n", k, t);
    output_matrix(new_matrix, n, new_m);

    delete_matrix(matrix, n);
    delete_matrix(new_matrix, n);
}
