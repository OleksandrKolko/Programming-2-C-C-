#include <iostream>
#include "ex_15.3.h"

int main() {
    Polynom p4[10];
    Polynom p3(3);
    double a[5] = {1, 2, 3, 4, 5};
    Polynom p2(3, a);

    Polynom p1(p2);
    p3 = p2;

    p2.show();
    p1.show();
    p3.show();

    save_file("p1.dat", p2);
    save_file("p1.dat", p3);
    p3.show();
}