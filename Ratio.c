#include <stdio.h>
#include "Ratio.h"

unsigned gcd(unsigned n, unsigned m) {
    if (m == 0) {
        return n;
    }
    return gcd(m, n % m);
}

void output(Ratio x) {
    printf("%d / %u", x.num, x.dem);
}

int input(Ratio* x) {
    printf("x / y\n");
    printf("Enter numerator: \n");
    scanf("%d", &x->num);
    printf("Enter denominator: \n");
    scanf("%u", &x->dem);
    return x->dem != 0;
}

Ratio add(Ratio x, Ratio y) {
    Ratio z;
    z.num = (int)(x.num * y.dem +  y.num * x.dem);
    z.dem = (int)(x.dem * y.dem);
    return z;
}

Ratio mull(Ratio x, Ratio y) {
    Ratio z;
    z.num = (int)(x.num * y.num);
    z.dem = (int)(x.dem * y.dem);
    return z;
}

void reduce(Ratio* x) {
    unsigned g;
    int n = x->num;
    unsigned m = x->dem;
    if(n > 0) {
        if(n > m) {
            g = gcd(n, m);
        }
        else {
            g = gcd(m, n);
        }
    }
    x->num/=g;
    x->dem/=g;
}

int compare(Ratio x, Ratio y) {
    int left = x.num * y.dem;
    int right = y.num * x.dem;

    if (left > right) {
        return 1; // x > y
    } else if (left < right) {
        return -1; // x < y
    } else {
        return 0; // x == y
    }
}