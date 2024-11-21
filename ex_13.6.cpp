#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> findShortestWords(const string& sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> words;
    size_t minLength = SIZE_MAX;

    while (ss >> word) {
        words.push_back(word);
        minLength = min(minLength, word.size());
    }

    vector<string> shortestWords;
    for (const string& w : words) {
        if (w.size() == minLength) {
            shortestWords.push_back(w);
        }
    }

    return shortestWords;
}

int main() {
    string sentence;

    cout << "Enter the sentence: ";
    getline(cin, sentence);

    vector<string> shortestWords = findShortestWords(sentence);

    cout << "Shortest words: ";
    for (const string& word : shortestWords) {
        cout << word << " ";
    }
    cout << endl;

}
