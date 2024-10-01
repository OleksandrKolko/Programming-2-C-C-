#include <stdio.h>
#include <math.h>
int main() {
    unsigned char n;
    scanf("%hhu",&n);
    // unsigned long long - щоб усе вмістилося
    unsigned long long m;
    scanf("%llu",&m);
    printf("%llu", m &~(1 << n));
}
