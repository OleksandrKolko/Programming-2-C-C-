#include <iostream>
#include "ex_15.1.h"

Rational max_rational(Rational* arr, int n) {
    Rational min_rat;
    min_rat = arr[0];
    for (int i = 1; i < n; i++) {
        if(arr[i].less(min_rat)) {
            min_rat = arr[i];
        }
    }
    return min_rat;
}

Rational Hregory(double eps) {
    Rational s;
    int sign = -1;
    for(int i = 2; eps * i * i < 1; i++) {
        Rational tmp;
        tmp.set_norm(sign);
        sign = -sign;
        tmp.set_denom(i* i);
        s = s.add(tmp);
    }
    return s;
}