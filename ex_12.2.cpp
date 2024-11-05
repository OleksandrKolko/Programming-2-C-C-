#include <iostream>
#include <cmath>

int main() {
    char str[10];
    unsigned a;
    unsigned long long sum = 0UL;
    std:: cout<<"Enter:\n";
    unsigned n = 0;
    unsigned mas[1000];
    size_t sz;
    while(std:: cin.get(str, 10)) {
        std:: cout << str << "," << std::endl;
        a = std::stoull(str, &sz);
        mas[n] = a;
        n++;
        sum += a;
    }
    std:: cout << "s = " << sum << "\n";
}