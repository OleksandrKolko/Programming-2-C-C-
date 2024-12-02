#include <iostream>
#include <cmath>

using namespace std;

// Base class for 2D point
class Point {
protected:
    double x, y;

public:
    Point() : x(0), y(0) {}

    Point(double xVal, double yVal) : x(xVal), y(yVal) {}

    virtual ~Point() {} // Virtual destructor for inheritance

    virtual void input() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    virtual void show() const {
        cout << "(" << x << ", " << y << ")";
    }

    double getX() const { return x; }
    double getY() const { return y; }

    virtual int getDimensions() const { return 2; }
};

// Derived class for 3D point
class Point3D : public Point {
private:
    double z;

public:
    Point3D() : Point(), z(0) {}

    Point3D(double xVal, double yVal, double zVal) : Point(xVal, yVal), z(zVal) {}

    void input() override {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
        cout << "Enter z: ";
        cin >> z;
    }

    void show() const override {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }

    double getZ() const { return z; }

    int getDimensions() const override { return 3; }
};

// Class representing a line segment
class Segment {
private:
    Point* p1;
    Point* p2;

public:
    Segment(Point* point1, Point* point2) : p1(point1), p2(point2) {}

    ~Segment() {
        // Clean up allocated memory (if applicable)
    }

    void show() const {
        cout << "Segment: ";
        p1->show();
        cout << " to ";
        p2->show();
        cout << endl;
    }

    double length() const {
        if (p1->getDimensions() == p2->getDimensions()) {
            if (p1->getDimensions() == 2) {
                double dx = p2->getX() - p1->getX();
                double dy = p2->getY() - p1->getY();
                return sqrt(dx * dx + dy * dy);
            } else if (p1->getDimensions() == 3) {
                Point3D* pt1 = static_cast<Point3D*>(p1);
                Point3D* pt2 = static_cast<Point3D*>(p2);
                double dx = pt2->getX() - pt1->getX();
                double dy = pt2->getY() - pt1->getY();
                double dz = pt2->getZ() - pt1->getZ();
                return sqrt(dx * dx + dy * dy + dz * dz);
            }
        }

        cout << "Error: Points must have the same dimensions!" << endl;
        return 0;
    }
};

int main() {
    cout << "2D Point Example:" << endl;
    Point p1, p2;
    cout << "Enter coordinates for the first point in 2D:\n";
    p1.input();

    cout << "Enter coordinates for the second point in 2D:\n";
    p2.input();

    Segment segment2D(&p1, &p2);
    cout << "2D Segment: ";
    segment2D.show();
    cout << "Length of 2D segment: " << segment2D.length() << endl;

    cout << "\n3D Point Example:" << endl;
    Point3D p3, p4;
    cout << "Enter coordinates for the first point in 3D:\n";
    p3.input();

    cout << "Enter coordinates for the second point in 3D:\n";
    p4.input();

    Segment segment3D(&p3, &p4);
    cout << "3D Segment: ";
    segment3D.show();
    cout << "Length of 3D segment: " << segment3D.length() << endl;

    return 0;
}
