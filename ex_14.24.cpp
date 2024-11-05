#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printFullFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void printSpecificLengthLines(const string& filename, int length) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.length() == length) {
            cout << line << endl;
        }
    }

    file.close();
}

int main() {
    string filename = "file.txt";

    cout << "All file:\n";
    printFullFile(filename);

    cout << "\nOnly rows with 60 symbols:\n";
    printSpecificLengthLines(filename, 60);

    return 0;
}
