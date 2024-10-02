#include <stdio.h>
#include <math.h>

int main() {
    int matrix[3][3] = {{1, 1, 1}, {4, 5 ,6}, {7, 8, 9}};
    unsigned int N, M;
    printf("Enter the number N and M:\n");
    scanf("%d %d", &N, &M);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (matrix[i][j] == M) {
                matrix[i][j] = N;
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}