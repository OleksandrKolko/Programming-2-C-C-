#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;
int main() {
    const char* filename = "text.txt";
    fstream f(filename);
    string word;
    map<string, int> fr;

    if (!f.is_open()) {
        cout << "error opening file" << endl;
        return 1;
    }

    while (f >> word) {
        fr[word]++;
    }
    for (const auto& entry : fr) {
        cout << entry.first << ": " << entry.second << endl;
    }
    f.close();

}