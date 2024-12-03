#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;
struct Segment {
    int x1, y1, x2, y2;
    double length;
    Segment(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {
        length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
    bool operator<(const Segment& other) const {
        return length < other.length;
    }
    bool isDegenerate() const {
        return x1 == x2 && y1 == y2;
    }
    bool operator==(const Segment& other) const {
        return (x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2) ||
               (x1 == other.x2 && y1 == other.y2 && x2 == other.x1 && y2 == other.y1);
    }
};
struct SegmentHash {
    size_t operator()(const Segment& seg) const {
        return hash<int>{}(seg.x1) ^ hash<int>{}(seg.y1) ^ hash<int>{}(seg.x2) ^ hash<int>{}(seg.y2);
    }
};

int main() {
    ifstream inputFile("points.txt");
    ofstream outputFile("segments.txt");

    if (!inputFile) {
        cerr << "unable to open the input file" << endl;
        return 1;
    }

    vector<pair<int, int>> points;
    string line;
    while (getline(inputFile, line)) {
        int x1, y1, x2, y2;
        char ch;
        istringstream stream(line);
        stream >> ch >> x1 >> ch >> y1 >> ch >> ch >> ch >> x2 >> ch >> y2 >> ch;

        points.push_back({x1, y1});
        points.push_back({x2, y2});
    }
    set<Segment> uniqueSegments;

    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            Segment seg(points[i].first, points[i].second, points[j].first, points[j].second);
            if (!seg.isDegenerate()) {
                uniqueSegments.insert(seg);
            }
        }
    }
    vector<Segment> segments(uniqueSegments.begin(), uniqueSegments.end());
    for (const auto& seg : segments) {
        outputFile << "(" << seg.x1 << ", " << seg.y1 << ") (" << seg.x2 << ", " << seg.y2 << ")\n";
    }
    inputFile.close();
    outputFile.close();

    cout << "segments successfully written to file" << endl;
}