#include <iostream>
#include "Rational.h"
#include <string>
#include <cstring>
using namespace std;

template <typename T>
T* our_max(T* a, T* b) {
    int n = strlen(a);
    int m = strlen(b);
    int k = min(n, m);
    for (int i = 0; i < k; i++) {
        if (a[i] < b[i]) {
            return b;
        }
        else if (a[i] > b[i]) {
            return b;
        }
    }
    return a;
}

template <typename T>
T our_max(T a, T b) {
    return a > b ? a : b;
}

int main() {
    Rational r1 = {4, 9};
    Rational r2 = {3, 7};
    Rational r3 = our_max(r1, r2);
    cout << r3 << endl;
}