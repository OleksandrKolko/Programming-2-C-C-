#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cout << "number of rows (n): ";
    cin >> n;
    cout << "number of columns (m): ";
    cin >> m;
    vector<list<double>> matrix(n);
    for (int i = 0; i < n; i++) {
        double temp;
        cout << i + 1 << "th row:\n";
        for (int j = 0; j < m; j++) {
            cout << "enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> temp;
            matrix[i].push_back(temp);
        }
    }
    vector<pair<double, int>> max_elements(n);
    
    for (int i = 0; i < n; i++) {
        double max_val = *max_element(matrix[i].begin(), matrix[i].end());
        max_elements[i] = {max_val, i};
    }
    sort(max_elements.begin(), max_elements.end(), greater<pair<double, int>>());
    vector<list<double>> result_matrix(n);
    for (int i = 0; i < n; i++) {
        result_matrix[i] = matrix[max_elements[i].second];
    }

    cout << "res:\n";
    for (int i = 0; i < n; i++) {
        for (auto value : result_matrix[i]) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}