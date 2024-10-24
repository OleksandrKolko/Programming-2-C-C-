#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_power_of_two(int x) {
    // Побітова перевірка
    return ((x & (x - 1)) == 0);
}

int is_power_of_three(int x) {
    while(x % 3 == 0) {
        x /= 3;
    }
    return x == 1;
}

int main() {
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);

    int* arr = (int*)calloc(n, sizeof(int));
    printf("Enter array elements: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int power_of_two = 0, power_of_three = 0;
    for(int i = 0; i < n; i++) {
        if(is_power_of_two(arr[i])) {
            power_of_two++;
        }
        else if(is_power_of_three(arr[i])) {
            power_of_three++;
        }
    }
    free(arr);

    printf("Power of two count: %d\nPower of three: %d", power_of_two, power_of_three);
}