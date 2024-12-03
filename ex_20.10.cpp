#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    cout << "Enter a string: ";
    string inputString;
    getline(cin, inputString);

    cout << "Enter vector characters (as a single string): ";
    string vectorInput;
    getline(cin, vectorInput);

    vector<char> V(vectorInput.begin(), vectorInput.end());

    size_t mid = V.size() / 2;
    vector<char> firstHalf(V.begin(), V.begin() + mid);
    vector<char> secondHalf(V.begin() + mid, V.end());

    set<char> firstSet(firstHalf.begin(), firstHalf.end());
    set<char> secondSet(secondHalf.begin(), secondHalf.end());

    set<char> intersectionSet;
    set_intersection(
        firstSet.begin(), firstSet.end(),
        secondSet.begin(), secondSet.end(),
        inserter(intersectionSet, intersectionSet.begin())
    );

    cout << "Enter the name of the output file: ";
    string fileName;
    getline(cin, fileName);

    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Failed to open the file for writing." << endl;
        return 1;
    }

    for (char c : V) {
        if (intersectionSet.count(c)) {
            outFile << c << ' ';
            intersectionSet.erase(c);
        }
    }

    outFile.close();
    cout << "Results saved to " << fileName << endl;

    return 0;
}
