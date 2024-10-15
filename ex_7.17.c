#include<stdio.h>
#define N 10
#define EPS 1e-6

double arithmetic_mean(double arr[N - 2]) {
    double sum = 0;
    for(int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum / (N - 2);
}

int main() {
    double arr[N], new_arr[N - 2];
    for(int i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
    }
    double max, min;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            max = min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int first_max = 1, first_min = 1, j = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] == max && first_max) {
            first_max = 0;
            continue;
        }
        if(arr[i] == min && first_min) {
            first_min = 0;
            continue;
        }
        new_arr[j] = arr[i];
        j++;
    }
    for(int i = 0; i < (N - 2); i++) {
        printf("%.0lf ", new_arr[i]);
    }
    double result = arithmetic_mean(new_arr);
    printf("\nGrade = %.2lf\n", result);
}