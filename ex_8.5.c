#include <stdio.h>
#define N 3
#define M 3

void transpose(double matrix1[N][M], double matrix2[N][M]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            matrix2[i][j] = matrix1[j][i];
        }
    }
}

int main() {
    double matrix1[N][M] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, matrix2[N][M];
    transpose(matrix1, matrix2);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%.0lf ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%.0lf ", matrix2[i][j]);
        }
        printf("\n");
    }
}