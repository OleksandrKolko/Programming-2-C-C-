#include <iostream>
#include <list>
#include <cmath>
using namespace std;
template <typename T>
class Polynomial {
private:
    list<T> coefficients;

public:
    Polynomial() = default;
    Polynomial(const list<T>& coeffs) : coefficients(coeffs) {}
    void input() {
        size_t degree;
        cout << "enter the degree of the polynomial: ";
        cin >> degree;

        coefficients.clear();

        cout << "enter the coefficients (from constant to highest degree):\n";
        for (size_t i = 0; i <= degree; ++i) {
            T coef;
            cout << "coefficient of x^" << i << ": ";
            cin >> coef;
            coefficients.push_back(coef);
        }
    }
    void output() const {
        if (coefficients.empty()) {
            cout << "polynomial is empty\n";
            return;
        }

        size_t i = 0;
        for (const T& coef : coefficients) {
            if (i > 0 && coef >= 0) cout << "+";
            cout << coef;
            if (i > 0) cout << "x^" << i;
            if (i < coefficients.size() - 1) cout << " ";
            ++i;
        }
        cout << "\n";
    }
    Polynomial<T> operator+(const Polynomial<T>& other) const {
        auto it1 = coefficients.begin();
        auto it2 = other.coefficients.begin();
        list<T> result;
        while (it1 != coefficients.end() || it2 != other.coefficients.end()) {
            T coef1 = (it1 != coefficients.end()) ? *it1 : 0;
            T coef2 = (it2 != other.coefficients.end()) ? *it2 : 0;
            result.push_back(coef1 + coef2);

            if (it1 != coefficients.end()) ++it1;
            if (it2 != other.coefficients.end()) ++it2;
        }

        return Polynomial<T>(result);
    }
    Polynomial<T> operator*(const Polynomial<T>& other) const {
        size_t degree1 = coefficients.size();
        size_t degree2 = other.coefficients.size();
        list<T> result(degree1 + degree2 - 1, 0);

        for (size_t i = 0; i < degree1; ++i) {
            for (size_t j = 0; j < degree2; ++j) {
                auto it_result = result.begin();
                advance(it_result, i + j);
                auto it1 = coefficients.begin();
                advance(it1, i);
                auto it2 = other.coefficients.begin();
                advance(it2, j);
                *it_result += *it1 * *it2;
            }
        }

        return Polynomial<T>(result);
    }
    T evaluate(T x) const {
        T result = 0;
        size_t power = 0;
        for (const T& coef : coefficients) {
            result += coef * pow(x, power);
            ++power;
        }
        return result;
    }
};

int main() {
    Polynomial<int> p1, p2;

    cout << "enter poly1:\n";
    p1.input();
    cout << "Enter poly2:\n";
    p2.input();
    cout << "polynom1: ";
    p1.output();
    cout << "polynom2: ";
    p2.output();
    Polynomial<int> sum = p1 + p2;
    cout << "sum of polynomials: ";
    sum.output();
    Polynomial<int> product = p1 * p2;
    cout << "mul of polynomials: ";
    product.output();
    int x;
    cout << "enter x: ";
    cin >> x;
    cout << "value of polynom1 at x = " << x << ": " << p1.evaluate(x) << "\n";
    cout << "value of polynom2 at x = " << x << ": " << p2.evaluate(x) << "\n";
    cout << "value of sum at x = " << x << ": " << sum.evaluate(x) << "\n";
    cout << "value of mul at x = " << x << ": " << product.evaluate(x) << "\n";
}