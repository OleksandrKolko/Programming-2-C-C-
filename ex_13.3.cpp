#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    string word;
    vector<string> words;

    while (ss >> word) {

        if (!word.empty()) {
            word.pop_back();
        }
        words.push_back(word);
    }

    for (size_t i = 0; i < words.size(); ++i) {
        cout << words[i];
        if (i < words.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;
}