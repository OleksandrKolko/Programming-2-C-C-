#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    long long* numbers = nullptr;
    int size = 0;
    int capacity = 10;

    numbers = new long long[capacity];
    long long number;

    while (file >> number) {
        if (size >= capacity) {
            capacity *= 2;
            long long* new_numbers = new long long[capacity];
            for (int i = 0; i < size; i++) {
                new_numbers[i] = numbers[i];
            }
            delete[] numbers;
            numbers = new_numbers;
        }
        numbers[size++] = number;
    }
    file.close();

    double* new_numbers = new double[size];
    for (int i = 0; i < size; i++) {
        new_numbers[i] = sqrt(numbers[i]);
    }

    for (int i = size - 1; i >= 0; i--) {
        cout << fixed << setprecision(3) << new_numbers[i] << endl;
    }

    delete[] numbers;
    delete[] new_numbers;
}
