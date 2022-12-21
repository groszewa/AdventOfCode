#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool char_in_string(const char &c, const string &s) {
    return s.find(c)!=string::npos;
}

char get_common_char(const string &str1, const string &str2, const string &str3) {
    for(auto ch1 : str1) {
        if(char_in_string(ch1, str2) and char_in_string(ch1, str3)) return ch1;
    }
    return -1;
}

int main() {
    //ifstream file("test.txt");
    ifstream file("input.txt");
    string str;
    int priority_sum = 0;
    int linenum = 0;
    string str1, str2, str3;
    while(getline(file, str)) {
        int half = str.size()/2;
        string left  = str.substr(0,half);
        string right = str.substr(half, half);
        if(linenum%3==0) str1 = str;
        if(linenum%3==1) str2 = str;
        if(linenum%3==2) {
            str3 = str;
            char common = get_common_char(str1, str2, str3);
            int score =  ((common >= 'a' and common <= 'z') ? common - 'a' + 1 : common - 'A' + 27);
            priority_sum += score;
            //cout << str1 << " : " << str2 << " : " << str3 << " : common = " << common << " : score = " << score << endl;
        }
        linenum++;
    }
    cout << "Priority sum is " << priority_sum << endl;
    return 0;
}
