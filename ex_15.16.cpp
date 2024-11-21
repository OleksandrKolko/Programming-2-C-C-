#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

class QuadraticEquation {
private:
    double a, b, c; 
    vector<double> roots;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void findRoots() {
        roots.clear();
        if (a == 0) {
            if (b != 0) {
                roots.push_back(-c / b);
            }
        } else {
            double discriminant = b * b - 4 * a * c;
            if (discriminant > 0) {
                roots.push_back((-b + sqrt(discriminant)) / (2 * a));
                roots.push_back((-b - sqrt(discriminant)) / (2 * a));
            } else if (discriminant == 0) {
                roots.push_back(-b / (2 * a));
            }
        }
    }

    vector<double> getRoots() const {
        return roots;
    }

    pair<double, double> findVertex() const {
        double x_vertex = -b / (2 * a);
        double y_vertex = a * x_vertex * x_vertex + b * x_vertex + c;
        return {x_vertex, y_vertex};
    }

    string findIntervals() const {
        if (a > 0) {
            return "Decreasing on (-inf, " + to_string(-b / (2 * a)) + "), Increasing on (" + to_string(-b / (2 * a)) + ", +inf)";
        } else if (a < 0) {
            return "Increasing on (-inf, " + to_string(-b / (2 * a)) + "), Decreasing on (" + to_string(-b / (2 * a)) + ", +inf)";
        } else {
            return "No intervals (not a quadratic function)";
        }
    }
};

int main() {
    vector<QuadraticEquation> equations = {
        QuadraticEquation(1, -3, 2),
        QuadraticEquation(1, -2, 1),
        QuadraticEquation(2, 5, -3),
        QuadraticEquation(1, 1, 1)
    };

    vector<double> allRoots;

    for (auto& eq : equations) {
        eq.findRoots();
        auto roots = eq.getRoots();
        allRoots.insert(allRoots.end(), roots.begin(), roots.end());
    }

    if (!allRoots.empty()) {
        double minRoot = *min_element(allRoots.begin(), allRoots.end());
        double maxRoot = *max_element(allRoots.begin(), allRoots.end());
        cout << "Minimum root: " << minRoot << endl;
        cout << "Maximum root: " << maxRoot << endl;
    } else {
        cout << "No roots found in all equations!" << endl;
    }

    for (size_t i = 0; i < equations.size(); ++i) {
        auto vertex = equations[i].findVertex();
        cout << "Equation " << i + 1 << ": Vertex at (" << vertex.first << ", " << vertex.second << ")" << endl;
        cout << "Intervals: " << equations[i].findIntervals() << endl;
    }

}
