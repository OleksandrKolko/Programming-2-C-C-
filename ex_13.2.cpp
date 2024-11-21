#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string processString(const string& input) {
    size_t firstDot = input.find('.');
    if (firstDot == string::npos) {
        string trimmedInput = input;
        trimmedInput.erase(0, trimmedInput.find_first_not_of(' '));
        return trimmedInput;
    }

    size_t lastDot = input.rfind('.');
    if (firstDot == lastDot) {

        return input.substr(firstDot + 1);
    }

    string result = input.substr(0, firstDot + 1) + input.substr(lastDot);
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string result = processString(input);
    cout << "Processed string: " << result << endl;
}