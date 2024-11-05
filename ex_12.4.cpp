#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    int n;

    cout << "Enter n: \n";
    cin >> n;

    if (n <= 0) {
        cerr << "n must be greater than 0." << endl;
        return 1;
    }

    int* numbers = new int[n];

    cout << "Enter " << n << " numbers: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    ifstream file1("file.txt");
    if (!file1.is_open()) {
        cerr << "Can't open file" << endl;
        delete[] numbers;
        return 1;
    }

    int* file_numbers = new int[n];

    for (int i = 0; i < n; ++i) {
        if (!(file1 >> file_numbers[i])) {
            cerr << "Can't read number from file or file has fewer numbers!" << endl;
            delete[] file_numbers;
            delete[] numbers;
            file1.close();
            return 1;
        }
    }

    file1.close();

    ofstream file2("file.txt");
    if (!file2.is_open()) {
        cerr << "Can't open file for writing!" << endl;
        delete[] file_numbers;
        delete[] numbers;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        double result = pow(numbers[i], file_numbers[i]);
        file2 << result << ' ';
    }
    file2.close();

    delete[] file_numbers;
    delete[] numbers;

    return 0;
}
