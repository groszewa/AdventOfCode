#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;
int main() {
    ifstream file("input.txt");
    string str;
    int cur_cals = 0;
    priority_queue<int> pq;
    while(getline(file, str)) {
        if(str.empty()) {
            pq.push(cur_cals);
            cur_cals = 0;
        } else {
            cur_cals += stoi(str);
        }
    }
    pq.push(cur_cals);
    int top3 = 0;
    for (int i=0; i<3; i++) {
        top3 += pq.top(); pq.pop();
    }
    cout << "Total calories for top 3 = " << top3 << endl;
    return 0;
}
