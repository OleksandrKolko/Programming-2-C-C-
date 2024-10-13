#include <stdio.h>
#include <math.h>

int with_cycle(unsigned int n) {
    int is_power = 0;
    while(n > 0) {
        if(n & 1) {
            if(is_power) {
                is_power = 0;
                return is_power;
            }
            else {
                is_power = 1;
            }
        }
        n >>= 1;
    }
    return is_power;
}

int without_cycle(unsigned int n) {
    return ((n & (n - 1)) == 0);
}


int main() {
    unsigned int n;
    printf("Enter n: \n");
    scanf("%u", &n);
    int is_power1 = with_cycle(n);
    printf("Using function with cycle:\n");
    if (is_power1) {
        printf("Number %u is power of 2.\n", n);
    }
    else {
        printf("Number %u not is power of 2.\n", n);
    }
    printf("\n");
    printf("Now using non-cycle function:\n");
    int is_power2 = with_cycle(n);
    if (is_power2) {
        printf("Number %u is power of 2.\n", n);
    }
    else {
        printf("Number %u not is power of 2.\n", n);
    }
}