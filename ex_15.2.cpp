#include <iostream>
#include <math.h>
using namespace std;

class Point {
    double x;
    double y;

    public:
    void input() {
        cin >> x >> y;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
};

double length(Point a, Point b) {
    double x = a.getX() - b.getX();
    double y = a.getY() - b.getY();
    return sqrt(x*x + y*y);
}

int main() {
    char answer;
    Point points[10];
    int i = 0;
    do {
        cout << "Input vertex?(Y/N):";
        cin >> answer;
        if (answer == 'N') {
            break;
        }

        points[i].input();
        i++;
    }while (answer == 'Y');

    double per = 0;
    for(int j = 1; j < i; j++) {
        per += length(points[j], points[j - 1]);
    }
    per += length(points[i - 1], points[0]);
}