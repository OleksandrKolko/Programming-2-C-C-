#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << string(10 * n + 1, '+') << "\n";

    for (int i = 1; i <= n; ++i) {
        cout << setw(6) << i << "   ";
    }
    cout << "\n";

    cout << string(10 * n + 1, '+') << "\n";

    for (int i = 1; i <= n; ++i) {
        double root = sqrt(i);
        cout << setw(6) << fixed << setprecision((root == static_cast<int>(root)) ? 0 : 2) << root << "   ";
    }
    cout << "\n";

    cout << string(10 * n + 1, '+') << "\n";

    return 0;
}
