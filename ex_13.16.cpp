#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

vector<string> wordsEndingWith(const string& sentence, char endingChar) {
    vector<string> result;
    stringstream ss(sentence);
    string word;

    endingChar = tolower(endingChar);

    while (ss >> word) {

        if (!word.empty() && tolower(word.back()) == endingChar) {
            result.push_back(word);
        }
    }

    return result;
}

int main() {
    string sentence;
    char endingChar;

    cout << "Enter the sentence: ";
    getline(cin, sentence);

    cout << "Enter the ending character: ";
    cin >> endingChar;

    vector<string> matchingWords = wordsEndingWith(sentence, endingChar);

    cout << "Words ending with '" << endingChar << "': ";
    for (const string& word : matchingWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}