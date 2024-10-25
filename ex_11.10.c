#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef struct TPair {
    unsigned key;
    char data[10];
} TPair;

int write_file(char* file_name, TPair* pairs, int size) {
    FILE* fp = fopen(file_name, "wb");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return -1;
    }
    int k = fwrite(pairs, sizeof(TPair), size, fp);
    fclose(fp);
    return k;
}

int read_file(char* file_name, TPair* pairs) {
    FILE* fp = fopen(file_name, "rb");
    if (!fp) {
        printf("Error opening file for reading.\n");
        return -1;
    }
    int i = 0;
    while (fread(&pairs[i], sizeof(TPair), 1, fp) == 1) {
        i++;
    }
    fclose(fp);
    return i;
}

int find_by_key(char* file_name, TPair* pairs, TPair* need_pairs, unsigned index) {
    int k = read_file(file_name, pairs);
    int n = 0;

    for (int i = 0; i < k; i++) {
        if (pairs[i].key == index) {
            need_pairs[n] = pairs[i];
            n++;
        }
    }
    return n;
}

int del_by_key(char* file_name, TPair* pairs, TPair* need_pairs, unsigned index) {
    int k = read_file(file_name, pairs);
    int n = 0;

    for (int i = 0; i < k; i++) {
        if (pairs[i].key != index) {
            need_pairs[n] = pairs[i];
            n++;
        }
    }
    return n;
}

int main() {
    int size = 5;
    char* file_name = "test.txt";

    TPair pairs[] = {
        {1, "AAA"},
        {2, "BBB"},
        {2, "KKK"},
        {3, "CCC"},
        {4, "DDD"}
    };
    write_file(file_name, pairs, size);

    TPair pairs_2[MAX_SIZE];
    TPair pairs_3[MAX_SIZE];

    int k = read_file(file_name, pairs_2);

    int n = del_by_key(file_name, pairs_2, pairs_3, 2);

    printf("Remaining pairs after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("key = %u, data = %s\n", pairs_3[i].key, pairs_3[i].data);
    }
}