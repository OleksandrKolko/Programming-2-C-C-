#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void createStudentFile(const char* fname) {
    ofstream f1(fname);
    unsigned N;
    cin >> N;

    string surname;
    int course;
    string group;
    string marks;

    for(int i = 0; i < N; i++) {
        cin >> surname >> course >> group >> marks;
        f1 << surname << ' ' <<  course << ' ' << group << ' ' << marks << '\n';
    }
    f1.close();
}

double averageMark(string marks) {
    double sum = 0;
    int counter = 0;
    char coma = '\'';
    int tmp;
    stringstream str(marks);
    while(str >> tmp) {
        sum += tmp;
        counter++;
        str >> coma;
    }
    return sum / counter;
}

string findStudent(const char* fname) {
    double min_mark = 12;
    string looser;
    ifstream f1(fname);
    while(!f1.eof()) {
        string surname, course, group, marks;
        f1 >> surname >> course >> group >> marks;
        double average_mark = averageMark(marks);
        if(average_mark < min_mark) {
            min_mark = average_mark;
            looser = surname;
        }
    }
    return looser;
    f1.close()
}

int main() {
    createStudentFile("students.txt");
    cout << findStudent("students.txt") << endl;
}