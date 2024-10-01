#include <stdio.h>
#include <math.h>

int input_vector(double vec[], int n) {
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%lf", &vec[i]);
    }

}

void print_vector( int n ,double vec[n]) {
    for(int i = 0; i < n; i++) {
        if (i == 0) {
            printf("{%.0lf, ", vec[i]);
        }
        else if (i == (n - 1)) {
            printf(" %.0lf}\n", vec[i]);
        }
        else {
            printf("%.0lf, ", vec[i]);
        }
    }
}

void sum(int n, const double vec1[n], const double vec2[n], double vec3[]) {
    for(int i = 0; i < n; i++) {
        vec3[i] = vec1[i] + vec2[i];
    }
}

double scalar_product(int n, const double vec1[], const double vec2[]) {
    double result = 0;
    for(int i = 0; i < n; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

int main() {
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    double vec1[n], vec2[n], vec3[n];
    input_vector(vec1, n);
    input_vector(vec2, n);
    printf("Vector 1 = ");
    print_vector(n, vec1);
    printf("Vector 2 = ");
    print_vector(n, vec2);
    sum(n, vec1, vec2, vec3);
    printf("Sum of vector 1 and vector 2 = ");
    print_vector(n, vec3);
    double scalar = scalar_product(n, vec1, vec2);
    printf("Scalar product = %.2lf", scalar);
}