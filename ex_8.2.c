#include <stdio.h>
#include <math.h>

int main() {
    double matrix[3][3] = {{1, 1, 1}, {4, 5 ,6}, {7, 8, 9}};
    int i, j;
    double a;
    printf("Enter i and j: \n");
    scanf("%d %d", &i, &j);
    if(i >= 3 || j >= 3) {
        printf("Index out of range!");
        return 0;
    }
    printf("Enter a: \n");
    scanf("%lf", &a);
    matrix[i][j] = a;
    for(int m = 0; m < 3; m++) {
        for(int k = 0; k < 3; k++) {
            printf("%.0lf ", matrix[m][k]);
        }
        printf("\n");
    }
}