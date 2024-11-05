#include "ex_15.3.h"
#include <iostream>
#include <cstdio>

using namespace  std;

Polynom::Polynom (size_t n) {
    this->n = n;
    p = new double[n];
}
Polynom::Polynom(size_t, double *arr) {
    this->n = n;
    p = new double[n];
    for(int i = 0; i < n; i++) {
        p[i] = arr[i];
    }
}
Polynom::Polynom(const Polynom& a) {
    this->n = a.n;
    p = new double[a.n];
    for(int i = 0; i < n; i++) {
        p[i] = a.p[i];
    }
}

Polynom & Polynom::operator=(const Polynom& a) {
    if(n>0) delete [] p;
    this->n = a.n;
    p = new double[a.n];
    for(int i = 0; i < n; i++) {
        p[i] = a.p[i];
    }
}
int Polynom::set(size_t k, double a) {
    if(n > n) return -1;
    p[k] = a;
}

double Polynom::get(size_t k) {
    if(k > n) return 0;
    return p[k];
}
void Polynom::show() {
    for(int i = 0; i < n; i++) {
        cout << p[i] << "*x^" << (n-i-1) << "+";
    }
    cout << p[n-1] << endl;
}

int save_file(const char *fname, Polynom& p) {
    FILE* fp = fopen(fname, "w + b");
    if(fp == NULL) {
        cerr<<"Error writing file";
        return -1;
    }
    fwrite(&(p.n), sizeof(size_t), 1, fp);
    fwrite(p.p, sizeof(double), p.n, fp);
    fclose(fp);
    return 0;
}