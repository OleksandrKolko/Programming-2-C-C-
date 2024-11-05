#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    char fname[20] = "deutsch.txt";
    ifstream f(fname);
    string Articles[] = {"der", "die", "das"};
    string buf;
    bool is_article = false;
    ofstream f2("tmp.txt");

    while(f >> buf) {
        if(is_article) {
            buf[0] = toupper(buf[0]);
        }
        clog << buf << " ";
        f2 << buf << " ";
        is_article = false;
        for(int i = 0; i < 3; i++) {
            if(buf == Articles[i]) {
                is_article = true;
                break;
            }
        }
    }
    f.close();
    f2.close();
    rename("tmp.txt", fname);
}