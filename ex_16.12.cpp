#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <functional>

using namespace std;

// Базовий клас Рівняння
class Equation {
public:
    virtual bool hasRealRoot(double a, double b) = 0;
    virtual double findRoot(double a, double b) = 0;
    virtual string toString() = 0;
    virtual ~Equation() = default;
};

// Лінійне рівняння (ax + b = 0)
class LinearEquation : public Equation {
    double a, b;
public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    bool hasRealRoot(double, double) override {
        return a != 0;
    }

    double findRoot(double, double) override {
        if (a == 0) throw runtime_error("No root for linear equation.");
        return -b / a;
    }

    string toString() override {
        return to_string(a) + "x + " + to_string(b) + " = 0";
    }
};

// Квадратичне рівняння (ax^2 + bx + c = 0)
class QuadraticEquation : public Equation {
    double a, b, c;
public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    bool hasRealRoot(double, double) override {
        double discriminant = b * b - 4 * a * c;
        return discriminant >= 0;
    }

    double findRoot(double a, double b) override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) throw runtime_error("No real root for quadratic equation.");
        return (-b + sqrt(discriminant)) / (2 * a);
    }

    string toString() override {
        return to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + " = 0";
    }
};

// Експоненціальне рівняння (ae^x + b = 0)
class ExponentialEquation : public Equation {
    double a, b;
public:
    ExponentialEquation(double a, double b) : a(a), b(b) {}

    bool hasRealRoot(double, double) override {
        return a != 0 && b != 0;
    }

    double findRoot(double a, double b) override {
        if (a == 0 || b == 0) throw runtime_error("No real root for exponential equation.");
        return log(-b / a);
    }

    string toString() override {
        return to_string(a) + "e^x + " + to_string(b) + " = 0";
    }
};


void processEquations(const vector<Equation*>& equations, double a, double b) {
    cout << "Equations with no real roots:\n";
    for (const auto& eq : equations) {
        if (!eq->hasRealRoot(a, b)) {
            cout << eq->toString() << endl;
        }
    }

    cout << "\nFinding the largest root:\n";
    double largestRoot = -numeric_limits<double>::infinity();
    Equation* largestRootEq = nullptr;

    for (const auto& eq : equations) {
        if (eq->hasRealRoot(a, b)) {
            double root = eq->findRoot(a, b);
            if (root > largestRoot) {
                largestRoot = root;
                largestRootEq = eq;
            }
        }
    }

    if (largestRootEq) {
        cout << "Largest root: " << largestRoot << " from equation " << largestRootEq->toString() << endl;
    } else {
        cout << "No real roots found in the interval.\n";
    }
}

int main() {
    vector<Equation*> equations;

    equations.push_back(new LinearEquation(2, -4));          // 2x - 4 = 0
    equations.push_back(new QuadraticEquation(1, -3, 2));    // x^2 - 3x + 2 = 0
    equations.push_back(new ExponentialEquation(1, -2));     // e^x - 2 = 0

    double intervalStart = -10;
    double intervalEnd = 10;

    processEquations(equations, intervalStart, intervalEnd);

    // Очищення пам'яті
    for (auto eq : equations) {
        delete eq;
    }

    return 0;
}
