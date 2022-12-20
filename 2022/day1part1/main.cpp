#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream file("input.txt");
    string str;
    int cur_max = 0;
    int cur_cals = 0;
    while(getline(file, str)) { 
        if(str.empty()) {
            cur_max = max(cur_max, cur_cals);
            cur_cals = 0;
        } else {
            cur_cals += stoi(str);
        }
    }
    cur_max = max(cur_max, cur_cals);
    cout << "Max calories is " << cur_max << endl;
    return 0;
}
