#include <iostream>
#include <fstream>
using namespace std;

string reverseString(const string& str) {
    string reversed_str;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed_str += str[i];
    }
    return reversed_str;
}

int main() {
    ifstream file1("file.txt");
    if (!file1.is_open()) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    string str;
    string* words = new string[100];
    int size = 0;
    while(file1 >> str) {

        if (size >= 100) {
            cerr << "Exceeded maximum number of words" << endl;
            break;
        }
        words[size++] = str;
    }
    file1.close();

    ofstream file2("file.txt");
    if (!file2.is_open()) {
        cerr << "Can't open file" << endl;
        delete[] words;
        return 1;
    }

    for(int i = 0; i < size; i++) {
        file2 << reverseString(words[i]) << ' ';
    }

    file2.close();
    delete[] words;
    return 0;
}
