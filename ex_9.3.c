#include <stdio.h>
#include <stdlib.h>

double* input_vec(int n){
    double* vec = (double*) calloc(n, sizeof(*vec));
    for(int i = 0 ; i < n; i++){
        printf("a[%d]=",i);
        scanf("%lf",&vec[i]);
    }
    return vec;
}

void delete_vec(double *arr) {
    if(arr){free(arr);}
}

double* sub_vec(const double* vec1,const double* vec2, int n){

    double* vec3 = (double*)calloc(n,sizeof(*vec3));
    for(int i = 0; i < n ;i++) {
        vec3[i] = vec1[i]- vec2[i];
    }
    return vec3;
}
void output_vec(const double *arr, size_t n) {
    for(size_t i = 0; i < n; i++) {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}


int main() {
    size_t n;
    double *vec1, *vec2, *vec3;
    printf("Enter n: \n");
    scanf("%zu", &n);
    vec1 = input_vec(n);
    output_vec(vec1, n);
    vec2 = input_vec(n);
    output_vec(vec2, n);
    vec3 = sub_vec(vec1, vec2, n);
    output_vec(vec3, n);
    delete_vec(vec1);
    delete_vec(vec2);
    delete_vec(vec3);
}