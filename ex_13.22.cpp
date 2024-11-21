#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string transformWord(const string& word) {
    if (word.length() <= 2) {
        return word;
    }

    char penultimateChar = word[word.length() - 2];
    string transformedWord;

    for (char c : word) {
        if (c != penultimateChar) {
            transformedWord += c;
        }
    }

    return transformedWord;
}

string processSentence(const string& sentence) {
    string result;
    size_t start = 0;
    bool firstWord = true;

    while (start < sentence.length()) {

        size_t end = start;
        while (end < sentence.length() && sentence[end] == ' ') {
            end++;
        }

        if (!firstWord) {
            result += string(end - start, ' ');
        }
        start = end;

        while (end < sentence.length() && sentence[end] != ' ') {
            end++;
        }

        if (start < end) {
            string word = sentence.substr(start, end - start);
            result += transformWord(word);
            start = end;
            firstWord = false;
        }
    }

    return result;
}

int main() {
    string sentence;

    cout << "Enter the sentence: ";
    getline(cin, sentence);

    string transformedSentence = processSentence(sentence);

    cout << "Transformed sentence: " << transformedSentence << endl;
}