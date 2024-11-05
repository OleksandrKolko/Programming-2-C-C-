#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, res;
    cin >> x;
    cin >> y;
    res = pow(x, y);
    cout <<  res << ", " <<scientific << res << endl;
}