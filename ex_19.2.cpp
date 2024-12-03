#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double norm(const vector<double>& vec) {
    double sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        double val = vec[i];
        sum += val * val;
    }
    return sqrt(sum);
}

int main() {
    int n, d;
    cout << "enter number of vectors (n): ";
    cin >> n;
    cout << "enter dimension of vectors (d): ";
    cin >> d;
    vector<vector<double>> vectors(n, vector<double>(d));
    for (int i = 0; i < n; ++i) {
        cout << "enter vector " << i + 1 << " (size " << d << "): ";
        for (int j = 0; j < d; ++j) {
            cin >> vectors[i][j];
        }
    }
    double sum_of_norms = 0;
    for (const auto& vec : vectors) {
        sum_of_norms += norm(vec);
    }
    cout << "sum of norms of vectors: " << sum_of_norms << endl;
}