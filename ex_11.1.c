#include <stdio.h>
#include <stdlib.h>

int read_file(const char *file_name, double *arr) {
    FILE * fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return -1;
    }
    double item;
    int k = 0;
    while(!feof(fp)) {
        int res = fread(&item, sizeof(item), 1, fp);
        if(res != 1) {
            break;
        }
        arr[k++] = item;
    }
    fclose(fp);
    return k;
}

int write_file(const char *file_name, double *arr, int n) {
    FILE * fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return -1;
    }
    int res = fwrite(arr, sizeof(*arr), n, fp);
    fclose(fp);
    return res;
}

int main() {
    char file_name[50] = "test.txt";
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    double* arr1 = (double*)malloc(sizeof(double) * n);
    for(int i = 0; i < n; i++) {
        printf("Enter arr[%d]: \n", i);
        scanf("%lf", &arr1[i]);
    }
    write_file(file_name, arr1, n);
    free(arr1);

    double* arr2 = (double*)malloc(sizeof(double) * n);
    int k = read_file(file_name, arr2);

    for (int i = 0; i < k; i++) {
        printf("%.0lf, ", arr2[i]);
    }
    free(arr2);
}