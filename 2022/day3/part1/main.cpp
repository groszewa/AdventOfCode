#include<iostream>
#include<fstream>
#include<string>
using namespace std;

char get_common_char(const string &left, const string &right) {
    for(auto ch1 : left) {
        if(right.find(ch1) != string::npos) return ch1;
    }
    return -1;
}

int main() {
    //ifstream file("test.txt");
    ifstream file("input.txt");
    string str;
    int priority_sum = 0;
    while(getline(file, str)) {
        int half = str.size()/2;
        string left  = str.substr(0,half);
        string right = str.substr(half, half);
        char common = get_common_char(left, right);
        priority_sum += ((common >= 'a' and common <= 'z') ? common - 'a' + 1 : common - 'A' + 27);
    }
    cout << "Priority sum is " << priority_sum << endl;
    return 0;
}
