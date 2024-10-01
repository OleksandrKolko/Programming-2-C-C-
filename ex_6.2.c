#include <stdio.h>
#include <math.h>

int main() {
    int n;
    unsigned k;
    scanf("%d",&n);
    scanf("%u", &k);
    printf("%d", k|(1 << n));
}
