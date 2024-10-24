#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Пункт e)

int is_perfect_square(int x) {
    int s = (int)sqrt(x);
    return (s * s == x);
}


int is_Fibonacchi(int n) {
    // Перевіряємо за формулою: 5n^2 + 4 або 5n^2 - 4 має бути квадратом
    return is_perfect_square(5 * n * n + 4) || is_perfect_square(5 * n * n - 4);
}


int write_file(char* file_name) {
    FILE* fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return -1;
    }
    int item;
    scanf("%d", &item);
    int k = 0;
    while(item != 0) {
        fwrite(&item, sizeof(item), 1, fp);
        k++;
        scanf("%d", &item);
    }
    fclose(fp);
    return k;
}


int file_read(char* file_name, int* arr) {
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return -1;
    }

    int k = 0;
    while(fread(&arr[k], sizeof(arr[k]), 1, fp)) {
        k++;
    }
    fclose(fp);
    return k;
}

int main() {
    char* file_name1 = "input.txt";
    char* file_name2 = "output.txt";


    int k = write_file(file_name1);

    FILE* fp1 = fopen(file_name1, "rb");
    FILE* fp2 = fopen(file_name2, "wb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    int item;
    int fib_count = 0;

    while(fread(&item, sizeof(item), 1, fp1)) {
        if (is_Fibonacchi(item)) {
            fwrite(&item, sizeof(item), 1, fp2);
            fib_count++;
        }
    }

    fclose(fp1);
    fclose(fp2);


    int* arr = (int*)malloc(sizeof(int) * fib_count);


    file_read(file_name2, arr);


    for(int i = 0; i < fib_count; i++) {
        printf("%d, ", arr[i]);
    }

    free(arr);

    return 0;
}
