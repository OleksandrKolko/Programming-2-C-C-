#include <iostream>
#include <string>
using namespace std;

string processString(const string& input, bool replaceOriginal = false) {
    size_t firstColon = input.find(':');
    if (firstColon == string::npos) {
        return input;
    }

    size_t nextComma = input.find(',', firstColon + 1);
    if (nextComma == string::npos) {

        return input.substr(firstColon);
    }


    return input.substr(firstColon + 1, nextComma - firstColon - 1);
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string result = processString(input);
    cout << "Result in a new string: " << result << endl;

    string modifiedString = processString(input, true);
    cout << "Original string replaced with: " << modifiedString << endl;
}