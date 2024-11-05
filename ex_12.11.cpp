#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int count_decimal_places(string num_str) {
    size_t pos = num_str.find('.');

    if (pos == string::npos) {
        return 0;
    }

    int decimal_places = 0;
    for (size_t i = pos + 1; i < num_str.length(); ++i) {
        if (num_str[i] == '0') break;
        decimal_places++;
    }

    return decimal_places;
}


int main() {
    ifstream file("file.txt");
    if (!file.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    int max_decimal = 0;
    int size = 0;
    int capacity = 10;
    string temp;
    double* numbers = new double[capacity];
    while( getline(file, temp, ';')) {
        if (size >= capacity) {
            capacity *= 2;
            double* new_numbers = new double[capacity];
            for (int i = 0; i < size; i++) {
                new_numbers[i] = numbers[i];
            }
            delete[] numbers;
            numbers = new_numbers;
        }
        if (max_decimal < count_decimal_places(temp)) {
            max_decimal = count_decimal_places(temp);
        }
        numbers[size++] = fabs(stod(temp));
    }
    file.close();

    ofstream out("file.txt");
    for(int i = 0; i < size; i++) {
        out << fixed << setprecision(3) << numbers[i] << endl;
    }
    out.close();

    delete[] numbers;
}