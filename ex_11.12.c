#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct Toy {
    char name[30];
    float price;
    int age_limit;
} Toy;

int write_file(const char* file_name, Toy* toys, int size) {
    FILE* fp = fopen(file_name, "wb");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return -1;
    }
    int k = fwrite(toys, sizeof(Toy), size, fp);
    fclose(fp);
    return k;
}

int read_file(const char* file_name, Toy* toys) {
    FILE* fp = fopen(file_name, "rb");
    if (!fp) {
        printf("Error opening file for reading.\n");
        return -1;
    }
    int i = 0;
    while (fread(&toys[i], sizeof(Toy), 1, fp) == 1) {
        i++;
    }
    fclose(fp);
    return i;
}

int find_by_name(const char* file_name, Toy* toys, Toy* found_toys, const char* toy_name) {
    int k = read_file(file_name, toys);
    int n = 0;

    for (int i = 0; i < k; i++) {
        if (strcmp(toys[i].name, toy_name) == 0) {
            found_toys[n] = toys[i];
            n++;
        }
    }
    return n;
}

int main() {
    int size = 5;
    char* file_name = "toys.txt";

    Toy toys[] = {
        {"AAA", 300.0, 3},
        {"AAA", 250.0, 5},
        {"DDD", 450.0, 6},
        {"DDD", 200.0, 2},
        {"DDD", 150.0, 4}
    };

    write_file(file_name, toys, size);

    Toy read_toys[MAX_SIZE];
    Toy found_toys[MAX_SIZE];

    char toy_name[30];
    printf("Enter toy name to find: \n");
    scanf("%s", toy_name);

    int found_count = find_by_name(file_name, read_toys, found_toys, toy_name);


    if (found_count > 0) {
        printf("Found toys:\n");
        for (int i = 0; i < found_count; i++) {
            printf("Name: %s, Price: %.2f UAH\n", found_toys[i].name, found_toys[i].price);
        }
    } else {
        printf("No toys found with the name '%s'.\n", toy_name);
    }

    return 0;
}
