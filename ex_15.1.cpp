#include "ex_15.1.h"
using namespace std;

void Rational::show() {
    cout << nom << "/" << denom << "\n";
}

int Rational::input() {
    cout << "Input nom" << "\n";
    cin >> nom;
    cout << "Input denom" << "\n";
    cin >> denom;
    reduce();
    return 0;
}

Rational Rational::add(const Rational& x) {
    int t = (int)(this-> nom * x.denom + this->denom * x.nom);
    unsigned y = x.nom * x.denom;
    return Rational(t, y);
}
Rational Rational::mull(const Rational& x) {
    int t = (int)(nom * x.nom);
    unsigned y = denom * x.denom;
    return Rational(t, y);
}

unsigned Rational::gcd(unsigned x, unsigned y) {
    if(y==0||x==0) return x+y;
    if(x>=y) return gcd(x%y, y);
    return gcd(y%x, x);
}


void Rational::reduce() {
    int nsd;
    if(nom >= 0) {
        nsd = (int)(gcd(nom, denom));
    }
    else {
        nsd = (int)(gcd(-nom, denom));
    }
    nom /= nsd;
    denom /= nsd;
}