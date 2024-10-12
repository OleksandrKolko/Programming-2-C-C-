#include <stdio.h>
#include <math.h>

// Пункт б)
int main() {
    double S = 0, a1 =1, a2 = 1, ak;
    unsigned n;
    printf("Enter n: \n");
    scanf("%u", &n);
    if(n == 1) {
        S = 3 / a1;
    }
    else if(n == 2) {
        S =  9 / a2;
    }
    else {
        S = 12;
        for(int k = 3; k <= n; k++) {
            ak = (a2 / k) + a1;
            S += pow(3, k) / ak;
            a1 = a2;
            a2 = ak;
        }
    }
    printf("S = %lf", S);
}
