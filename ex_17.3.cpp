#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

int charToDigit(char c, int base) {
    if (c >= '0' && c <= '9') {
        int digit = c - '0';
        if (digit >= base) {
            throw std::invalid_argument("Invalid character for the given base: " + std::string(1, c));
        }
        return digit;
    } else if (c >= 'A' && c <= 'F') {
        int digit = c - 'A' + 10;
        if (digit >= base) {
            throw std::invalid_argument("Invalid character for the given base: " + std::string(1, c));
        }
        return digit;
    } else if (c >= 'a' && c <= 'f') {
        int digit = c - 'a' + 10;
        if (digit >= base) {
            throw std::invalid_argument("Invalid character for the given base: " + std::string(1, c));
        }
        return digit;
    } else {
        throw std::invalid_argument("Invalid character: " + std::string(1, c));
    }
}


unsigned long long calculateValue(const std::string& number, int base) {
    assert(base >= 2 && base <= 16);

    unsigned long long value = 0;
    for (char c : number) {
        int digit = charToDigit(c, base);
        value = value * base + digit; 
    }

    return value;
}

int main() {
    try {
        std::string number;
        int base;

        std::cout << "Enter the number: ";
        std::cin >> number;

        std::cout << "Enter the base (2 <= b <= 16): ";
        std::cin >> base;

        if (base < 2 || base > 16) {
            throw std::invalid_argument("Base must be in the range 2 <= b <= 16.");
        }

        unsigned long long result = calculateValue(number, base);
        std::cout << "The value of the number in decimal: " << result << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
