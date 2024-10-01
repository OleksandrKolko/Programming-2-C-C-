#include <stdio.h>
#include <math.h>
int max_ones_count(unsigned long long n) {
    int max_cnt = 0;
    while(n) {
        int cnt = 0;
        while(n & 1) {
            n >>= 1;
            cnt++;
        }
        n >>= 1;
        if (max_cnt < cnt) {
            max_cnt = cnt;
        }
    }
    return max_cnt;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    printf("%d", max_ones_count(n));
}
