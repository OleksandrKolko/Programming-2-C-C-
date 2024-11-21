#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<double> extractNumbers(const string& input, char delimiter, int n) {
    vector<double> result;
    stringstream ss(input);
    string token;

    while (getline(ss, token, delimiter)) {
        try {
            double num = stod(token);
            result.push_back(num);

            if (result.size() == n) {
                break;
            }
        } catch (const invalid_argument& e) {
            continue;
        }
    }

    return result;
}

int main() {
    string input;
    char delimiter;
    int n;

    cout << "Enter the string: ";
    getline(cin, input);

    cout << "Enter the delimiter: ";
    cin >> delimiter;

    cout << "Enter the number of real numbers to extract: ";
    cin >> n;

    vector<double> numbers = extractNumbers(input, delimiter, n);

    cout << "Extracted numbers: ";
    for (double num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}