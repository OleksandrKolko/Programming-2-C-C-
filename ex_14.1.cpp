#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    char f_name[] = "Test.txt";
    fstream f(f_name);
    if(!f) {
        cerr << "error reading file" << f_name << "\n";
        return 1;
    }
    char c;
    int num = 0;
    int num2 = 0;
    int summ = 0;
    int prev_sign =  0;
    while(f>>c) {
        if(isdigit(c)) {
            int d = c - '0';
            num = num * 10 + d;
        }
        else if(c == '-') {
            num2 = num;
            num = 0;
            if (prev_sign == 1 || prev_sign == 0) {
                summ += num2;
            }
            else if(prev_sign == 2) {
                summ -= num2;
            }
            prev_sign = 2;
            cout << summ << "i";
        }
        else if(c == '+') {
            num2 = num;
            num = 0;
            if (prev_sign == 1 || prev_sign == 0) {
                summ += num2;
            }
            else if(prev_sign == 2) {
                summ -= num2;
            }
            prev_sign = 1;
            cout << summ << "i";
        }
        else if(c == '=') {
            num2 = num;
            if(prev_sign == 1) {
                summ += num2;
            }
            else if(prev_sign == 2) {
                summ -= num2;
            }
            cout << "sum = " << summ << "\n";
        }
        else {
            cout << "Not required format:" << c << "- incorrect symbol\n";
        }
    }
}