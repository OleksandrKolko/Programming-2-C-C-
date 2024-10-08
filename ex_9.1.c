#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double input_array(const double* arr, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }
}

double sum_sqrt(const double* arr, int n) {
    double sum = 0;
    double* beg = arr;
    double* end = arr + n;
    for (beg <= end; beg++;) {
        double n_arr = *beg;
        sum += pow(n_arr, 2);
    }
    return sum;
}

int main() {
    unsigned n;
    printf("Enter n: \n");
    scanf("%lf", &n);

    double* arr;
    arr = (double*)malloc(n * sizeof(*arr));
    input_array(arr, n);
    double res = sum_sqrt(arr, n);
    printf("%lf\n", res);
    free(arr);
}
