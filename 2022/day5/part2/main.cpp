#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream file("test.txt");
    //ifstream file("input.txt");
    string str;
    while(getline(file, str)) {
        cout << str << endl;
    }
    return 0;
}
